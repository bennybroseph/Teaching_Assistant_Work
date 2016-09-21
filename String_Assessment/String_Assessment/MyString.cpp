#include "MyString.h"



MyString::MyString()
{
	data = "";
}

MyString::MyString(char *newString) : MyString()
{
	if (newString == "")
		return;

	int stringLength = 0;
	for (int i = 0; newString[i] != '\0'; ++i)
		stringLength = i;
	stringLength++;

	data = new char[stringLength + 1]; // This will cause a memory leak without a destructor

	int i;
	for (i = 0; i < stringLength; ++i)
	{
		data[i] = newString[i];
	}
	data[stringLength] = '\0';
}

int MyString::Length()
{
	if (data[0] == '\0')
		return 0;

	int stringLength = 0;
	for (int i = 0; data[i] != '\0'; ++i)
		stringLength = i;
	stringLength++;

	return stringLength;
}

char MyString::GetCharacter(int index)
{
	return data[index];
}

bool MyString::Compare(MyString otherString)
{
	if (data == "" && otherString.data == "")
		return true;

	if (data == "" || otherString.data == "")
		return false;

	if (Length() != otherString.Length())
		return false;

	for (int i = 0; data[i] != '\0'; ++i)
		if (data[i] != otherString.data[i])
			return false;

	return true;
}

void MyString::Append(MyString otherString)
{
	char *oldData = data;
	int oldLength = Length();

	int newLength = Length() + otherString.Length();
	data = new char[newLength + 1];

	int i;
	for (i = 0; i < oldLength; ++i)
	{
		data[i] = oldData[i];
	}
	for (i = oldLength; i - oldLength < otherString.Length(); ++i)
	{
		data[i] = otherString.data[i - oldLength];
	}
	data[i] = '\0';
}

void MyString::Prepend(MyString otherString)
{
	otherString.Append(data);

	data = otherString.data;
}

const char * MyString::CStyle()
{
	return data;
}

MyString MyString::ToLower()
{
	MyString toLower = MyString(data);

	for (int i = 0; i < Length(); ++i)
	{
		if (toLower.data[i] >= 'A' && toLower.data[i] <= 'Z')
			toLower.data[i] += 32;
	}
	return toLower;
}

MyString MyString::ToUpper()
{
	MyString toUpper = MyString(data);

	for (int i = 0; i < Length(); ++i)
	{
		if (toUpper.data[i] >= 'a' && toUpper.data[i] <= 'z')
			toUpper.data[i] -= 32;
	}
	return toUpper;
}

bool MyString::FindSubString(MyString otherString)
{
	return FindSubString(otherString, 0);
}

bool MyString::FindSubString(MyString otherString, int begin)
{
	if (data == "" && otherString.data == "")
		return true;

	if (data == "" || otherString.data == "")
		return false;

	int matchLength = 0;
	for (int i = begin; i < Length(); ++i)
	{
		if (data[i] == otherString.data[matchLength])
			matchLength++;
		else
			matchLength = 0;

		if (matchLength == otherString.Length())
			break;
	}

	return matchLength == otherString.Length();
}

void MyString::ReplaceSubString(MyString replace, MyString with)
{
	if (data == "" || replace.data == "")
		return;

	while (FindSubString(replace))
	{
		int matchLength = 0;
		int matchStart = 0;
		int matchEnd = 0;
		for (int i = 0; i < Length(); ++i)
		{
			if (data[i] == replace.data[matchLength])
			{
				if (matchLength == 0)
					matchStart = i;
				else
					matchEnd = i;

				matchLength++;
			}
			else
				matchLength = 0;

			if (matchLength == replace.Length())
				break;
		}
		if (matchLength == replace.Length())
		{
			int i;

			char *prepend = new char[matchStart + 1];
			for (i = 0; i < matchStart; ++i)
				prepend[i] = data[i];
			prepend[i] = '\0';

			char *append = new char[Length() - matchEnd];
			for (i = matchEnd + 1; i < Length(); ++i)
				append[i - matchEnd - 1] = data[i];
			append[i - matchEnd - 1] = '\0';

			MyString newString = MyString();

			if (prepend[0] != '\0')
				newString.Prepend(prepend);
			newString.Append(with);
			newString.Append(append);

			data = newString.data;

			delete[] prepend;
			delete[] append;
		}
	}
}