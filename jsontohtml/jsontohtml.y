%{
  #include<stdio.h>
  #include<string.h>
  #include<stdlib.h>
  #include<malloc.h>
  char* substring(char*);
  char* strconcat(char*,char*);
  int flag=1;
  char *value;
%}

%union{
	char* str;
}
%token<str> STRING NUM BOOL
%type<str> array arr object ob a n v
%%

P:  object {
				value=strconcat("<html><body>",$1);
				value=strconcat(value,"</body></html>");
			}
    ;
object: '{' ob '}' {
					  $$=strconcat("<table border='1' bordercolor='black'>",$2);
					  $$=strconcat($$,"</table>");					                      
                    }
    ;
ob: a ',' ob {
             	$$=strconcat($1,$3); 
              }
  | a {
        $$=$1;
      }
  ;
a: n ':' v {  	
				$$=strconcat("<tr><td style='padding:5px'>",$1);
				$$=strconcat($$,"</td><td style='padding:5px'>");
				$$=strconcat($$,$3);
				$$=strconcat($$,"</td></tr>");
            }
  ;
n: STRING {$$=substring($1);}
  ;
v: STRING {
   			$$=substring($1);			         
          }
  | NUM {
          $$=$1;	
        }
  | BOOL {
            $$=$1;
          }
  | array {
            $$=$1;
          }
  | object {
           	 $$=$1;
           }
  ;
array: '[' arr ']' {
                   	  $$=strconcat("<table border='1' bordercolor='black'>",$2);
					  $$=strconcat($$,"</table>");	  
                    }
      ;
arr: v ',' arr {
                 	$$=strconcat("<tr><td style='padding:5px'>",$1);
                 	$$=strconcat($$,"</td></tr>");
                 	$$=strconcat($$,$3);
                }
    | v {
          	$$=strconcat("<tr><td style='padding:5px'>",$1);
            $$=strconcat($$,"</td></tr>");
        }
    ;

%%

int main(){
    yyparse();
    if(flag)
    {
        printf("%s\n",value);
    }
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

char* substring(char*s)
{
	char *str = (char *)malloc(sizeof(char)*(strlen(s)+1-2));
	int i;
	for(i=0;i<strlen(s)-2;i++)
	{
		*(str+i)=*(s+1+i);
	}
	*(str+i) = '\0';
	return str;
}

int yyerror (const char *msg) {
	flag=0;
    printf("invalid input\n");
    return 0;
}
