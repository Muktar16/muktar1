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
class Stack1{
      char Array[MAX_SIZE];
      int top;

      public:
      Stack1()
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

bool isOperand(char ch);
string PostfixToInfix(string postfix);
string InfixToPrefix(string infix);
int precedence(char ch);
string Reverse(string String);

int main(void)
{
    string postfix, infix, prefix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    infix = PostfixToInfix(postfix);
    prefix = InfixToPrefix(infix);

    cout << "Equal Prefix Expression: ";
    cout << prefix;

    return 0;
}

bool isOperand(char ch)
{
    return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}

string PostfixToInfix(string postfix)
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

string InfixToPrefix(string infix)
{
    string prefix;
    int i;
    char ch;
    Stack1 S;

    //reverse infix expression
    infix = Reverse(infix);
    S.push('A');

    i = 0;
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
        {
            prefix = prefix + infix[i];
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
                prefix = prefix + ch;
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
                prefix = prefix + ch;
            }
            S.push(infix[i]);
        }

        i++;
    }

    while(S.peep() != 'A')
    {
        ch = S.peep();
        prefix = prefix + ch;
        S.pop();
    }

    //reverse prefix expression
    prefix = Reverse(prefix);

    return prefix;
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
