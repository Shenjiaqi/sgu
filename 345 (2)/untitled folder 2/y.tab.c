#ifndef lint
/*static char yysccsid[] = "from: @(#)yaccpar	1.9 (Berkeley) 02/21/93";*/
static char yyrcsid[] = "$Id: skeleton.c,v 1.2 1997/06/23 02:51:17 tdukes Exp $";
#endif
#include <string.h>
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#line 2 "y.y"
#include <cstdio>
extern int yylineno;
extern yyerror(const char *s);
extern int yylex(void);
#line 19 "y.tab.c"
#define tok_183 257
#define tok_187 258
#define tok_191 259
#define tok_195 260
#define tok_199 261
#define tok_203 262
#define tok_207 263
#define tok_211 264
#define tok_215 265
#define tok_219 266
#define tok_223 267
#define tok_228 268
#define tok_233 269
#define tok_238 270
#define tok_243 271
#define tok_248 272
#define tok_144 273
#define tok_148 274
#define tok_152 275
#define tok_156 276
#define tok_160 277
#define tok_164 278
#define tok_168 279
#define tok_172 280
#define tok_261 281
#define tok_265 282
#define tok_269 283
#define tok_273 284
#define tok_285 285
#define tok_289 286
#define tok_293 287
#define tok_297 288
#define tok_309 289
#define tok_313 290
#define tok_317 291
#define tok_321 292
#define tok_332 293
#define tok_336 294
#define tok_340 295
#define tok_344 296
#define tok_706 297
#define tok_1066 298
#define tok_1026 299
#define tok_510 300
#define tok_514 301
#define tok_519 302
#define tok_523 303
#define tok_527 304
#define tok_532 305
#define tok_537 306
#define tok_543 307
#define tok_548 308
#define tok_572 309
#define tok_577 310
#define tok_582 311
#define tok_587 312
#define tok_592 313
#define tok_598 314
#define tok_604 315
#define tok_609 316
#define tok_614 317
#define tok_619 318
#define tok_624 319
#define tok_629 320
#define tok_655 321
#define tok_659 322
#define tok_662 323
#define tok_666 324
#define tok_670 325
#define tok_674 326
#define tok_678 327
#define tok_683 328
#define tok_750 329
#define tok_755 330
#define tok_760 331
#define tok_765 332
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    2,    3,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    5,    5,    5,    5,    6,
    0,    0,    0,
};
short yylen[] = {                                         2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    4,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    6,
    1,    1,    1,
};
short yydefred[] = {                                      0,
    0,   42,   43,   44,   45,   46,   47,   48,   49,   50,
   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,
   61,   62,   63,   64,   65,   66,   67,   68,   69,   70,
   71,   72,   73,   74,   75,    0,   81,   83,    0,   82,
    1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
   11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
   31,   32,   33,   34,   35,   36,   37,   38,   39,   40,
    0,   76,   77,   78,   79,    0,    0,    0,   41,    0,
    0,   80,
};
short yydgoto[] = {                                      36,
   81,   37,   38,   39,   86,   40,
};
short yysindex[] = {                                   -256,
 -257,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -199,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -258,    0,    0,    0,    0, -219, -257, -257,    0, -218,
 -257,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
short yygindex[] = {                                      0,
  -10,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 85
short yytable[] = {                                      41,
   42,   43,   44,   45,   46,   47,   48,   49,   50,   51,
   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,
   62,   63,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   73,   74,   75,   76,   77,   78,   79,   80,   87,
    1,    0,    2,    3,    4,    5,    6,    7,    8,    9,
   10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
   30,   31,   32,   33,   34,   35,   89,   90,   88,   91,
   92,   82,   83,   84,   85,
};
short yycheck[] = {                                     257,
  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,  273,  274,  275,  276,  277,
  278,  279,  280,  281,  282,  283,  284,  285,  286,  287,
  288,  289,  290,  291,  292,  293,  294,  295,  296,  298,
  297,   -1,  299,  300,  301,  302,  303,  304,  305,  306,
  307,  308,  309,  310,  311,  312,  313,  314,  315,  316,
  317,  318,  319,  320,  321,  322,  323,  324,  325,  326,
  327,  328,  329,  330,  331,  332,   87,   88,  298,  298,
   91,  281,  282,  283,  284,
};
#define YYFINAL 36
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 332
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tok_183","tok_187","tok_191",
"tok_195","tok_199","tok_203","tok_207","tok_211","tok_215","tok_219","tok_223",
"tok_228","tok_233","tok_238","tok_243","tok_248","tok_144","tok_148","tok_152",
"tok_156","tok_160","tok_164","tok_168","tok_172","tok_261","tok_265","tok_269",
"tok_273","tok_285","tok_289","tok_293","tok_297","tok_309","tok_313","tok_317",
"tok_321","tok_332","tok_336","tok_340","tok_344","tok_706","tok_1066",
"tok_1026","tok_510","tok_514","tok_519","tok_523","tok_527","tok_532",
"tok_537","tok_543","tok_548","tok_572","tok_577","tok_582","tok_587","tok_592",
"tok_598","tok_604","tok_609","tok_614","tok_619","tok_624","tok_629","tok_655",
"tok_659","tok_662","tok_666","tok_670","tok_674","tok_678","tok_683","tok_750",
"tok_755","tok_760","tok_765",
};
char *yyrule[] = {
"$accept : rule_insn64slot1",
"rule_reg_all : tok_183",
"rule_reg_all : tok_187",
"rule_reg_all : tok_191",
"rule_reg_all : tok_195",
"rule_reg_all : tok_199",
"rule_reg_all : tok_203",
"rule_reg_all : tok_207",
"rule_reg_all : tok_211",
"rule_reg_all : tok_215",
"rule_reg_all : tok_219",
"rule_reg_all : tok_223",
"rule_reg_all : tok_228",
"rule_reg_all : tok_233",
"rule_reg_all : tok_238",
"rule_reg_all : tok_243",
"rule_reg_all : tok_248",
"rule_reg_all : tok_144",
"rule_reg_all : tok_148",
"rule_reg_all : tok_152",
"rule_reg_all : tok_156",
"rule_reg_all : tok_160",
"rule_reg_all : tok_164",
"rule_reg_all : tok_168",
"rule_reg_all : tok_172",
"rule_reg_all : tok_261",
"rule_reg_all : tok_265",
"rule_reg_all : tok_269",
"rule_reg_all : tok_273",
"rule_reg_all : tok_285",
"rule_reg_all : tok_289",
"rule_reg_all : tok_293",
"rule_reg_all : tok_297",
"rule_reg_all : tok_309",
"rule_reg_all : tok_313",
"rule_reg_all : tok_317",
"rule_reg_all : tok_321",
"rule_reg_all : tok_332",
"rule_reg_all : tok_336",
"rule_reg_all : tok_340",
"rule_reg_all : tok_344",
"rule_insn64slot1_mov : tok_706 rule_reg_all tok_1066 rule_reg_all",
"rule_insn64slot1_nop : tok_1026",
"rule_insn64slot1_others_iterm : tok_510",
"rule_insn64slot1_others_iterm : tok_514",
"rule_insn64slot1_others_iterm : tok_519",
"rule_insn64slot1_others_iterm : tok_523",
"rule_insn64slot1_others_iterm : tok_527",
"rule_insn64slot1_others_iterm : tok_532",
"rule_insn64slot1_others_iterm : tok_537",
"rule_insn64slot1_others_iterm : tok_543",
"rule_insn64slot1_others_iterm : tok_548",
"rule_insn64slot1_others_iterm : tok_572",
"rule_insn64slot1_others_iterm : tok_577",
"rule_insn64slot1_others_iterm : tok_582",
"rule_insn64slot1_others_iterm : tok_587",
"rule_insn64slot1_others_iterm : tok_592",
"rule_insn64slot1_others_iterm : tok_598",
"rule_insn64slot1_others_iterm : tok_604",
"rule_insn64slot1_others_iterm : tok_609",
"rule_insn64slot1_others_iterm : tok_614",
"rule_insn64slot1_others_iterm : tok_619",
"rule_insn64slot1_others_iterm : tok_624",
"rule_insn64slot1_others_iterm : tok_629",
"rule_insn64slot1_others_iterm : tok_655",
"rule_insn64slot1_others_iterm : tok_659",
"rule_insn64slot1_others_iterm : tok_662",
"rule_insn64slot1_others_iterm : tok_666",
"rule_insn64slot1_others_iterm : tok_670",
"rule_insn64slot1_others_iterm : tok_674",
"rule_insn64slot1_others_iterm : tok_678",
"rule_insn64slot1_others_iterm : tok_683",
"rule_insn64slot1_others_iterm : tok_750",
"rule_insn64slot1_others_iterm : tok_755",
"rule_insn64slot1_others_iterm : tok_760",
"rule_insn64slot1_others_iterm : tok_765",
"rule_reg_acc : tok_261",
"rule_reg_acc : tok_265",
"rule_reg_acc : tok_269",
"rule_reg_acc : tok_273",
"rule_insn64slot1_others : rule_insn64slot1_others_iterm rule_reg_acc tok_1066 rule_reg_all tok_1066 rule_reg_all",
"rule_insn64slot1 : rule_insn64slot1_mov",
"rule_insn64slot1 : rule_insn64slot1_others",
"rule_insn64slot1 : rule_insn64slot1_nop",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
#ifdef __cplusplus
extern "C" { 
char * getenv();
int yylex();
int yyparse();
}

#endif
int
#if defined(__STDC__)
yyparse(void)
#else
yyparse()
#endif
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
#ifndef __cplusplus
    extern char *getenv();
#endif

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
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
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
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
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
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
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 99 "y.y"
{return (string)"000000";}
break;
case 2:
#line 100 "y.y"
{return (string)"000001";}
break;
case 3:
#line 101 "y.y"
{return (string)"000010";}
break;
case 4:
#line 102 "y.y"
{return (string)"000011";}
break;
case 5:
#line 103 "y.y"
{return (string)"000100";}
break;
case 6:
#line 104 "y.y"
{return (string)"000101";}
break;
case 7:
#line 105 "y.y"
{return (string)"000110";}
break;
case 8:
#line 106 "y.y"
{return (string)"000111";}
break;
case 9:
#line 107 "y.y"
{return (string)"001000";}
break;
case 10:
#line 108 "y.y"
{return (string)"001001";}
break;
case 11:
#line 109 "y.y"
{return (string)"001010";}
break;
case 12:
#line 110 "y.y"
{return (string)"001011";}
break;
case 13:
#line 111 "y.y"
{return (string)"001100";}
break;
case 14:
#line 112 "y.y"
{return (string)"001101";}
break;
case 15:
#line 113 "y.y"
{return (string)"001110";}
break;
case 16:
#line 114 "y.y"
{return (string)"001111";}
break;
case 17:
#line 115 "y.y"
{return (string)"010000";}
break;
case 18:
#line 116 "y.y"
{return (string)"010001";}
break;
case 19:
#line 117 "y.y"
{return (string)"010010";}
break;
case 20:
#line 118 "y.y"
{return (string)"010011";}
break;
case 21:
#line 119 "y.y"
{return (string)"010100";}
break;
case 22:
#line 120 "y.y"
{return (string)"010101";}
break;
case 23:
#line 121 "y.y"
{return (string)"010110";}
break;
case 24:
#line 122 "y.y"
{return (string)"010111";}
break;
case 25:
#line 123 "y.y"
{return (string)"011000";}
break;
case 26:
#line 124 "y.y"
{return (string)"011001";}
break;
case 27:
#line 125 "y.y"
{return (string)"011010";}
break;
case 28:
#line 126 "y.y"
{return (string)"011011";}
break;
case 29:
#line 127 "y.y"
{return (string)"011100";}
break;
case 30:
#line 128 "y.y"
{return (string)"011101";}
break;
case 31:
#line 129 "y.y"
{return (string)"011110";}
break;
case 32:
#line 130 "y.y"
{return (string)"011111";}
break;
case 33:
#line 131 "y.y"
{return (string)"100000";}
break;
case 34:
#line 132 "y.y"
{return (string)"100001";}
break;
case 35:
#line 133 "y.y"
{return (string)"100010";}
break;
case 36:
#line 134 "y.y"
{return (string)"100011";}
break;
case 37:
#line 135 "y.y"
{return (string)"100100";}
break;
case 38:
#line 136 "y.y"
{return (string)"100101";}
break;
case 39:
#line 137 "y.y"
{return (string)"100110";}
break;
case 40:
#line 138 "y.y"
{return (string)"100111";}
break;
case 41:
#line 141 "y.y"
{ yyval.string = (string)"100010"+ yyvsp[-2].string+ yyvsp[0].string}
break;
case 42:
#line 144 "y.y"
{ yyval.string = (string)"000000000000000000"}
break;
case 43:
#line 146 "y.y"
{return (string)"000001";}
break;
case 44:
#line 147 "y.y"
{return (string)"000010";}
break;
case 45:
#line 148 "y.y"
{return (string)"000011";}
break;
case 46:
#line 149 "y.y"
{return (string)"000100";}
break;
case 47:
#line 150 "y.y"
{return (string)"000101";}
break;
case 48:
#line 151 "y.y"
{return (string)"000110";}
break;
case 49:
#line 152 "y.y"
{return (string)"000111";}
break;
case 50:
#line 153 "y.y"
{return (string)"001000";}
break;
case 51:
#line 154 "y.y"
{return (string)"001001";}
break;
case 52:
#line 155 "y.y"
{return (string)"001010";}
break;
case 53:
#line 156 "y.y"
{return (string)"001011";}
break;
case 54:
#line 157 "y.y"
{return (string)"001100";}
break;
case 55:
#line 158 "y.y"
{return (string)"001101";}
break;
case 56:
#line 159 "y.y"
{return (string)"001110";}
break;
case 57:
#line 160 "y.y"
{return (string)"001111";}
break;
case 58:
#line 161 "y.y"
{return (string)"010000";}
break;
case 59:
#line 162 "y.y"
{return (string)"010001";}
break;
case 60:
#line 163 "y.y"
{return (string)"010010";}
break;
case 61:
#line 164 "y.y"
{return (string)"010011";}
break;
case 62:
#line 165 "y.y"
{return (string)"010100";}
break;
case 63:
#line 166 "y.y"
{return (string)"010101";}
break;
case 64:
#line 167 "y.y"
{return (string)"010110";}
break;
case 65:
#line 168 "y.y"
{return (string)"010111";}
break;
case 66:
#line 169 "y.y"
{return (string)"011000";}
break;
case 67:
#line 170 "y.y"
{return (string)"011001";}
break;
case 68:
#line 171 "y.y"
{return (string)"011010";}
break;
case 69:
#line 172 "y.y"
{return (string)"011011";}
break;
case 70:
#line 173 "y.y"
{return (string)"011100";}
break;
case 71:
#line 174 "y.y"
{return (string)"011101";}
break;
case 72:
#line 175 "y.y"
{return (string)"011110";}
break;
case 73:
#line 176 "y.y"
{return (string)"011111";}
break;
case 74:
#line 177 "y.y"
{return (string)"100000";}
break;
case 75:
#line 178 "y.y"
{return (string)"100001";}
break;
case 76:
#line 180 "y.y"
{return (string)"00";}
break;
case 77:
#line 181 "y.y"
{return (string)"01";}
break;
case 78:
#line 182 "y.y"
{return (string)"10";}
break;
case 79:
#line 183 "y.y"
{return (string)"11";}
break;
case 80:
#line 186 "y.y"
{ yyval.string = yyvsp[-5].string+ yyvsp[-4].string+ yyvsp[-2].string+ yyvsp[0].string}
break;
case 81:
#line 188 "y.y"
{yyval.string= yyvsp[0].string;}
break;
case 82:
#line 189 "y.y"
{yyval.string= yyvsp[0].string;}
break;
case 83:
#line 190 "y.y"
{yyval.string= yyvsp[0].string;}
break;
#line 803 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
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
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
