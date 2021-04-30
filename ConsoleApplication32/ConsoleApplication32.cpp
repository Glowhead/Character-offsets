// Hernan L. Paulet
// CIS 1202
// 20210429
//
// A function to claculate Charatcer offsets
// I am probably making this more complicated but I think I got the hang of it

#include <iostream> // required for cin and cout
#include <string> // required for the string error codes

using namespace std;

char character(char start, int offset); // prototypes
void evaluateLetter(char);
void evaluateRange(int, int);
char evaluateTarget(char);
bool biggieSmalls(char, char); // <- say that 3x

int main()
{
	char letter; // users character entry
	int offset;		// users offset entry
	char validLetter; // the variable that holds the tested value
	bool validProcess; // comfirm the biggieSmalls testing is good
	
	cout << "This is a chrarcter offset program." << endl;
	cout << "Enter a letter (upper or lower case) followed by a space" << endl;
	cout << "Enter a number to offset the character by the value you entered." << endl;
	cout << endl;
	cout << "Please enter your letter and offset value -> ";
	cin >> letter >> offset;


	validLetter = character(letter, offset); // check programmer entry


	if ((int)validLetter < 33) 
	{
		return 0;
	}

	try 
	{
		validProcess = biggieSmalls(letter, validLetter); // testing case validation
	}
	catch (string invalidbiggieSmalls)
	{
		cout << invalidbiggieSmalls << endl;
		return 0;

	}
	if (validProcess)
	{
		cout << "The letter with offset comes out to: " << validLetter;
		return 0;

	}

	return 0;
}

char character(char start, int offset) // function test the entry
{
	int characterValue; // entered character expressed in ascII
	char newLetter;		// start and offest combine to a new character
	char finalLetter;	// newletter after being tested for validation
	int newValue;		// ascII for the entered character with the offset in ascII values
	bool pass = true;	// verify all testing parameters are satisfied

	try
	{
		evaluateLetter(start); // checking if the entered character is a letter
		
	}
	catch (string invalidCharacterException)
	{
		cout << invalidCharacterException << endl;
		pass = false; // failed process will produce a written notification, and fail the checks
	}

	characterValue = (int)start;

	try
	{

		evaluateRange(characterValue, offset); // checking if the offset entered is within the limits
												// of the C++ ASCII code
	}
	catch (string invalidRangeException)
	{
		cout << invalidRangeException << endl; 
		// failed process will produce a written notification, and fail the checks
		pass = false;
		offset = 0; // offset value set to 0 as to not lock the program
	}

	newValue = (offset + characterValue);

	newLetter = (char)newValue;

	try
	{ // make sure the target value is an alpha character
		finalLetter = evaluateTarget(newLetter); 

	}
	catch (string invalidTargetException)
	{
		// failed process will produce a written notification, and fail the checks
		cout << invalidTargetException << endl;
		pass = false;
	}

	if (pass == 0)
	{
		finalLetter = ' '; // final letter set to " " to signify failure of the entry
	}


	return finalLetter;


}


void evaluateLetter(char character)
{
	if (isalpha(character) == 0) // testing for an alpha character
	{
		string invalidCharacterException =  "ERROR - Invalid Character must be a letter"; 
		throw invalidCharacterException;

	}
	
}

void evaluateRange(int asc2Value, int offsetValue)
{
	char nextLetter;
	int tempValue;

	// testing the ascii value remains in the limits of C++ 
	if (offsetValue > 25 or (offsetValue + asc2Value) > 127) 
	{
		string invalidRangeException = "ERROR - Invalid Offset Range";
		throw invalidRangeException;
	}
	else
	{
		tempValue = (offsetValue + asc2Value);
		nextLetter = (char)tempValue;
	}

}

char evaluateTarget(char targetLetter)
{
	if (isalpha(targetLetter) == 0) // confirm the offset+character entry is an alpha
	{
		string invalidTargetException = "ERROR - Invalid letter/offset combination";
		throw invalidTargetException;
		targetLetter = ' ';
	}
	
	return targetLetter;
}

bool biggieSmalls(char firstChar, char secondChar)
{
	int letterEval1 = 0;
	int letterEval2 = 0;
	bool passTest = true;

	if (isupper(firstChar) == 0) // determining that cases match
	{
		letterEval1 = 4;
	}
	else
	{
		letterEval1 = 6;
	}

	if (isupper(secondChar) == 0)
	{
		letterEval2 = 4;
	}
	else
	{
		letterEval2 = 6;
	}

	
	// if the combination = 8 then both are small, 10 = mismatch, 12 = large letters
		if ((letterEval1 + letterEval2) == 10)
		{
			string letterMismatchException = "ERROR - Target must match case with the letter entered";
			throw letterMismatchException;
			passTest = false;
		}
		
	

	return passTest;
}
