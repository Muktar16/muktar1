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
string ExpressionConverter(string postfix);

int main(void)
{
    string postfix, infix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    infix = ExpressionConverter(postfix);

    cout << "Equal Infix Expression: ";
    cout << infix;

    return 0;
}

bool isOperand(char ch)
{
    return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}

string ExpressionConverter(string postfix)
{
    int i=0;
    string ch, ch1, ch2;

    Stack S;

    while(postfix[i] != '\0')
    {
        if(isOperand(postfix[i]))
        {
            ch = postfix[i];
            S.push(ch);
        }
        else
        {
            ch1 = S.peep();
            S.pop();
            ch2 = S.peep();
            S.pop();

            S.push( "(" + ch2 + postfix[i] + ch1 + ")" );
        }
        i++;
    }

    return S.peep();
}
