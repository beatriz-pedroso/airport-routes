#makefile
all: rotas

funcoes.o: funcoes.c headers.h
	gcc -c -ansi -pedantic -Wall funcoes.c
distancias.o: distancias.c headers.h
	gcc -c -ansi -pedantic -Wall distancias.c
cria_pilhas_escalas.o: cria_pilhas_escalas.c headers.h
	gcc -c -ansi -pedantic -Wall cria_pilhas_escalas.c
abrefich_aloca_liberta.o: abrefich_aloca_liberta.c headers.h
	gcc -c -ansi -pedantic -Wall abrefich_aloca_liberta.c
testes.o: testes.c headers.h
	gcc -c -ansi -pedantic -Wall testes.c
ordenacoes.o: ordenacoes.c headers.h
	gcc -c -ansi -pedantic -Wall ordenacoes.c
mostra_rotas.o: mostra_rotas.c headers.h
	gcc -c -ansi -pedantic -Wall mostra_rotas.c
inicializacoes.o: inicializacoes.c headers.h
	gcc -c -ansi -pedantic -Wall inicializacoes.c
func_main.o: func_main.c headers.h
	gcc -c -ansi -pedantic -Wall func_main.c
main.o: main.c headers.h
	gcc -c -ansi -pedantic -Wall main.c


rotas: main.o funcoes.o distancias.o cria_pilhas_escalas.o abrefich_aloca_liberta.o testes.o ordenacoes.o mostra_rotas.o inicializacoes.o func_main.o
	gcc main.o funcoes.o distancias.o cria_pilhas_escalas.o abrefich_aloca_liberta.o testes.o ordenacoes.o mostra_rotas.o inicializacoes.o func_main.o -o rotas -lm

clean:
	rm main.o funcoes.o cria_pilhas_escalas.o  rotas 
run: 
	./rotas MADRID FRANKFURT -L 2 ALL