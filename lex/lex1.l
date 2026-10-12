%{
#include <stdio.h>
int lc=0 ,sc=0 ,tc=0,ch=0;
%}

%%
\n lc++;
([ ])+ sc++;
\t tc++; 
. ch++; 
%%

int main(){
	yylex();
	printf("\n No.of lines =%d",lc);
	printf("\n No.of spaces =%d",sc);
	printf("\n No.of tabs =%d",tc);
	printf("\n No.of other characters =%d",ch);

	return 0;
	}
int yywrap() 
	{return 1;}
