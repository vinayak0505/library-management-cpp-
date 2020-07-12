#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

class bookinfo
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
}s;
class library:public bookinfo
{
 public:
 int lbno,luno;
 char lbname[30],luname[30];
 long ltime;

  int lcheckuser(int a);
  int lcheckbook(int a);
  void merge()          ;
  void ldisplay()        ;
  void ldisplayall()      ;
  void lreturn(int no)     ;
  void lreissue(int no)     ;
  void checktime(long no);
}l;
//////////////////////////////////////////////////////////////////////////
void bookinfo::bedit(int q)
{
 cout<<"\nyou have choose to edit name\n"             ;
 cout<<"now type new name and we will handel the rest\n;)\n";
 fstream save;
 save.open("bookinfo.txt",ios::in|ios::out|ios::binary);
 for(;save;)
 {
  long A=save.tellg();
  save.read((char*)&s,sizeof(s));
  if(bno==q)
  {
   gets(s.bookn);

   cout<<"\nname updated successfully\n";
   save.seekp(A);
   save.write((char*)&s,sizeof(s));
   break;
  }
 }
 save.close();
}

void bookinfo::bgetdata()// takes and save it into bookinfo
{
 int ch;
 fstream fout;
 fout.open("bookinfo.txt",ios::out|ios::app|ios::binary);
 cout<<"\nenter book no. you want to store ";
 cin>>bno;
 int k=s.bcheckdata(bno);
 if(k==1)
 {
  cout<<"\nenter name of the book ";
  gets(s.bookn);
  fout.write((char*)&s,sizeof(s));
  fout.close();
 }
 else
 {
  cout<<"\nyou want to edit the name press 1 or";
  cout<<" to creat other identity press 0 ";
  cin>>ch;
  if(ch==1)
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
int bookinfo::bcheckdata(int m)//checks the identity is taken or not and returns 0 if taken
{
 s.bno=-4000;
 fstream save;
 save.open("bookinfo.txt",ios::in|ios::binary);
 for(;save;)
 {
 save.read((char*)&s,sizeof(s));
  if(s.bno==m)
  {
   cout<<"\nthis identitiy is alredy taken by "<<s.bookn;
   save.close();
   return(0);
  }
 }
 s.bno=m;
 save.close();
 return(1);
}
void bookinfo::bdisplay()//shows all book name stored
{
 fstream fin;
 fin.open("bookinfo.txt",ios::in|ios::binary);
 while(fin.read((char*)&s,sizeof(s)))
 {
  cout<<"\nno of book "<<s.bno;
  cout<<"\nname of the book "<<s.bookn;
 }
}
void bookinfo::bsearch()
{
 int ch=0;
 char word[30];
 cout<<"\nplease enter the book name you want to search by name ";
 gets(word);
 fstream fin;
 fin.open("bookinfo.txt",ios::out|ios::in|ios::binary);
 for(;!fin.eof();)
 {
  fin.read((char*)&s,sizeof(s));
  if(strcmp(s.bookn,word)==0)
  {
   cout<<"\nthis book is store at "<<s.bno<<"\nwant to change the book name press 1 for yes else 0 ";
   cin>>ch;
   if(ch==1)
   {
    ch=1;
    bchange(word);
   }
  }
 }
 fin.close();
}
void bookinfo::bchange(char oldbook[30]) //changes old store book
{
 fstream fin;
 fin.open("bookinfo.txt",ios::out|ios::in|ios::binary);
 for(;fin;)
 {
  long a=fin.tellg();
  fin.read((char*)&s,sizeof(s));
  if(strcmp(s.bookn,oldbook)==0)
  {
   cout<<"\nenter name of new book you want to store ";
   gets(s.bookn);
   fin.seekp(a);
   fin.write((char*)&s,sizeof(s));
   cout<<"\nname updated ";
  }
 }
 fin.close();
}
void bookinfo::clearbook()
{
 remove("bookinfo.txt");
}
/*----------------------------------------------------------------------*/
int RN=0,ck;
char name[30];
void getdata() //store data or input value
{
 fstream save;
 save.open("shinchan.txt",ios::out|ios::ate);
 cout<<"\nenter identity of the person \n";
 int q=9478554;
 cin>>RN;
 int checkdata(int);
 q=checkdata(RN);
 if(q==0)
 {
  cout<<"\nyou can edit it or create a new one press 1 and 2 respectively\n";
  int y;
  cin>>y;
  if(y==1)
   {
    void edit(int);
    edit(RN);
    remove("shinchan.txt");
    rename("temp.txt","shinchan.txt");

   }
  else
   {
    getdata();
   }
 }
 else
 {
  save<<RN;
  cout<<"\nenter name of the person\n";
  gets(name);
  save<<" "<<name<<"\n";
  save.close();
 }
}
void search(int rn) //search user by rn
{
 int un;
 fstream fin;
 fin.open("shinchan.txt",ios::in);
 while(fin>>un)
 {
  fin>>name;
  if(un==rn)
  {
   cout<<name;
  }
 }
 fin.close();
}
void display() //display data.
{
 fstream take;
 take.open("shinchan.txt",ios::in);
 for(;take>>RN;)
 {
  take>>name;
  cout<<"\nrollno. "<<RN<<"\t";
  cout<<"name of the person "<<name<<"\n";
 }
}
int checkdata(int k)//checks the identity is taken or not and returns 0 if taken
{
  int RN=94786856;
  fstream save;
  save.open("shinchan.txt",ios::in);
  while (save>>RN)
  {
   if(RN==k)
   {
   save>>name;
   cout<<"\nthis identitiy is alredy taken by "<<name<<"\n";
   return(0);
   }
  save>>name;
  }
return(1);
}

void edit(int q)
{
 cout<<"\nyou have choose to edit name\n"             ;
 cout<<"now type new name and we will handel the rest\n;)\n";
 int r=1000;
 fstream save,temp;
 save.open("shinchan.txt",ios::in);
 temp.open("temp.txt",ios::out);
 for(int m=0;m==(save.eof());)
 {
  int g=1;
  save>>RN;
  if(RN!=r&&g==1)
  {
   r=RN;
   temp<<RN<<" ";
   if(RN==q)
   {
    save>>name;
    gets(name);
    temp<<name<<"\n";
    cout<<"\nname updated successfully\n";
   }
   else
   {
    save>>name;
    temp<<name<<"\n";
    g=0;
   }
  }
 }
 remove("shinchan.txt");
 rename("temp.txt","shinchan.txt");
}
void cleardata()
{
 fstream save;
 save.open("shinchan.txt",ios::out);
 save.close();
}
/*----------------------------------------------------------------------*/
////////////////////////////////////////////////////////////////////////////
int library::lcheckuser(int a)
{
  fstream lib;
  lib.open("lib.txt",ios::in|ios::binary);
  while(lib.read((char*)&l,sizeof(l)))
  {
   if(a==l.luno)
   {
    cout<<"\nuser had already issued a book first return that book";
    cout<<"\nperson i card no is "<<l.luno<<"| user name is "<<l.luname;
    cout<<"\nbook issued no is "<<l.lbno<<"| book name "<<l.luname;
    char* date=ctime(&l.ltime);
    cout<<"\nissued on "<<date;
    return(0);
   }
  }
 lib.close();
 return(1);
}
int library::lcheckbook(int a)
{
  fstream lib;
  lib.open("lib.txt",ios::in|ios::binary);
  while(lib)
  {
   lib.read((char*)&l,sizeof(l));
   if(a==l.lbno)
   {
    cout<<"\nsorry book had already issued by";
    cout<<"\nperson i card no is "<<l.luno<<"| user name is "<<l.luname;
    cout<<"\nbook issued no is "<<l.lbno<<"| book name is"<<l.luname;
    char* date=ctime(&l.ltime);
    cout<<"\nissued on "<<date;
    return(0);
   }
  }
 lib.close();
 return(1);
}

void library::merge()
{
 char a[30];
 int bno,uno,i=0,q=0;
 fstream book,user,lib,libr;
 book.open("bookinfo.txt",ios::in|ios::binary);
 user.open("shinchan.txt",ios::in);
 lib.open("lib.txt",ios::out|ios::binary|ios::app);
 libr.open("librecord.txt",ios::out|ios::binary|ios::app);
 cout<<"\nenter user icard who wants to issue book ";
 cin>>uno;
 int k=l.lcheckuser(uno);
 if(k==1)
 {
  while(i==0)
  {
   user>>l.luno;
   user>>l.luname;
   if(uno==l.luno)
   i++;
   if(user.eof())
   i=2;
  }
  if(i==2)
  cout<<"\nerror user not found";
  else
  {
  i=0;
  cout<<"\nenter book number user wants to issue ";
  cin>>q;
  int p=l.lcheckbook(q);
  if(p==1)
  {
   long t;
   while(i==0)
    {
     book.read((char*)&s,sizeof(s));
     if(s.bno==q)
     {
      l.lbno=s.bno;
      strcpy(l.lbname,s.bookn);
      i++;
     }
     if(book.eof())
     i=2;
    }
    if(i==2)
    cout<<"\nerror book not found";
    else
    {
     time_t now=time(0);
     ltime=now;
     lib.write((char*)&l,sizeof(l));
     libr.write((char*)&l,sizeof(l));
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
 int c=0;
 char chr;
 fstream lib;
 lib.open("lib.txt",ios::in|ios::binary);
 for(;lib.read((char*)&l,sizeof(l));)
 {
  if(!l.luno==0)
  {
   cout<<"\nperson i card no is "<<l.luno<<"| user name is  "<<l.luname<<"\n";
   cout<<"\nbook issued no is "<<l.lbno<<"| book name "<<l.luname<<"\n";
   char* date=ctime(&l.ltime);
   cout<<"\nissued on "<<date<<"\n";
   cout<<"--------------------------------------------------------------------------";
   c++;
   if(c%10==0)
   {
   cout<<"\npress n to see next 10 records ";
   cin>>chr;
   }
  }
  else cout<<"\n no record found";
  if(lib.eof()==1)
  {
  cout<<"\nlast record shown press c to continue ";
  cin>>chr;
  }
 }
 lib.close();
}
void library::ldisplayall()
{
 int c=0;
 char chr;
 fstream libr;
 libr.open("librecord.txt",ios::in|ios::binary);
 for(;libr.read((char*)&l,sizeof(l));)
 {
  cout<<"\nperson i card no is "<<l.luno<<"| name is  "<<l.luname<<"\n";
  cout<<"\nbook issued no is "<<l.lbno<<"| book name "<<l.luname<<"\n";
  char* date=ctime(&l.ltime);
  cout<<"\nissued on "<<date<<"\n";
  cout<<"--------------------------------------------------------------------------";
  c++;
  if(c%10==0)
  {
  cout<<"\npress n to see next 10 records ";
  cin>>chr;
  }
  if(libr.eof())
  {
  cout<<"\nlast record shown press c to continue ";
  cin>>chr;
  }
 }
 libr.close();
}
void library::lreturn(int no)
{
 fstream lib,temp;
 lib.open("lib.txt",ios::in|ios::binary) ;
 temp.open("temp.txt",ios::out|ios::binary);
 for(;lib.read((char*)&l,sizeof(l));)
 {
  if(no==l.lbno)
  {
   cout<<"\nreturning info ";
   cout<<"\nperson i card no is "<<l.luno<<"| user name is "<<l.luname<<"\n";
   cout<<"\nbook issued no is "<<l.lbno<<"| book name "<<l.luname<<"\n";
   char* date=ctime(&l.ltime);time_t now=time(0); char* date1=ctime(&now);
   cout<<"\nissued on "<<date<<"\nreturning on "<<date1;
  }
  else
  temp.write((char*)&l,sizeof(l));
 }
 lib.close();
 temp.close();
 remove("lib.txt");
 rename("temp.txt","lib.txt");
 cout<<"\nrecord edited";

}
void library::lreissue(int no)
{
 float a;
 fstream lib;
 lib.open("lib.txt",ios::in|ios::out|ios::binary);
 for(;lib.read((char*)&l,sizeof(l));)
 {
  if(no==l.lbno)
  {
   cout<<"\nreissuing info";
   cout<<"\nperson i card no is "<<l.luno<<"| user name is "<<l.luname;
   cout<<"\nbook issued no is "<<l.lbno<<"| book name "<<l.luname;
   char* date=ctime(&l.ltime);time_t now=time(0); char* date1=ctime(&now);
   cout<<"\nissued on "<<date<<"\nreissuing on "<<date1;
   l.ltime=now;
   lib.seekp(a);
   lib.write((char*)&l,sizeof(l));
  }
  cout<<"\nrecord edited";
  lib.close();
 }
}
void library::checktime(long a)
{
 fstream lib;
 lib.open("lib.txt",ios::in|ios::binary);
 for(;lib.read((char*)&l,sizeof(l));)
 {
  lib.read((char*)&l,sizeof(l));
  if(a-l.ltime>691200)
  { cout<<"\nyou should have recieve a book buy know ";
    cout<<"\nperson i card no is "<<l.luno<<"| user name is "<<l.luname;
    cout<<"\nbook issued no is "<<l.lbno<<"| book name "<<l.luname;
    char* date=ctime(&l.ltime);
    cout<<"\nissued on "<<date;
    cout<<"\nif you have receved this book then you set it from 3rd option in main menu";
    cout<<"----------------------------------------------------------------------------";
  }
  else
  {
   if(a-l.ltime>604800)
   {cout<<"\na user might return a book today";
    cout<<"\nperson i card no is "<<l.luno<<"| name is "<<l.luname;
    cout<<"\nbook issued no is "<<l.lbno<<"| book name "<<l.luname;
    char* date=ctime(&l.ltime);
    cout<<"\nissued on "<<date                          ;
    cout<<"------------------------------------------------------------------------";
   }
  }
 }
}
///////////////////////////////////////////////////////////////////////////
void main()
{
 clrscr();
 cout<<"\n";
 int ch,ch1,ch2,ch3,bno,a,b,c,ic;
 char w,y=y;
 for(int e=0;e<1;)
 {
  time_t now=time(0);
  char* date=ctime(&now);
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\ntodays date is "<<date;
  l.checktime(now);
  cout<<"\npress 1 for user information";
  cout<<"\npress 2 for book information" ;
  cout<<"\npress 3 for record information";
  cout<<"\npress 4 to exit";
  cout<<"\nenter a choise\n";
  cin>>ch;
  switch(ch)
   {
    case 1:
	   cout<<"\npress 1 to enter user information";
	   cout<<"\npress 2 to display all users";
	   cout<<"\npress 3 to search user by icard";
	   cout<<"\npress 4 to edit user name";
	   cout<<"\npress 5 to enter clear all existing user";
	   cout<<"\npress 6 to exit";
	   cout<<"\nenter a choise\n";
	   cin>>ch1;
	   switch(ch1)
	   {
	    case 1:getdata(); break;
	    case 2:display(); break;
	    case 3:cout<<"\nenter icard number";
		   cin>>ic;
		   search(ic); break;
	    case 4:cout<<"\nenter identity you want to edit\n";
		   cin>>RN;
		   edit(RN);
		   remove("shinchan.txt");
		   rename("temp.txt","shinchan.txt");
		   break;
	    case 5:cleardata(); break;
	    case 6:break;
	    default:cout<<"option not available";
	   }
    break;
    case 2:
	   cout<<"\npress 1 to enter book information";
	   cout<<"\npress 2 display all book information";
	   cout<<"\npress 3 to edit book info";
	   cout<<"\npress 4 to search book";
	   cout<<"\npress 5 to clear all book store in lib";
	   cout<<"\npress 6 to exit";
	   cout<<"\nenter a choise\n";
	   cin>>ch2;
	   switch(ch2)
	   {
	    case 1:s.bgetdata();break;
	    case 2:s.bdisplay();break;
	    case 3:
		   {
		   cout<<"enter no you want to edit ";
		   cin>>bno;
		   s.bedit(bno);break;
		   }
	    case 4:s.bsearch();break;
	    case 5:s.clearbook();break;
	    case 6:break;
	    default:cout<<"option not available";
	   }
    break;
    case 3:
	   cout<<"\npress 1 to issue a book and store in record";
	   cout<<"\npress 2 to display issued book with user";
	   cout<<"\npress 3 to display all information all books ever issued book with user";
	   cout<<"\npress 4 to reissue book if any issued before";
	   cout<<"\npress 5 to return a book if taken";
	   cout<<"\npress 6 to exit";
	   cout<<"\nenter a choise\n";
	   cin>>ch3;
	   switch(ch3)
		     {
		      case 1:l.merge();break;
		      case 2:l.ldisplay();break;
		      case 3:l.ldisplayall();break;
		      case 4:cout<<"\nenter book no you want to issue ";
			     cin>>c;
			     l.lreissue(c);break;
		      case 5:cout<<"\nenter book no you want to return";
			     cin>>b;
			     l.lreturn(b);
		     case 6:break;
		     default:cout<<"option not available";
		     }
   break;
   default:cout<<"option not available";break;
  }
  cout<<"\nwant to do some more stuff press y if yes or n to exit program\n";
  cin>>w;
  if(w==121)
  {}
  else break;
 }
 cout<<"\nmore updates comming soon\n";
 getch();
}

