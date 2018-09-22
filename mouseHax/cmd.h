#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <fstream>
using namespace std;

class cmd
{
public:
	cmd();
	~cmd();

	static void pause(string prompt = "press any key...") { // pauses the cmd prompt
		cout << prompt; // prints the prompt to the cmd prompt without a new line
		system("pause>nul"); // uses the pause function in cmd, '>nul' makes the output invisile.
	}

	static void echo(string toEcho) { // echos the command to cmd prompt
		cout << toEcho << endl;  // puts string onto cmd prompt
	}

	static void print(string toPrint) { // like echo but without /n ( new line )
		cout << toPrint;  // puts string onto cmd prompt
	}

	static void hide() { // hides the console window
		ShowWindow(::GetConsoleWindow(), SW_HIDE); // hides the console window
	} 

	static void show() { // shows the console window
		ShowWindow(::GetConsoleWindow(), SW_SHOW); // shows the console
	}

	static void color(int color) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); // sets the console color from an INT
	}

	static void cls() {
		system("cls");
	}
	
	static void runCmd(string command) { // runs any batch command
		system(command.c_str()); // converts the string to a char pointer
	}

	static void font(string font_name, int size) {
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = size;                   // Width of each character in the font
		cfi.dwFontSize.Y = size * 2;                  // Height
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		string font = font_name;
		wstring wideFontName;
		for (int i = 0; i < font.length(); ++i)
			wideFontName += wchar_t(font[i]);

		const wchar_t* fontWChar = wideFontName.c_str();

		std::wcscpy(cfi.FaceName, fontWChar); // Choose your font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &cfi);
	}

	static int string2Int(string str) {
		stringstream str2Int(str);
		int x = 0;
		str2Int >> x;
		return x;
	}

};

