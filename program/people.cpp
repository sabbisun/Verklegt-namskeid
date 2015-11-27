#include "people.h"

People::People(const string filename)
{
    ifstream ins;
    ins.open(filename.c_str());
    if(ins.fail())
    {
        cout << "Something went wrong while opening the file" << endl;
        exit(1);
    }
    string first ,last;
    int byear, dyear;
    char gender;
    while(!ins.eof())
    {
      getline(ins,last);
      getline(ins,first);
      cin >> gender;
      cin >> byear;
      cin >> dyear;
      Individual i1(last,first,gender,byear,dyear);
      person.push_back(i1);
    }

    ins.close();

}

