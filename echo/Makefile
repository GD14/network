include ../Make.defines

PROGS = test serecho cliecho

all:	${PROGS}

test:	test.o
	${CC} ${CFLAGS} -o $@ test.o ${LIBS}
serecho:	serecho.o
	${CC} ${CFLAGS} -o $@ serecho.o ${LIBS}
	
cliecho:	cliecho.o
	${CC} ${CFLAGS} -o $@ cliecho.o ${LIBS}
	
clean:
		rm -f ${PROGS} ${CLEANFILES}
