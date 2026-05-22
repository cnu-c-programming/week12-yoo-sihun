#include <stdio.h>

int main(int argc, const char* argv[], const char* envp[]) {
    int i = 0;
    while (envp[i] != NULL) {
        printf("%s\n", envp[i]);
        i++;
    }

    return 0;
}
