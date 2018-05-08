%{
    #include<stdio.h>
    #include<string.h>
    #include "json.tab.h"
    
    char *strclone(char *str);
   
%} 
DIGIT1to9 [1-9]
DIGIT [0-9]
DIGITS {DIGIT}+
INT {DIGIT}|{DIGIT1to9}{DIGITS}|-{DIGIT}|-{DIGIT1to9}{DIGITS}
FRAC [.]{DIGITS}
EXP {E}{DIGITS}
E [eE][+-]?
HEX_DIGIT [0-9a-f]
NUMBER {INT}|{INT}{FRAC}|{INT}{EXP}|{INT}{FRAC}{EXP}
UNESCAPEDCHAR [ -!#-\[\]-~]
ESCAPEDCHAR \\["\\bfnrt/]
UNICODECHAR \\u{HEX_DIGIT}{HEX_DIGIT}{HEX_DIGIT}{HEX_DIGIT}
CHAR {UNESCAPEDCHAR}|{ESCAPEDCHAR}|{UNICODECHAR}
CHARS {CHAR}+
DBL_QUOTE ["]
%%
{DBL_QUOTE}{DBL_QUOTE} |
{DBL_QUOTE}{CHARS}{DBL_QUOTE} {
    yylval.value=strclone(yytext);
    return STRING;
};

{NUMBER} {
    yylval.value=strclone(yytext);
    return NUMBER;
}

true {return true;}
false {return false;};
null {return null;};
\{ {return O_BEGIN;};
\} {return O_END;};
\[ {return A_BEGIN;};
\] {return A_END;};
, {return COMMA;};
: {return COLON;};
[ \t\n]+ /* ignore whitespace */;
. {
    printf("Syntax Error !! \nUnexpected: %c\nExiting...\n",*yytext);
    exit(0);
	}

%%

char *strclone(char *str)
{
    int len = strlen(str);
    char *clone = (char *)malloc(sizeof(char)*(len+1));
    strcpy(clone,str);
    return clone;
}

