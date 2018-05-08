%{
  #include<stdio.h>
  #include<string.h>
  #include<stdlib.h>
  #include<malloc.h>
  char* substring(char*);
  char* strconcat(char*,char*);
  char s[20];
  int flag=1;
  int arrindex=0;
  int i,j,k,length;
  char *value[100]; 
%}
%code requires{
	struct np{
		char* val[50];
		int type,len;
	};
	struct np2{
		char* val[50];
		int len;
	};
}
%union{
	char* str;
	struct np p;
	struct np2 q;
}
%token<str> STRING NUM BOOL
%type<str> n
%type<q> array arr object ob a
%type<p> v;
%%

P:  object {
				for(i=0;i<$1.len;i++)
            		value[i]=$1.val[i];
            	length=$1.len;
			}
    ;
object: '{' ob '}' {
					  $$=$2;					                      
                    }
    ;
ob: a ',' ob {
             	for(i=0;i<$1.len;i++)
             		$$.val[i]=$1.val[i];
             	for(j=i,k=0;k<$3.len;k++,j++)
             		$$.val[j]=$3.val[k];
             	$$.len=$1.len+$3.len;  
              }
  | a {
        $$=$1;
      }
  ;
a: n ':' v {  	
				if($3.type==4)
				{
					for(i=0;i<$3.len;i++)
					{
						$$.val[i]=strconcat($1,".");
						$$.val[i]=strconcat($$.val[i],$3.val[i]);
					}
				}
				else if($3.type==1)
				{
					for(i=0;i<$3.len;i++)
					{
						$$.val[i]=strconcat($1,"  :  ");
						$$.val[i]=strconcat($$.val[i],$3.val[i]);
					}
				}
				$$.len=$3.len;
            }
  ;
n: STRING {$$=substring($1);}
  ;
v: STRING {
            $$.val[0]=substring($1);
            $$.len=1;
            $$.type=1;
          }
  | NUM {
          	$$.val[0]=$1;
            $$.len=1;
            $$.type=1;
        }
  | BOOL {
            $$.val[0]=$1;
            $$.len=1;
            $$.type=1;
          }
  | array {
            $$.type=4;
            $$.len=$1.len;
            for(i=0;i<$1.len;i++)
            	$$.val[i]=$1.val[i];
          }
  | object {
           	 $$.type=4;
           	 $$.len=$1.len;
             for(i=0;i<$1.len;i++)
           		$$.val[i]=$1.val[i]; 
           }
  ;
array: '[' arr ']' {
                     $$=$2;
                     arrindex=0;
                    }
      ;
arr: v ',' arr {
                 	if($1.type==4)
                 	{
	                 	for(i=0;i<$1.len;i++)
	             		{	
	             			$$.val[i]=itoa(arrindex,s,10);
         					$$.val[i]=strconcat($$.val[i],".");
         					$$.val[i]=strconcat($$.val[i],$1.val[i]);
	             		}
	             	}
	             	else if($1.type==1)
	             	{
	             		for(i=0;i<$1.len;i++)
	             		{	
	             			$$.val[i]=itoa(arrindex,s,10);
         					$$.val[i]=strconcat($$.val[i],"  :  ");
         					$$.val[i]=strconcat($$.val[i],$1.val[i]);
	             		}
	             	}
             		for(j=i,k=0;k<$3.len;k++,j++)
             			$$.val[j]=$3.val[k];
             		$$.len=$1.len+$3.len;
             		arrindex++;
                }
    | v {
          	if($1.type==4)
          	{
          		for(i=0;i<$1.len;i++)
         		{	
         			$$.val[i]=itoa(arrindex,s,10);
         			$$.val[i]=strconcat($$.val[i],".");
         			$$.val[i]=strconcat($$.val[i],$1.val[i]);
         		}
          	}
          	else if($1.type==1)
          	{
          		for(i=0;i<$1.len;i++)
         		{	
         			$$.val[i]=itoa(arrindex,s,10);
         			$$.val[i]=strconcat($$.val[i],"  :  ");
         			$$.val[i]=strconcat($$.val[i],$1.val[i]);
         		}
          	}
          	arrindex++;
          	$$.len=$1.len;
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
