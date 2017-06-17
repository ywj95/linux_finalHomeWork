main:main.o   bitree.o  mgraph.o linkqueue.o  sqstack.o
	gcc main.o   bitree.o   mgraph.o   linkqueue.o  sqstack.o  -o main

main.o:main.c
	gcc -c main.c

bitree.o:bitree.c
	gcc -c bitree.c

mgraph.o:mgraph.c
	gcc -c mgraph.c

linkqueue.o:linkqueue.c
	gcc -c linkqueue.c

sqstack.o:sqstack.c
	gcc -c sqstack.c


clean:
	rm main *.o


