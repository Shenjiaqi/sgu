%{
#include <gmpxx.h>
#include "front.h"
extern int yylineno;
%}

%token

ACTION
ALIAS
BYPASS
CASE
CHESS_PC_OFFSET
CHESS_VIEW
CST
CYCLES
DEFAULT
DEF
DELAY_SLOTS
ELSE
ENUM
FU
HW_INIT
HW_STALL
IF
IMAGE
INPORT
MEM
MODE
OP
OTHERS
OUTPORT
PIPE
PROPERTIES
PROPERTY
READ_ACTION
READ
REG
RSRC
STAGE
START
SW_STALL
SWITCH
SYNTAX
TRN
VALUE
WORDS
WRITE_ACTION
WRITE_VALUE
WRITE
ARBITARY_ORDER
CLASS
PRIMITIVE
DOUBLEDOT
DOLLAR
DCOLON
BITNEG
IS_EXCLUSIVE
MAKE_EXCLUSIVE
OP_AND_RULE
RULE_REF
CHESS

<charP>INT_CONST
<charP>STRING_CONST
<charP>BINARY_CONST
<charP>HEX_CONST 
<charP>IDENTIFIER
ASSIGN
SEMI
COLON
COMMA
LPAREN
RPAREN
LBRACE
RBRACE
LBRACK
RBRACK
AND
OR
EQU
NEQU
LESS
LESSE
GRT
GRTE
NOT
POINT
PLUS
MINUS
BITOR
BITAND
MUL
DIV
POW
ALIGN
DELAY
<charP>ENUM_NAME
<charP>MODE_AND_NAME
<charP>MODE_RULE_NAME
<charP>OP_RULE_NAME
<charP>NUMBER_NAME
<charP>TYPE_ID

%left BITAND BITOR
%left PLUS MINUS
%left MUL DIV
%nonassoc NEG BITNEG
%right POW

%union{
char *charP;
int int;
}

%type <charP> Identifier
%type <mpz_class> Integer
%type <mpz_class> Binary
%type <mpz_class> Hex
%type <mpz_class> Integer_expression
/*%type <int> Number_name*/
%type <int> Mnemonic_opt
%type <mpz_class> Init_opt
/*%type <int> Enum_declare*/
%type <mpz_class> Constant_declaration
/*%type <charP> Type_id*/
%type <charP> Address_type
%type <charP> String
%type <mpz_class> Syntax_nr
%type <mpz_class> Syntax_nr_opt
%type <mpz_class> Constant_value_opt
/*%type <charP> Enum_instant_name*/
%type <mpz_class> Image_nr_opt
%type <mpz_class> Image_nr
%type <int> Syntax_attribute_list
%type <int> Syntax_attribute
%type <int> And_image_attribute_list
%type <int> And_image_attribute
%type <charP> Op_rule_instant_name
/*%type <charP> Op_rule_name*/
/*%type <charP> Enum_name*/
%type <int> Or_image_attribute_list
%type <int> Or_image_attribute
/*%type <charP> Mode_rule_name*/
%type <charP> Rule_instant_name
%type <int> Rule_syntax_ref
%type <charP> Enum_element_name
%type <charP> Bit_string_literal
/*%type <charP> Register_file_name*/
%type <charP> Rule_image_ref
%type <charP> Address_range
/*%type <charP> Const_instant_name*/


%%

nml_description : Declaration_list Rule_list
;
Rule_list : Rule
	| Rule_list Rule
;
Rule : Op_rule
	| Mode_rule
;
Op_rule : Or_op_rule
	| And_op_rule
;
And_op_rule: OP Identifier LPAREN Parameter_declaration_list RPAREN
	LBRACE /*Action_attribute*/ Syntax_attribute_list And_image_attribute_list RBRACE{
	int tmp=vartab.find($2);
	if(!tmp)
	{	
		printf("L%d: %s already defined at line %d\n",yylineno,$2,vartab.getdefline(tmp));
		partab.clear();
	}
	else
	{
		vartab.add(strtab.addstr($2),OP_AND_RULE,opntab.add(partab.clear(),$7,$8));
	}
	syntab.addtrm();
	}
;
Syntax_attribute_list: {$$=0;}
	|	Syntax_attribute_list Syntax_attribute{
		$$=min($1,$2);
		}
;
And_image_attribute_list:{$$=0;}
	|	/*And_image_attribute_list*/ And_image_attribute{$$=$1;}
;
And_image_attribute: IMAGE COLON And_field_encoding_list Instr_properties_opt SEMI{
		$$=opimg.addent();
		}
	|	IMAGE COLON Instr_properties {printf("TODO\n");$$=0;}
;
Instr_properties_opt:
	|	COMMA Instr_properties
;
Instr_properties: Instr_property
	|	Instr_properties COMMA Instr_property
;
Instr_property:
	|	CYCLES LPAREN  Integer_expression RPAREN
	|	CYCLES LPAREN Integer_expression BITOR Integer_expression RPAREN
	|	DELAY_SLOTS LPAREN Integer_expression RPAREN
	|	CHESS_PC_OFFSET LPAREN Integer_expression RPAREN
	|	CLASS LPAREN Identifier RPAREN
;
And_field_encoding_list:
	And_field_encoding Enc_alias_opt
	And_field_encoding_list DCOLON And_field_encoding Enc_alias_opt
/*
And_field_encoding:
	Bit_string_literal
	ENUM_NAME . Enum_element_name
	Opn_rule_image_ref
	Mode_rule_image_ref
	Cst_expression
	Cst_expression Bit_selection*/
/*
Opn_rule_image_ref :
	Opn_rule_instant_name Image_nr_opt
	Opn_rule_instant_name POINT IMAGE Image_nr_opt*/

/*Opn_rule_instant_name : String*/

/*Mode_rule_image_ref :
	Mode_rule_instant_name Image_nr_opt
	Mode_rule_instant_name POINT IMAGE Image_nr_opt*/
;
Mode_rule : Or_mode_rule
	|	And_mode_rule
;
Parameter_declaration_list : Parameter_declaration
	|	Parameter_declaration_list COMMA Parameter_declaration
;
Parameter_declaration : Op_rule_instant_name COLON OP_RULE_NAME{
		int tmp=partab.find($1);
		if(tmp)
			printf("L%d: %s already declared before\n",yylineno,$1);
		else
		{
			tmp=vartab.find($3);
			if(!tmp)
				printf("L%d: %s not defined",yylineno,$3);
			else
			{
				int type=vartab.gettype(tmp);
				if(type!=OP_AND_RULE && type!=MOD_AND_RULE &&
				type!=OP_OR_RULE && type!=MOD_OR_RULe &&
				type!=CST)
					printf("L%d: %s wrong type\n",yylineno,$3);
				else partab.add(strtab.getstr(strtab.addstr($1)),tmp);
			}
		}
	/*|	Mode_rule_instant_name COLON MODE_RULE_NAME
	|	Enum_instant_name COLON ENUM_NAME
	|	Const_instant_name COLON Const_name*/
		}
;
Op_rule_instant_name : Identifier{$$=$1;}

/*Const_instant_name : Identifier{$$=$1;}*/
/*Mode_rule_instant_name : Identifier*/

/*Enum_instant_name : Identifier{$$=$1;}*/

/*OP_RULE_NAME : Identifier{$$=$1;}
*/

/*Enum_name : Identifier{
	$$=$1;
	}*/
/*
;
Const_name : Identifier*/
;
Or_op_rule : /*OP Identifier LPAREN Op_rule_name_list RPAREN /*exclusive_command_opt COLON
	|*/	OP Identifier LPAREN Op_rule_name_list RPAREN /*exclusive_command_opt*/ 
	LBRACE Or_image_attribute_list RBRACE{
		int tmp=vartab.find($2);
		if(tmp)
		{
			printf("L%d: %s already defined at line %d\n",yylineno,$2,vartab.getdefline(tmp));
			partab.clear();/*TODO clear entries in list*/
		}
		else
		{
			vartab.add(strtab.addstr($2),OP_OR_RULE,oroptab.add(partab.clear(),$7),yylineno);
			/*TODO now no check on paraments, just throw it*/
		}
		}
;
Op_rule_name_list : OP_RULE_NAME{
		/*TODO*/
		int tmp=vartab.find($1);
		if(!tmp)
			printf("L%d: %s not defined\n",yylineno,$1);
		else
		{
			int type=vartab.gettype(tmp);
			if(type!=OP_AND_RULE || type!=OP_OR_RULE ||
			type!=MODE_AND_RULE || type!=MODE_OR_RULE)
				printf("L%d: %s wrong type\n",yyline,$1);
			else
			{
				partab.add(strtab.getstr(strtab.addstr($1)),tmp);
			}
		}
		}
	|	Op_rule_name_list BITOR OP_RULE_NAME{
		int tmp=vartab.find($3);
		if(!tmp)
			printf("L%d: %s not defined\n",yylineno,$3);
		else
		{
			int type=vartab.gettype(tmp);
			if(type!=OP_AND_RULE || type!=OP_OR_RULE ||
			type!=MODE_AND_RULE || type!=MODE_OR_RULE)
				printf("L%d: %s wrong type\n",yyline,$3);
			else
			{
				partab.add(strtab.getstr(strtab.addstr($3)),tmp);
			}
		}
		}
;
Or_image_attribute_list : Or_image_attribute{$$=$1;}
	/*|	Or_image_attrbute_list Or_image_attribute*/
;
And_mode_rule : MODE Identifier Class_access_opt LPAREN Parameter_declaration_list RPAREN
	LBRACE Syntax_attribute_list And_image_attribute_list RBRACE{
	int tmp=vartab.find($2);
	if(!tmp)
	{	
		printf("L%d: %s already defined at line %d\n",yylineno,$2,vartab.getdefline(tmp));
		partab.clear();
	}
	else
	{
		vartab.add(strtab.addstr($2),MODE_AND_RULE,opntab.add(partab.clear(),$8,$9));
							/* ^^^^^^TODO*/
	}
	}
;
Class_access_opt : 
	|	Class_access
;
Class_access : CLASS LPAREN Register_class_name RPAREN
;
Register_class_name : Identifier
;
Or_mode_rule : MODE Identifier Class_access_opt LPAREN Mode_rule_name_list RPAREN Exclusive_command_opt
	|	MODE Identifier Class_access_opt LPAREN Mode_rule_name_list RPAREN Exclusive_command_opt
	LBRACE Or_image_attribute_list RBRACE{
		int tmp=vartab.find($2);
		if(tmp)
		{
			printf("L%d: %s already defined at line %d\n",yylineno,$2,vartab.getdefline(tmp));
			partab.clear();/*TODO clear entries in list*/
		}
		else
		{
			vartab.add(strtab.addstr($2),MODE_OR_RULE,ormodetab.add(partab.clear(),$9),yylineno);
									/*TODO^^^^^^
									now no check on paraments, just throw it*/
		}
		}
;
Mode_rule_name_list : N_mode_rule_name
	|	Mode_rule_name_list BITOR N_mode_rule_name
;
N_mode_rule_name : MODE_RULE_NAME{
		int tmp=vartab.find($1);
		if(!tmp)
			printf("L%d: %s not defined\n",yylineno,$1);
		else
		{
			int type=vartab.gettype(tmp);
			if(type!=OP_AND_RULE || type!=OP_OR_RULE ||
			type!=MODE_AND_RULE || type!=MODE_OR_RULE)
				printf("L%d: %s wrong type\n",yyline,$1);
			else
			{
				partab.add(strtab.getstr(strtab.addstr($1)),tmp);
			}
		}
	}

/*Mode_rule_name : Identifier{$$=$1;}*/
;
Syntax_attribute : SYNTAX COLON Syntax_encoding_list SEMI{
		$$=syntab.addtrm();
		}
;
Syntax_encoding_list : Syntax_encoding{
		syntab.addalt();
		}
	|	Syntax_encoding_list BITOR Syntax_encoding_list{
		}
;
Syntax_encoding : Syntax_encoding_element{
		}
	|	Syntax_encoding Syntax_encoding_element{
		}
;
Syntax_encoding_element: String{syntab.addele(syn_ref_c(STRING_CONST,strtab.addstr($1),0));}
	/*	|	Op_rule_syntax_ref{$$=syn_element_c(SYN_REF,$1);}
		|	Mode_rule_syntax_ref{$$=syn_element_c(MOD_REF,$1);}*/
	|	Rule_syntax_ref{syntab.addele($1);}
/*	|	Transitory_name
	|	Pipe_name
	|	Register_name
	|	Register_file_name
	|	Memory_name*/
	/*|	Enum_instant_name*/
/*	|	Matching_cond_opt
	|	Const_instant_name
	|	Integer
	|	DOLLAR Cst_expressioin DOLLAR
	|	ARBITARY_ORDER
	|	Integer
	|	Hex
	|	Binary*/

/*Register_file_name: Identifier{$$=$1;}*/
;
Rule_syntax_ref : Rule_instant_name Poi_syn_opt Syntax_nr_opt{
		int tmp=partab.find($1);
		if(!tmp)
		{
			printf("L%d:instant %s not defined\n",yylineno,$1);
			$$=syntax_ele_c(0,0,0);
		}
		else if(vartab.gettype(partab.getval(tmp))==ENUM && $3==0)//TODO bug here
			$$=syntax_ele_c(ENUM,tmp,0);
		else{
			int type=vartab.gettype(partab.getval(tmp));
			if(type!=OP_AND_RULE && type!=OP_OR_RULE
			&& type!=MOD_AND_RULE && type!=MOD_OR_RULE)
				printf("L%d: %s is not op or mod rule\n",yylineno,$1);
			else $$=syntax_ele_c(RULE_REF,tmp,(int)$3/*check size*/);
		}
		}
/*
Op_rule_syntax_ref : Op_rule_instant_name Poi_syn_opt Syntax_nr_opt{
		}*/
;
Poi_syn_opt: 
	|	POINT SYNTAX
/*
Mode_rule_syntax_ref : Mode_rule_instant_name Syntax_nr_opt
	|	Mode_rule_instant_name POINT SYNTAX Syntax_nr_opt*/
;
Syntax_nr_opt :	{$$=0;}
	|	Syntax_nr{$$=$1;}
;
Syntax_nr : POINT Integer{$$=$2;}
/*
Quoted_char_list :
	Quoted_char_list String*/

/*Match_cond_opt :
	|	Match_cond
;
Match_cond : LESS Logic_expression GRT
;
And_image_attrbute : IMAGE COLON And_field_encoding_list
;*/
;
And_field_encoding_list : And_field_encoding Enc_alias_opt
	|	And_field_encoding_list DCOLON And_field_encoding Enc_alias_opt
;
And_field_encoding : String {opimg.addele(STRING,strtab.addstr($1),0);}/*Bit_string */
	|	ENUM_NAME POINT Enum_element_name{
		int tmp=vartab.find($1);
		int idx;
		if(!tmp)
			printf("L%d: %s not defined\n",yylineno,$1);
		else if(vartab.gettype(tmp)!=ENUM)
			printf("L%d: %s wrong type\n",yylineno,$1);
		else if(!(tmp=enumtab.findent(tmp,$3)))
			printf("L%d: No such entry in %s",yyline,$1);
		else opimg.addele(ENUM,tmp,idx);
		}
	/*|	Op_rule_image_ref
	|	Mode_rule_image_ref*/
	|	Rule_image_ref{
			opimg.addele(RULE_REF, ($1).val , ($1).ref );
			}
	|	Cst_expression
	|	Cst_expression Bit_selection
;
Rule_image_ref : Rule_instant_name Image_nr_opt{
		int tmp=vartab.find($1);
		if(!tmp)
		{
			printf("L%d:i %s not defined\n",yylineno,$1);
			$$=rule_ref(0,0);
		}
		else
		{
			int type=vartab.gettype($1);
			if(type!=OP_AND_RULE && type!=OP_OR_RULE &&
			type!=MODE_AND_RULE && type!=MODE_OR_RULE)
			{
				printf("L%d: %s wrong type",yylineno,$1);
				$$=rule_ref(0,0);
			}
			else
			{
				$$=rule_ref(tmp,(int)$2);
				/*TODO check*/
			}
		}
		}
;
Rule_instant_name : Identifier{$$=$1;}
/*
Op_rule_image_ref : Op_rule_instant_name Image_nr_opt
	|	Op_rule_instant_name POINT IMAGE Image_nr_opt*/
;
Image_nr_opt :	{$$=(mpz_class)0;}
	|	Image_nr{$$=$1;}
;
Image_nr : POINT Integer{$$=$2;}
;
Enum_element_name : Identifier{$$=$1;}
;
Cst_expression : Const_instant_name_Enum_instant_name
	/*|	Enum_instant_name*/
	|	Integer
	|	Cst_expression PLUS Cst_expression
	|	Cst_expression MINUS Cst_expression
	|	Cst_expression MUL Cst_expression
	|	Cst_expression DIV Cst_expression
	|	Cst_expression BITAND Cst_expression
	|	Cst_expression BITOR Cst_expression
	|	BITNEG Cst_expression
	|	LBRACE Cst_expression RBRACE
;
Const_instant_name_Enum_instant_name: Identifier{
		
		}
;
Bit_selection : LBRACK Bit_kind_opt Integer_expression Bit_kind_opt RBRACK
	|	LBRACK Bit_kind_opt Integer_expression DOUBLEDOT Integer_expression Bit_kind_opt RBRACK
;
Bit_kind_opt :
/*	|	one
	|	sign
	|	zero*/
;
Enc_alias_opt :
	|	Enc_alias
;
Enc_alias : LESS ALIAS And_field_encoding GRT
;
Or_image_attribute : IMAGE COMMA Or_encoding_list COLON{$$=ortab.addent();}
;
Or_encoding_list : Or_field_encoding_list{ortab.finele();}
	|	Or_encoding_list BITOR Or_field_encoding_list{
		ortab.finele();
		}
;
Or_field_encoding_list : Or_field_encoding
	|	Or_field_encoding_list DCOLON Or_field_encoding
;
Or_field_encoding : Bit_string_literal{
			ortab.addele(STRING,strtab.addstr($1),0);
		}
	|	ENUM_NAME POINT Enum_element_name{
			int tmp=vartab.find($1);
			if(!tmp)
				printf("L%d: %s not defined\n",yylineno,$1);
			else if(vartab.gettype(tmp)!=ENUM)
				printf("L%d: %s wrong");
			else
				ortab.addele(ENUM,tmp,enumtab.findent(vartab.getval(tmp),$3));
		}
	/*|	Or_op_rule_image_ref
	|	Or_mode_rule_image_ref*/
	|	Rule_image_ref{
		ortab.addele(RULE_REF,($1).val,($1).ref);
		}
;
Bit_string_literal: String{$$=$1;}

/*Or_op_rule_image_ref : Op_rule_name Image_nr_opt
	|	MODE_RULE_NAME POINT IMAGE Image_nr_opt*/
/*
Data_type_def : PRIMITIVE CLASS Identifier SEMI
;
Data_type_attr : CST INT Identifier ASSIGN INT_CONST
;
*/
Identifier : IDENTIFIER{$$=$1;}
;
Integer : INT_CONST{($$).set_str($1);}
;
String : STRING_CONST{$$=$1;}
;
Binary : BINARY_CONST{$$=$1;}
;
Hex : HEX_CONST{$$=$1;}
;
Declaration_list : Declaration
	|	Declaration_list Declaration
;
Declaration:	Number_declaration
	|	Enum_declaration
	|	Constant_declaration
	|	Storage_declaration
/*	|	Fu_declaration
	|	Resource_declaration
	|	Property_declaration
	|	Hw_init_declaration*/
	|	Start_declaration
;
Start_declaration:
	|	START OP_RULE_NAME Exclusive_command_opt

/*OP_RULE_NAME: Identifier*/
;
Exclusive_command_opt:
	|	Exclusive_command
;
Exclusive_command: IS_EXCLUSIVE | MAKE_EXCLUSIVE
;
Number_declaration : DEF Identifier ASSIGN Integer_expression SEMI{
		int tmp=vartab.find($2);
		if(tmp)
			printf("L%d: %s previous defined at line %d\n",yylineno,$2,vartab.getdefline(tmp));
		else
		{
			int idx=strtab.addstr($2);
			tmp=numtab.add($4);
			vartab.add(strtab.getstr(idx),DEF,tmp,yylineno);
		}
		}
;
Integer_expression : Integer_expression PLUS Integer_expression{ $$ = $1 + $3 ; }
	|	Integer_expression MINUS Integer_expression{ $$ = $1 - $3 ; }
	|	Integer_expression MUL Integer_expression{ $$ = $1 * $3; }
	|	Integer_expression DIV Integer_expression{ $$ = $1 / $3 ; }
	|	MINUS  Integer_expression %prec NEG{ $$ = - ($1) ; }
	|	Integer_expression POW Integer_expression{
		if(!($3).fits_slong_p())//can fit into signed long
			printf("L%d:Exponent too large\n",yylineno);
		if($3<(signed long int)0)//should be positive
			printf("L%d:Exponent cannot be negative\n",yylineno);
		unsigned long int exp=(unsigned long int)$3;
		mpz_pow_ui(($$).get_mpz_t(),($1).get_mpz_t(),exp);}
	|	LPAREN  Integer_expression RPAREN{ $$ = $2 ; }
	|	Integer{ $$ = $1 ; }
	|	NUMBER_NAME{
		int tmp=vartab.find(strtab.getstr($1));
		if(!tmp)
			printf("L%d:Cannot find Number_name %s\n",yylineno,strtab.getstr($1));
		else
			$$=numtab.getval(vartab.getval(tmp));
		}

/*Number_name : Identifier{$$=strtab.addstr($1);}*/
;

Enum_declaration : ENUM Identifier LBRACE Enum_list RBRACE COMMA{
		int tmp=vartab.find($2);
		if(/*$4 &&*/ !tmp)
			vartab.add(strtab.getstr(strtab.addstr($2)),ENUM,enumtab.addentfin(),yylineno);
		else if(tmp)
			printf("L%d: %s already defined at %d",yylineno,$2,vartab.getdefline(tmp));
		enumtab.clearent();
		}

	/*	Enum_declare : ENUM Identifier{
		if(vartab.find($2));
			printf("L%d: %s previous defined at %d\n",yylineno,$1,vartab.getdefline(tmp));
		else vartab.add(strtab.getstr(strtab.addstr($1)),ENUM,0,yylineno);
		}*/
	;

Enum_list : Enum_element{}
	|	Enum_list COMMA Enum_element{}
;
Enum_element : Identifier Mnemonic_opt Init_opt{
		int tmp=strtab.addstr($1);
		if(!enumtab.addent(strtab.getstr(tmp),$2,$3))
			printf("L%d:Enum entry %s already defined\n",yylineno,$1);
		}
;

Mnemonic_opt : {$$=0;}
	|	STRING_CONST {$$=strtab.add($1);}
;
Init_opt : {$$=(mpz_class)-1;}
	|	ASSIGN Integer_expression {
		if($2<0)
		{
			printf("L%d:Value set for enum cannot be negative\n",yylineno);
			$$=-1;
		}
		else $$=$2;
		}
;

Constant_declaration : CST Identifier LESS TYPE_ID GRT Constant_value_opt SEMI{
		int tmp=vartab.find($2);
		if(tmp)
			printf("L%d: %s already defined at line %d\n",yylineno,$2,vartab.getdefline(tmp));
		else
		{
			tmp=vartab.find($4);
			if(!tmp)
				printf("L%d: Can not find type %s\n",$4);
			else if(vartab.gettype(tmp)!=TYPE)
				printf("L%d: %s is not defined as type",yylineno,$4);
			else
			{
				tmp=csttab.add(tmp,$6);
				vartab.add(strtab.getstr(strtab.addstr($2)),CST,tmp,yylineno);
			}
		}
		}
;
Constant_value_opt : {$$=mpz_class(0);}
	|	ASSIGN Integer{$$=$2;}
	|	ASSIGN Binary{($$).set_str($2,0);}
	|	ASSIGN Hex{($$).set_str($2,0);}
;
Storage_declaration : Memory_declaration
	|	Register_declaration
	|	Transitory_declaration
	|	Pipe_declaration
	|	Port_declaration
	|	Class_declaration

/*Type_id : Identifier{ $$=$1;} */
;
Memory_declaration : MEM Identifier Valid_address_declaration LESS TYPE_ID COMMA Address_type GRT
		Alias_declaration_opt
		/*Record_delcaration_opt*/
		Read_access_transitory_list_opt
		Write_access_transitory_list_opt
		SEMI{
		int tmp=vartab.find($2);
		if(tmp)
			printf("L%d: %s already defined at %d\n",yylineno,$2,vartab.getdefline(tmp));
		else
		{
			int typeid=vartab.find($5);
			int addresstype=vartab.find($7);
			if(!typeid)
				printf("L%d: type %s not defined\n",yylineno,$5);
			else if(vartab.gettype(typeid)!=TYPE)
				printf("L%d: %s is not defined as type\n",yylineno,$5);
			else if(!addresstype)
				printf("L%d: type %s not defined\n",yylineno,$7);
			else if(vartab.gettype(addresstype)!=TYPE)
				printf("L%d: %s is not defined as type\n",yylineno,$7);
			else
			{
				//tmp=memtab.add($3,typeid,addresstype,$9,$10,$11,$12);
				tmp=memtab.add(3,typeid,addresstype,9,10,11,12);
				vartab.add(strtab.getstr(strtab.addstr($2)),MEM,tmp,yylineno);
			}
		}
		}
;
Register_declaration : REG Identifier Valid_address_declaration_opt LESS TYPE_ID COMMA Address_type GRT
		Field_names_opt
		Alias_declaration_opt
		Record_declaration_opt
		Read_access_transitory_list_opt
		Write_access_transitory_list_opt
		SEMI{
		int tmp=vartab.find($2);
		if(tmp)
			printf("L%d: %s already defined at %d\n",yylineno,$2,vartab.getdefline(tmp));
		else
		{
			int typeid=vartab.find($5);
			int addresstype=vartab.find($7);
			if(!typeid)
				printf("L%d: %s not defined\n",yylineno,$5);
			else if(vartab.gettype(typeid)!=TYPE)
				printf("L%d: %s is not defined as type\n",yylineno,$5);
			else if(!addresstype)
				printf("L%d: %s not defined\n",yylineno,$7);
			else if(vartab.gettype(addresstype)!=TYPE)
				printf("L%d: %s is not defined as type\n",yylineno,$7);
			else
			{
				//tmp=memtab.add($3,typeid,addresstype,$9,$10,$11,$12,$13);
				tmp=memtab.add(3,typeid,addresstype,9,10,11,12,13);
				vartab.add(strtab.getstr(strtab.addstr($2)),REG,tmp,yylineno);
			}
		}
		}

;
Transitory_declaration : TRN Identifier LESS TYPE_ID GRT Record_declaration_opt SEMI
;
Pipe_declaration : PIPE Identifier LESS TYPE_ID GRT Record_declaration_opt SEMI
;
Port_declaration : INPORT Identifier LESS TYPE_ID GRT Record_declaration_opt SEMI
		OUTPORT Identifier LESS TYPE_ID GRT Record_declaration_opt SEMI
;
Class_declaration : CLASS Identifier Valid_address_declaration LESS TYPE_ID GRT Record_declaration SEMI
;
Valid_address_declaration_opt : 
	|	Valid_address_declaration 
;
Valid_address_declaration : 
	|	LBRACK Address_range Address_step_opt RBRACK
;
Address_range : Integer_expression {
		if($1<=0)
		{
			printf("L%d: address range should be a positive integer\n",yylineno);
			$$=class(0,0);
		}
		else
			$$=address_range_c(0,($1)_1);}
	|	Integer_expression DOUBLEDOT Integer_expression {
		if($1<0)
		{
			printf("L%d: address range should be nonnegative\n",yylineno);
			$1=0;
		}
		if($3<0)
		{
			printf("L%d: address range should be nonnegative\n",yylineno);
			$3=0;
		}
		if($1>$3)
			$$=address_range_c($3,$1);
		else $$=address_range_c($1,$3);}
;
Address_step_opt :
	|	COMMA Integer_expression
;
Address_type : TYPE_ID{ $$=$1;}
;
Alias_declaration_opt :
	|	Alias_declaration
;
Alias_declaration : ALIAS Identifier Align_opt
	|	ALIAS Identifier Offset_declaration
;
Offset_declaration : LBRACK Integer_expression RBRACK
;
Align_opt :
	|	ALIGN Integer_expression
;
Record_declaration_opt :
	|	Record_declaration
;
Record_declaration : LBRACE Storage_element_list RBRACE
;
Storage_element_list : Identifier SEMI
	|	Storage_element_list Identifier SEMI
;
Field_names_opt :
	|	Field_names
;
Field_names : SYNTAX LPAREN ENUM_NAME RPAREN
	|	SYNTAX LPAREN String RPAREN

/*Enum_name : Identifier{$$=$1;}*/
;
Read_access_transitory_list_opt : 
	|	Read_access_transitory_list
;
Write_access_transitory_list_opt :
	|	Write_access_transitory_list
;
Read_access_transitory_list : READ LPAREN Access_transitory_list RPAREN
;
Write_access_transitory_list : WRITE LPAREN Access_transitory_list RPAREN
;
Access_transitory_list :
	|	Access_transitory_list Access_transitory
;
Access_transitory : /*Transitory_name
	|	Pipe_name*/
		Transitory_name_Pipe_name
/*
Transitory_name : Identifier
;
Pipe_name : Identifier*/
;
Transitory_name_Pipe_name: Identifier
;

/*Logic_expression: Logic_expression Binary_logic_operator Logic_expression
	|	NOT Logic_expression
	|	LPAREN Logic_expression RPAREN
	|	Enum_value
;
Enum_value : Identifier
;
Binary_logic_operator: BITAND | BITOR*/
;
