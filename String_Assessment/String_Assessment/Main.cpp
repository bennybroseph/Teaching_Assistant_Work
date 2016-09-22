#include <iostream>
#include "MyString.h"

using std::cout;
using std::endl;

using std::cin;

int main(int numArgs, char *args)
{
	MyString string = "Default String";
	cout << "Constructor:" << endl;
	cout << string.CStyle() << endl;
	cin.get();

	int length = string.Length();
	cout << "Length():" << endl;
	cout << length << endl;
	cin.get();

	bool equal = string.Compare("Default String");
	cout << "Compare(\"Default String\")" << endl;
	cout << equal << endl;
	cin.get();

	string.Append(" Append");
	cout << "Append(\" Append\"):" << endl;
	cout << string.CStyle() << endl;
	cin.get();

	string.Prepend("Prepend ");
	cout << "Prepend(\"Prepend \"):" << endl;
	cout << string.CStyle() << endl;
	cin.get();

	string = string.ToLower();
	cout << "string = string.ToLower():" << endl;
	cout << string.CStyle() << endl;
	cin.get();

	string = string.ToUpper();
	cout << "string = string.ToUpper():" << endl;
	cout << string.CStyle() << endl;
	cin.get();

	bool foundSubString = string.FindSubString("DEFAULT");
	cout << "FindSubString(\"DEFAULT\"):" << endl;
	cout << foundSubString << endl;
	cin.get();

	foundSubString = string.FindSubString("DEFAULT", 15);
	cout << "FindSubString(\"DEFAULT\", 15):" << endl;
	cout << foundSubString << endl;
	cin.get();

	string.ReplaceSubString("PREPEND", "Gone");
	cout << "ReplaceSubString(\"APPEND\", \"Gone\"):" << endl;
	cout << string.CStyle() << endl;
	cin.get();

	string.ReplaceSubString("APPEND", "That's gone now too");
	cout << "ReplaceSubString(\"APPEND\", \"That's gone now too\"):" << endl;
	cout << string.CStyle() << endl;
	cin.get();

	cout << endl << "End of Program" << endl;
	system("pause");

	return 0;
}