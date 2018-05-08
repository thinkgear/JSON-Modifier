%{
  #include<stdio.h>
  int flag=1;
%}

%token STRING NUM BOOL

%%

P:  object 
    ;
object: '{' ob '}' 
    ;
ob: a ',' ob | a
  ;
a: n ':' v 
  ;
n: STRING 
  ;
v: STRING | NUM | BOOL | array | object 
  ;
array: '[' arr ']' 
      ;
arr: v ',' arr | v 
    ;

%%

int main(){
    yyparse();
    if(flag)
    {
       printf("success\n");
    }
}

int yyerror (const char *msg) {
	flag=0;
    printf("invalid input\n");
    return 0;
}
