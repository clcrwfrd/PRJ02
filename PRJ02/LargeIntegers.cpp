#include "stdafx.h"
#include "LargeIntegers.h"
#include <iostream>

//Constructors

LargeIntegers::LargeIntegers()
{
		
	ptr_Input	= &Input;
	Continue	= true;
	Input		= "";
	Temp		= "";
	Count		= 0;
	TempInt		= 0;
	LengthOne	= 0;
	LengthTwo	= 0;
	GreaterLen  = 0;
	
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
		StoreIntoArrayOne(Input);

}
void LargeIntegers::SetNumber2()
{
	cout << "\nEnter number 2 > ";
	cin  >> Input;
	cout << endl
		 << *ptr_Input
		 << endl;
	StoreIntoArrayTwo(Input);
}
void LargeIntegers::StoreIntoArrayOne(string Input)
{
	std::reverse(Input.begin(), Input.end());											
	LengthOne	 = Input.length();	
	Size		 = Input.length();											
	IntArray1	 = new int[Size + 1] {0};
	
	for (int i = Size - 1; i >= 0; i--)
	{
		if (Count < Size)
		{
			Temp	= Input.at(Count);
			TempInt = atoi(Temp.c_str());
			Count++;
		}
		else
			TempInt = 0;

		IntArray1[i] = TempInt;
	}
	Count = 0;
}
void LargeIntegers::StoreIntoArrayTwo(string Input)
{
	std::reverse(Input.begin(), Input.end());														
	LengthTwo	 = Input.length();	
	Size		 = Input.length();												
	IntArray2	 = new int[Size + 1] {0};

	for (int i = Size - 1; i >= 0; i--)
	{
		if (Count < Size)
		{
			Temp	 = Input.at(Count);
			TempInt  = atoi(Temp.c_str());
			Count++;
		}
		else
			TempInt  = 0;
		IntArray2[i] = TempInt;		
	}
	Count = 0;
}
void LargeIntegers::CalcSum()	
{
	(LengthOne >= LengthTwo)   ?
		GreaterLen = LengthOne :
		GreaterLen = LengthTwo;
	IntArray3 = new int[GreaterLen + 1] {0};

	for (int i = GreaterLen - 1; i >= 0; i--) 
	{
		if (((IntArray1[i] + IntArray2[i]) / 10) == 1)
			IntArray3[i - 1]++;

		IntArray3[i] =
			(IntArray1[i] + IntArray2[i]) % 10;	
	}
}
void LargeIntegers::EchoAll()
{	
	cout << "\n\t"
		 << "Number One: ";
	for (int i = LengthOne - 1; i >= 0; i--){

		cout << IntArray1[i];
	}
	
	cout << "\n\t"
		 << "Number Two: ";
	for (int i = LengthTwo - 1; i >= 0; i--){
		cout << IntArray2[i];
	}

	cout << "\n\t   "
		 << "The Sum: ";
	for (int i = GreaterLen - 1; i >= 0; i--){
		cout << IntArray3[i];
	}
}
void LargeIntegers::DeleteAll()
{
	delete[] IntArray1;
	delete[] IntArray2;
	delete[] IntArray3;
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
		DeleteAll();

		cout << "\n\t\tPress any key to continue...";
		_getch();
		system("cls");

	} while (Continue == true);
}