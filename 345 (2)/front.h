#ifndef __front_H__
#define  __front_H__
#include "string_table.h"
#include "num_table.h"
#include "var_table.h"
#include "integer_table.h"
#include "enum_table.h"
#include "cst_table.h"
#include "type_table.h"
#include "mem_table.h"
#include "address_table.h"
#include "address_range_c.h"
#include "or_table.h"
#include "oropn_table.h"
#include "par_table.h"
#include "syntax_table.h"
#include "opn_table.h"
#include "op_image.h"
#include "ormode_table.h"

extern ormode_table ormodetab;
extern op_image opimg;
extern opn_table opntab;
extern syntax_trm_c syntab;
extern par_table partab;
extern oropn_table oroptab;
extern or_table ortab;
extern address_range_c addrangetab;
extern address_table addrtab;
extern mem_table memtab;
extern string_table strtab;
extern num_table numtab;
extern var_table vartab;
extern integer_table inttab;
extern enum_table enumtab;
extern cst_table csttab;
extern type_table typetab;
int output_h(const char * filename,bool h=true);
void setstart(const char * v);
const char * getstart();
#endif
