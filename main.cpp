#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
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

	Student student;

	time_t now = time(0);
	char *date = ctime(&now);
	cout << "\ntodays date is " << date;
	l.checktime(now);

	char continue_program = 'y';
	do
	{
		cout << "\npress 1 for user information";
		cout << "\npress 2 for book information";
		cout << "\npress 3 for record information";
		cout << "\nother to exit";
		cout << "\nenter a choise\n";

		int choice;
		cin >> choice;
		switch (choice)
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
		cin >> continue_program;
	} while (continue_program == 'y');

	cout << "\nprogram is closing";
	return 0;
}
