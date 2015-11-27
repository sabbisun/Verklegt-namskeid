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
      ins >> gender;
      ins >> byear;
      ins >> dyear;
      Individual i1(last,first,gender,byear,dyear);
      person.push_back(i1);
    }

    ins.close();

}
void People::addIndi(Individual& i1)
{

    person.push_back(i1);

}
void People::saveFile(const string filename)
{
    ofstream outs;
    outs.open(filename.c_str());
    if(outs.fail())
    {
        cout << "Something went wrong with opening the output file" << endl;
        exit(1);
    }
    for(unsigned int i = 0; i<person.size();i++)
    {
        outs << person[i].getSurname() << endl;
        outs << person[i].getName() << endl;
        outs << person[i].getGender() << endl;
        outs << person[i].getBirth() << endl;
        outs << person[i].getDeath() <<endl;

    }
}
Individual People::getIndi(const int i) const
{
    return person[i];
}
