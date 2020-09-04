#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#define PI 3.141592
using namespace std;

struct point{
    int x;
    int y;
};
point p[100];
stack <point> s;
double theta[100];

void swap_point(int i,int j);
void sort_points(int n);
int if_right_turn(point p, point q, point r);
int find_min_point(int n);


void sort_points(int n)
{
    theta[0]=-1;
    double x,y;
    //calculate slope for all points
    for(int i=1;i<n;i++)
    {
        x=p[i].x-p[0].x;
        y=p[i].y-p[0].y;

        theta[i] = atan(y/x);
        theta[i] = 180.0 * theta[i]/ PI;
        if(theta[i]<0.0) theta[i]=180.0+theta[i];
    }
    //sort points according to polar angle
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n-i;j++)
        {
             if(theta[j+1]<theta[j])
             {
                 swap_point(j,j+1);
                 double temp=theta[j+1];
                 theta[j+1]=theta[j];
                 theta[j]=temp;
             }
        }
    }
}

int if_right_turn(point p, point q, point r)
{
    int v=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);

    if (v<0)  return 1;
    return 0;
}

int find_min_point(int n)
{
    int min=0;
    for(int i=1;i<n;i++)
    {
        if(p[i].y<p[min].y || (p[i].y==p[min].y && p[i].x<p[min].x)) min=i;
    }
    return min;
}

point nextToTop()
{
    point p = s.top();
    s.pop();
    point rslt = s.top();
    s.push(p);
    return rslt;
}

void swap_point(int i,int j)
{
    int x=p[i].x;
    p[i].x=p[j].x;
    p[j].x=x;

    int y=p[i].y;
    p[i].y=p[j].y;
    p[j].y=y;
}

void convex_hull(int n)
{
    int min = find_min_point(n);

    swap_point(min,0);

    sort_points(n);

    int m=1;
    for (int i=1; i<n; i++)
    {
       while (i < n-1 && if_right_turn(p[0], p[i], p[i+1])==0)  i++;
       p[m] = p[i];
       m++;
    }

    if (m < 3)
    {
        cout<<"Convex Polygon Not possible";
        return;
    }

    s.push(p[0]);
    s.push(p[1]);
    s.push(p[2]);

    for (int i = 3; i < n; i++)
   {
      while(if_right_turn(nextToTop(), s.top(), p[i])!=1)    s.pop();
      s.push(p[i]);
   }


    while(!s.empty())
    {
        point a=s.top();
        cout<<"{"<<a.x<<", "<<a.y<<"}\n";
        s.pop();
    }

}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].x;
        cin>>p[i].y;
    }
    convex_hull(n);
}

