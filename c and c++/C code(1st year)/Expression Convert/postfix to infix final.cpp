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

void postfix_to_infix(string exp)
{
    string op1,op2,strtemp;

    int i=0;
    while(exp[i] != '\0')
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
            push("(" + op2 + exp[i] + op1 + ")");
        }
        i++;
    }
}

void display()
{
    cout<<pop();
}

int main()
{
    string exp;
    cout<<"Enter postfix Expression : ";
    cin>>exp;

    postfix_to_infix(exp);

    cout<<"\nEquivalent infix expression : ";
    display();
    cout<<"\n\n";
}
