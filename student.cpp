#include <iostream>
#include <fstream>

using namespace std;
class Student
{
    char name[30];
    int RN;

public:
    void getdata() // store data or input value
    {
        fstream save;
        save.open("data/shinchan.txt", ios::out | ios::ate);
        cout << "\nenter identity of the person \n";
        int q = 9478554;
        cin >> RN;
        q = checkdata(RN);
        if (q == 0)
        {
            cout << "\nyou can edit it or create a new one press 1 and 2 respectively\n";
            int y;
            cin >> y;
            if (y == 1)
            {
                edit(RN);
                remove("data/shinchan.txt");
                rename("data/temp.txt", "data/shinchan.txt");
            }
            else
            {
                // getdata();
            }
        }
        else
        {
            save << RN;
            cout << "\nenter name of the person\n";
            cin >> name;
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
                    cin >> name;
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
        remove("data/shinchan.txt");
        rename("data/temp.txt", "data/shinchan.txt");
    }
    void cleardata()
    {
        fstream save;
        save.open("data/shinchan.txt", ios::out);
        save.close();
    }
};