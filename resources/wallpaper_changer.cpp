/*
NOTES:

This language is C++

In order to build this program, you need visual studio

It can be installed here: https://visualstudio.microsoft.com/downloads/

I recommend the free version
*/

#include <iostream>
#include <string>
#include <fstream>
#include <lmcons.h>
#include <Windows.h>

using namespace std;

string target_file;

bool f_exists(string file)
{
	bool r = false;
	ifstream f(file, ios::binary);
	if (f.is_open())
	{
		r = true;
		f.close();
	}
	return r;
}

string uname()
{
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);
	string r(username);
	return r;
}

int main(int argc, char *argv[])
{
	SetConsoleTitle("Wallpaper Changing Device");
	target_file = "C:/users/" + uname() + "/logo.bmp";
	if (argc > 1)
	{
		char *data = NULL;
		streampos size;
		ifstream f(argv[1], ios::binary | ios::ate);
		if (f.is_open())
		{
			size = f.tellg();
			data = new char[size];
			f.seekg(0, ios::beg);
			f.read(data, size);
			f.close();
		}
		ofstream a(target_file, ios::binary | ios::trunc);
		if (a.is_open())
		{
			a.close();
		}
		ofstream b(target_file, ios::binary);
		if (b.is_open())
		{
			b.write(data, size);
			b.close();
		}
		SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, PVOID(target_file.c_str()), SPIF_UPDATEINIFILE);
	}
	else
	{
		system("color a");
		while (true)
		{
			string c;
			cout << "[ENTER FILE]>";
			getline(cin, c);
			if (f_exists(c))
			{
				char *data = NULL;
				streampos size;
				ifstream f(c, ios::binary | ios::ate);
				if (f.is_open())
				{
					size = f.tellg();
					data = new char[size];
					f.seekg(0, ios::beg);
					f.read(data, size);
					f.close();
				}
				ofstream a(target_file, ios::binary | ios::trunc);
				if (a.is_open())
				{
					a.close();
				}
				ofstream b(target_file, ios::binary);
				if (b.is_open())
				{
					b.write(data, size);
					b.close();
				}
				SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, PVOID(target_file.c_str()), SPIF_UPDATEINIFILE);
			}
			else
			{
				cout << "[*] INVALID FILE [*]" << endl;
				MessageBeep(MB_ICONERROR);
			}
		}
	}
	return 0;
}
