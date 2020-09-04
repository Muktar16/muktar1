#include<bits/stdc++.h>
using namespace std;

char postfix[20];
char Stack[20];
int top = 0;

void push(char ch)
{
    Stack[top++]=ch;
}

char pop()
{
    return Stack[--top];
}


int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}



void infix_to_postfix(char exp[])
{
    char x;
    int i,p=0;

    for(i=0; exp[i] != '\0'; i++)
    {
        if((exp[i] >='a' && exp[i] <='z') || (exp[i] >='A' && exp[i] <='Z'))
        {
            postfix[p++] = exp[i];
        }
        else if(exp[i] == '(')
        {
            push(exp[i]);
        }
        else if(exp[i] == ')')
        {
            while((x=pop()) != '(') postfix[p++]=x;
        }
        else
        {
            while(priority(Stack[top]) > priority(exp[i]))
            postfix[p++] = pop();
            push(exp[i]);
        }
    }

    while(top != -1)  postfix[p++] = pop();
}


int main()
{
    char exp[20];
    cout<<"Enter Infix Expression: ";
    cin>>exp;

    infix_to_postfix(exp);
    cout<<"Equivalent postfix expression :  " << postfix;
    cout<<"\n\n";
}
