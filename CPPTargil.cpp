// ConsoleApplication11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;



int i = 0; //to keep track of the vector
vector<string> varKeeper(100); //keeping all the vars we create in the console
map<string, string> varValueKeeper;



int checkWhichOne(string input)
{
	if (input.size() >= 5)
	{
		if (input.find_first_not_of("0123456789") == string::npos)
		{
			return 0;
		}
		else if (input.substr(0, 2).compare("var") && input.at(3) == ' ' && input.at(input.size() - 1) == ';')
		{
			return 2;
		}
		else if (input.substr(0, 4).compare("print") && input.at(5) == ' ')
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
}



int xorOperation(int num1, int num2)
{
	return num1 ^ num2;
}



void addVarToVector(string varName)
{
	string varValue;
	if (varName.find('=') != UINT_MAX)
	{
		//with assigned value
		varValue = varName.substr(varName.find('=') + 1, varName.find(';') - 1);
		varName = varName.substr(0, varName.find('=') - 1);
		if (find(varKeeper.begin(), varKeeper.end(), varName) != varKeeper.end())
		{
			//check if has value, if doesnt, assign the value. if does, update it/print error
			if (varValueKeeper.count(varName))
			{

			}
			else
			{
				varValueKeeper[varName] = varValue;
			}
		}
		else
		{
			//add the var to the vector + assign value
			varKeeper[i] = varName;
			varValueKeeper[varName] =  varValue;
			i++;
		}
	}
	else
	{
		//without assigned value
		varName = varName.substr(0, varName.find(';') - 1);
		if (find(varKeeper.begin(), varKeeper.end(), varName) != varKeeper.end())
		{
			//if it has already been assigend
			cout << "You already have a var named that! var wasn't defined!";
		}
		else
		{
			//adding a new one.
			varKeeper[i] = varName;
			i++;
		}
	}
}

void printWhenNeeded(string input)
{
	if (find(varKeeper.begin(), varKeeper.end(), input) != varKeeper.end())
	{
		cout << "Yay";
	}
	else
	{
		cout << input;
	}
}

int main()
{
	int num1, num2, num3; //for the xor operation
	string input; //the cin input
	int indicator; //checks what to do
	while (true)
	{
		getline(cin, input);
		cout << input.find('=');
		indicator = checkWhichOne(input);
		if (indicator == 1)
		{
			printWhenNeeded(input.substr(6));
		}
		else if (indicator == 2)
		{
			addVarToVector(input.substr(4));
		}
		else if (indicator == 0)
		{
			scanf_s("%d", &num1);
			scanf_s("%d", &num2);
			cout << xorOperation(num1, num2);
		}
		else if (indicator == -1)
		{
			break;
		}
	}
    return 0;
}

