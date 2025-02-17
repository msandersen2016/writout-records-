// week seven lab.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include <vector>

using namespace std;
class record
{
 public:
	string name;
	string city;
	string street;
	string zip;
	string state;
	
};
void writeout();
void save();
void ShowOrder();
void append();
int numberOfRecords;
const int capacity = 100;
record records[capacity];
int main()
{
	char input; bool end = false;
	
	cout << " hello welcome to records\n";
	writeout();
	cout << "\n"<<numberOfRecords << ":records where loaded from storage";
	do
	 {
		 cout << "\nplease enter what you would like to do (A)ppend,(L)oad,(S)ave(E)xit\n";
		 cin >> input;

		 
		 
		 if (input == 'e' || input == 'E')
		 {
			 end = true;

		 }
		 else if (input == 'a' || input == 'A')
		 {



			 cout << "\ninput name:";
			 cin >> records[numberOfRecords].name;
			 cout << "\ninput city:";
			 cin >> records[numberOfRecords].city;
			 cout << "\ninput  street:";
			 cin >> records[numberOfRecords].street;
			 cout << "\ninput state:";
			 cin >> records[numberOfRecords].state;
			 cout << "\ninput zip:";
			 cin >> records[numberOfRecords].zip;

			 void save();
			 numberOfRecords++;
		 }
		 else if (input == 'l' || 'L')
		 {
			 ShowOrder();
		 }
		 else if (input == 's' || 'S')
		 {
			 save();
		 }
	} while (end != true);
		
		return 0;
}
void writeout()
{

	fstream file;
	file.open("records.csv", ios::in);
	string line;
	int recordesloaded = 0;
	while (getline(file, line, '\n'))
	{
		istringstream templine(line);
		string data;
		int column=0;
		while (getline(templine, data, ','))
		{
			switch (column)
			{
			case 0:
				records[recordesloaded].name;
				break;
			case 1:
				records[recordesloaded].city;
					break;
			case 3:
				records[recordesloaded].state;
					break;
			case 4:
				records[recordesloaded].zip;
					break;

			}
		}column++;
	}numberOfRecords = recordesloaded;
	file.close();
}
void ShowOrder()
{
	int count = 0;
	for (int index = 0; index < numberOfRecords; index++)
	{
		cout << "\n record:" << count + 1;
		cout << "\n\n" << records[index].name;
		cout << "\n" << records[index].city;
		cout << "\n" << records[index].state;
		cout << "\n" << records[index].zip;
		
	}
}
void save()
{
	fstream file;
	file.open("records.csv", ios::out);
	for (int i = 0; i < numberOfRecords; i++)
	{
		file << records[i].name << "," << records[i].city << "," << records[i].state << "," << records[i].zip << '\n';

	}
	file.close();
}