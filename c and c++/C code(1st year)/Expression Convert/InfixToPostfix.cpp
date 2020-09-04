#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100

class Stack{
      char Array[MAX_SIZE];
      int top;

      public:
      Stack()
      {
          top=-1;
      }
      void push(char ch)
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
      char peep()
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
string ExpressionConverter(string infix);
bool isOperand(char ch);
int precedence(char ch);

int main(void)
{
    string infix, postfix;
    cout << "Enter An Infix Expression: ";
    cin >> infix;

    postfix = ExpressionConverter(infix);

    cout << "Equivalent Postfix Expression: " << postfix << endl;

    return 0;
}

string ExpressionConverter(string infix)
{
    string postfix;
    int i;
    char ch;
    Stack S;

    S.push('A');

    i = 0;
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
        {
            postfix = postfix + infix[i];
        }
        else if(infix[i] == '(')
        {
            S.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(S.peep() != '(' && S.peep() != 'A')
            {
                ch = S.peep();
                S.pop();
                postfix = postfix + ch;
            }

            //special case
            if(S.peep()=='(')
            {
                char c = S.peep();
                S.pop();
            }
        }
        else
        {
            while( S.peep() != 'A' && (precedence(S.peep()) >= precedence(infix[i])) )
            {
                ch = S.peep();
                S.pop();
                postfix = postfix + ch;
            }
            S.push(infix[i]);
        }

        i++;
    }

    while(S.peep() != 'A')
    {
        ch = S.peep();
        postfix = postfix + ch;
        S.pop();
    }

    return postfix;
}

bool isOperand(char ch)
{
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
}


int precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;

        default:
            return -1;
    }
}




