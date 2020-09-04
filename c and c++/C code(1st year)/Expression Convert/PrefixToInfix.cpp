
#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100

class Stack{
      string Array[MAX_SIZE];
      int top;

      public:
      Stack()
      {
          top = -1;
      }
      void push(string ch)
      {
          if(top != MAX_SIZE-1)
          {
              Array[++top]=ch;
          }
          else
          {
              cout << "\aStack Overflow!!" << endl;
          }
      }
      void pop()
      {
          if(top != -1)
          {
              top = top - 1;
          }
          else
          {
             cout << "\aStack Underflow!!" << endl;
          }
      }
      string peep()
      {
          if(top !=-1 )
          {
              return Array[top];
          }
          else
          {
             cout << "\aStack underflow!!" << endl;
          }
      }
};

bool isOperand(char ch);
string ExpressionConverter(string prefix);
string Reverse(string prefix);

int main(void)
{
    string prefix, infix;
    cout << "Enter prefix Expression: ";
    cin >> prefix;

    infix = ExpressionConverter(prefix);

    cout << "Equal Infix Expression: ";
    cout << infix;

    return 0;
}

bool isOperand(char ch)
{
    return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}

string ExpressionConverter(string prefix)
{
    int i=0;
    string ch, ch1, ch2;

    prefix = Reverse(prefix);
    Stack S;

    while(prefix[i] != '\0')
    {
        if(isOperand(prefix[i]))
        {
            ch = prefix[i];
            S.push(ch);
        }
        else
        {
            ch1 = S.peep();
            S.pop();
            ch2 = S.peep();
            S.pop();

            S.push( "(" + ch2 + prefix[i] + ch1 + ")" );
        }
        i++;
    }

    string infix = Reverse(S.peep());
    S.pop();
    S.push(infix);

    return S.peep();
}

string Reverse(string infix)
{
    int i, j, l;
    char temp;
    l = infix.length();

    for(i=0,j=l-1;  i<=l/2;  i++,j--)
    {
        if(infix[j]=='(')
        {
            infix[j]=')';
        }
        else if(infix[j]==')')
        {
            infix[j]='(';
        }

        temp = infix[j];

        if(infix[i]=='(')
        {
            infix[i]=')';
        }
        else if(infix[i]==')')
        {
            infix[i]='(';
        }

        infix[j]=infix[i];
        infix[i]=temp;
    }

    return infix;
}
