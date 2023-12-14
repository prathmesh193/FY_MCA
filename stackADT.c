#include<stdio.h>
#define MAXSIZE 20
typedef struct
{
 	int data[MAXSIZE];
 	int top;
}STACK;
void initstack(STACK *ps)
{
 	ps->top=-1;
}
int isempty(STACK *ps)
{
 	return(ps->top==-1);
}
int isfull(STACK *ps)
{
 	return(ps->top==MAXSIZE-1);
}
int pop(STACK *ps)
{
 	return(ps->data[ps->top--]);
}
int push(STACK *ps,int n)
{
 	ps->data[++ps->top]=n;
}
int peek(STACK *ps)
{
 	return ps->data[ps->top];
}
int priority (char ch)
{
 	switch(ch)
 	{
 		case '(': return 0;
 		case '+':
 		case '-':return 1;
		case '*':
 		case '/':
 		case '%':return 2;
 		case '^':
 		case '$':return 3;
 	}
 	return 0;
}
void convert(char infix[20], char post[20])
{
 	int i,j=0;
 	char ch,ch1;
 	STACK s;
 	initstack(&s);
 	for(i=0;infix[i]!='\0';i++)
 	{
 		ch=infix[i];
 		switch(ch)
 		{
 			case '(': push(&s,ch);
 			break;
 			case '+':
 			case '-':
 			case '*':
 			case '/':
 			case '%':
 			case '^':
 			case '$':
 			while(!isempty(&s) && (priority(peek(&s))>=priority(ch)))post[j++]=pop(&s);
 				push(&s,ch);
			break;
 			case ')':
			while ((ch1=pop(&s))!='(')
 				post[j++]=ch1;
 			break;
 			default:post[j++]=ch;
 		}
 	}
 	while(!isempty(&s))
 	post[j++]=pop(&s);
	post[j]='\0';
}
main()
{
 	char infix[20],postfix[20];
 	printf("\nEnter the infix expression:");
 	scanf("%s",infix);
 	convert(infix,postfix);
 	printf("\n The postfix string is %s",postfix);
}
