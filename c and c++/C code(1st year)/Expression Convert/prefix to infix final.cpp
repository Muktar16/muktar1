#include<bits/stdc++.h>

using namespace std;


int top = 0;

string Stack[20];

void push(string str)
{
    Stack[top++] = str;
}

string pop()
{
    return Stack[--top];
}

void prefix_to_infix(string exp)
{
    string op1,op2,strtemp;

    int i=exp.length()-1;
    while(i>=0)
    {
        if((exp[i] >='a' && exp[i] <='z') || (exp[i] >='A' && exp[i] <='Z'))
        {
            strtemp = exp[i];
            push(strtemp);
        }
        else
        {
            op1 = pop();
            op2 = pop();
            push(")" + op2 + exp[i] + op1 + "(");
        }
        i--;
    }
}


string reversing()
{
    string str;
    str = pop();
    int l = str.length();

    int i,j;

    for(i=0,j=l-1;i<j;i++,j--)
    {
        char ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }

    return str;
}

int main()
{
    string exp,infix;
    cout<<"Enter prefix Expression : ";
    cin>>exp;

    prefix_to_infix(exp);

    cout<<"\nEquivalent infix expression : ";
    infix = reversing();
    cout<<infix;
}
