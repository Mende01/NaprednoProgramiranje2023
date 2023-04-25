#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
using namespace std;
class date
{
private:
	int day, month, year;
public:
	date() {}
	friend void operator>>(istream& in, date& d); //Overloading >> operator
	friend void operator<<(ostream& out, date& d) //Overloading << operator
		
	{
		out << "\n Date : ";
		out << d.day;
		out << "/";
		out << d.month;
		out << "/";
		out << d.year;
	}
	~date() {}
};

void operator>>(istream& in, date& d)

{
	cout << "\n Enter Day : "; //vnesi den
	in >> d.day;
	cout << "\n Enter Month : "; //vnesi mesec
	in >> d.month;
	cout << "\n Enter Year : "; // vnesi godiuina
	cin >> d.year; 
	cout << "\n ------------------";
	switch (d.month)
	{

	case 1: //January
	case 3: //March
	case 5: //May
	case 7: //July
	case 8: //August
	case 10: //October
	case 12: //December
		if (d.day > 31)
		{
			cout << "\n Invalid Days ";
			exit(0);
		}
		break;
	case 4: //April
	case 6: //June
	case 9: //September
	case 11: //November
		if (d.day > 30)
		{
			cout << "\n Invalid Days ";
			exit(0);
		}
		break;
	case 2:
		if((d.year%100!=0&&d.year%4==0)||(d.year%400==0))
		{
			if (d.day > 29)
			{
				cout << "\n Invalid Days ";
				exit(0);
			}
		}
		else
		{
			if (d.day > 28)
			{
				cout << "\n Invalid Days ";
				exit(0);
			}
		}
		break;
	}
}

void vreme()
{
	int hour, min, sec;

	cout << "Enter the hour: ";
	cin >> hour;

	cout << "Enter the minute: ";
	cin >> min;

	cout << "Enter the second: ";
	cin >> sec;

	cout << "The time entered is: " << hour << ":" << min << ":" << sec << endl;

}
int main()
{
	date d;
	cout << "\n Enter Date: \n";
	cout << "\n ";
	cin >> d;
	cout << d;
	cout<<"\n";

	cout << "Enter Time: ";
	cout << "\n";
	vreme();
	return 0;
}