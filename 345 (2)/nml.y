%{
#include <gmpxx.h>
#include "front.h"
#include <iostream>
extern int yylineno;
extern var_table vartab;
extern string_table strtab;
extern num_table numtab;
void yyerror(const char *s);
extern int yylex(void);
%}

%token
ASSIGN
DEF
SEMI
<charP> IDENTIFIER
PLUS
MINUS
DIV
POW
LPAREN
RPAREN
LBRACE
RBRACE
ENUM
<charP>STRING_CONST
COMMA
CST
LESS
GRT
TYPE
<charP>INT_CONST
<charP>BIN_CONST
<charP>HEX_CONST
<index>VAL_TYPE
SYNTAX
MEM
LBRACK
RBRACK
DOUBLEDOT
REG
START
OP
RULE_REF
DCOLON
IMAGE
POINT
COLON
BITOR
OP_OR_RULE
OP_AND_RULE
MODE_AND_RULE
MODE_OR_RULE
CYCLES
ALIAS
CHESS_PC_OFFSET
CLASS
DELAY_SLOTS
MODE
<charP>ENUM_NAME
%union{
const char* charP;
int index;
}

%left PLUS MINUS
%left MUL DIV
%nonassoc NEG
%right POW

%type <charP> integer
%type <charP> mnemonic_opt 
%type <index> init_opt 
%type <index> type_id
%type <index> cst_value_opt
%type <index> val_type
%type <index> valid_address_declaration
%type <index> address_step_opt
%type <index> address_type
%type <index> address_range
%type <charP> op_rule_name
%type <index> image_nr_opt
%type <index> image_nr
%type <index> or_image_attribute
%type <index> or_image_attribute_list
%type <charP> enum_element_name
%type <charP> bit_string_literal
%type <charP> rule_instant_name
%type <index> syntax_nr
%type <index> syntax_nr_opt
%type <charP> number_name
%type <charP> r_name
%%

nml_description: declaration_list rule_list
;

rule_list: rule
	| rule_list rule
;

rule: op_rule
	| mode_rule
;

mode_rule: or_mode_rule
	| and_mode_rule
;

and_mode_rule: MODE IDENTIFIER LPAREN parameter_declaration_list RPAREN
	LBRACE syntax_attribute_list and_image_attribute_list RBRACE{
	int tmp=vartab.find($2);
	int z=partab.clear();
	if(tmp)
		fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,$2,vartab.getdefline(tmp));
	else
	{
		vartab.add($2,MODE_AND_RULE,opntab.add(z,syntab.addtrm(),opimg.addtrm()),yylineno);
	}
};

or_mode_rule: MODE IDENTIFIER LPAREN mode_rule_name_list RPAREN 
	LBRACE or_image_attribute_list RBRACE{
	int tmp=vartab.find($2);
	if(tmp)
	{
		fprintf(stderr,"L%d: %s already defined at %d\n",yylineno,$2,vartab.getdefline(tmp));
		partab.clear();
	}
	else vartab.add($2,MODE_OR_RULE,ormodetab.add(partab.clear(),$7),yylineno);
};

mode_rule_name_list: mode_rule_name
	| mode_rule_name_list mode_rule_name;

mode_rule_name: IDENTIFIER{
	int tmp=vartab.find($1);
	if(!tmp)
		fprintf(stderr,"L%d: %s not defined\n",yylineno,$1);
	else
	{
		int type=vartab.gettype(tmp);
		if(type!=MODE_OR_RULE && type!=MODE_AND_RULE)
			fprintf(stderr,"L%d: %s is not a mode rule\n",yylineno,$1);
		else partab.add($1,$1);
	}
};

op_rule: and_op_rule
	| or_op_rule
;

and_op_rule: OP IDENTIFIER LPAREN parameter_declaration_list RPAREN
	LBRACE /*action_attribute*/ syntax_attribute_list and_image_attribute_list RBRACE{
	int tmp=vartab.find($2);
	if(tmp)
	{
		fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,$2,vartab.getdefline(tmp));
		partab.clear();
	}
	else vartab.add($2,OP_AND_RULE,opntab.add(partab.clear(),syntab.addtrm(),opimg.addtrm()),yylineno);
};

and_image_attribute_list: {}
	| and_image_attribute_list and_image_attribute{}
;

and_image_attribute: IMAGE COLON and_field_encoding_list instr_properties_opt SEMI{
	opimg.addalt();
};

instr_properties_opt:
	| COMMA instr_properties;

instr_properties: instr_property
	| instr_properties COMMA instr_property
;

instr_property:
        |       CYCLES LPAREN  integer_expression RPAREN
        |       CYCLES LPAREN integer_expression BITOR integer_expression RPAREN
        |       DELAY_SLOTS LPAREN integer_expression RPAREN
        |       CHESS_PC_OFFSET LPAREN integer_expression RPAREN
        |       CLASS LPAREN IDENTIFIER RPAREN
;

and_field_encoding_list: and_field_encoding enc_alias_opt
	| and_field_encoding_list DCOLON and_field_encoding enc_alias_opt
;

enc_alias_opt:
	| enc_alias
;

enc_alias: LESS ALIAS /*and_field_encoding*/ GRT;

and_field_encoding: STRING_CONST {opimg.addele(STRING_CONST,strtab.addstr($1),0);}
	| ENUM_NAME POINT enum_element_name{
		int tmp=vartab.find($1);
		tmp=vartab.getval(tmp);
		int idx=enumtab.findent(tmp,$3);
		if(!idx)
			fprintf(stderr,"L%d: no entry %s in %s\n",yylineno,$3,$1);
		else opimg.addele(ENUM,tmp,idx);
	}
	| rule_instant_name image_nr_opt{
		opimg.addele(RULE_REF,partab.find($1),$2);
	}
	//| cst_expression
	//| cst_expression bit_selection
;

rule_instant_name: IDENTIFIER{
	int tmp=partab.find($1);
	$$=NULL;
	if(!tmp)
		fprintf(stderr,"L%d: %s not declared\n",yylineno,$1);
	else $$=$1;
};

syntax_attribute_list:
	| syntax_attribute_list syntax_attribute{
};

syntax_attribute: SYNTAX COLON syntax_encoding_list SEMI{
	syntab.addalt();
};

syntax_encoding_list: syntax_encoding{
//	| syntax_encoding_list BITOR syntax_encoding{
};

syntax_encoding: syntax_encoding_element{}
	| syntax_encoding syntax_encoding_element{};

syntax_encoding_element: STRING_CONST{syntab.addele(syntax_ref_c(STRING_CONST,strtab.addstr($1),0));}
	| rule_instant_name syntax_nr_opt{
	/*TODO no check on rule_instant_name(such as enum cannot follow by syntax_nr*/
	syntab.addele(syntax_ref_c(RULE_REF,partab.find($1),$2/*TODO check size*/));
};

syntax_nr_opt: {$$=0;}
	| syntax_nr {$$=$1;};

syntax_nr: POINT integer{
	$$=0;
	mpz_class t=(mpz_class)$2;
	if(!t.fits_sint_p())
		fprintf(stderr,"L%d: %s too large\n",yylineno,$2);
	else if(t<0)
		fprintf(stderr,"L%d: %s should not be negative\n",yylineno,$2);
	else $$=t.get_si();
};
/*
poi_syntax_opt:
	| POINT SYNTAX;*/

parameter_declaration_list: 
	| parameter_declaration
	| parameter_declaration_list COMMA parameter_declaration;

parameter_declaration: IDENTIFIER COLON r_name{
	int tmp=partab.find($1);
	if(tmp)
		fprintf(stderr,"L%d: %s already declared\n",yylineno,$1);
	else
	{
		tmp=vartab.find($3);
		partab.add($1,$3);
	}
};

r_name: IDENTIFIER{
	int tmp=vartab.find($1);
	$$=NULL;
	if(!tmp)
		fprintf(stderr,"L%d: %s not defined\n",yylineno,$1);
	else
	{
		int type=vartab.gettype(tmp);
		if(type!=OP_OR_RULE && type!=OP_AND_RULE
		&& type!=MODE_OR_RULE && type!=MODE_AND_RULE
		&& type!=CST)
			fprintf(stderr,"L%d: %s wrong type\n",yylineno,$1);
		else $$=$1;
	}
}
	| ENUM_NAME{
	$$=$1;
};

or_op_rule:  OP IDENTIFIER LPAREN op_rule_name_list RPAREN 
	LBRACE or_image_attribute_list RBRACE{
	int tmp=vartab.find($2);
	if(tmp)
	{
		fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,$2,vartab.getdefline(tmp));
		partab.clear();
	}
	else
	{
		vartab.add($2,OP_OR_RULE,oroptab.add(partab.clear(),$7),yylineno);
	}
};

or_image_attribute_list: or_image_attribute{$$=$1;};

or_image_attribute: IMAGE COLON or_encoding_list SEMI{
	$$=ortab.addent();
};

or_encoding_list: or_field_encoding_list{ortab.finele();}
	| or_encoding_list BITOR or_field_encoding_list{ortab.finele();};

or_field_encoding_list: or_field_encoding
	| or_field_encoding_list DCOLON or_field_encoding;

enum_element_name: IDENTIFIER{
	$$=$1;
};

or_field_encoding: bit_string_literal{
		ortab.addele(STRING_CONST,strtab.addstr($1),0);
	}
	| ENUM_NAME POINT enum_element_name{
		int ename=vartab.find($1);
		int tmp=0;
		if(ename)
			tmp=enumtab.findent(vartab.getval(ename),$3);
		if(!tmp)
			fprintf(stderr,"L%d: enum %s has not entry %s\n",yylineno,$1,$3);
		ortab.addele(ENUM,ename,tmp);
	}
	| rule_instant_name image_nr_opt{
		//ortab.addele(RULE_REF,vartab.getval(vartab.find(partab.getval(partab.find($1)))),$2);
		ortab.addele(RULE_REF,partab.find($1),$2);
};

image_nr_opt: {$$=0;}
	| image_nr{$$=$1;}
;

image_nr: POINT integer{
	mpz_class t=(mpz_class)$2;
	$$=0;
	if(!t.fits_sint_p())
		fprintf(stderr,"L%d: number %s too large\n",yylineno,$2);
	else if(t<0)
		fprintf(stderr,"L%d: expect a positive number at %s\n",yylineno,$2);
	else $$=t.get_si();
};

bit_string_literal: STRING_CONST{$$=$1;};

op_rule_name: IDENTIFIER{
	int tmp=vartab.find($1);
	$$=NULL;
	if(!tmp)
	{
		fprintf(stderr,"L%d: %s not defined\n",yylineno,$1);
	}
	else
	{
		int type=vartab.gettype(tmp);
		if(type!=OP_AND_RULE && type!=OP_OR_RULE && type!=MODE_AND_RULE && type!=MODE_OR_RULE)
			fprintf(stderr,"L%d %s wrong type\n",yylineno,$1);
		else
			$$=$1;
	}
};

op_rule_name_list: op_rule_name{
	if(partab.find($1))
		fprintf(stderr,"L%d: %s already declared\n",yylineno,$1);
	partab.add($1,vartab.getname(vartab.find($1)));}
	| op_rule_name_list BITOR op_rule_name{
	if(partab.find($3))
		fprintf(stderr,"L%d: %s already declared\n",yylineno,$3);
	partab.add($3,vartab.getname(vartab.find($3)));
};

declaration_list: declaration
	| declaration_list declaration
;

declaration: number_declaration
	| enum_declaration
	| cst_declaration
	| type_declaration
	| storage_declaration
	| start_declaration
;

start_declaration: START IDENTIFIER/*op_rule_name exclusive_command_opt*/ SEMI{
	/*int tmp=vartab.find($2);
	if(setstart(tmp))
		fprintf(stderr,"L%d: %s alreay declared as start rule\n",yylineno,vartab.getname(tmp));*/
	setstart($2);
};

storage_declaration: memory_declaration
	| register_declaration;

register_declaration: REG IDENTIFIER valid_address_declaration LESS type_id COMMA address_type GRT
                /*Field_names_opt
                Alias_declaration_opt
                Record_declaration_opt
                Read_access_transitory_list_opt
                Write_access_transitory_list_opt*/
                SEMI{
	int tmp=vartab.find($2);
	if(tmp)
		fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,$2,vartab.getdefline(tmp));
	else
	{
		tmp=memtab.add($3,$5,$7,9,10,11,12);/*TODO*/
		vartab.add($2,REG,tmp,yylineno);
	}
};

memory_declaration: MEM IDENTIFIER valid_address_declaration LESS type_id COMMA address_type GRT
	/*alias_opt
	record_declaration
	read_access_transitory_list_opt
	write_access_transitory_list_opt*/
	SEMI{
	int tmp=vartab.find($2);
        if(tmp)
                fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,$2,vartab.getdefline(tmp));
        else
        {
                int tid=$5;
                int addresstype=$7;
                //tmp=memtab.add($3,typeid,addresstype,$9,$10,$11,$12);
                tmp=memtab.add($3,tid,addresstype,9,10,11,12);
                vartab.add($2,MEM,tmp,yylineno);
        }
};

address_type: type_id{$$=$1;};

valid_address_declaration: {$$=0;}
        |       LBRACK address_range address_step_opt RBRACK{
	$$=addrtab.add($2,$3);
};

address_step_opt :{$$=numtab.add(1);}
        |       COMMA integer_expression{
	$$=numtab.add(inttab.getans());
	inttab.clear();
};

type_declaration: TYPE IDENTIFIER LESS integer COMMA val_type GRT SEMI{
	int tmp=vartab.find($2);
	if(tmp)
		fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,$2,vartab.getdefline(tmp));
	else
	{
		mpz_class width;
		width=(mpz_class)$4;
		if(width<=0)
		{
			fprintf(stderr,"L%d: %s width of type should be positive",yylineno,$2);
			width=1;/*TODO*/
		}
		vartab.add($2,TYPE,typetab.add($2,$6,width.get_ui()),yylineno);
	}
};

address_range : integer_expression {
		mpz_class tmp=inttab.getans();
		inttab.clear();
                if(tmp<=0)
                {
                        fprintf(stderr,"L%d: address range should be a positive integer\n",yylineno);
                        $$=0;
                }
                else
                        $$=addrangetab.add(numtab.add(0),numtab.add(tmp-1));}
        |       integer_expression DOUBLEDOT integer_expression {
		mpz_class e=inttab.getans();
		mpz_class b=inttab.getans();
		inttab.clear();
                if(e<0)
                {
                        fprintf(stderr,"L%d: address range should be nonnegative\n",yylineno);
                        e=0;
                }
                if(b<0)
                {
                        fprintf(stderr,"L%d: address range should be nonnegative\n",yylineno);
                        b=0;
                }
                if(e>=b)
                        $$=addrangetab.add(numtab.add(b),numtab.add(e));
                else $$=addrangetab.add(numtab.add(e),numtab.add(b));
};

val_type: VAL_TYPE{
	$$=$1;
};
cst_declaration: CST IDENTIFIER LESS type_id GRT cst_value_opt SEMI{
	int tmp=vartab.find($2);
	if(tmp)
		fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,$2,vartab.getdefline(tmp));
	else
	{
		if(numtab.getwidth($6)>typetab.getwidth($4))
			fprintf(stderr,"L%d: %s is too large for type of width %d\n",
			yylineno,numtab.getstr($6),typetab.getwidth($4));
      		tmp=csttab.add($4,$6);
		vartab.add($2,CST,tmp,yylineno);
	}
};

cst_value_opt : {$$=numtab.add(0);}
        | ASSIGN INT_CONST{mpz_class tmp;tmp=$2;$$=numtab.add(tmp);}
	| ASSIGN BIN_CONST{mpz_class tmp;tmp.set_str($2,0);$$=numtab.add(tmp);}
	| ASSIGN HEX_CONST{mpz_class tmp;tmp.set_str($2,0);$$=numtab.add(tmp);}
;

type_id: IDENTIFIER{
	int tmp=vartab.find($1);
	$$=0;
	if(!tmp)
		fprintf(stderr,"L%d: Can not find type %s\n",yylineno,$1);
	else if(vartab.gettype(tmp)!=TYPE)
		fprintf(stderr,"L%d: %s is not defined as type\n",yylineno,$1);
	else $$=vartab.getval(tmp);
};

enum_declaration: ENUM IDENTIFIER LBRACE enum_list RBRACE SEMI{
	int tmp=vartab.find($2);
	int t=enumtab.addentfin();
	if(!tmp)
		vartab.add($2,ENUM,t,yylineno);
	else fprintf(stderr,"L%d: %s already defined at line %d\n",yylineno,$2,vartab.getdefline(tmp));
	enumtab.clearent();
};

enum_list: enum_element
	|	enum_list COMMA enum_element
;

enum_element: IDENTIFIER mnemonic_opt init_opt{
	if(!enumtab.addent($1,$2,$3))
		fprintf(stderr,"L%d:Enum entry %s already defined\n",yylineno,$1);
};

mnemonic_opt: {$$=NULL;}
	|	STRING_CONST{$$=$1;}
;

init_opt: {$$=-1;}
        |	ASSIGN integer_expression {
	mpz_class tmp=inttab.getans();
	if(tmp<0)
	{
		fprintf(stderr,"L%d:Value set for enum cannot be negative\n",yylineno);
		$$=-1;
	}
	else $$=tmp.get_si();
	inttab.clear();
};

number_declaration: DEF IDENTIFIER ASSIGN integer_expression SEMI{
	int tmp=vartab.find($2);
	if(tmp)
		fprintf(stderr,"L%d: %s previous defined at line %d\n",yylineno,$2,vartab.getdefline(tmp));
	else
	{
		mpz_class tmp=inttab.getans();
		int t=numtab.add(tmp);
		inttab.clear();
		vartab.add($2,DEF,t,yylineno);
	}
};

integer_expression : integer_expression PLUS integer_expression{ inttab.vadd(); }
	|	integer_expression MINUS integer_expression{ inttab.vsub(); }
	|	integer_expression MUL integer_expression{ inttab.vmul(); }
	|	integer_expression DIV integer_expression{ inttab.vdiv(); }
	|	MINUS  integer_expression %prec NEG{ inttab.vneg() ; }
	|	integer_expression POW integer_expression{inttab.vpow();}
	|	LPAREN  integer_expression RPAREN{ }
	|	integer{ inttab.add($1) ; }
	|	number_name{
		inttab.add(numtab.getval(vartab.getval(vartab.find($1))));
		}
;

number_name: IDENTIFIER{
	int tmp=vartab.find($1);
	$$=0;
	if(!tmp)
		fprintf(stderr,"L%d: %s not defined\n",yylineno,$1);
	else $$=$1;
};

integer: INT_CONST{
	$$=$1;
};
%%
void yyerror(const char *s)
{
	fprintf (stderr, "L%d: %s\n",yylineno,s);
}
