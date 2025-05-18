#include <iostream>
#include <fstream>

using namespace std;

class BookInfo
{
public:
  int bno;
  char bookn[30];

  void bgetdata();
  void bdisplay();
  void bsearch();
  void bchange(char a[30]);
  void bedit(int);
  void clearbook();
  int bcheckdata(int);
} s;

void BookInfo::bedit(int q)
{
  cout << "\nyou have choose to edit name\n";
  cout << "now type new name and we will handel the rest\n;)\n";
  fstream save;
  save.open("data/BookInfo.txt", ios::in | ios::out | ios::binary);
  for (; save;)
  {
    long A = save.tellg();
    save.read((char *)&s, sizeof(s));
    if (bno == q)
    {
      gets(s.bookn);

      cout << "\nname updated successfully\n";
      save.seekp(A);
      save.write((char *)&s, sizeof(s));
      break;
    }
  }
  save.close();
}

void BookInfo::bgetdata() // takes and save it into BookInfo
{
  int ch;
  fstream fout;
  fout.open("data/BookInfo.txt", ios::out | ios::app | ios::binary);
  cout << "\nenter book no. you want to store ";
  cin >> bno;
  int k = s.bcheckdata(bno);
  if (k == 1)
  {
    cout << "\nenter name of the book ";
    gets(s.bookn);
    fout.write((char *)&s, sizeof(s));
    fout.close();
  }
  else
  {
    cout << "\nyou want to edit the name press 1 or";
    cout << " to creat other identity press 0 ";
    cin >> ch;
    if (ch == 1)
    {
      bedit(s.bno);
    }
    else
    {
      bgetdata();
    }
  }
  fout.close();
}
int BookInfo::bcheckdata(int m) // checks the identity is taken or not and returns 0 if taken
{
  s.bno = -4000;
  fstream save;
  save.open("data/BookInfo.txt", ios::in | ios::binary);
  for (; save;)
  {
    save.read((char *)&s, sizeof(s));
    if (s.bno == m)
    {
      cout << "\nthis identitiy is alredy taken by " << s.bookn;
      save.close();
      return (0);
    }
  }
  s.bno = m;
  save.close();
  return (1);
}
void BookInfo::bdisplay() // shows all book name stored
{
  fstream fin;
  fin.open("data/BookInfo.txt", ios::in | ios::binary);
  while (fin.read((char *)&s, sizeof(s)))
  {
    cout << "\nno of book " << s.bno;
    cout << "\nname of the book " << s.bookn;
  }
}
void BookInfo::bsearch()
{
  int ch = 0;
  char word[30];
  cout << "\nplease enter the book name you want to search by name ";
  gets(word);
  fstream fin;
  fin.open("data/BookInfo.txt", ios::out | ios::in | ios::binary);
  for (; !fin.eof();)
  {
    fin.read((char *)&s, sizeof(s));
    if (strcmp(s.bookn, word) == 0)
    {
      cout << "\nthis book is store at " << s.bno << "\nwant to change the book name press 1 for yes else 0 ";
      cin >> ch;
      if (ch == 1)
      {
        ch = 1;
        bchange(word);
      }
    }
  }
  fin.close();
}
void BookInfo::bchange(char oldbook[30]) // changes old store book
{
  fstream fin;
  fin.open("data/BookInfo.txt", ios::out | ios::in | ios::binary);
  for (; fin;)
  {
    long a = fin.tellg();
    fin.read((char *)&s, sizeof(s));
    if (strcmp(s.bookn, oldbook) == 0)
    {
      cout << "\nenter name of new book you want to store ";
      gets(s.bookn);
      fin.seekp(a);
      fin.write((char *)&s, sizeof(s));
      cout << "\nname updated ";
    }
  }
  fin.close();
}
void BookInfo::clearbook()
{
  remove("data/BookInfo.txt");
}