%{
  #include<stdio.h>
  #include<string.h>
  #include<stdlib.h>
  #include<malloc.h>
  char* substring(char*);
  char* strconcat(char*,char*);
  int flag=1;
  int i,j,k,length;
  char *value[100];
%}
%code requires{
	struct np{
		char* val[100];
		int len;
	};
}
%union{
	char* str;
	struct np p;
}
%token<str> STRING NUM BOOL
%type<p> array arr object ob a v
%type<str> n
%%

P:  object {
				for(i=0;i<$1.len;i++)
					value[i]=$1.val[i];
				length=$1.len;
			}
    ;
object: '{' ob '}' {
					  	$$.val[0]="{";
                     	for(i=0;i<$2.len;i++)
                     		$$.val[i+1]=strconcat("    ",$2.val[i]);
                     	$$.val[i+1]="}";
                     	$$.len=$2.len+2;		                       
                    }
    ;
ob: a ',' ob {
             	 for(i=0;i<$1.len;i++)
                  	$$.val[i]=$1.val[i];
                  $$.val[i-1]=strconcat($$.val[i-1],",");
                  for(j=i,k=0;k<$3.len;j++,k++)
                  	$$.val[j]=$3.val[k];
                  $$.len=$1.len+$3.len; 
              }
  | a {
        $$=$1;
      }
  ;
a: n ':' v {  	
				$$=$3;
				$$.val[0]=strconcat($1,":");
				$$.val[0]=strconcat($$.val[0],$3.val[0]);
            }
  ;
n: STRING {$$=substring($1);}
  ;
v: STRING {
            $$.val[0]=substring($1);
            $$.len=1;
          }
  | NUM {
          	$$.val[0]=$1;
            $$.len=1;
        }
  | BOOL {
            $$.val[0]=$1;
            $$.len=1;
          }
  | array {
           	$$=$1;
          }
  | object {
           	 $$=$1;
           }
  ;
array: '[' arr ']' {
                     	$$.val[0]="[";
                     	for(i=0;i<$2.len;i++)
                     		$$.val[i+1]=strconcat("    ",$2.val[i]);
                     	$$.val[i+1]="]";
                     	$$.len=$2.len+2;
                    }
      ;
arr: v ',' arr {
                  for(i=0;i<$1.len;i++)
                  	$$.val[i]=$1.val[i];
                  $$.val[i-1]=strconcat($$.val[i-1],",");
                  for(j=i,k=0;k<$3.len;j++,k++)
                  	$$.val[j]=$3.val[k];
                  $$.len=$1.len+$3.len;     	
                }
    | v {
          	$$=$1;
        }
    ;

%%

int main(){
    yyparse();
    if(flag)
    {
        for(i=0;i<length;i++)
        	printf("%s\n",value[i]);
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
