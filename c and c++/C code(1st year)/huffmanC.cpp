#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct node
{
        char ch;
        int freq;
        struct node *left;
        struct node *right;
}node;

node * heap[100];
int heap_size=0;

void Insert(node * NewNode);
void print(node *temp,char *code);
node * DeleteMin();


int main()
{

    heap[0] = new node;
    heap[0]->freq = 0;
    int n ;

    while(1)
    {

        cout<<"ENTER THE NUMBER OF CHARACTER:(1-100) ";
        cin>>n;
        if(n>=100 || n<=0) return 0;
        cout<<"\nENTER "<<n<<" CHARACTERS WITH THEIR FREQUENCIES: (e.g: A 45)   \n";
        char ch;
        int freq,i;

        for(i=0;i<n;i++)
        {
                cin>>ch;
                cin>>freq;

                node * temp = new node;
                temp -> ch = ch;
                temp -> freq = freq;
                temp -> left = temp -> right = NULL;

                Insert(temp);
        }

        if(n==1)
        {
                cout<<"char "<<ch <<"code 0\n";
                return 0;
        }

        for(i=0;i<n-1 ;i++)
        {
                node * left = DeleteMin();
                node * right = DeleteMin();
                node * temp = new node;
                temp -> ch = 0;
                temp -> left = left;
                temp -> right = right;
                temp -> freq = left->freq + right -> freq;
                Insert(temp);
        }

        node *tree = DeleteMin();
        char code[10];
        code[0] = '\0';
        cout<<"\n  Char\t  Code\n  =====   =====\n";
        print(tree,code);
        cout<<"\n";
    }

}



void Insert(node * NewNode)
{
        heap_size++;
        heap[heap_size] = NewNode;
        int now = heap_size;

        while(heap[now/2]->freq > NewNode->freq)
        {
                heap[now] = heap[now/2];
                now /= 2;
        }
        heap[now] = NewNode;
}



node * DeleteMin()
{
        node * minNewNode,*lastNewNode;
        int child,now;
        minNewNode = heap[1];
        lastNewNode = heap[heap_size--];

        for(now=1; now*2<=heap_size ;now=child)
        {
             child = now*2;
                 if(child != heap_size && heap[child+1]->freq < heap[child] -> freq )
                {
                        child++;
                }
                if(lastNewNode -> freq > heap[child] -> freq)
                {
                        heap[now] = heap[child];
                }
                else
                {
                        break;
                }
        }
        heap[now] = lastNewNode;
        return minNewNode;
}


void print(node *temp,char *code)
{

    if(temp->left==NULL && temp->right==NULL)
    {
            cout<<"   "<<temp->ch<<"\t   "<<code<<endl;
            return;
    }
    int length = strlen(code);
    char leftcode[10],rightcode[10];
    strcpy(leftcode,code);
    strcpy(rightcode,code);
    leftcode[length] = '0';
    leftcode[length+1] = '\0';
    rightcode[length] = '1';
    rightcode[length+1] = '\0';
    print(temp->left,leftcode);
    print(temp->right,rightcode);
}

