#include<iostream>
//posebna bibloteka za rabota 
#include <bits/stdc++.h> 
#include<cstring>
#include<cstring>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
	string str1;
	string str2;

	//deklracija na vektor i iterator
	vector<int> StringVek(80);
	vector<int>::iterator iterString;
	//vnesuvanjena dvata stringovi
	cout<<"\n Vnesete INKIBrIndex.Ime.Prezime => ";
	cin>>str1;
	cout<<"\n Vnesete mail za komunikacija so fax => ";
	cin>>str2;
	
	//deklariranje n apromenlici od cel tip na podtaok
	int nstr1,nstr2;
	//odreduvanje na dolizni 
	nstr1=str1.length();
	nstr2=str2.length();
	
	//dopolnuvanje na prviot string so prazno mesto
	str1.append(" ");
	//i dopolnuvanje na prviot string so vtor string
	str1.append(str2);
	
	//pecatenje na elementite od spoen string 
	cout<<"\n Spoeni string => "<<str1;
	
	//oderduvanje na dolzinata na stringot koj e spoen
	int dolZaedno=str1.length();
	//polenje na elementite od stringot so ascii kodovite 
	for(int i=0;i<dolZaedno;i++)
		StringVek.push_back((int)str1[i]);
	//dodavanje na elementite od data vo vektorot
	sort(StringVek.begin(),StringVek.end());
	StringVek.push_back(16);
	StringVek.push_back(05);
	StringVek.push_back(03);
	cout<<"\n\n Vektor - Int  ";
	//pecatenje na vektorot so iterator
	for(iterString=StringVek.begin();iterString<StringVek.end();++iterString)
	{
		if((*iterString)!=0)
		cout<<*iterString<<" ";			
	}
	//otvaranje na datoteka 
	ofstream Mende("1010.Proect03.txt");
	//zapisuvanje na podatocite vo datotekata
	Mende<<"\n Spoeni string => "<<str1<<endl;
	Mende<<"\n Vektor - Int  "<<endl<<endl;
	for(iterString=StringVek.begin();iterString<StringVek.end();++iterString)
	{
		if((*iterString)!=0)
		Mende<<*iterString<<" ";			
	}
}
