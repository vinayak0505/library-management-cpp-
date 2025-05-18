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
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\ntodays date is " << date;
		l.checktime(now);
		cout << "\npress 1 for user information";
		cout << "\npress 2 for book information";
		cout << "\npress 3 for record information";
		cout << "\npress 4 to exit";
		cout << "\nenter a choise\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			ch1 = library::displayOptionAndGetInput();
			switch (ch1)
			{
			case 1:
				student.getdata();
				break;
			case 2:
				student.display();
				break;
			case 3:
				cout << "\nenter icard number";
				cin >> ic;
				student.search(ic);
				break;
			case 4:
				cout << "\nenter identity you want to edit\n";
				cin >> ic;
				student.edit(ic);
				remove("data/shinchan.txt");
				rename("data/temp.txt", "data/shinchan.txt");
				break;
			case 5:
				student.cleardata();
				break;
			case 6:
				break;
			default:
				cout << "option not available";
			}
			break;
		case 2:
			cout << "\npress 1 to enter book information";
			cout << "\npress 2 display all book information";
			cout << "\npress 3 to edit book info";
			cout << "\npress 4 to search book";
			cout << "\npress 5 to clear all book store in lib";
			cout << "\npress 6 to exit";
			cout << "\nenter a choise\n";
			cin >> ch2;
			switch (ch2)
			{
			case 1:
				s.bgetdata();
				break;
			case 2:
				s.bdisplay();
				break;
			case 3:
			{
				cout << "enter no you want to edit ";
				cin >> bno;
				s.bedit(bno);
				break;
			}
			case 4:
				s.bsearch();
				break;
			case 5:
				s.clearbook();
				break;
			case 6:
				break;
			default:
				cout << "option not available";
			}
			break;
		case 3:
			cout << "\npress 1 to issue a book and store in record";
			cout << "\npress 2 to display issued book with user";
			cout << "\npress 3 to display all information all books ever issued book with user";
			cout << "\npress 4 to reissue book if any issued before";
			cout << "\npress 5 to return a book if taken";
			cout << "\npress 6 to exit";
			cout << "\nenter a choise\n";
			cin >> ch3;
			switch (ch3)
			{
			case 1:
				l.merge();
				break;
			case 2:
				l.ldisplay();
				break;
			case 3:
				l.ldisplayall();
				break;
			case 4:
				cout << "\nenter book no you want to issue ";
				cin >> c;
				l.lreissue(c);
				break;
			case 5:
				cout << "\nenter book no you want to return";
				cin >> b;
				l.lreturn(b);
			case 6:
				break;
			default:
				cout << "option not available";
			}
			break;
		default:
			cout << "option not available";
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
