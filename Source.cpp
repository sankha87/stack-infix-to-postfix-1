#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
char stack[30];
int top = -1;
void push(char ch)
{
	top = top++;
	stack[top] = ch;
}
int pop()
{
	int val = stack[top];
	top = top--;
	return val;
}
int priority(char ch)
{
	if (ch == '(')
		return 0;
	if (ch == '+' || ch == '-')
		return 1;
	if (ch == '*' || ch == '/')
		return 2;
}
void main()
{
	char exp[20];
	char *e, x;
	printf("Enter the expression : ");
	scanf("%s", exp);
	e = exp;
	while (*e != '\0')
	{
		if (isalnum(*e))
			printf("%c", *e);
		else if ((*e) == '(')
			push(*e);
		else if ((*e) == ')')
		{
			while ((x = pop()) != '(')
				printf("%c", x);
		}
		else
		{
			while (priority(stack[top]) >= priority(*e))
			{
				printf("%c", pop());
			}
			push(*e);
		}
		e++;
	}
	while (stack[top] != '\0')
		printf("%c", pop());

_getch();
}