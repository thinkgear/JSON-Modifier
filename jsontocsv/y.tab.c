#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "jsontocsv.y"

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
#line 17 "jsontocsv.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
	char* str;
	struct np{char* val[50];int type,len;}p;
	struct np2{char* val[50];int len;}q;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 45 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define STRING 257
#define NUM 258
#define BOOL 259
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    4,    5,    5,    6,    1,    7,    7,    7,    7,
    7,    2,    3,    3,
};
static const short yylen[] = {                            2,
    1,    3,    3,    1,    3,    1,    1,    1,    1,    1,
    1,    3,    3,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    1,    6,    0,    0,    0,    0,    2,    0,
    7,    8,    9,    0,   10,   11,    5,    3,    0,    0,
   12,    0,   13,
};
static const short yydgoto[] = {                          2,
    5,   15,   19,   16,    6,    7,   20,
};
static const short yysindex[] = {                      -122,
 -255,    0,    0,    0,  -55, -121,  -39,  -91,    0, -255,
    0,    0,    0,  -91,    0,    0,    0,    0,  -87,  -37,
    0,  -91,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0, -117,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -84,
    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  -12,   11,    2,    0,    5,
};
#define YYTABLESIZE 168
static const short yytable[] = {                         14,
    1,    4,    8,    9,   10,   21,   22,    4,   14,   23,
    3,   18,   17,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   11,   12,   13,
};
static const short yycheck[] = {                         91,
  123,  257,   58,  125,   44,   93,   44,  125,   93,   22,
    0,   10,    8,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  123,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 259
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,"':'",0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"STRING",
"NUM","BOOL","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : P",
"P : object",
"object : '{' ob '}'",
"ob : a ',' ob",
"ob : a",
"a : n ':' v",
"n : STRING",
"v : STRING",
"v : NUM",
"v : BOOL",
"v : array",
"v : object",
"array : '[' arr ']'",
"arr : v ',' arr",
"arr : v",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 152 "jsontocsv.y"


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

void yyerror (const char *msg) {
	flag=0;
    printf("invalid input\n");
    //return 0;
}
#line 259 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 28 "jsontocsv.y"
	{
				for(i=0;i<yystack.l_mark[0].q.len;i++)
            		value[i]=yystack.l_mark[0].q.val[i];
            	length=yystack.l_mark[0].q.len;
			}
break;
case 2:
#line 34 "jsontocsv.y"
	{
					  yyval.q=yystack.l_mark[-1].q;					                      
                    }
break;
case 3:
#line 38 "jsontocsv.y"
	{
             	for(i=0;i<yystack.l_mark[-2].q.len;i++)
             		yyval.q.val[i]=yystack.l_mark[-2].q.val[i];
             	for(j=i,k=0;k<yystack.l_mark[0].q.len;k++,j++)
             		yyval.q.val[j]=yystack.l_mark[0].q.val[k];
             	yyval.q.len=yystack.l_mark[-2].q.len+yystack.l_mark[0].q.len;  
              }
break;
case 4:
#line 45 "jsontocsv.y"
	{
        yyval.q=yystack.l_mark[0].q;
      }
break;
case 5:
#line 49 "jsontocsv.y"
	{  	
				if(yystack.l_mark[0].p.type==4)
				{
					for(i=0;i<yystack.l_mark[0].p.len;i++)
					{
						yyval.q.val[i]=strconcat(yystack.l_mark[-2].str,".");
						yyval.q.val[i]=strconcat(yyval.q.val[i],yystack.l_mark[0].p.val[i]);
					}
				}
				else if(yystack.l_mark[0].p.type==1)
				{
					for(i=0;i<yystack.l_mark[0].p.len;i++)
					{
						yyval.q.val[i]=strconcat(yystack.l_mark[-2].str,"  :  ");
						yyval.q.val[i]=strconcat(yyval.q.val[i],yystack.l_mark[0].p.val[i]);
					}
				}
				yyval.q.len=yystack.l_mark[0].p.len;
            }
break;
case 6:
#line 69 "jsontocsv.y"
	{yyval.str=substring(yystack.l_mark[0].str);}
break;
case 7:
#line 71 "jsontocsv.y"
	{
            yyval.p.val[0]=substring(yystack.l_mark[0].str);
            yyval.p.len=1;
            yyval.p.type=1;
          }
break;
case 8:
#line 76 "jsontocsv.y"
	{
          	yyval.p.val[0]=yystack.l_mark[0].str;
            yyval.p.len=1;
            yyval.p.type=1;
        }
break;
case 9:
#line 81 "jsontocsv.y"
	{
            yyval.p.val[0]=yystack.l_mark[0].str;
            yyval.p.len=1;
            yyval.p.type=1;
          }
break;
case 10:
#line 86 "jsontocsv.y"
	{
            yyval.p.type=4;
            yyval.p.len=yystack.l_mark[0].q.len;
            for(i=0;i<yystack.l_mark[0].q.len;i++)
            	yyval.p.val[i]=yystack.l_mark[0].q.val[i];
          }
break;
case 11:
#line 92 "jsontocsv.y"
	{
           	 yyval.p.type=4;
           	 yyval.p.len=yystack.l_mark[0].q.len;
             for(i=0;i<yystack.l_mark[0].q.len;i++)
           		yyval.p.val[i]=yystack.l_mark[0].q.val[i]; 
           }
break;
case 12:
#line 99 "jsontocsv.y"
	{
                     yyval.q=yystack.l_mark[-1].q;
                     arrindex=0;
                    }
break;
case 13:
#line 104 "jsontocsv.y"
	{
                 	if(yystack.l_mark[-2].p.type==4)
                 	{
	                 	for(i=0;i<yystack.l_mark[-2].p.len;i++)
	             		{	
	             			yyval.q.val[i]=itoa(arrindex,s,10);
         					yyval.q.val[i]=strconcat(yyval.q.val[i],".");
         					yyval.q.val[i]=strconcat(yyval.q.val[i],yystack.l_mark[-2].p.val[i]);
	             		}
	             	}
	             	else if(yystack.l_mark[-2].p.type==1)
	             	{
	             		for(i=0;i<yystack.l_mark[-2].p.len;i++)
	             		{	
	             			yyval.q.val[i]=itoa(arrindex,s,10);
         					yyval.q.val[i]=strconcat(yyval.q.val[i],"  :  ");
         					yyval.q.val[i]=strconcat(yyval.q.val[i],yystack.l_mark[-2].p.val[i]);
	             		}
	             	}
             		for(j=i,k=0;k<yystack.l_mark[0].q.len;k++,j++)
             			yyval.q.val[j]=yystack.l_mark[0].q.val[k];
             		yyval.q.len=yystack.l_mark[-2].p.len+yystack.l_mark[0].q.len;
             		arrindex++;
                }
break;
case 14:
#line 128 "jsontocsv.y"
	{
          	if(yystack.l_mark[0].p.type==4)
          	{
          		for(i=0;i<yystack.l_mark[0].p.len;i++)
         		{	
         			yyval.q.val[i]=itoa(arrindex,s,10);
         			yyval.q.val[i]=strconcat(yyval.q.val[i],".");
         			yyval.q.val[i]=strconcat(yyval.q.val[i],yystack.l_mark[0].p.val[i]);
         		}
          	}
          	else if(yystack.l_mark[0].p.type==1)
          	{
          		for(i=0;i<yystack.l_mark[0].p.len;i++)
         		{	
         			yyval.q.val[i]=itoa(arrindex,s,10);
         			yyval.q.val[i]=strconcat(yyval.q.val[i],"  :  ");
         			yyval.q.val[i]=strconcat(yyval.q.val[i],yystack.l_mark[0].p.val[i]);
         		}
          	}
          	arrindex++;
          	yyval.q.len=yystack.l_mark[0].p.len;
        }
break;
#line 618 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
