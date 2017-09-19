#include <iostream>
#include <string>

using namespace std;

void PrintTitle(int colNumber);
void PrintTopEdge(int colNumber);
void PrintMidEdge(int colNumber);
void PrintBotEdge(int colNumber);
void PrintASCII(int lineNumber, int rowNumber, int colNumer);

int main()
{
	//row 가로 col 세로 
	const int rowNumber = 19;
	const int colNumber = static_cast<int>(floor(127 / rowNumber));

	PrintTitle(colNumber);
	PrintTopEdge(colNumber);

	for (int ASCII = 0; ASCII < rowNumber; ++ASCII)
	{
		PrintASCII(ASCII, rowNumber, colNumber);
	}

	system("pause");
}

void PrintTitle(int colNumber)
{
	string line = "=====";

	cout << " ";

	for (int i = 0; i <= colNumber; ++i)
	{
		cout << line;
	}

	cout << "아스키 코드표";

	for (int i = 0; i <= colNumber; ++i)
	{
		cout << line;
	}
	cout << endl << endl;
}

void PrintTopEdge(int colNumber)
{
	string topEdge = "━━━━━";

	cout << "┏";
	for (int i = 0; i <= colNumber; ++i)
	{
		cout << topEdge;
		(i == colNumber) ? cout << "┓" << endl : cout << "┳";
	}
}

void PrintMidEdge(int colNumber)
{
	string midEdge = "━━━━━";

	cout << "┣";
	for (int i = 0; i <= colNumber; ++i)
	{
		cout << midEdge;
		(i == colNumber) ? cout << "┫" << endl : cout << "╋";
	}
}

void PrintBotEdge(int colNumber)
{
	string botEdge = "━━━━━";

	cout << "┗";
	for (int i = 0; i <= colNumber; ++i)
	{
		cout << botEdge;
		(i == colNumber) ? cout << "┛" << endl : cout << "┻";
	}
}

void PrintASCII(int lineNumber, int rowNumber, int colNumber)
{
	for (int col = 0; col <= colNumber; ++col)
	{
		int ASCIINumber = lineNumber + (rowNumber * col);

		if (ASCIINumber == 7 || ASCIINumber == 8 || ASCIINumber == 9 || ASCIINumber == 10 || ASCIINumber == 13)
			printf("┃ %3d번 %3c", ASCIINumber, '?');
		else if (ASCIINumber > 127)
			printf("┃ %9c", ' ');
		else
			printf("┃ %3d번 %3c", ASCIINumber, ASCIINumber);
	}
	cout << "┃" << endl;
	(lineNumber == rowNumber - 1) ?
		PrintBotEdge(colNumber) :
		PrintMidEdge(colNumber);
}