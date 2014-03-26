#include "stdafx.h"
#include "LargeIntegers.h"
#include <iostream>

//Constructors

LargeIntegers::LargeIntegers()
{
	
	array<int, 10> IntArray1 = { 0 };
	array<int, 10> IntArray2 = { 0 };
	array<int, 10> IntArray3 = { 0 };
	
	ptr_Input	= &Input;
	//ptr_Size  = &Input.length();
	Continue	= true;
	Input		= "";
	Temp		= "";
	Count		= 0;
	TempInt		= 0;
	LengthOne	= 0;
	LengthTwo	= 0;
	GreaterLen  = 0;
	
}
LargeIntegers::LargeIntegers(int Size)
{

}
LargeIntegers::~LargeIntegers()
{
}

//private

void LargeIntegers::SetNumber1()
{
	cout << "\nEnter number 1 > ";
	cin  >> Input;
	cout << endl
		 << *ptr_Input
		 << endl;

	string Controller(Input);	
	if ((Continue = ContinueLoop(Controller)))
		StoreIntoArrayOne(ptr_Input);

}
void LargeIntegers::SetNumber2()
{
	cout << "\nEnter number 2 > ";
	cin  >> Input;
	cout << endl
		 << *ptr_Input
		 << endl;
	StoreIntoArrayTwo(ptr_Input);
}
void LargeIntegers::StoreIntoArrayOne(string* Input)
{
	int TempSize = (*Input).length();	//I know theres a better way...
	ptr_Size = &TempSize;
	//ptr_Size  = (&Input)->length();
	//ptr_Size  = Input.length();
	//LengthOne = (*Input).length();
	
				//wish use back inserter l8er
	for (int i = (*ptr_Size); i < 10; i++)
	{
		if (Count < (*ptr_Size))
		{
			Temp	= (*Input).at(Count);
			TempInt = atoi(Temp.c_str());
			Count++;
		}
		else
			TempInt = 0;

		IntArray1[i] = TempInt;
	}
	Count = 0;
}
void LargeIntegers::StoreIntoArrayTwo(string* Input)
{
	int TempSize = (*Input).length();	//I know theres a better way...
	ptr_Size = &TempSize;
	//ptr_Size = (*Input).length;
	//LengthTwo = (*Input).length();
	
	for (int i = (*ptr_Size); i < 10; i++)
	{
		if (Count < (*ptr_Size))
		{
			Temp	 = (*Input).at(Count);
			TempInt  = atoi(Temp.c_str());
			Count++;
		}
		else
			TempInt  = 0;
		IntArray2[i] = TempInt;
		
	}
	Count = 0;
}
void LargeIntegers::CalcSum()		//can i use ptr_size for greater?
{
	for (int i = GreaterLen; i < 10; i++)
	{
		if (((IntArray1[i] + IntArray2[i]) / 10) == 1)
			IntArray3[i]++;
		IntArray3[i] =
			(IntArray1[i] + IntArray2[i]) % 10;	
	}
}
void LargeIntegers::EchoAll()
{	
	cout << "\n\t"
		 << "Number One: ";
	for (int i = LengthOne; i < 10; i++){

		cout << IntArray1[i];
	}
	
	cout << "\n\t"
		 << "Number Two: ";
	for (int i = LengthTwo; i < 10; i++){
		cout << IntArray2[i];
	}
	
	(LengthOne >= LengthTwo)   ?	//<<==Wont need l8r
		GreaterLen = LengthOne : 
		GreaterLen = LengthTwo;
	cout << "\n\t   "
		 << "The Sum: ";
	for (int i = GreaterLen; i < 10; i++){
		cout << IntArray3[i];
	}

	/*
	for (int i = 0; i < 10; i++)
	{
		cout << *(IntArray1 + i) << endl;
	}
	*/
}
bool LargeIntegers::ContinueLoop(string Controller)
{
	std::transform(Controller.begin(),
		Controller.end(),
		Controller.begin(),
		std::ptr_fun<int, int>(std::tolower));
	if (Controller == "exit" || Controller == "\\q")
		return false;
	else
		return true;

}

//Public

void LargeIntegers::Run()
{
	do
	{
		cout << "\n\t\tType 'exit' or '\\q' to quit program"
			 << endl;

		SetNumber1();
		if (Continue == false) break;
		SetNumber2();
		CalcSum();
		EchoAll();

		cout << "\n\t\tPress any key to continue...";
		_getch();
		system("cls");
	} while (Continue == true);

}