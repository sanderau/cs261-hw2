/*stackapp.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
param: s pointer to a string 
pre: s is not null
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s+i);
	if ( c == '\0' )
		return '\0';
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
param: s pointer to a string 
pre: s is not null
post:
*/
int isBalanced(char* s)
{

	char ch;  /*stores the current character from the input string*/

	DynArr *stack;
	stack=newDynArr(5);/*initialize stack with capacity = 5*/


	if (s && strlen(s))
	while(1)
	{
		ch=nextChar(s);

		if(ch==0 || ch=='\0')
			break;

 
		if(ch=='(' || ch=='[' || ch=='{' )
			pushDynArr(stack,ch);

		else
		{
			if(ch == ')' && topDynArr(stack) != ')')
			{
				freeDynArr(stack);
				return 0;
			}	

			if(ch == ')' && topDynArr(stack) == ')')
			{
				popDynArr(stack);
			}
	
			if(ch == '}' && topDynArr(stack) != '{')
			{
				freeDynArr(stack);
				return 0;
			}	

			if(ch == '}' && topDynArr(stack) == '{')
			{
				popDynArr(stack);
			}	

			if(ch == ']' && topDynArr(stack) != '[')
			{
				freeDynArr(stack);
				return 0;
			}	

			if(ch == ']' && topDynArr(stack) == '[')
			{
				popDynArr(stack);
			}	
		}

	}


	ch = topDynArr(stack);

	freeDynArr(stack);


	if(ch == 0)
		return 1;

	else
		return 0;
}

int main(int argc, char* argv[])
{

	char* s=argv[1];
	
/*	char s[]="()+x+r*{{{((--{{[()[]]}}))}}}"; */
	

	int res;

	printf("Assignment 2\n");

	if(argc==2)
	{
		res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	}
	else
		printf("Please enter a string to be evaluated.\n");


	return 0;
}

