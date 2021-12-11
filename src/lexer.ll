%{
#include <iostream>
#include <string>

using namespace std;

#include "tokens.h"
#include "Lexer.h"

%}

%option c++
%option outfile="Lexer.cpp"
%option yyclass="C_1::Lexer"
%option case-insensitive


%%
"char"  {return CHAR;}
"int"   {return INT;}
"float" {return FLOAT;}
"double" {return DOUBLE;}
"struct"    {return STRUCT;}
"," {return COMA;}
";" {return PUNTO_COMA;}
"void"  {return VOID;}
"if"    {return IF;}
"else"  {return ELSE;}
"{" {return LBRA;}
"}" {return RBRA;}
"(" {return LPAR;}
")" {return RPAR;}
"while" {return WHILE;}
"do"    {return DO;}
"." {return POINT;}
"print" {return PRINT;}
"scan"  {return SCAN;}
"break" {return BREAK;}
"return"    {return RETURN;}
"&&"    {return AND;}
"||"    {return OR;}
">" {return MAYOR;}
"<" {return MENOR;}
"=="    {return IGUAL;}
">="    {return MAYOROI;}
"<="    {return MENOROI;}
"+" {return MAS;}
"-" {return MENOS;}
"=" {return ASIG;}
"*" {return MUL;}
"/" {return DIV;}
"!" {return NEGACION;}
"!="    {return DIFERENCIA;}
[a-zA-Z_]([a-zA-Z0-9_])* {return ID;}
[0-9]+  {return NUMERO;}
([0-9])*.([0-9])+([Ee]([+-][)?([0-9])+)?    {return NUMERO;}
[+-]?([0-9])*[.]([0-9])+([Ee]([+-])?([0-9])+)?   {return NUMERO;}
[+-]?(((([0-9]+[.]?[0-9]*)|([.][0-9]+))([eE][+-]?[0-9]+[fF]?)?)|(([0-9]+[.][0-9]*)|([.][0-9]+))[fF]?)   {return NUMERO;}
[ \t\r\n]+ {return ESP;}
\'([a-zA-Z0-9]|[ \t\r\n])\' {return CARACTER;}
\'\'    {return CARACTER;}
\"([a-zA-Z0-9]|[ \t\r\n])*\"  {return CADENA;}
.   { cout << "ERROR LEXICO EN: " << yytext << endl;}

%%

int yyFlexLexer::yywrap(){
    return 1;
}