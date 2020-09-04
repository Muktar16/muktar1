#include<iostream>
using namespace std;

int x1,x2,x3,x4;

int find_cross_product(int x1,int x2,int y1,int y2)
{
    return (x1*y2)-(x2*y1);
}

int main()
{
    int a,b,c,d;
    int p[4][2];
    for(int i=0;i<4;i++)
    {
        cin>>p[i][0];
        cin>>p[i][1];
    }
    a=find_cross_product(p[0][0]-p[3][0], p[2][0]-p[3][0], p[0][1]-p[3][1], p[2][1]-p[3][1]);
    b=find_cross_product(p[1][0]-p[3][0], p[2][0]-p[3][0], p[1][1]-p[3][1], p[2][1]-p[3][1]);
    c=find_cross_product(p[2][0]-p[1][0], p[0][0]-p[1][0], p[2][1]-p[1][1], p[0][1]-p[1][1]);
    d=find_cross_product(p[3][0]-p[1][0], p[0][0]-p[1][0], p[3][1]-p[1][1], p[0][1]-p[1][1]);

    if((a>0 && b>0) || (a<0 && b<0) || (c>0 && d>0) || (c<0 && d<0)) cout<<"Dose't Intersect";
    else cout<<"Intersects";
}
