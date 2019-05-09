#pragma once

#include <iostream>
#include <windows.h>
#include <WinUser.h>
#include <WinBase.h>
#include <tchar.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"wininet.lib")
#pragma comment(lib, "Advapi32.lib")
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <WinInet.h>
#include <iomanip>
#include <cstdio>  

#pragma region HWID

std::string GetHwUID()
{
	HW_PROFILE_INFO hwProfileInfo;
	std::string szHwProfileGuid = "";

	if (GetCurrentHwProfileA(&hwProfileInfo) != NULL)
		szHwProfileGuid = hwProfileInfo.szHwProfileGuid;

	return szHwProfileGuid;
}
std::string GetCompUserName(bool User)
{
	std::string CompUserName = "";

	char szCompName[MAX_COMPUTERNAME_LENGTH + 1];
	char szUserName[MAX_COMPUTERNAME_LENGTH + 1];

	DWORD dwCompSize = sizeof(szCompName);
	DWORD dwUserSize = sizeof(szUserName);

	if (GetComputerNameA(szCompName, &dwCompSize))
	{
		CompUserName = szCompName;

		if (User && GetUserNameA(szUserName, &dwUserSize))
		{
			CompUserName = szUserName;
		}
	}

	return CompUserName;
}
std::string StringToHex(const std::string input)
{
	const char* lut = "0123456789ABCDEF";
	size_t len = input.length();
	std::string output = "";

	output.reserve(2 * len);

	for (size_t i = 0; i < len; i++)
	{
		const unsigned char c = input[i];
		output.push_back(lut[c >> 4]);
		output.push_back(lut[c & 15]);
	}

	return output;
}
DWORD GetVolumeID()
{
	DWORD VolumeSerialNumber;

	BOOL GetVolumeInformationFlag = GetVolumeInformationA(
		"c:\\",
		0,
		0,
		&VolumeSerialNumber,
		0,
		0,
		0,
		0
	);

	if (GetVolumeInformationFlag)
		return VolumeSerialNumber;

	return 0;
}

std::string GetSerialKey()
{
	std::string SerialKey = "61A345B5496B2";
	std::string CompName = GetCompUserName(false);
	std::string UserName = GetCompUserName(true);

	SerialKey.append(StringToHex(GetHwUID()));
	SerialKey.append("-");
	SerialKey.append(StringToHex(std::to_string(GetVolumeID())));
	SerialKey.append("-");
	SerialKey.append(StringToHex(CompName));
	SerialKey.append("-");
	SerialKey.append(StringToHex(UserName));

	return SerialKey;
}
bool SpectroFobia = true;
bool Revenger = false;
bool Diss = false;
std::string GetHashText(const void * data, const size_t data_size)
{
	HCRYPTPROV hProv = NULL;

	if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT))
	{
		return "";
	}

	BOOL hash_ok = FALSE;
	HCRYPTPROV hHash = NULL;

	hash_ok = CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash);

	if (!hash_ok)
	{
		CryptReleaseContext(hProv, 0);
		return "";
	}

	if (!CryptHashData(hHash, static_cast<const BYTE *>(data), data_size, 0))
	{
		CryptDestroyHash(hHash);
		CryptReleaseContext(hProv, 0);
		return "";
	}

	DWORD cbHashSize = 0, dwCount = sizeof(DWORD);
	if (!CryptGetHashParam(hHash, HP_HASHSIZE, (BYTE *)&cbHashSize, &dwCount, 0))
	{
		CryptDestroyHash(hHash);
		CryptReleaseContext(hProv, 0);
		return "";
	}

	std::vector<BYTE> buffer(cbHashSize);

	if (!CryptGetHashParam(hHash, HP_HASHVAL, reinterpret_cast<BYTE*>(&buffer[0]), &cbHashSize, 0))
	{
		CryptDestroyHash(hHash);
		CryptReleaseContext(hProv, 0);
		return "";
	}

	std::ostringstream oss;

	for (std::vector<BYTE>::const_iterator iter = buffer.begin(); iter != buffer.end(); ++iter)
	{
		oss.fill('0');
		oss.width(2);
		oss << std::hex << static_cast<const int>(*iter);
	}

	CryptDestroyHash(hHash);
	CryptReleaseContext(hProv, 0);
	return oss.str();
}

std::string GetHashSerialKey()
{
	std::string SerialKey = GetSerialKey();
	const void* pData = SerialKey.c_str();
	size_t Size = SerialKey.size();
	std::string Hash = GetHashText(pData, Size);

	for (auto& c : Hash)
	{
		if (c >= 'a' && c <= 'f')
		{
			c = '4';
		}
		else if (c == 'b')
		{
			c = '5';
		}
		else if (c == 'c')
		{
			c = '6';
		}
		else if (c == 'd')
		{
			c = '7';
		}
		else if (c == 'e')
		{
			c = '8';
		}
		else if (c == 'f')
		{
			c = '9';
		}

		c = toupper(c);
	}

	return Hash;
}
std::string GetSerial()
{
	std::string Serial = "";
	std::string HashSerialKey = GetHashSerialKey();

	std::string Serial1 = HashSerialKey.substr(0, 4);
	std::string Serial2 = HashSerialKey.substr(4, 4);
	std::string Serial3 = HashSerialKey.substr(8, 4);
	std::string Serial4 = HashSerialKey.substr(12, 4);

	Serial += Serial1;
	Serial += 'H';
	Serial += Serial2;
	Serial += 'H';
	Serial += Serial3;
	Serial += 'H';
	Serial += Serial4;

	return Serial;
}
std::string valid[] =
{
	(""),
	(""),
	(""),
	(""),
	(""),
	(""),
	(""),
	(""),
	(""),
	(""),
	(""),
	(""),
	(""),
	(""),//if you'r going to use the hwid lock, add here the serials.
};

bool CheckLicense()
{
for (int i = 0; i < sizeof(valid); i++)
{
if (valid[i] == GetSerial())
{
return true;
}
}
return false;
}
#pragma endregion


namespace AssualtRifle
{
	int recoilTableY[29] = { 55, 55, 55, 55, 35, 35, 30, 26, 16, 13, 18, 22, 24, 37, 40, 43, 40, 33, 29, 20, 15, 15, 15, 25, 38, 35, 35, 38, 35 };
	int recoilTableX[29] = { -36, 5, -59, -55, 10, 15, 30, 60, 55, 35, 82, 8, 43, -32, -28, -42, -60, -60, -60, -60, -60, -60, -25, 30, 45, 55, 45, 50, 45 };
}

namespace SemiRifle
{
	int recoilTableY[16] = { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 };
	int recoilTableX[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
}

namespace Python
{
	int recoilTableY[6] = { 61, 61, 61, 61, 61, 61 };
	int recoilTableX[6] = { 0, 0, 0, 0, 0, 0 };
}

namespace CustomSmg
{

	int recoilTableY[23] = { 30, 30, 30, 35, 35, 20, 20, 25, 25, 13, 13, 13, 10, 10, 10, 15, 12, 10, 5, 5, 6, 6, 6 };
	int recoilTableX[23] = { -10, -8, -5, 18, 15, 15, 15, -10, -10, -8, -8, -8, -5, -5, 10, 10, 7, 7, 4, 4, 4, 4, 4 };
}

namespace MachineGun
{
	int recoilTableY[99] = { 35, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44 };
	int recoilTableX[99] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
}

namespace Revolver
{
	int recoilTableY[8] = { 19, 19, 19, 19, 19, 19 };
	int recoilTableX[8] = { 0, 0, 0, 0, 0, 0 };
}

namespace PistolO
{
	int recoilTableY[15] = { 27, 28, 28, 28, 28, 28, 28, 28, 28, 27, 28, 27, 28, 28, 28 };
	int recoilTableX[15] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
}

namespace SemiPistol
{
	int recoilTableY[10] = { 37, 37, 38, 38, 37, 36, 37, 38, 38, 38 };
	int recoilTableX[10] = { 0, 0, 0, 0, 0, 0, 0, 0 };
}

namespace LazerRifle
{
	int recoilTableY[30] = { 23, 35, 40, 45, 45, 40, 35, 30, 15, 12, 10, 5, 3, 2, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 3, 2, 3, 3, 3, 5 };
	int recoilTableX[30] = { 0, 0, -15, -17, -18, -18, -18, 8, 25, 25, 15, 13, -10, -10, -10, -10, -25, -25, -23, -19, -16, -15, 15, 15, 20, 20, 22, 28, 28 };
}

namespace LaserSmg
{
	int recoilTableY[30] = { 25, 20, 20, 10, 5, 5, 3, 3, 3, 3, 3, 3, 2, 2, 3, 4, 4, 5, 5, 0, -4, -4, -3, -4, -3, -3, -4, -4, -3, -4 };
	int recoilTableX[30] = { 0, 0, 0, 15, 35, 35, 35, -10, -25, -23, -23, -23, 15, 15, 15, 23, 25, 25, -10, -15, -25, -24, -30, -35, -35, -35, -35, -35, -35, -35 };
}