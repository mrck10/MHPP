#pragma once

#include <windows.h>
#include <iostream>

using namespace std;

class cheat
{
public:
	cheat();
	~cheat();

	static int readProcessMemory(string windowName, int adress) {
		WORD address = adress;
		int value = 0;
		DWORD pid;
		HWND hwnd;
		hwnd = FindWindow(NULL, windowName.c_str());
		if (!hwnd)
		{
			cout << "Window not found!\n";
			cin.get();
		}
		else
		{
			GetWindowThreadProcessId(hwnd, &pid);
			HANDLE phandle = OpenProcess(PROCESS_VM_READ, 0, pid);
			if (!phandle)
			{
				cout << "Could not get handle!\n";
				cin.get();
			}
			else
			{
				ReadProcessMemory(phandle, (void*)  address, &value, sizeof(value), 0);
				return value;
			}
		}
	}

	static void writeProcessMemory(string windowName, int adress, int data) {

		HWND hWnd = FindWindow(0, windowName.c_str()); // find the window with the name
		//If we can't find the window, it will come up with a error box below prompting the message.	
		if (hWnd == NULL)
		{
			MessageBox(0, "Error cannot find window!", "Error!", MB_OK + MB_ICONERROR);
		}
		else
		{
			DWORD proc_id;
			GetWindowThreadProcessId(hWnd, &proc_id);
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, proc_id);
			if (!hProcess)
			{
				MessageBox(NULL, "Cannot open process!", "Error!", MB_OK + MB_ICONERROR);
			}
			else
			{
				BYTE data = data;
				DWORD dataSize = sizeof(data);

				if (WriteProcessMemory(hProcess, (LPVOID)adress, &data, dataSize, NULL))
				{
					MessageBox(NULL, "WriteProcessMemory is a success!", "Success!", MB_OK + MB_ICONINFORMATION);
				}
				else
				{
					MessageBox(NULL, "Error cannot WriteProcessMemory!", "Error!", MB_OK + MB_ICONERROR);
				}
				CloseHandle(hProcess);
			}
		}
	}
};

