main: main.c
	cc -Wall -Wextra -ggdb -o main main.c -I../umka-lang/build/include/ -L../umka-lang/build/ -l:libumka.a -lm -rdynamic
