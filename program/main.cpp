#include <QCoreApplication>
#include <iostream>
#include "people.h"

const string FILENAME = "people.txt";
using namespace std;

bool legalAns(char ans);
//checks if answear fits choices, if false then programs ends
void ask();
//asks what should be done with the list
void menu(char ans, People& list);
//call for changes to the list

int main()
{
    People list(FILENAME);
    char choice;

    do {
        ask();
        cin >> choice;
        menu(choice, list);
    } while (legalAns(choice));

}

bool legalAns(char ans) {
    return (ans == 'A' || ans == 'a' || ans == 'B' || ans == 'b'
            || ans == 'C' || ans == 'c' || ans == 'D' || ans == 'd');
}

void ask() {
    cout << "Do you want to: " << endl;
    cout << "(A) Add to list? " << endl;
    cout << "(B) Search list? " << endl;
    cout << "(C) Print list? " << endl; //fyrst spurt um sort svo print
    cout << "(D) Change list? " << endl;
}

void menu(char ans, People& list)
{
    switch(ans) {
        case 'a':
        case 'A':   {
                    cin.ignore();
                    Individual id;
                    cin >> id;
                    list.addIndi(id);
                    }
                    break;
        case 'b':
        case 'B':   list.searchMenu();
                    break;
        case 'c':
        case 'C':   {list.sortMenu();
                    list.printVector();}
                    break;
        case 'd':
        case 'D':   //..
                    break;
        default:;
    }
}

