#ifndef __SYMBOLS_HPP__
#define __SYMBOLS_HPP__


enum Token {t_eof, CHAR, INT, FLOAT, DOUBLE, ID, COMA, STRUCT, PUNTO_COMA,
            VOID, IF, ELSE, LBRA, RBRA, LPAR, RPAR, WHILE, DO, POINT, PRINT,
            SCAN, BREAK, RETURN, NUMERO, AND, OR, MAYOR, MENOR, IGUAL, MAYOROI,
            MENOROI, MAS, MENOS, ASIG, MUL, DIV, ESP, CARACTER, CADENA, NEGACION, DIFERENCIA};

enum NoTerm {strEmpty, programa, declaraciones, declaracion, dec_var, tipo, lista_var,
                decl_truck, body_struck, decl_fun, tipo_fun, lista_args, args, arg, 
                decl_locales, decl_local, bloque_sentencias, sentencias, sentencia, sentif,
                sentWhile, sentDo, sentAsig, parte_izq, sentPutw, sentPuts, sentScan,
                sentBreak, sentReturn, expresion, lista_params, params, param, bloque_o_sentencia};

#endif // !__SYMBOLS_HPP__
