
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
string PrefixToInfix(string prefix);
string InfixToPostfix(string infix);
string Reverse(string prefix);
int precedence(char ch);

int main(void)
{
    string prefix, infix, postfix;
    cout << "Enter prefix Expression: ";
    cin >> prefix;

    infix = PrefixToInfix(prefix);
    postfix = InfixToPostfix(infix);

    cout << "Equal Postfix Expression: ";
    cout << postfix;

    return 0;
}

bool isOperand(char ch)
{
    return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}

string PrefixToInfix(string prefix)
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

string InfixToPostfix(string infix)
{
    string postfix;
    int i;
    char ch;
    Stack1 S1;

    S1.push('A');

    i = 0;
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
        {
            postfix = postfix + infix[i];
        }
        else if(infix[i] == '(')
        {
            S1.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(S1.peep() != '(' && S1.peep() != 'A')
            {
                ch = S1.peep();
                S1.pop();
                postfix = postfix + ch;
            }
            //special case
            if(S1.peep()=='(')
            {
                char c = S1.peep();
                S1.pop();
            }
        }
        else
        {
            while( S1.peep() != 'A' && (precedence(S1.peep()) >= precedence(infix[i])) )
            {
                ch = S1.peep();
                S1.pop();
                postfix = postfix + ch;
            }
            S1.push(infix[i]);
        }

        i++;
    }

    while(S1.peep() != 'A')
    {
        ch = S1.peep();
        postfix = postfix + ch;
        S1.pop();
    }

    return postfix;
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


