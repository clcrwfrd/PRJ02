#ifndef _LARGE_INTEGERS_H_
#define _LARGE_INTEGERS_H_

#include "stdafx.h"
#include <iosfwd>
#include <string>
#include <algorithm>
#include <cctype>
#include <functional>
#include <array>
#include <iomanip>
#include <conio.h>
using namespace std;

class LargeIntegers
{
private:
	array<int, 10> IntArray1;
	array<int, 10> IntArray2;
	array<int, 10> IntArray3;
	//int IntArray1[10];
	//int IntArray2[10];
	//int IntArray3[10];
	
	string Input;
	string* ptr_Input;
	string Temp;
	int	   TempInt;
	int	   Count; 
	int LengthOne;
	int	LengthTwo;
	int GreaterLen;
	bool Continue;

	void SetNumber1();
	void SetNumber2();
	int GetNumber1();
	int GetNumber2();

	void StoreIntoArrayOne(string* Input);
	void StoreIntoArrayTwo(string* Input);
	void CalcSum();
	void EchoAll();
	

public:
	LargeIntegers();
	~LargeIntegers();

	void Run();
	

};

#endif