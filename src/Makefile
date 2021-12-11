TARGET = compiler
OBJS = Lexer.o main.o

$(TARGET) : $(OBJS)
	g++ $(OBJS) -o $(TARGET)
	./compiler prueba

Lexer.o : tokens.h Lexer.h
	flex++ lexer.ll
	g++ -g -c Lexer.cpp

main.o : main.cpp Lexer.h
	g++ -g -c main.cpp

.PHONY : clean
clean:
	rm -f *.o Lexer.cpp		$(TARGET)