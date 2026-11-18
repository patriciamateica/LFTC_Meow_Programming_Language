%{
#include <stdio.h>

int yylex(void);
void yyerror(const char *msg);
void report_syntax_error(const char *msg);

FILE *prodf;
int nprod;

static void prod(const char *text) {
    nprod++;
    fprintf(prodf, "%d. %s\n", nprod, text);
}
%}

%define parse.error verbose
%start program

%token FRIEND TREATS ADOPT PAW CUDDLE SCRATCH PURR BABY ZOOMIES MEOW
%token SNIFF HISS BISCUITS MADE UP DOWN CHUNKY AND OR NOT
%token PLUS MINUS TIMES DIV MOD EQ NE LT LE GT GE ASSIGN ARROW
%token LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE SEMI COMMA
%token ID NUMBER STRING
%token UNKNOWN

%%

program      : stmt_list                          { prod("program -> stmt_list"); }
             ;

stmt_list    : statement                          { prod("stmt_list -> statement"); }
             | stmt_list statement                { prod("stmt_list -> stmt_list statement"); }
             ;

statement    : list_decl                          { prod("statement -> list_decl"); }
             | num_decl                           { prod("statement -> num_decl"); }
             | assign                             { prod("statement -> assign"); }
             | input_stmt                         { prod("statement -> input_stmt"); }
             | add_stmt                           { prod("statement -> add_stmt"); }
             | map_stmt                           { prod("statement -> map_stmt"); }
             | filter_stmt                        { prod("statement -> filter_stmt"); }
             | sort_stmt                          { prod("statement -> sort_stmt"); }
             | unique_stmt                        { prod("statement -> unique_stmt"); }
             | join_stmt                          { prod("statement -> join_stmt"); }
             | output_stmt                        { prod("statement -> output_stmt"); }
             | if_stmt                            { prod("statement -> if_stmt"); }
             | for_stmt                           { prod("statement -> for_stmt"); }
             ;

list_decl    : FRIEND ID ASSIGN list_literal SEMI { prod("list_decl -> friend ID = list_literal ;"); }
             ;

num_decl     : TREATS ID SEMI                     { prod("num_decl -> treats ID ;"); }
             | TREATS ID ASSIGN arith SEMI        { prod("num_decl -> treats ID = arith ;"); }
             ;

assign       : ref ASSIGN arith SEMI              { prod("assign -> ref = arith ;"); }
             ;

input_stmt   : ADOPT ref SEMI                     { prod("input_stmt -> adopt ref ;"); }
             ;

add_stmt     : PAW ID arith SEMI                  { prod("add_stmt -> paw ID arith ;"); }
             ;

map_stmt     : CUDDLE ID ID ARROW arith SEMI      { prod("map_stmt -> cuddle ID ID => arith ;"); }
             ;

filter_stmt  : SCRATCH ID ID ARROW cond SEMI      { prod("filter_stmt -> scratch ID ID => cond ;"); }
             ;

sort_stmt    : PURR ID order SEMI                 { prod("sort_stmt -> purr ID order ;"); }
             ;

unique_stmt  : BABY ID SEMI                       { prod("unique_stmt -> baby ID ;"); }
             ;

join_stmt    : ZOOMIES ID STRING SEMI             { prod("join_stmt -> zoomies ID STRING ;"); }
             ;

output_stmt  : MEOW out_list SEMI                 { prod("output_stmt -> meow out_list ;"); }
             ;

out_list     : out_item                           { prod("out_list -> out_item"); }
             | out_list COMMA out_item            { prod("out_list -> out_list , out_item"); }
             ;

out_item     : STRING                             { prod("out_item -> STRING"); }
             | arith                              { prod("out_item -> arith"); }
             ;

if_stmt      : SNIFF cond block                   { prod("if_stmt -> sniff cond block"); }
             | SNIFF cond block HISS block        { prod("if_stmt -> sniff cond block hiss block"); }
             ;

for_stmt     : BISCUITS ID MADE ID block          { prod("for_stmt -> biscuits ID made ID block"); }
             ;

block        : LBRACE stmt_list RBRACE            { prod("block -> { stmt_list }"); }
             ;

order        : UP                                 { prod("order -> up"); }
             | DOWN                               { prod("order -> down"); }
             ;

list_literal : LBRACKET RBRACKET                  { prod("list_literal -> [ ]"); }
             | LBRACKET arith_list RBRACKET       { prod("list_literal -> [ arith_list ]"); }
             ;

arith_list   : arith                              { prod("arith_list -> arith"); }
             | arith_list COMMA arith             { prod("arith_list -> arith_list , arith"); }
             ;

cond         : and_cond                           { prod("cond -> and_cond"); }
             | cond OR and_cond                   { prod("cond -> cond or and_cond"); }
             ;

and_cond     : not_cond                           { prod("and_cond -> not_cond"); }
             | and_cond AND not_cond              { prod("and_cond -> and_cond and not_cond"); }
             ;

not_cond     : NOT not_cond                       { prod("not_cond -> not not_cond"); }
             | comparison                         { prod("not_cond -> comparison"); }
             ;

comparison   : arith comp_op arith                { prod("comparison -> arith comp_op arith"); }
             ;

comp_op      : EQ                                 { prod("comp_op -> =="); }
             | NE                                 { prod("comp_op -> !="); }
             | LT                                 { prod("comp_op -> <"); }
             | LE                                 { prod("comp_op -> <="); }
             | GT                                 { prod("comp_op -> >"); }
             | GE                                 { prod("comp_op -> >="); }
             ;

arith        : term                               { prod("arith -> term"); }
             | arith PLUS term                    { prod("arith -> arith + term"); }
             | arith MINUS term                   { prod("arith -> arith - term"); }
             ;

term         : factor                             { prod("term -> factor"); }
             | term TIMES factor                  { prod("term -> term * factor"); }
             | term DIV factor                    { prod("term -> term / factor"); }
             | term MOD factor                    { prod("term -> term % factor"); }
             ;

factor       : NUMBER                             { prod("factor -> NUMBER"); }
             | ref                                { prod("factor -> ref"); }
             | CHUNKY LPAREN ID RPAREN            { prod("factor -> chunky ( ID )"); }
             | LPAREN arith RPAREN                { prod("factor -> ( arith )"); }
             ;

ref          : ID                                 { prod("ref -> ID"); }
             | ID LBRACKET arith RBRACKET         { prod("ref -> ID [ arith ]"); }
             ;

%%

void yyerror(const char *msg) {
    report_syntax_error(msg);
}
