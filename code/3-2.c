#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 2)
        return 0;

    const char* filename = argv[1];
    char buffer[10] = {0};

    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
        return 0;

    // 버퍼 크기가 10이므로 널 문자를 제외하고 최대 9 바이트만 안전하게 읽음
    fscanf(fp, "%9s", buffer);
    fclose(fp);

    printf("%s\n", buffer);

    return 0;
}
