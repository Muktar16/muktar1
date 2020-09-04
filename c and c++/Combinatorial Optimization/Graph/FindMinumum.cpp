#include <iostream>
#include <string>
using namespace std;

int FindMin(string a,string b)
{
    int c = stoi(a);
    int d = stoi(b);

    if(c>d) return d;
    return c;
}

int FindMin(int a,int b)
{
    if(a<b) return a;
    return b;
}

double FindMin(double a,double b)
{
    if(a<b) return a;
    return b;
}


