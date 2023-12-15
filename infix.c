#define SIZE 50
#include <ctype.h>

char s[SIZE];
int top=-1; 

void push(char elem)
{
top=top+1;
s[top]=elem;
}

char pop()
{
return(s[top--]);
}

int pr(char elem)
{ 
switch(elem)
{
case '#': return 0;
case '(': return 1;
case '+':
case '-': return 2;
case '*':
case '/': return 3;
case '^': return 4;
}
return 0;
}

void main()
{
char infx[50],pofx[50],ch,elem;
int i=0,k=0;
//clrscr();
printf("\n\nRead the Infix Expression ? ");
scanf("%s",infx);
push('#');
while( (ch=infx[i++]) != '\0')
{
if( ch == '(')
push(ch);
else if(isalnum(ch))
pofx[k++]=ch;
else if( ch == ')')
{while( s[top] != '(')
pofx[k++]=pop();
elem=pop(); 
}
else
{ 
while( pr(s[top]) >= pr(ch) )
pofx[k++]=pop();
push(ch);
}
}
while( s[top] != '#') // Pop from stack till empty
pofx[k++]=pop();
pofx[k]='\0'; // Make pofx as valid string
printf("\n\n Postfix Expn: %s\n",pofx);
getch();
}
