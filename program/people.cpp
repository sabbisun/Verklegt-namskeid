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
    int byear, dyear,count=0;
    char gender;
    while(getline(ins,last))
    {
      if(last == "\0")
      {
          getline(ins,last);
      }
      getline(ins,first);
      ins >> gender;
      ins >> byear;
      ins >> dyear;
      Individual i1(last,first,gender,byear,dyear);

      person.push_back(i1);
      count ++;
    }
    cout << count << endl;
    ins.close();

}
void People::addIndi(Individual& i1)
{

    person.push_back(i1);
    saveFile("people.txt");



}
void People::saveFile(const string filename)
{
    ofstream outs;
    outs.open(filename.c_str(), ios::app);
    if(outs.fail())
    {
        cout << "Something went wrong with opening the output file" << endl;
        exit(1);
    }
    outs << person[person.size()-1].getSurname() << endl;
    outs << person[person.size()-1].getName() << endl;
    outs << person[person.size()-1].getGender() << endl;
    outs << person[person.size()-1].getBirth() << endl;
    outs << person[person.size()-1].getDeath() <<endl;
    cout << endl;
    outs.close();
}
Individual People::getIndi(const int i) const
{
    return person[i];

}
void People::sortAlpabetFront()
{
     People result(*this);
     for(unsigned int i = 1 ; i < result.person.size(); i++)
     {
         for(unsigned int j = 0; j < result.person.size(); j++)
         {
             if(result.checkIndiOrder(result.person[i],result.person[j]))
             {
                result.swap(j,i);
             }

         }
     }
    result.printVector();

}

People::People(People& p1)
{
    for(unsigned int i = 0 ; i < p1.person.size(); i++)
    {
       person.push_back(p1.person[i]);

    }
}
void People::swap(const int i, const int j)
{
    Individual temp = person[i];
    person[i] = person[j];
    person[j] = temp;
}
 void People::printVector()
{

     for(unsigned int i = 0; i < person.size(); i++)
     {
        cout << person[i];
     }

}
bool People::checkIndiOrder(const Individual& i1, const Individual& i2)
{
    string s1 = i1.getSurname();
    string s2 = i2.getSurname();
    char c1 = tolower(s1[0]);
    char c2 = tolower(s2[0]);
    int t1 = static_cast <int> (c1);
    int t2 = static_cast <int> (c2);
    return(t2>t1);

}
