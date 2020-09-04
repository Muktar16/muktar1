#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int item;
    vector<int>MyVector;

    for(int i=10;i<=15;i++)
    {

        MyVector.push_back(i);
    }

    MyVector.erase(MyVector.begin()+2);
    vector<int> :: iterator vecIterator;

    for(vecIterator=MyVector.begin();vecIterator!=MyVector.end();vecIterator++)
    {
        cout<<endl<<*vecIterator<<endl;
    }

    MyVector.erase(MyVector.begin()+2);
    for(int i=0;i<MyVector.size();i++)
    {
        cout<<endl<<MyVector[i]<<endl;
    }

    return 0;
}

