#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config {
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr) {
    FILE* fp = fopen("config.txt", "r");
    if (fp == NULL)
        return;

    char line[128];
    char key[64], value[64];

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "%[^=]=%s", key, value) == 2) {
            // 공백이나 개행 제거 처리가 필요할 수 있으나 기본 sscanf 처리
            if (strcmp(key, "InputFileName") == 0) {
                strcpy(config_ptr->InputFileName, value);
            } else if (strcmp(key, "Options") == 0) {
                config_ptr->Options = atoi(value);
            } else if (strcmp(key, "SectionName") == 0) {
                strcpy(config_ptr->SectionName, value);
            } else if (strcmp(key, "Address") == 0) {
                // 0x로 시작하는 16진수 문자열 변환
                config_ptr->Address = strtoull(value, NULL, 16);
            }
        }
    }
    fclose(fp);
}

int main(int argc, const char* argv[]) {
    Config config;
    memset(&config, 0, sizeof(Config)); // 초기화

    config_parser(&config);

    printf("config: %s %d %s %llu\n",
           config.InputFileName,
           config.Options,
           config.SectionName,
           config.Address);

    return 0;
}
