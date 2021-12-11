#ifndef PARSER_H
#define PARSER_H
#include "./AL/Lexer.h"
#include <string>
using namespace std;
#include "./AL/tokens.h"

namespace C_1
{
  class Parser
  {

  private:
    Lexer *lexer;
    int token;

  public:
    Parser();
    Parser(Lexer *lexer);
    ~Parser();

    void programa(); //función del símbolo incial
    void declaraciones();
    void declaracion();
    void decl_var();
    void tipo();
    void lista_var();
    void decl_struct();
    void body_struct();
    void decl_fun();
    void tipo_fun();
    void lista_args();
    void args();
    void arg();
    void decl_locales();
    void decl_local();
    void bloque_sentencias();
    void sentencias();
    void sentencia();
    void sentif();
    void sentWhile();
    void sentDo();
    void sentAsig();
    void parte_izq();
    void sentPutw();
    void sentPuts();
    void sentScan();
    void sentBreak();
    void sentReturn();
    void expresion();
    void lista_params();
    void params();
    void param();
    void bloque_o_sentencia();


    void eat(int t);
    void error(string msg);
    void parse();
  };
}


#endif