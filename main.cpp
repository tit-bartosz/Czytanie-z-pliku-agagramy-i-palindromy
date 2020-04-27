#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
string s1,s2;  //zmienne


bool sprawdzpali (string s1) //funkcja sprawdzaj¹ca czy to jest palingram.
{
    int dl=s1.size();
    for (int i=0; i<dl/2; i++)
        if (s1[i]!=s1[dl-i-1])
            return false;
    return true;

}


bool sprawdzana(string s1,string s2) //u¿y³em innej funkcji, bo tamta z ksi¹¿ki by³a zepsuta. sprawdza anagram
{
    int n1=s1.length();
    int n2=s2.length();

    if(n1!=n2)
        return false;

    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    for (int i=0; i<n1; i++)
        if(s1[i]!=s2[i])
            return false;
    return true;
}





int main()   //funkcja głowna, która wybiera czy to palindrom czy anagram
{
    fstream dopliku;
    dopliku.open("notatnik.txt",ios::out);

    cout << "Wprowadz pierwszy wyraz" << endl;
    cin >> s1;
    cout << "Wprowadz drugi wyraz" << endl;
    cin >> s2;
    if(sprawdzpali(s1)==true && sprawdzana(s1,s2)==true)
        dopliku << "Jest anagramem i palindromem";
    else if(sprawdzpali(s1)==true && sprawdzana(s1,s2)==false)
        dopliku <<"Nie jest anagramem, ale jest palindromem";
    else if(sprawdzpali(s1)==false && sprawdzana(s1,s2)==true)
        dopliku <<"Jest anagramem, ale nie palindromem";
    else if(sprawdzpali(s1)==false && sprawdzana(s1,s2)==false)
        dopliku <<"Nie jest anagramem i nie jest palindromem";

    dopliku.close();
    return 0;
}
//Tworca Bartosz Osikowski IITI
















