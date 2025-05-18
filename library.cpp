class library : public BookInfo
{
public:
  int lbno, luno;
  char lbname[30], luname[30];
  long ltime;

  int lcheckuser(int a);
  int lcheckbook(int a);
  void merge();
  void ldisplay();
  void ldisplayall();
  void lreturn(int no);
  void lreissue(int no);
  void checktime(long no);
} l;

////////////////////////////////////////////////////////////////////////////
int library::lcheckuser(int a)
{
  fstream lib;
  lib.open("data/lib.txt", ios::in | ios::binary);
  while (lib.read((char *)&l, sizeof(l)))
  {
    if (a == l.luno)
    {
      cout << "\nuser had already issued a book first return that book";
      cout << "\nperson i card no is " << l.luno << "| user name is " << l.luname;
      cout << "\nbook issued no is " << l.lbno << "| book name " << l.luname;
      char *date = ctime(&l.ltime);
      cout << "\nissued on " << date;
      return (0);
    }
  }
  lib.close();
  return (1);
}
int library::lcheckbook(int a)
{
  fstream lib;
  lib.open("data/lib.txt", ios::in | ios::binary);
  while (lib)
  {
    lib.read((char *)&l, sizeof(l));
    if (a == l.lbno)
    {
      cout << "\nsorry book had already issued by";
      cout << "\nperson i card no is " << l.luno << "| user name is " << l.luname;
      cout << "\nbook issued no is " << l.lbno << "| book name is" << l.luname;
      char *date = ctime(&l.ltime);
      cout << "\nissued on " << date;
      return (0);
    }
  }
  lib.close();
  return (1);
}

void library::merge()
{
  char a[30];
  int bno, uno, i = 0, q = 0;
  fstream book, user, lib, libr;
  book.open("data/BookInfo.txt", ios::in | ios::binary);
  user.open("data/shinchan.txt", ios::in);
  lib.open("data/lib.txt", ios::out | ios::binary | ios::app);
  libr.open("data/librecord.txt", ios::out | ios::binary | ios::app);
  cout << "\nenter user icard who wants to issue book ";
  cin >> uno;
  int k = l.lcheckuser(uno);
  if (k == 1)
  {
    while (i == 0)
    {
      user >> l.luno;
      user >> l.luname;
      if (uno == l.luno)
        i++;
      if (user.eof())
        i = 2;
    }
    if (i == 2)
      cout << "\nerror user not found";
    else
    {
      i = 0;
      cout << "\nenter book number user wants to issue ";
      cin >> q;
      int p = l.lcheckbook(q);
      if (p == 1)
      {
        long t;
        while (i == 0)
        {
          book.read((char *)&s, sizeof(s));
          if (s.bno == q)
          {
            l.lbno = s.bno;
            strcpy(l.lbname, s.bookn);
            i++;
          }
          if (book.eof())
            i = 2;
        }
        if (i == 2)
          cout << "\nerror book not found";
        else
        {
          time_t now = time(0);
          ltime = now;
          lib.write((char *)&l, sizeof(l));
          libr.write((char *)&l, sizeof(l));
        }
      }
    }
  }
  book.close();
  user.close();
  lib.close();
  libr.close();
}
void library::ldisplay()
{
  int c = 0;
  char chr;
  fstream lib;
  lib.open("data/lib.txt", ios::in | ios::binary);
  for (; lib.read((char *)&l, sizeof(l));)
  {
    if (!l.luno == 0)
    {
      cout << "\nperson i card no is " << l.luno << "| user name is  " << l.luname << "\n";
      cout << "\nbook issued no is " << l.lbno << "| book name " << l.luname << "\n";
      char *date = ctime(&l.ltime);
      cout << "\nissued on " << date << "\n";
      cout << "--------------------------------------------------------------------------";
      c++;
      if (c % 10 == 0)
      {
        cout << "\npress n to see next 10 records ";
        cin >> chr;
      }
    }
    else
      cout << "\n no record found";
    if (lib.eof() == 1)
    {
      cout << "\nlast record shown press c to continue ";
      cin >> chr;
    }
  }
  lib.close();
}
void library::ldisplayall()
{
  int c = 0;
  char chr;
  fstream libr;
  libr.open("data/librecord.txt", ios::in | ios::binary);
  for (; libr.read((char *)&l, sizeof(l));)
  {
    cout << "\nperson i card no is " << l.luno << "| name is  " << l.luname << "\n";
    cout << "\nbook issued no is " << l.lbno << "| book name " << l.luname << "\n";
    char *date = ctime(&l.ltime);
    cout << "\nissued on " << date << "\n";
    cout << "--------------------------------------------------------------------------";
    c++;
    if (c % 10 == 0)
    {
      cout << "\npress n to see next 10 records ";
      cin >> chr;
    }
    if (libr.eof())
    {
      cout << "\nlast record shown press c to continue ";
      cin >> chr;
    }
  }
  libr.close();
}
void library::lreturn(int no)
{
  fstream lib, temp;
  lib.open("data/lib.txt", ios::in | ios::binary);
  temp.open("data/temp.txt", ios::out | ios::binary);
  for (; lib.read((char *)&l, sizeof(l));)
  {
    if (no == l.lbno)
    {
      cout << "\nreturning info ";
      cout << "\nperson i card no is " << l.luno << "| user name is " << l.luname << "\n";
      cout << "\nbook issued no is " << l.lbno << "| book name " << l.luname << "\n";
      char *date = ctime(&l.ltime);
      time_t now = time(0);
      char *date1 = ctime(&now);
      cout << "\nissued on " << date << "\nreturning on " << date1;
    }
    else
      temp.write((char *)&l, sizeof(l));
  }
  lib.close();
  temp.close();
  remove("lib.txt");
  rename("temp.txt", "lib.txt");
  cout << "\nrecord edited";
}
void library::lreissue(int no)
{
  float a;
  fstream lib;
  lib.open("data/lib.txt", ios::in | ios::out | ios::binary);
  for (; lib.read((char *)&l, sizeof(l));)
  {
    if (no == l.lbno)
    {
      cout << "\nreissuing info";
      cout << "\nperson i card no is " << l.luno << "| user name is " << l.luname;
      cout << "\nbook issued no is " << l.lbno << "| book name " << l.luname;
      char *date = ctime(&l.ltime);
      time_t now = time(0);
      char *date1 = ctime(&now);
      cout << "\nissued on " << date << "\nreissuing on " << date1;
      l.ltime = now;
      lib.seekp(a);
      lib.write((char *)&l, sizeof(l));
    }
    cout << "\nrecord edited";
    lib.close();
  }
}
void library::checktime(long a)
{
  fstream lib;
  lib.open("data/lib.txt", ios::in | ios::binary);
  for (; lib.read((char *)&l, sizeof(l));)
  {
    lib.read((char *)&l, sizeof(l));
    if (a - l.ltime > 691200)
    {
      cout << "\nyou should have recieve a book buy know ";
      cout << "\nperson i card no is " << l.luno << "| user name is " << l.luname;
      cout << "\nbook issued no is " << l.lbno << "| book name " << l.luname;
      char *date = ctime(&l.ltime);
      cout << "\nissued on " << date;
      cout << "\nif you have receved this book then you set it from 3rd option in main menu";
      cout << "----------------------------------------------------------------------------";
    }
    else
    {
      if (a - l.ltime > 604800)
      {
        cout << "\na user might return a book today";
        cout << "\nperson i card no is " << l.luno << "| name is " << l.luname;
        cout << "\nbook issued no is " << l.lbno << "| book name " << l.luname;
        char *date = ctime(&l.ltime);
        cout << "\nissued on " << date;
        cout << "------------------------------------------------------------------------";
      }
    }
  }
}