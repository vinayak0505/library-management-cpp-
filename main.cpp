#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "book_info.cpp"
#include "library.cpp"
#include "student.cpp"

using namespace std;

int main()
{
	if (!filesystem::exists("data"))
	{
		filesystem::create_directory("data");
	}
	int ch, ch1, ch2, ch3, bno, a, b, c, ic;
	char w;
	Student student;
	for (int e = 0; e < 1;)
	{
		time_t now = time(0);
		char *date = ctime(&now);
		cout << "\ntodays date is " << date;
		l.checktime(now);
		cout << "\npress 1 for user information";
		cout << "\npress 2 for book information";
		cout << "\npress 3 for record information";
		cout << "\nother to exit";
		cout << "\nenter a choise\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			student.displayOptionAndHandleInput();
			break;
		case 2:
			s.displayOptionAndHandleInput();
			break;
		case 3:
			l.displayOptionAndHandleInput();
			break;
		}
		cout << "\nwant to do some more stuff press y if yes or n to exit program\n";
		cin >> w;
		if (w != 'y')
			break;
	}
	cout << "\nprogram is closing";
	int test;
	cin >> test;
	return 0;
}
