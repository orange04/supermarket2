system: system.o base.o menu.o
	gcc -o system system.o base.o menu.o
	make clean
	./system

system.o: system.c base.h menu.h
	gcc -c system.c

base.o: base.c base.h menu.h define_my.h
	gcc -c base.c

menu.o: menu.c menu.h define_my.h
	gcc -c menu.c

clean: 
	rm -rf base.o menu.o system.o
	
