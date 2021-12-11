#include "Parser.h"
//#include "AL/tokens.h"
#include <iostream>

namespace C_1
{
  Parser::Parser(/* args */)
  {
  }

  Parser::Parser(Lexer *lexer)
  {
    this->lexer = lexer;
  }

  Parser::~Parser()
  {
  }

  /************************************************************************/
  /**                                                                    **/
  /**                       Funciones por cada NT                        **/
  /**                                                                    **/
  /************************************************************************/

  void Parser::programa(){
    std::cout << " En programa" << '\n';
    declaraciones();
  }

  void Parser::declaraciones(){
    std::cout << " En declaraciones" << '\n';
    declaraciones();
    declaracion();
  }
  
  void Parser::declaracion() {
    std::cout << " En declaracion" << '\n';
    decl_var();
    decl_struct();
    decl_fun();
  }

  void Parser::decl_var() {
    std::cout << " En decl_var" << '\n';
    tipo();
    lista_var();
  }

  void Parser::tipo() {
    std::cout << " En tipo" << '\n';
    switch(token) {
      case CHAR:
        eat(CHAR);
        break;
      case INT:
        eat(INT);
        break;
      case FLOAT:
        eat(FLOAT);
        break;
      case DOUBLE:
        eat(DOUBLE);
        break;
      default:
        error("Se esperaba un tipo númerico o un char");
        break;
    }
  }

  void Parser::lista_var(){
    std::cout << " En lista_var" << '\n';
    switch(token) {
      case COMA:
        eat(COMA);
        eat(ID);
        break;
      case ID:
        eat(ID);
        break;
      default:
        error("se esperaba una coma o identificador");
    }
  }

  void Parser::decl_struct() {
    std::cout << " En decl_struck" << '\n';
    eat(STRUCT);
    if(token == ID) {
      eat(ID);
    }
    body_struct();
    lista_var();
    eat(PUNTO_COMA);
  }

  void Parser::body_struct(){
    std::cout << " En body_struct" << '\n'; 
    eat(LBRA);
    decl_locales();
    eat(RBRA);
  }
    
  void Parser::decl_fun(){
    std::cout << " En decl_fun" << '\n';
    tipo_fun();
    eat(ID);
    eat(LPAR);
    lista_args();
    eat(RPAR);
    eat(LBRA);
    decl_locales();
    bloque_sentencias();
    eat(RBRA);
  }

  void Parser::tipo_fun(){
    std::cout << " En tipo_fun" << '\n';

    switch(token) {
      case VOID:
        eat(VOID);
        break;
      case STRUCT:
        eat(STRUCT);
        eat(ID);
        break;
      default:
        tipo();
        break;
    }
  }

  void Parser::lista_args() {
    std::cout << " En lista_args" << '\n';
    args();
  }

  void Parser::args() {
    std::cout << " En args" << '\n';
    if(token == COMA) {
      eat(COMA);
    }

    arg();  
  }

  void Parser::arg() {
    std::cout << " En arg" << '\n';
    tipo();
    eat(ID);
  }

  void Parser::decl_locales() {
    std::cout << " En decl_locales" << '\n';
    decl_local();
  }

  void Parser::decl_local() {
    std::cout << " En decl_local" << '\n';
    decl_var();
  }

  void Parser::bloque_sentencias() {
    std::cout << " En bloque_sentencias" << '\n';
    sentencias();
  }

  void Parser::sentencias() {
    std::cout << " En sentencias" << '\n';
    sentencia();
  }

  void Parser::sentencia() {
    std::cout << " En sentencia" << '\n';
    sentif();
    sentWhile();
    sentPuts();
    sentPutw();
    sentAsig();
    sentBreak();
    sentDo();
    sentReturn();
    sentScan();
  }

  void Parser::sentif() {
    std::cout << " En sentif" << '\n';
    eat(IF);
    eat(LPAR);
    expresion();
    eat(RPAR);
    bloque_o_sentencia();
    if(token == ELSE) {
      eat(ELSE);
      bloque_o_sentencia();
    }    
  }

  void Parser::sentWhile() {
    std::cout << " En sentWhile" << '\n';
    eat(WHILE);
    eat(LPAR);
    expresion();
    eat(RPAR);
    bloque_o_sentencia();
  }

  void Parser::sentDo() {
    std::cout << " En sentWhile" << '\n';
    eat(DO);
    bloque_o_sentencia();
    eat(WHILE);
    eat(LPAR);
    expresion();
    eat(RPAR);
    eat(PUNTO_COMA);
  }

  void Parser::sentAsig() {
    std::cout << " En sentAsig" << '\n';
    parte_izq();
    eat(ASIG);
    expresion();
  }
  
  void Parser::parte_izq() {
    std::cout << " En parte_izq" << '\n';
    eat(ID);

    if(token == POINT) {
      eat(POINT);
      eat(ID);
    }
  }
  
  void Parser::sentPutw() {
    std::cout << " En sentPutw" << '\n';
    eat(PRINT);
    eat(LPAR);
    expresion();
    eat(RPAR);
    eat(PUNTO_COMA);
  }
  
  void Parser::sentPuts() {
    std::cout << " En sentPuts" << '\n';
    eat(PRINT);
    eat(LPAR);
    eat(CADENA);
    eat(RPAR);
    eat(PUNTO_COMA);
  }
  
  void Parser::sentScan(){
    std::cout << " En sentScan" << '\n';
    eat(SCAN);
    eat(ID);
    eat(PUNTO_COMA);
  }
  
  void Parser::sentBreak() {
    std::cout << " En sentBreak" << '\n';
    eat(BREAK);
    eat(PUNTO_COMA);
  }
  
  void Parser::sentReturn() {
    std::cout << " En sentReturn" << '\n';
    eat(RETURN);
    if(token == PUNTO_COMA) {
      eat(PUNTO_COMA);
    }else {
      expresion();
      eat(PUNTO_COMA);
    }
  }
  
  void Parser::expresion() {
    std::cout << " En sentReturn" << '\n';

    if(token == ID) {
      switch(token) {
      case ID:
        eat(ID);
        switch(token) {
          case LPAR:
            eat(LPAR);
            lista_params();
            eat(RPAR);
            break;
          case POINT:
            eat(POINT);
            eat(ID);
            break;
          default:
            break;
        }
        break;
      case NUMERO:
        eat(NUMERO);
        break;
      case CARACTER:
        eat(CARACTER);
        break;
      }
    }else {
      if(token == NEGACION) {
        eat(NEGACION);
        expresion();
      }else if(token == LPAR) {
        eat(LPAR);
        expresion();
        eat(RPAR);
      }else {
        expresion();
      switch(token){
        case MAS:
          eat(MAS);
          expresion();
          break;
        case MENOS:
          eat(MENOS);
          expresion();
          break;
        case OR:
          eat(OR);
          expresion();
          break;
        case AND:
          eat(AND);
          expresion();
          break;
         case MENOR:
          eat(MENOR);
          expresion();
          break;
         case MAYOR:
          eat(MAYOR);
          expresion();
          break;
         case IGUAL:
          eat(IGUAL);
          expresion();
          break;
         case DIFERENCIA:
          eat(DIFERENCIA);
          expresion();
          break;
         case MAYOROI:
          eat(MAYOROI);
          expresion();
          break;
         case MENOROI:
          eat(MENOROI);
          expresion();
          break;
         case MUL:
          eat(MUL);
          expresion();
          break;
         case DIV:
          eat(DIV);
          expresion();
          break;
         default:
          error("Se esperaba un operador");
      }         
      }
    }   
  }
  
  void Parser::lista_params() {
    std::cout << " En lista_params" << '\n';
    params();
  }
  
  void Parser::params(){
    std::cout << " En params" << '\n';
    if(token == COMA) {
      eat(COMA);
    }
    param();
  }
  
  void Parser::param() {
    std::cout << " En param" << '\n';
    expresion();
  }
  
  void Parser::bloque_o_sentencia(){
    std::cout << " En bloque_o_sentencia" << '\n';
    if(token == LBRA) {
      eat(LBRA);
      sentencias();
      eat(RBRA);
    }else {
      sentencia();
    }
  }


void Parser::eat(int t){
    if(token == t) {
      cout << "token: " << lexer -> YYText() << " " << token << endl;
      token = lexer->yylex();
      if (token == ESP) {
        eat(ESP);
      }
    }
    else {
      cout << "token: " << lexer->YYText() << " " << token << endl;
      cout << "t: " << t << " " << t << endl;
      string err = lexer->YYText();
      error("Se esperaba el token "+ err);
    }
  }

  void Parser::error(string msg){
    cout << lexer->YYText() << " " << token << endl;
    cout << "ERROR DE SINTAXIS " << msg <<endl;
    exit(1);
  }

  void Parser::parse(){
    token = lexer->yylex();
    programa();
    cout << lexer->YYText() << " " << token << endl;
    if(token == 0)
      cout << "La cadena es aceptada" << endl;
    else
      cout << "La cadena no pertenece al lenguaje generado por la gramática" << endl;
  }
}