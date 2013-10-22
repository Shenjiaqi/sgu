%{
#include <cstdio>
#include "strstack.h"
extern int yylineno;
extern void yyerror(const char *s);
extern strstack strsta;
extern int yylex(void);
%}
%union{
int idx;
}

%token

tok_183/*_r0*/
tok_187/*_r1*/
tok_191/*_r2*/
tok_195/*_r3*/
tok_199/*_r4*/
tok_203/*_r5*/
tok_207/*_r6*/
tok_211/*_r7*/
tok_215/*_r8*/
tok_219/*_r9*/
tok_223/*_r10*/
tok_228/*_r11*/
tok_233/*_r12*/
tok_238/*_r13*/
tok_243/*_r14*/
tok_248/*_r15*/
tok_144/*_a0*/
tok_148/*_a1*/
tok_152/*_a2*/
tok_156/*_a3*/
tok_160/*_a4*/
tok_164/*_a5*/
tok_168/*_a6*/
tok_172/*_a7*/
tok_261/*_c0*/
tok_265/*_c1*/
tok_269/*_c2*/
tok_273/*_c3*/
tok_285/*_o0*/
tok_289/*_o1*/
tok_293/*_o2*/
tok_297/*_o3*/
tok_309/*_b0*/
tok_313/*_b1*/
tok_317/*_b2*/
tok_321/*_b3*/
tok_332/*_m0*/
tok_336/*_m1*/
tok_340/*_m2*/
tok_344/*_m3*/
tok_706/*mov*/
tok_1066/*,*/
tok_1026/*nop*/
tok_510/*add*/
tok_514/*addu*/
tok_519/*sub*/
tok_523/*mul*/
tok_527/*mulu*/
tok_532/*fmul*/
tok_537/*fcmul*/
tok_543/*cmac*/
tok_548/*mac*/
tok_572/*dadd*/
tok_577/*qadd*/
tok_582/*dsub*/
tok_587/*qsub*/
tok_592/*fdmul*/
tok_598/*fqmul*/
tok_604/*dmac*/
tok_609/*qmac*/
tok_614/*dmax*/
tok_619/*qmax*/
tok_624/*dmin*/
tok_629/*qmin*/
tok_655/*and*/
tok_659/*or*/
tok_662/*xor*/
tok_666/*max*/
tok_670/*min*/
tok_674/*sla*/
tok_678/*slaa*/
tok_683/*srl*/
tok_750/*dabs*/
tok_755/*qabs*/
tok_760/*dsum*/
tok_765/*qsum*/

%type <idx> rule_reg_all
%type <idx> rule_insn64slot1_mov
%type <idx> rule_insn64slot1_nop
%type <idx> rule_insn64slot1_others_iterm
%type <idx> rule_reg_acc
%type <idx> rule_insn64slot1_others
%type <idx> rule_insn64slot1

%start rule_insn64slot1

%%

rule_reg_all: tok_183 /*_r0*/	{ $$ = strsta.newstr((string)"000000");}|
 tok_187 /*_r1*/	{ $$ = strsta.newstr((string)"000001");}|
 tok_191 /*_r2*/	{ $$ = strsta.newstr((string)"000010");}|
 tok_195 /*_r3*/	{ $$ = strsta.newstr((string)"000011");}|
 tok_199 /*_r4*/	{ $$ = strsta.newstr((string)"000100");}|
 tok_203 /*_r5*/	{ $$ = strsta.newstr((string)"000101");}|
 tok_207 /*_r6*/	{ $$ = strsta.newstr((string)"000110");}|
 tok_211 /*_r7*/	{ $$ = strsta.newstr((string)"000111");}|
 tok_215 /*_r8*/	{ $$ = strsta.newstr((string)"001000");}|
 tok_219 /*_r9*/	{ $$ = strsta.newstr((string)"001001");}|
 tok_223 /*_r10*/	{ $$ = strsta.newstr((string)"001010");}|
 tok_228 /*_r11*/	{ $$ = strsta.newstr((string)"001011");}|
 tok_233 /*_r12*/	{ $$ = strsta.newstr((string)"001100");}|
 tok_238 /*_r13*/	{ $$ = strsta.newstr((string)"001101");}|
 tok_243 /*_r14*/	{ $$ = strsta.newstr((string)"001110");}|
 tok_248 /*_r15*/	{ $$ = strsta.newstr((string)"001111");}|
 tok_144 /*_a0*/	{ $$ = strsta.newstr((string)"010000");}|
 tok_148 /*_a1*/	{ $$ = strsta.newstr((string)"010001");}|
 tok_152 /*_a2*/	{ $$ = strsta.newstr((string)"010010");}|
 tok_156 /*_a3*/	{ $$ = strsta.newstr((string)"010011");}|
 tok_160 /*_a4*/	{ $$ = strsta.newstr((string)"010100");}|
 tok_164 /*_a5*/	{ $$ = strsta.newstr((string)"010101");}|
 tok_168 /*_a6*/	{ $$ = strsta.newstr((string)"010110");}|
 tok_172 /*_a7*/	{ $$ = strsta.newstr((string)"010111");}|
 tok_261 /*_c0*/	{ $$ = strsta.newstr((string)"011000");}|
 tok_265 /*_c1*/	{ $$ = strsta.newstr((string)"011001");}|
 tok_269 /*_c2*/	{ $$ = strsta.newstr((string)"011010");}|
 tok_273 /*_c3*/	{ $$ = strsta.newstr((string)"011011");}|
 tok_285 /*_o0*/	{ $$ = strsta.newstr((string)"011100");}|
 tok_289 /*_o1*/	{ $$ = strsta.newstr((string)"011101");}|
 tok_293 /*_o2*/	{ $$ = strsta.newstr((string)"011110");}|
 tok_297 /*_o3*/	{ $$ = strsta.newstr((string)"011111");}|
 tok_309 /*_b0*/	{ $$ = strsta.newstr((string)"100000");}|
 tok_313 /*_b1*/	{ $$ = strsta.newstr((string)"100001");}|
 tok_317 /*_b2*/	{ $$ = strsta.newstr((string)"100010");}|
 tok_321 /*_b3*/	{ $$ = strsta.newstr((string)"100011");}|
 tok_332 /*_m0*/	{ $$ = strsta.newstr((string)"100100");}|
 tok_336 /*_m1*/	{ $$ = strsta.newstr((string)"100101");}|
 tok_340 /*_m2*/	{ $$ = strsta.newstr((string)"100110");}|
 tok_344 /*_m3*/	{ $$ = strsta.newstr((string)"100111");}
;
rule_insn64slot1_mov: tok_706 /*mov*/ rule_reg_all tok_1066 /*,*/ rule_reg_all
{ $$ = strsta.newstr( (string)"100010"+ strsta.getstr($2)+ strsta.getstr($4));}
;
rule_insn64slot1_nop: tok_1026 /*nop*/
{ $$ = strsta.newstr( (string)"000000000000000000");}
;
rule_insn64slot1_others_iterm: tok_510 /*add*/	{ $$ = strsta.newstr((string)"000001");}|
 tok_514 /*addu*/	{ $$ = strsta.newstr((string)"000010");}|
 tok_519 /*sub*/	{ $$ = strsta.newstr((string)"000011");}|
 tok_523 /*mul*/	{ $$ = strsta.newstr((string)"000100");}|
 tok_527 /*mulu*/	{ $$ = strsta.newstr((string)"000101");}|
 tok_532 /*fmul*/	{ $$ = strsta.newstr((string)"000110");}|
 tok_537 /*fcmul*/	{ $$ = strsta.newstr((string)"000111");}|
 tok_543 /*cmac*/	{ $$ = strsta.newstr((string)"001000");}|
 tok_548 /*mac*/	{ $$ = strsta.newstr((string)"001001");}|
 tok_572 /*dadd*/	{ $$ = strsta.newstr((string)"001010");}|
 tok_577 /*qadd*/	{ $$ = strsta.newstr((string)"001011");}|
 tok_582 /*dsub*/	{ $$ = strsta.newstr((string)"001100");}|
 tok_587 /*qsub*/	{ $$ = strsta.newstr((string)"001101");}|
 tok_592 /*fdmul*/	{ $$ = strsta.newstr((string)"001110");}|
 tok_598 /*fqmul*/	{ $$ = strsta.newstr((string)"001111");}|
 tok_604 /*dmac*/	{ $$ = strsta.newstr((string)"010000");}|
 tok_609 /*qmac*/	{ $$ = strsta.newstr((string)"010001");}|
 tok_614 /*dmax*/	{ $$ = strsta.newstr((string)"010010");}|
 tok_619 /*qmax*/	{ $$ = strsta.newstr((string)"010011");}|
 tok_624 /*dmin*/	{ $$ = strsta.newstr((string)"010100");}|
 tok_629 /*qmin*/	{ $$ = strsta.newstr((string)"010101");}|
 tok_655 /*and*/	{ $$ = strsta.newstr((string)"010110");}|
 tok_659 /*or*/	{ $$ = strsta.newstr((string)"010111");}|
 tok_662 /*xor*/	{ $$ = strsta.newstr((string)"011000");}|
 tok_666 /*max*/	{ $$ = strsta.newstr((string)"011001");}|
 tok_670 /*min*/	{ $$ = strsta.newstr((string)"011010");}|
 tok_674 /*sla*/	{ $$ = strsta.newstr((string)"011011");}|
 tok_678 /*slaa*/	{ $$ = strsta.newstr((string)"011100");}|
 tok_683 /*srl*/	{ $$ = strsta.newstr((string)"011101");}|
 tok_750 /*dabs*/	{ $$ = strsta.newstr((string)"011110");}|
 tok_755 /*qabs*/	{ $$ = strsta.newstr((string)"011111");}|
 tok_760 /*dsum*/	{ $$ = strsta.newstr((string)"100000");}|
 tok_765 /*qsum*/	{ $$ = strsta.newstr((string)"100001");}
;
rule_reg_acc: tok_261 /*_c0*/	{ $$ = strsta.newstr((string)"00");}|
 tok_265 /*_c1*/	{ $$ = strsta.newstr((string)"01");}|
 tok_269 /*_c2*/	{ $$ = strsta.newstr((string)"10");}|
 tok_273 /*_c3*/	{ $$ = strsta.newstr((string)"11");}
;
rule_insn64slot1_others: rule_insn64slot1_others_iterm rule_reg_acc tok_1066 /*,*/ rule_reg_all tok_1066 /*,*/ rule_reg_all
{ $$ = strsta.newstr( strsta.getstr($1)+ strsta.getstr($2)+ strsta.getstr($4)+ strsta.getstr($6));}
;
rule_insn64slot1: rule_insn64slot1_mov{$$=strsta.newstr( strsta.getstr($1));}|
 rule_insn64slot1_others{$$=strsta.newstr( strsta.getstr($1));}|
 rule_insn64slot1_nop{$$=strsta.newstr( strsta.getstr($1));}
;
%%
void yyerror(const char *s)
{
	fprintf (stderr, "L%d: %s\n",yylineno,s);
}
