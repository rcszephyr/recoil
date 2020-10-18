/***************************
*	Contributors: OMGPROD  *
*    Thank's to Bardiukz   *
****************************/

#include <Windows.h>
#include <iostream>
#include <thread>
#include "Patterns.h"

using namespace std;

bool boolRec = false;
bool boolAk = false;
bool boolSAR = false;
bool boolPy = false;
bool boolSemiP = false;
bool boolRevo = false;
bool boolM9 = false;
bool boolTommy = false;
bool boolCustom = false;
bool boolMp5 = false;
bool boolMachine = false;
bool boolEnabled = false;
bool boolLR = false;
bool boolX8 = false;
bool boolX16 = false;
bool boolON = false;


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

void rec()
{
	for (;;)
	{
		int shotTiming = 0;
		int shakerNum = rand() % 2;
		while (GetAsyncKeyState(1) & 0x8000 && (GetAsyncKeyState(2) & 0x8000 && boolRec))
		{
			this_thread::sleep_for(1ms);

			if (boolAk == 1)
			{

				int fireRate = 134;

				if (shotTiming < 30)
				{
					int valueX = (AssualtRifle::recoilTableX[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48)) + shakerNum;
					int valueY = (AssualtRifle::recoilTableY[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48)) + shakerNum;

					int smoothingX = valueX / 5;
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

			if (boolSAR == 1) {
				int fireRate = 175;
				if (shotTiming < 16)
				{
					int valueX = (SemiRifle::recoilTableX[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48));
					int valueY = (SemiRifle::recoilTableY[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48)) + shakerNum;

					int smoothingX = valueX / 5;
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

			if (boolPy == 1) {
				int fireRate = 150;
				if (shotTiming < 6)
				{
					int valueX = (Python::recoilTableX[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48));
					int valueY = (Python::recoilTableY[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48)) + shakerNum;

					int smoothingX = valueX / 5;
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

			if (boolCustom == 1) {

				int fireRate = 100;
				if (shotTiming < 24)
				{
					int valueX = (CustomSmg::recoilTableX[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48));
					int valueY = (CustomSmg::recoilTableY[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48));

					int smoothingX = valueX / 5;
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

			if (boolMp5 == 1) {
				int fireRate = 98;
				if (shotTiming < 30)
				{
					int valueX = (LaserSmg::recoilTableX[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48)) + shakerNum;
					int valueY = (LaserSmg::recoilTableY[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48)) + shakerNum;

					int smoothingX = valueX / 5;
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

			if (boolMachine == 1) {
				int fireRate = 120;
				if (shotTiming < 100)
				{
					int valueX = (MachineGun::recoilTableX[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48));
					int valueY = (MachineGun::recoilTableY[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48)) + shakerNum;

					int smoothingX = valueX / 5;
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

			if (boolRevo == 1) {
				int fireRate = 175;
				if (shotTiming < 8)
				{
					int valueX = (Revolver::recoilTableX[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48));
					int valueY = (Revolver::recoilTableY[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48)) + shakerNum;

					int smoothingX = valueX / 5;
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

			if (boolM9 == 1) {
				int fireRate = 100;
				if (shotTiming < 15)
				{
					int valueX = (PistolO::recoilTableX[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48));
					int valueY = (PistolO::recoilTableY[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48)) + shakerNum;

					int smoothingX = valueX / 5;
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

			if (boolSemiP == 1) {
				int fireRate = 150;
				if (shotTiming < 10)
				{
					int valueX = (SemiPistol::recoilTableX[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48));
					int valueY = (SemiPistol::recoilTableY[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48)) + shakerNum;

					int smoothingX = valueX / 5;
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
			if (boolLR == 1) {
				int fireRate = 120;
				if (shotTiming < 30)
				{
					int valueX = (LazerRifle::recoilTableX[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48)) + shakerNum;
					int valueY = (LazerRifle::recoilTableY[shotTiming] * (boolX8 ? 2.0 : boolX16 ? 4.0 : 0.48)) + shakerNum;
					int smoothingX = valueX / 5;
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

int screen() {
	system("cls");
	cout << "-------------------------------------------" << endl;
	cout << "| IMPORTANT : FOV = 90, Sensitivity = 0.2 |" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "      ----------------------------       " << endl;
	cout << "      | Numpad / | ACTIVATE = " << (boolON ? "ON " : "OFF") << "| " << endl;
	cout << "      | Numpad + | ScopeX8  = " << (boolX8 ? "ON " : "OFF") << "| " << endl;
	cout << "      | Numpad * | ScopeX16 = " << (boolX16 ? "ON " : "OFF") << "| " << endl;
	cout << "      | Numpad 0 | AK47     = " << (boolAk ? "ON " : "OFF") << "| " << endl;
	cout << "      | Numpad 1 | LR       = " << (boolLR ? "ON " : "OFF") << "| " << endl;
	cout << "      | Numpad 2 | M249     = " << (boolMachine ? "ON " : "OFF") << "| " << endl;
	cout << "      | Numpad 3 | P250     = " << (boolSemiP ? "ON " : "OFF") << "| " << endl;
	cout << "      | Numpad 4 | M92      = " << (boolM9 ? "ON " : "OFF") << "| " << endl;
	cout << "      | Numpad 5 | SAR      = " << (boolSAR ? "ON " : "OFF") << "| " << endl;
	cout << "      | Numpad 6 | SMG      = " << (boolCustom ? "ON " : "OFF") << "| " << endl;
	cout << "      | Numpad 7 | Mp5      = " << (boolMp5 ? "ON " : "OFF") << "| " << endl;
	cout << "      | Numpad 8 | Revo     = " << (boolRevo ? "ON " : "OFF") << "| " << endl;
	cout << "      | Numpad 9 | Python   = " << (boolPy ? "ON " : "OFF") << "| " << endl;
	cout << "      ----------------------------       " << endl;
	return 0;
}


void menu()
{
	for (;;)
	{

		if (GetAsyncKeyState(VK_DIVIDE) < 0) {
			Beep(650, 500);
			boolRec = !boolRec;
			boolON = !boolON;
			thread(screen).detach();
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_ADD) < 0) {
			Beep(700, 500);
			boolX8 = !boolX8;
			boolX16 = false;
			thread(screen).detach();
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_MULTIPLY) < 0) {
			Beep(750, 500);
			boolX16 = !boolX16;
			boolX8 = false;
			thread(screen).detach();
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD0) < 0) {
			Beep(325, 600);
			boolAk = !boolAk;
			boolSAR = false;
			boolPy = false;
			boolSemiP = false;
			boolRevo = false;
			boolM9 = false;
			boolTommy = false;
			boolCustom = false;
			boolMp5 = false;
			boolMachine = false;
			boolLR = false;
			thread(screen).detach();
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD5) < 0) {
			Beep(360, 600);
			boolSAR = !boolSAR;
			boolAk = false;
			boolPy = false;
			boolSemiP = false;
			boolRevo = false;
			boolM9 = false;
			boolTommy = false;
			boolCustom = false;
			boolMp5 = false;
			boolMachine = false;
			boolLR = false;
			thread(screen).detach();
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD9) < 0) {
			Beep(398, 600);
			boolPy = !boolPy;
			boolAk = false;
			boolSAR = false;
			boolSemiP = false;
			boolRevo = false;
			boolM9 = false;
			boolTommy = false;
			boolCustom = false;
			boolMp5 = false;
			boolMachine = false;
			boolLR = false;
			thread(screen).detach();
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD3) < 0) {
			Beep(423, 600);
			boolSemiP = !boolSemiP;
			boolAk = false;
			boolPy = false;
			boolSAR = false;
			boolRevo = false;
			boolM9 = false;
			boolTommy = false;
			boolCustom = false;
			boolMp5 = false;
			boolMachine = false;
			boolLR = false;
			thread(screen).detach();
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD6) < 0) {
			Beep(466, 600);
			boolCustom = !boolCustom;
			boolAk = false;
			boolPy = false;
			boolSemiP = false;
			boolSAR = false;
			boolRevo = false;
			boolM9 = false;
			boolTommy = false;
			boolMp5 = false;
			boolMachine = false;
			boolLR = false;
			thread(screen).detach();
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD2) < 0) {
			Beep(488, 600);
			boolMachine = !boolMachine;
			boolAk = false;
			boolSAR = false;
			boolPy = false;
			boolSemiP = false;
			boolRevo = false;
			boolM9 = false;
			boolTommy = false;
			boolCustom = false;
			boolMp5 = false;
			boolLR = false;
			thread(screen).detach();
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD8) < 0) {
			boolRevo = !boolRevo;
			Beep(520, 600);
			boolAk = false;
			boolSAR = false;
			boolPy = false;
			boolSemiP = false;
			boolM9 = false;
			boolTommy = false;
			boolCustom = false;
			boolMp5 = false;
			boolMachine = false;
			boolLR = false;
			thread(screen).detach();
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD4) < 0) {
			boolM9 = !boolM9;
			boolAk = false;
			boolSAR = false;
			boolPy = false;
			boolSemiP = false;
			boolRevo = false;
			boolTommy = false;
			boolCustom = false;
			boolMp5 = false;
			boolMachine = false;
			boolLR = false;
			thread(screen).detach();
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD7) < 0) {
			boolMp5 = !boolMp5;
			Beep(581, 600);
			boolAk = false;
			boolSAR = false;
			boolPy = false;
			boolSemiP = false;
			boolRevo = false;
			boolM9 = false;
			boolTommy = false;
			boolCustom = false;
			boolMachine = false;
			boolLR = false;
			thread(screen).detach();
			Sleep(300);
		}
		if (GetAsyncKeyState(VK_NUMPAD1) < 0) {
			boolLR = !boolLR;
			Beep(600, 600);
			boolAk = false;
			boolSAR = false;
			boolPy = false;
			boolSemiP = false;
			boolRevo = false;
			boolM9 = false;
			boolCustom = false;
			boolMp5 = false;
			boolMachine = false;
			thread(screen).detach();
			Sleep(300);
		}
		this_thread::sleep_for(15ms);
	}
}

int main()
{
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 400, 350, TRUE);
	SetConsoleTitle("RNR Edition 2020");
	thread(screen).detach();
	thread(rec).detach();
	thread(menu).detach();
	for (;;)
		this_thread::sleep_for(15ms);
	return 0;
}
