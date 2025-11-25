#include <stdio.h>
#include "umka_api.h"

void foo(int num) {
    printf("Got deez %d\n", num);
}

void bar(int num, int num2) {
    printf("Yo 2 numbers lmao: %d,%d\n", num, num2);
}

int main(int argc, char **argv) {
    Umka *umka = umkaAlloc();

    bool ok = umkaInit(umka, "test.um", NULL, 4096, NULL, argc, argv, true, true, NULL);
    if (!ok) {
        printf("Failed to init umka :/\n");
        return 1;
    }

    ok = umkaCompile(umka);
    if (!ok) {
        printf("Failed to compile :/\n");
        UmkaError *err = umkaGetError(umka);
        printf("%s:%d: ERROR: %s\n", err->fileName, err->line, err->msg);
        return 1;
    }

    int run = umkaRun(umka);
    return run;
}
