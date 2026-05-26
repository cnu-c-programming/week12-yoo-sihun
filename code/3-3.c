#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "myfile.txt";

    FILE* fp1 = fopen(filename, "r");
    if (fp1 == NULL) return 0;
    
    FILE* fp2 = fopen(filename, "w");
    if (fp2 == NULL) {
        fclose(fp1);
        return 0;
    }

    char buf[256];
    while (fgets(buf, sizeof(buf), fp1) != NULL);

    char buf_fp1[256] = {0};
    char buf_fp2[256] = {0};

    char* res_fp1 = fgets(buf_fp1, sizeof(buf_fp1), fp1);
    char* res_fp2 = fgets(buf_fp2, sizeof(buf_fp2), fp2);

    printf("fp1 %s %p %d %d\n", buf_fp1, (void*)res_fp1, ferror(fp1), feof(fp1));
    printf("fp2 %s %p %d %d\n", buf_fp2, (void*)res_fp2, ferror(fp2), feof(fp2));

    fclose(fp1);
    fclose(fp2);

    return 0;
}
