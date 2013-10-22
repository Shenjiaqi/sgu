
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