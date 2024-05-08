#include<stdio.h>
#include<string.h>
/*
程序功能：从键盘输入10个英文单词到二维字符数组a并保存到文本文件a.txt中（单词间以空格分隔），然后再从该文件中读出所有单词并显示到屏幕。
*/
#define MAX_WORD_LEN 10

int main() {
    FILE *file = fopen("a.txt", "w");

    char a[10][MAX_WORD_LEN];
    printf("请输入 10 个英文单词:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < 9; i++) {
        fprintf(file, "%s ", a[i]);
    }
    fprintf(file, "%s", a[9]);  // 最后一个单词不需要空格分隔
    fclose(file);

    file = fopen("a.txt", "r");
    char word[MAX_WORD_LEN];
    printf("从文件读出的单词:\n");
    while (fscanf(file, "%s", word) != EOF) {
        printf("%s\n", word);
    }
    fclose(file);
    
    return 0;
}