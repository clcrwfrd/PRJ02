#include "stdafx.h"
#include "LargeIntegers.h"
#include <iostream>

//Constructors

LargeIntegers::LargeIntegers()
{
	//IntArray1[10] =  {0};
	//IntArray2[10] =  {0};
	//IntArray3[10] =  {0};

	array<int, 10> IntArray1 = { 0 };
	array<int, 10> IntArray2 = { 0 };
	array<int, 10> IntArray3 = { 0 };

	//test = new int[10]();
	//test = { 0 };
	Input = "";
	ptr_Input = &Input;
	Count = 0;
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
		 << "You entered: "
		 << *ptr_Input
		 << endl;
								//lot of forum searching to get this to 
	string Controller(Input);	//to work for some reason
	std::transform(Controller.begin(), Controller.end(), Controller.begin(),
		std::ptr_fun<int, int>(std::tolower));

	if (Controller == "exit" || Controller == "\\q")
		Continue = false;
	else
	{
		Continue = true;
		StoreIntoArrayOne(ptr_Input);
	}
}
void LargeIntegers::SetNumber2()
{
	cout << "\nEnter number 2 > ";
	cin  >> Input;
	cout << endl
		 << "You entered: "
		 << *ptr_Input
		 << endl;
	StoreIntoArrayTwo(ptr_Input);
}
void LargeIntegers::StoreIntoArrayOne(string* Input)
{
	LengthOne = (*Input).length();
	
				//wish use back inserter l8er
	for (int i = LengthOne; i < 10; i++)
	{
		if (Count < LengthOne)
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
	LengthTwo = (*Input).length();
	
	for (int i = LengthTwo; i < 10; i++)
	{
		if (Count < LengthTwo)
		{
			Temp = (*Input).at(Count);
			TempInt = atoi(Temp.c_str());
			Count++;
		}
		else
			TempInt = 0;
		IntArray2[i] = TempInt;
		
	}
	Count = 0;
}
void LargeIntegers::CalcSum()
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
	cout << "\Num one \t"		//This printed the arrays
	 	 << "Num Two \t"		//from top to bottom, and 
		 << "Sum"				//side by side
		 << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "\t"
			 << IntArray1[i] << "\t\t"
			 << IntArray2[i] << "\t\t"
			 << IntArray3[i]
			 << endl;
	}
	*/
	/*
	for (int i = 0; i < 10; i++)
	{
		cout << *(test + i) << endl;
	}
	*/
}

//Public

void LargeIntegers::Run()
{
	do
	{
		cout << "\n\tType 'exit' or '\\q' to quit program"
			 << "\n\tInitiating run sequence"
			 << endl;

		SetNumber1();
		if (Continue == false) break;
		SetNumber2();
		CalcSum();
		EchoAll();

		_getch();
		system("cls");
	} while (Continue == true);

}