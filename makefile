############################################################
#                                                          #
# INF01151 - Sistemas Operacionais II N - Turma A (2024/1) #
#           Mateus Luiz Salvi - Bianca Pelegrini           #
#                                                          #
############################################################

program.o: libbakery.so program.c
	gcc -c -L . -o program program.c
libbakery.so: bakery.c bakery.h #bakery.o
	gcc -c -fPIC -shared -o libbakery.so bakery.c
# bakery.o: bakery.h bakery.c
# 	gcc -c bakery.c

clean: 
	rm *.o program libbakery.so