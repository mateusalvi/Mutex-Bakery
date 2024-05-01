############################################################
#                                                          #
# INF01151 - Sistemas Operacionais II N - Turma A (2024/1) #
#           Mateus Luiz Salvi - Bianca Pelegrini           #
#                                                          #
############################################################

program.c: bakery.so
	gcc -L . -o program program.c -lmutex -lpthread 
bakery.so: bakery.o
	gcc -shared -o libbakery.so bakery.h
bakery.o: 
	gcc -shared -o libbakery.so bakery.c