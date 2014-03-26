// PRJ02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LargeIntegers.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	LargeIntegers largeIntegers;
	largeIntegers.Run();
	
	system("cls");
	cout << "\n\tPress any key to exit";
	_getch();
	return 0;
}

