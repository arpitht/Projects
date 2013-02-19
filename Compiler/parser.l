%{
#include<stdio.h>
#include<string.h>
#include "y.tab.h"
%}
digit [0-9]
letter [A-Za-z_]
%%
{digit}+ {	yylval.num=atoi(yytext);
			return NUM;
			}
">=" return GE;
"<=" return LE;
"==" return EQ;
"!=" return NE;
[-+*/();=\[\]><,{}]  return *yytext;
decl return DECL;
enddecl return ENDDECL;
begin return BEGN;
end return END;
int return INTEGER;
bool return BOOLEAN;
read return READ;
write return WRITE;
true return TRUE;
false return FALSE;
while return WHILE;
endwhile return ENDWHILE;
if return IF;
then return THEN;
else return ELSE;
endif return ENDIF;
main return MAIN;
return return RETN;
{letter}({letter}|{digit})* {strcpy(yylval.ch,yytext);
							
						return ID;
						}
[\t\n ] ;
. {printf("Unknown Symbol");}

%%
int yywrap(void)	{	return 1;	}

