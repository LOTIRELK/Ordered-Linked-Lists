// Assignment5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "orderedList.h"
#include <iostream>
#include <list>
#include <string>
#include <algorithm> 

using namespace std;

bool quitFlag = false;
void doQuit(void);
void displayMenu(void);

int main()
{
	SortedType<string> ol1;
	SortedType<string> ol2;
	SortedType<string> ol3;

	string item, item2, value, input;
	int length, length2, count, count2, option;

	do {
		
		displayMenu();
		cout << "\tPlease enter your option: ";
		cin >> option;
		switch (option)
		{
		case 1:
			length = 0;
			count = 0;
			ol1.SetCount(count);
			do
			{
				cout << "Please enter a word: ";
				cin >> item;
				if (item != "-1") 
				{
					transform(item.begin(), item.end(), item.begin(), toupper);
					ol1.InsertItem(item);
					length += 1;
				}
			} while (item != "-1");
			break;
		case 2:
			length2 = 0;
			count = 0;
			ol2.SetCount(count);
			do
			{
				cout << "Please enter a word: ";
				cin >> item2;
				if (item2 != "-1")
				{
					transform(item2.begin(), item2.end(), item2.begin(), toupper);
					ol2.InsertItem(item2);  
					length2 += 1;
				}
			} while (item2 != "-1");
			break;          
		case 3:
			cout << "Items from list 1 and list 2 have been copied to list 3.\n";
			cout << "List 1";
			ol1.PrintList();
			cout << "List 2";
			ol2.PrintList();
			for (int i = 0; i <= length-1; i++)
			{
				value = ol1.ReturnItem();
				ol3.InsertItem(value);
			}
			for (int i = 0; i <= length2-1; i++)
			{
				value = ol2.ReturnItem();
				ol3.InsertItem(value);
			}
			
			cout << "List 3";
			ol3.PrintList();
			break;
		case 4:
			cout << "Pick a list 1,2 or 3 to delete a string from.\n Please enter a number: ";
			cin >> input;
			if (input == "1")
			{
				ol1.PrintList();
				cout << "Please enter a string.\n";
				cin >> value;
				ol1.DeleteItem(value);
				ol1.PrintList();
			}
			else if (input == "2")
			{
				ol2.PrintList();
				cout << "Please enter a string: ";
				cin >> value;
				ol2.DeleteItem(value);
				ol2.PrintList();
			}
			else if (input == "3")
			{
				ol3.PrintList();
				cout << "Please enter a string.\n";
				cin >> value;
				ol3.DeleteItem(value);
				ol3.PrintList();
			}
			else
				cout << "Please enter 1, 2 or 3.";
			break;
		case 5:
			ol1.DeleteList();
			ol2.DeleteList();
			ol3.DeleteList();
			cout << "The contents of the lists have been deleted.\n";
			break;
		case 6:
			cout << "List 1";
			ol1.PrintList();
			cout << "List 2";
			ol2.PrintList();
			cout << "List 3";
			ol3.PrintList();
		case 7:
			quitFlag = true;
			break;
		default:
			cout << "Please enter a number.";
		}

	} while (!quitFlag);
		
		return 0;
}

void doQuit(void)
{
	quitFlag = true;
	cout << " \tGoodbye!\n";
}

void displayMenu(void)
{
	cout << "----------------Assignment Five-----------------" << endl;
	cout << "\t1)Enter a word to list 1." << endl;
	cout << "\t2)Enter a word to list 2." << endl;
	cout << "\t3)Add to list 3." << endl;
	cout << "\t4)Delete item from list." << endl;
	cout << "\t5)Delete lists." << endl;
	cout << "\t6)Print Lists." << endl;
	cout << "\t7)Quit" << endl;
	cout << "------------------------------------------------" << endl;
}