#include <Windows.h>
#include <iostream>
#include <thread>
#include "Patterns.h"

using namespace std;

bool bRecoil = false;
bool bAk = false;
bool bSemiR = false;
bool bPy = false;
bool bSemiP = false;
bool bRevo = false;
bool bM9Pistol = false;
bool bTommy = false;
bool bCust = false;
bool bMp5 = false;
bool bMachine = false;
bool bEnabled = false;
bool bLr = false;
bool bTurnedOn = false;


void mouse_move(int x, int y)
{
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.time = 0;
	input.mi.dx = x;
	input.mi.dy = y;
	input.mi.dwFlags = MOUSEEVENTF_MOVE;
	SendInput(1, &input, sizeof(input));
}


void recoil()
{
	for (;;)
	{
		int shotTiming = 0;
		int shakerNum = rand() % 3;
		while (GetAsyncKeyState(1) & 0x8000 && (GetAsyncKeyState(2) & 0x8000 && bRecoil))
		{
			this_thread::sleep_for(1ms);
			if (bAk == 1)

			{

				int fireRate = 134;

				if (shotTiming < 30)
				{
					int valueX = (AssualtRifle::recoilTableX[shotTiming] * 0.48) + shakerNum;
					int smoothingX = valueX / 5;
					int valueY = (AssualtRifle::recoilTableY[shotTiming] * 0.48) + shakerNum;
					int smoothingY = valueY / 5;
					Sleep(3);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}

			if (bSemiR == 1)

			{

				int fireRate = 175;
				if (shotTiming < 16)
				{
					int valueX = (SemiRifle::recoilTableX[shotTiming] * 0.48);
					int smoothingX = valueX / 5;
					int valueY = (SemiRifle::recoilTableY[shotTiming] * 0.48) + shakerNum;
					int smoothingY = valueY / 5;
					Sleep(1);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}

			if (bPy == 1)

			{

				int fireRate = 150;
				if (shotTiming < 6)
				{
					int valueX = (Python::recoilTableX[shotTiming] * 0.48);
					int smoothingX = valueX / 5;
					int valueY = (Python::recoilTableY[shotTiming] * 0.48) + shakerNum;
					int smoothingY = valueY / 5;
					Sleep(3);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}

			if (bCust == 1)

			{

				int fireRate = 100;
				if (shotTiming < 24)
				{
					int valueX = (CustomSmg::recoilTableX[shotTiming] * 0.48);
					int smoothingX = valueX / 5;
					int valueY = (CustomSmg::recoilTableY[shotTiming] * 0.48);
					int smoothingY = valueY / 5;
					Sleep(3);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}

			if (bMp5 == 1)

			{

				int fireRate = 98;
				if (shotTiming < 30)
				{
					int valueX = (LaserSmg::recoilTableX[shotTiming] * 0.48) + shakerNum;
					int smoothingX = valueX / 5;
					int valueY = (LaserSmg::recoilTableY[shotTiming] * 0.48) + shakerNum;
					int smoothingY = valueY / 5;
					Sleep(3);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}

			if (bMachine == 1)

			{

				int fireRate = 120;
				if (shotTiming < 100)
				{
					int valueX = (MachineGun::recoilTableX[shotTiming] * 0.48);
					int smoothingX = valueX / 5;
					int valueY = (MachineGun::recoilTableY[shotTiming] * 0.48) + shakerNum;
					int smoothingY = valueY / 5;
					Sleep(3);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}

			if (bRevo == 1)

			{

				int fireRate = 175;
				if (shotTiming < 8)
				{
					int valueX = (Revolver::recoilTableX[shotTiming] * 0.48);
					int smoothingX = valueX / 5;
					int valueY = (Revolver::recoilTableY[shotTiming] * 0.48) + shakerNum;
					int smoothingY = valueY / 5;
					Sleep(3);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}

			if (bM9Pistol == 1)

			{

				int fireRate = 100;
				if (shotTiming < 15)
				{
					int valueX = (PistolO::recoilTableX[shotTiming] * 0.48);
					int smoothingX = valueX / 5;
					int valueY = (PistolO::recoilTableY[shotTiming] * 0.48) + shakerNum;
					int smoothingY = valueY / 5;
					Sleep(1);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}

			if (bSemiP == 1)

			{

				int fireRate = 150;
				if (shotTiming < 10)
				{
					int valueX = (SemiPistol::recoilTableX[shotTiming] * 0.48);
					int smoothingX = valueX / 5;
					int valueY = (SemiPistol::recoilTableY[shotTiming] * 0.48) + shakerNum;
					int smoothingY = valueY / 5;
					Sleep(3);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}
			if (bLr == 1)

			{

				int fireRate = 120;
				if (shotTiming < 30)
				{
					int valueX = (LazerRifle::recoilTableX[shotTiming] * 0.48) + shakerNum;
					int smoothingX = valueX / 5;
					int valueY = (LazerRifle::recoilTableY[shotTiming] * 0.48) + shakerNum;
					int smoothingY = valueY / 5;
					Sleep(3);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}
		}
	}
}


void keyhandler()
{
	for (;;)
	{
		
		if (GetAsyncKeyState(VK_F2) < 0) {
			Beep(650, 500);
			bRecoil = !bRecoil;
			bTurnedOn = !bTurnedOn;
			cout << "Program Enabled = " << bTurnedOn << "\n";
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD0) < 0) {
			Beep(325, 600);
			bAk = !bAk;
			bSemiR = false;
			bPy = false;
			bSemiP = false;
			bRevo = false;
			bM9Pistol = false;
			bTommy = false;
			bCust = false;
			bMp5 = false;
			bMachine = false;
			bLr = false;
			cout << "Ak Enabled" << "\n";
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD5) < 0) {
			Beep(360, 600);
			bSemiR = !bSemiR;
			cout << "Semi Enabled" << "\n";
			bAk = false;
			bPy = false;
			bSemiP = false;
			bRevo = false;
			bM9Pistol = false;
			bTommy = false;
			bCust = false;
			bMp5 = false;
			bMachine = false;
			bLr = false;
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD9) < 0) {
			Beep(398, 600);
			bPy = !bPy;
			cout << "Python Enabled" << "\n";
			bAk = false;
			bSemiR = false;
			bSemiP = false;
			bRevo = false;
			bM9Pistol = false;
			bTommy = false;
			bCust = false;
			bMp5 = false;
			bMachine = false;
			bLr = false;
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD3) < 0) {
			Beep(423, 600);
			bSemiP = !bSemiP;
			cout << "Semi Pistol Enabled" << "\n";
			bAk = false;
			bPy = false;
			bSemiR = false;
			bRevo = false;
			bM9Pistol = false;
			bTommy = false;
			bCust = false;
			bMp5 = false;
			bMachine = false;
			bLr = false;
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD6) < 0) {
			Beep(466, 600);
			bCust = !bCust;
			cout << "Custom Smg Enabled" << "\n";
			bAk = false;
			bPy = false;
			bSemiP = false;
			bSemiR = false;
			bRevo = false;
			bM9Pistol = false;
			bTommy = false;
			bMp5 = false;
			bMachine = false;
			bLr = false;
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD2) < 0) {
			Beep(488, 600);
			bMachine = !bMachine;
			cout << "M249 Enabled" << "\n";
			bAk = false;
			bSemiR = false;
			bPy = false;
			bSemiP = false;
			bRevo = false;
			bM9Pistol = false;
			bTommy = false;
			bCust = false;
			bMp5 = false;
			bLr = false;
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD8) < 0) {
			bRevo = !bRevo;
			Beep(520, 600);
			cout << "Revolver Enabled" << "\n";
			bAk = false;
			bSemiR = false;
			bPy = false;
			bSemiP = false;
			bM9Pistol = false;
			bTommy = false;
			bCust = false;
			bMp5 = false;
			bMachine = false;
			bLr = false;
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD4) < 0) {
			bM9Pistol = !bM9Pistol;
			Beep(555, 600);
			cout << "M92 Enabled" << "\n";
			bAk = false;
			bSemiR = false;
			bPy = false;
			bSemiP = false;
			bRevo = false;
			bTommy = false;
			bCust = false;
			bMp5 = false;
			bMachine = false;
			bLr = false;
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD7) < 0) {
			bMp5 = !bMp5;
			Beep(581, 600);
			cout << "Mp5 Enabled" << "\n";
			bAk = false;
			bSemiR = false;
			bPy = false;
			bSemiP = false;
			bRevo = false;
			bM9Pistol = false;
			bTommy = false;
			bCust = false;
			bMachine = false;
			bLr = false;
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD1) < 0) {
			bLr = !bLr;
			Beep(600, 600);
			cout << "Lr Enabled" << "\n";
			bAk = false;
			bSemiR = false;
			bPy = false;
			bSemiP = false;
			bRevo = false;
			bM9Pistol = false;
			bCust = false;
			bMp5 = false;
			bMachine = false;
			Sleep(300);
		}
          this_thread::sleep_for(15ms);
	}
}

int main()
{
	SetConsoleTitle("Rust Script");

        cout << "Keybinds" << endl;
	cout << "F2 = On/Off" << endl;
	cout << "AK47 = Numpad 0" << endl;
	cout << "LR = Numpad 1" << endl;
	cout << "M249 = Numpad 2" << endl;
	cout << "Semi Pistol P250 = Numpad 3" << endl;
	cout << "M92 Pistol = Numpad 4" << endl;
	cout << "Semi Automatic Rifle = Numpad 5" << endl;
	cout << "Custom SMG / Tommy Gun = Numpad 6" << endl;
	cout << "Mp5 = Numpad 7" << endl;
	cout << "Revolver = Numpad 8" << endl;
	cout << "Python = Numpad 9" << endl;

	thread(recoil).detach();
	thread(keyhandler).detach();
	
	
	for (;;)
	   this_thread::sleep_for(15ms);
	return 0;
}
