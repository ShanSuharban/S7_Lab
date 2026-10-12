%{
#include <stdio.h>
%}

%%
[\n] {printf ("hai");}
%%

int main ()
{
	yylex();
	return 0;
}

int yywrap ()
{
	return 1;

}
