#include <iostream>
#include "MyString.h"

using std::cout;
using std::endl;

int main(const char *args, int numArgs)
{
	MyString string = "Default String";
	cout << "Constructor:" << endl;
	cout << string.CStyle() << endl << endl;

	string.Append(" Append");
	cout << "Append Function:" << endl;
	cout << string.CStyle() << endl << endl;

	string.Prepend("Prepend ");
	cout << "Prepend Function:" << endl;
	cout << string.CStyle() << endl << endl;

	string = string.ToLower();
	cout << "ToLower Function:" << endl;
	cout << string.CStyle() << endl << endl;

	string = string.ToUpper();
	cout << "ToUpper Function:" << endl;
	cout << string.CStyle() << endl << endl;

	bool foundSubString = string.FindSubString("APPEND");
	cout << "FindSubString Function:" << endl;
	cout << foundSubString << endl << endl;

	string.ReplaceSubString("APPEND", "Gone");
	cout << "ReplaceSubString Function:" << endl;
	cout << string.CStyle() << endl << endl;

	system("pause");

	return 0;
}