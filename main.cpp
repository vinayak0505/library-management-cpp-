#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "book_info.cpp"
#include "library.cpp"

using namespace std;

/*----------------------------------------------------------------------*/
int RN = 0, ck;
char name[30];
void getdata() // store data or input value
{
  fstream save;
  save.open("data/shinchan.txt", ios::out | ios::ate);
  cout << "\nenter identity of the person \n";
  int q = 9478554;
  cin >> RN;
  int checkdata(int);
  q = checkdata(RN);
  if (q == 0)
  {
    cout << "\nyou can edit it or create a new one press 1 and 2 respectively\n";
    int y;
    cin >> y;
    if (y == 1)
    {
      void edit(int);
      edit(RN);
      remove("shinchan.txt");
      rename("temp.txt", "shinchan.txt");
    }
    else
    {
      getdata();
    }
  }
  else
  {
    save << RN;
    cout << "\nenter name of the person\n";
    cin>>name;
    save << " " << name << "\n";
    save.close();
  }
}
void search(int rn) // search user by rn
{
  int un;
  fstream fin;
  fin.open("data/shinchan.txt", ios::in);
  while (fin >> un)
  {
    fin >> name;
    if (un == rn)
    {
      cout << name;
    }
  }
  fin.close();
}
void display() // display data.
{
  fstream take;
  take.open("data/shinchan.txt", ios::in);
  for (; take >> RN;)
  {
    take >> name;
    cout << "\nrollno. " << RN << "\t";
    cout << "name of the person " << name << "\n";
  }
}
int checkdata(int k) // checks the identity is taken or not and returns 0 if taken
{
  int RN = 94786856;
  fstream save;
  save.open("data/shinchan.txt", ios::in);
  while (save >> RN)
  {
    if (RN == k)
    {
      save >> name;
      cout << "\nthis identitiy is alredy taken by " << name << "\n";
      return (0);
    }
    save >> name;
  }
  return (1);
}

void edit(int q)
{
  cout << "\nyou have choose to edit name\n";
  cout << "now type new name and we will handel the rest\n;)\n";
  int r = 1000;
  fstream save, temp;
  save.open("data/shinchan.txt", ios::in);
  temp.open("data/temp.txt", ios::out);
  for (int m = 0; m == (save.eof());)
  {
    int g = 1;
    save >> RN;
    if (RN != r && g == 1)
    {
      r = RN;
      temp << RN << " ";
      if (RN == q)
      {
        save >> name;
        cin>>name;
        temp << name << "\n";
        cout << "\nname updated successfully\n";
      }
      else
      {
        save >> name;
        temp << name << "\n";
        g = 0;
      }
    }
  }
  remove("shinchan.txt");
  rename("temp.txt", "shinchan.txt");
}
void cleardata()
{
  fstream save;
  save.open("data/shinchan.txt", ios::out);
  save.close();
}
/*----------------------------------------------------------------------*/

///////////////////////////////////////////////////////////////////////////
int main()
{
  if (!filesystem::exists("data")) {
      filesystem::create_directory("data");
  }
  cout << "\033[2J\033[H";
  cout << "\n";
  int ch, ch1, ch2, ch3, bno, a, b, c, ic;
  char w, y = y;
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
      cout << "\npress 1 to enter user information";
      cout << "\npress 2 to display all users";
      cout << "\npress 3 to search user by icard";
      cout << "\npress 4 to edit user name";
      cout << "\npress 5 to enter clear all existing user";
      cout << "\npress 6 to exit";
      cout << "\nenter a choise\n";
      cin >> ch1;
      switch (ch1)
      {
      case 1:
        getdata();
        break;
      case 2:
        display();
        break;
      case 3:
        cout << "\nenter icard number";
        cin >> ic;
        search(ic);
        break;
      case 4:
        cout << "\nenter identity you want to edit\n";
        cin >> RN;
        edit(RN);
        remove("shinchan.txt");
        rename("temp.txt", "shinchan.txt");
        break;
      case 5:
        cleardata();
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
    if (w == 121)
    {
    }
    else
      break;
  }
  cout << "\nmore updates comming soon\n";
  int test;
  cin >> test;
  return 0;
}
