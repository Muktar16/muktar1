#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int top = 0;

typedef struct node
{
	char ch;
	node *next;
	node *prev;
};

node *Stack[20];

void push(node *str)
{
    Stack[top++] = str;
}

node *pop()
{
    return Stack[--top];
}

void postfix_to_infix(char exp[])
{
	node *op1, *op2;
	node *temp;
	int i;
	for (i=0;exp[i]!='\0';i++)
	if (exp[i] >= 'a'&& exp[i] <= 'z'|| exp[i] >= 'A' && exp[i] <= 'Z')
	{
		temp = (node*)malloc(sizeof(node));
		temp->ch = exp[i];
		temp->next = NULL;
		temp->prev = NULL;
		push(temp);
	}
	else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
	{
		op1 = pop();
		op2 = pop();
		temp = (node*)malloc(sizeof(node));
		temp->ch = exp[i];
		temp->next = op1;
		temp->prev = op2;
		push(temp);
	}
}

void display(node *temp)
{
	if (temp != NULL)
	{
		display(temp->prev);
		printf("%c", temp->ch);
		display(temp->next);
	}
}

int main()
{
	char exp[50];
	printf("Enter the postfix expression : ");
	scanf("%s", exp);

	postfix_to_infix(exp);

	printf("\nThe Equivalent Infix expression is: ");
	display(pop());
	printf("\n\n");

}
