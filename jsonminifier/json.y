%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
   
    char *strconcat(char *str1, char *str2);
%}
%union	{
					char* value;
					struct s1 {char* name; char* value; int level;} attrib;
				}
%token <value> NUMBER
%token <value> STRING
%token true false null
%left O_BEGIN O_END A_BEGIN A_END
%left COMMA
%left COLON
%type <attrib> OBJECT ARRAY MEMBERS PAIR VALUE ELEMENTS


%%
START: 	ARRAY 	{printf("%s",$1.value);}
			| OBJECT 	{printf("%s",$1.value);}
;
OBJECT: O_BEGIN O_END {$$.value = "{}";}
			| O_BEGIN MEMBERS O_END 
					{
    				$$.value = (char *)malloc(sizeof(char)*(1+strlen($2.value)+1+1));
    				sprintf($$.value,"{%s}",$2.value);
  				}
;
MEMBERS: PAIR {$$.value = $1.value;}
			| PAIR COMMA MEMBERS
					{
    				$$.value = (char *)malloc(sizeof(char)*(strlen($1.value)+1+strlen($3.value)+1));
    				sprintf($$.value,"%s,%s",$1.value,$3.value);
  				}
;
PAIR: STRING COLON VALUE 
					{
    				$$.value = (char *)malloc(sizeof(char)*(strlen($1)+1+strlen($3.value)+1));
    				sprintf($$.value,"%s:%s",$1,$3.value);
  				}	
;
ARRAY: A_BEGIN A_END 
					{
    				$$.value = (char *)malloc(sizeof(char)*(2+1));
    				sprintf($$.value,"[]");
  				}
			| A_BEGIN ELEMENTS A_END 
					{
    				$$.value = (char *)malloc(sizeof(char)*(1+strlen($2.value)+1+1));
    				sprintf($$.value,"[%s]",$2.value);
					}
;
ELEMENTS: VALUE {$$.value = $1.value;}
			| VALUE COMMA ELEMENTS 
			{
    			$$.value = (char *)malloc(sizeof(char)*(strlen($1.value)+1+strlen($3.value)+1));
    			sprintf($$.value,"%s,%s",$1.value,$3.value);
  		}
;
VALUE: STRING {$$.value=$1;}
			| NUMBER {$$.value=$1;}
			| OBJECT {$$.value=$1.value;}
			| ARRAY {$$.value=$1.value;}
			| true {$$.value="true";}
			| false {$$.value="false";}
			| null {$$.value="null";}
;
%%

int main()
{
   printf("\n");
   yyparse();
   printf("\n");
   return 0;
}
int yywrap()
{
   return 1;
}
int yyerror (const char*s) {
   fprintf (stderr, "%s\n", s);
   return 0;
}
char *strconcat(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *str3 = (char *)malloc(sizeof(char)*(len1+len2+1));
    strcpy(str3,str1);
    strcpy(&(str3[len1]),str2);
    return str3;
}
