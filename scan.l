%{
#include <iostream>
#include<cstdlib>
#include<string.h>
#define EOL 10
%}
letter      [a-zA-Z]

%%
[<>{}\[\]()&_.,`\'\"!\?:]	{ return (int)*yytext; }
[a-zA-Z0-9\t ]		{	return (int)*yytext;	}
\n					{	return EOL; }
.					{}
%%
int yywrap() { return 1; }

