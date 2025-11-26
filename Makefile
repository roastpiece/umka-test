LIBS = 	-L../umka-lang/build/ \
	-L../libffi/build/.libs \
	-l:libumka.a \
	-lffi \
	-lm

main: main.c
	cc -O3 -Wall -Wextra -ggdb -o main main.c -I../umka-lang/build/include/ $(LIBS) -rdynamic
