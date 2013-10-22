LEX = flex -v
YACC = bison -dv
CC = g++

test : drt.o drt.h front.h outputf.o test.cpp ormode_table.o op_image.o opn_table.o syntax_table.o par_table.o address_range_c.o mem_table.o address_table.o type_table.o cst_table.o enum_table.o integer_table.o front.o hash.o scanner.o nml.tab.o string_table.o num_table.o var_table.o oropn_table.o or_table.o -lgmpxx -lgmp
	$(CC) drt.o par_table.o outputf.o ormode_table.o op_image.o opn_table.o syntax_table.o address_range_c.o mem_table.o address_table.o cst_table.o type_table.o test.cpp enum_table.o integer_table.o front.o hash.o scanner.o nml.tab.o string_table.o num_table.o var_table.o oropn_table.o or_table.o -o test -lgmpxx

strstack.o: strstack.cpp
	$(CC) -c strstack.cpp -o strstack.o

l.o: l.c
	$(CC) -c l.c -o l.o

y.o: y.c
	$(CC) -c y.c -o y.o

l.h: 
	$(LEX) --header-file=l.h lexfile.l

ttest : ttest.cpp l.o y.o strstack.o strstack.h l.h
	$(CC) ttest.cpp l.o y.o strstack.o -o ttest

drt.o: drt.cpp syntax_table.h par_table.h opn_table.h ormode_table.h oropn_table.h var_table.h nml.tab.h op_image.h or_table.h enum_table.h string_table.h hash.h
	$(CC) -c drt.cpp -o drt.o

outputf.o: outputf.cpp
	$(CC) -c outputf.cpp -o outputf.o

ormode_table.o: ormode_table.cpp outputf.h
	$(CC) -c ormode_table.cpp -o ormode_table.o

op_image.o: op_image.cpp outputf.h
	$(CC) -c op_image.cpp -o op_image.o

opn_table.o: opn_table.cpp outputf.h
	$(CC) -c opn_table.cpp -o opn_table.o

syntax_table.o: syntax_table.cpp outputf.h
	$(CC) -c syntax_table.cpp -o syntax_table.o

par_table.o: par_table.cpp outputf.h
	$(CC) -c par_table.cpp -o par_table.o

oropn_table.o: oropn_table.cpp outputf.h
	$(CC) -c oropn_table.cpp -o oropn_table.o

or_table.o: or_table.cpp outputf.h
	$(CC) -c or_table.cpp -o or_table.o

address_range_c.o: address_range_c.cpp outputf.h
	$(CC) -c address_range_c.cpp -o address_range_c.o

mem_table.o: mem_table.cpp outputf.h
	$(CC) -c mem_table.cpp -o mem_table.o

address_table.o : address_table.cpp outputf.h
	$(CC) -c address_table.cpp -o address_table.o

type_table.o: type_table.cpp outputf.h
	$(CC) -c type_table.cpp -o type_table.o

cst_table.o: cst_table.cpp
	$(CC) -c cst_table.cpp -o cst_table.o
 
enum_table.o: enum_table.cpp outputf.h
	$(CC) -c enum_table.cpp -o enum_table.o
 
integer_table.o: integer_table.cpp -lgmpxx -lgmp
	$(CC) -c integer_table.cpp -o integer_table.o

front.o : opn_table.h front.cpp par_table.h op_image.h ormode_table.h syntax_table.h string_table.h num_table.h var_table.h integer_table.h or_table.h address_range_c.h address_table.h mem_table.h type_table.h cst_table.h enum_table.h oropn_table.h
	$(CC) -c front.cpp -o front.o

hash.o : hash.cpp
	$(CC) -c hash.cpp -o hash.o

string_table.o : string_table.cpp hash.h outputf.h
	$(CC) -c string_table.cpp -o string_table.o

num_table.o : num_table.cpp 
	$(CC) -c num_table.cpp -lgmpxx -o num_table.o

var_table.o : var_table.cpp outputf.h
	$(CC) -c var_table.cpp -o var_table.o

nml.tab.o : nml.tab.c 
	$(CC) -c nml.tab.c -o nml.tab.o

scanner.o : lex.yy.c nml.tab.h
	$(CC) -c lex.yy.c -o scanner.o

lex.yy.c : nml.lex
	$(LEX) nml.lex

nml.tab.c: nml.y
	$(YACC) nml.y

nml.tab.h: nml.y
	$(YACC) nml.y
clean:
	rm *.o lex.yy.c nml.tab.h nml.tab.c ttest l.c l.h y.y lexfile.l y.c

l.c: lexfile.l
	$(LEX) -o l.c lexfile.l

y.c: y.y
	$(YACC) -dv -o y.c y.y

lexfile.l: test in
	./test

y.y: test in
	./test
