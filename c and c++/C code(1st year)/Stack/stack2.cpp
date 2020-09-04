#include<iostream>
using namespace std;
#define max 100

struct Stack{
    int data[max];
    int top;
};

void push(Stack *s, int item);
int pop(Stack *s);

int main()
{
    int item,choice,n;

    Stack st;
    st.top=0;

    cout<<"\n1.Push data\nPop data\n";
    cin>>choice;

    if(choice==1)
    {
        cout<<"\nHow many data you want to push?  ";
        cin>>n;

        for(int i=0;i<n;i++)
        {

        }
    }

    push(&st,1);
    push(&st,2);
    push(&st,3);

    item=pop(&st);
    printf("%d\n",item);

    item=pop(&st);
    printf("%d\n",item);

    item=pop(&st);
    printf("%d\n",item);
}

void push(Stack *s, int item)
{
    if(s->top<max)
    {
        s->data[s->top]=item;
        s->top=s->top+1;
    }
    else printf("\nStack is Full\n");
}

int pop(Stack *s)
{
    int item;

    if(s->top==0)
    {
        printf("\nEmpty\n");
        return -1;
    }
    else
    {
        s->top=s->top-1;
        item=s->data[s->top];
    }
    return item;
}
