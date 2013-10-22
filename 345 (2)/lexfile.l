%{
#include "y.h"
%}

%%

"_r0"	{return tok_183/*_r0*/;}
"_r1"	{return tok_187/*_r1*/;}
"_r2"	{return tok_191/*_r2*/;}
"_r3"	{return tok_195/*_r3*/;}
"_r4"	{return tok_199/*_r4*/;}
"_r5"	{return tok_203/*_r5*/;}
"_r6"	{return tok_207/*_r6*/;}
"_r7"	{return tok_211/*_r7*/;}
"_r8"	{return tok_215/*_r8*/;}
"_r9"	{return tok_219/*_r9*/;}
"_r10"	{return tok_223/*_r10*/;}
"_r11"	{return tok_228/*_r11*/;}
"_r12"	{return tok_233/*_r12*/;}
"_r13"	{return tok_238/*_r13*/;}
"_r14"	{return tok_243/*_r14*/;}
"_r15"	{return tok_248/*_r15*/;}
"_a0"	{return tok_144/*_a0*/;}
"_a1"	{return tok_148/*_a1*/;}
"_a2"	{return tok_152/*_a2*/;}
"_a3"	{return tok_156/*_a3*/;}
"_a4"	{return tok_160/*_a4*/;}
"_a5"	{return tok_164/*_a5*/;}
"_a6"	{return tok_168/*_a6*/;}
"_a7"	{return tok_172/*_a7*/;}
"_c0"	{return tok_261/*_c0*/;}
"_c1"	{return tok_265/*_c1*/;}
"_c2"	{return tok_269/*_c2*/;}
"_c3"	{return tok_273/*_c3*/;}
"_o0"	{return tok_285/*_o0*/;}
"_o1"	{return tok_289/*_o1*/;}
"_o2"	{return tok_293/*_o2*/;}
"_o3"	{return tok_297/*_o3*/;}
"_b0"	{return tok_309/*_b0*/;}
"_b1"	{return tok_313/*_b1*/;}
"_b2"	{return tok_317/*_b2*/;}
"_b3"	{return tok_321/*_b3*/;}
"_m0"	{return tok_332/*_m0*/;}
"_m1"	{return tok_336/*_m1*/;}
"_m2"	{return tok_340/*_m2*/;}
"_m3"	{return tok_344/*_m3*/;}
"mov"	{return tok_706/*mov*/;}
","	{return tok_1066/*,*/;}
"nop"	{return tok_1026/*nop*/;}
"add"	{return tok_510/*add*/;}
"addu"	{return tok_514/*addu*/;}
"sub"	{return tok_519/*sub*/;}
"mul"	{return tok_523/*mul*/;}
"mulu"	{return tok_527/*mulu*/;}
"fmul"	{return tok_532/*fmul*/;}
"fcmul"	{return tok_537/*fcmul*/;}
"cmac"	{return tok_543/*cmac*/;}
"mac"	{return tok_548/*mac*/;}
"dadd"	{return tok_572/*dadd*/;}
"qadd"	{return tok_577/*qadd*/;}
"dsub"	{return tok_582/*dsub*/;}
"qsub"	{return tok_587/*qsub*/;}
"fdmul"	{return tok_592/*fdmul*/;}
"fqmul"	{return tok_598/*fqmul*/;}
"dmac"	{return tok_604/*dmac*/;}
"qmac"	{return tok_609/*qmac*/;}
"dmax"	{return tok_614/*dmax*/;}
"qmax"	{return tok_619/*qmax*/;}
"dmin"	{return tok_624/*dmin*/;}
"qmin"	{return tok_629/*qmin*/;}
"and"	{return tok_655/*and*/;}
"or"	{return tok_659/*or*/;}
"xor"	{return tok_662/*xor*/;}
"max"	{return tok_666/*max*/;}
"min"	{return tok_670/*min*/;}
"sla"	{return tok_674/*sla*/;}
"slaa"	{return tok_678/*slaa*/;}
"srl"	{return tok_683/*srl*/;}
"dabs"	{return tok_750/*dabs*/;}
"qabs"	{return tok_755/*qabs*/;}
"dsum"	{return tok_760/*dsum*/;}
"qsum"	{return tok_765/*qsum*/;}
[ \t]	{}

%%
int yywrap()
{
	return 1;
}