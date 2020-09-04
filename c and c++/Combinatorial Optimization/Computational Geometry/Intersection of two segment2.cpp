#include<bits/stdc++.h>
using namespace std;
struct point{
    int x,y;
};
point p[4];
int cross_product(point a,point b,point c)
{
    int d1,d2,d3,d4;
    d1 = c.x-a.x;
    d2 = c.y-a.y;
    d3 = b.x-a.y;
    d4 = b.x-a.y;
    return (d4*d1-d2*d3);
}

int if_intersect()
{
    int a,b,c,d;
    a = cross_product(p[2],p[3],p[0]);
    b = cross_product(p[2],p[3],p[1]);
    c = cross_product(p[0],p[1],p[2]);
    d = cross_product(p[0],p[1],p[3]);

    if(((a>0 && b< 0) || (a<0 && b>0)) && ((c>0 && d<0) || (c<0 && d>0))) return 1;

    else if(a==0&& cross_product(p[3],p[4],p[1]))  return 1;
    else if(b==0&& cross_product(p[3],p[4],p[2]))    return 1;
    else if(c==0&& cross_product(p[1],p[2],p[3]))    return 1;
    else if(d==0&& cross_product(p[1],p[2],p[4]))    return 1;
    else return 0 ;
}

int main()
{
    for(int i=0;i<4;i++)
    {
        cin>>p[i].x;
        cin>>p[i].y;
    }
    if(if_intersect()==1) cout<< "Intersects";
    else cout<< "No intersection";
}
