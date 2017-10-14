include ../Make.defines

PROGS = servBacklog clieBacklog 

all:	${PROGS}

servBacklog:	servBacklog.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}
	
clieBacklog:	clieBacklog.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

	
clean:
		rm -f ${PROGS} ${CLEANFILES}
