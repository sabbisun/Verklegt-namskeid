#include <QCoreApplication>
#include<iostream>
#include "people.h"

const string FILENAME = "people.txt";

using namespace std;

int main()
{
    People p1(FILENAME);
    Individual i1;
    cin >> i1;
    p1.addIndi(i1);
    p1.saveFile(FILENAME);
    cout << "blah";

}

