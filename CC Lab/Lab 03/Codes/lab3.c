#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEYWORDS 32
#define MAX_WORD_LEN 20

struct keyword {
    char word[MAX_WORD_LEN];
    int count;
};

int isKeyword(char word[]) {
    char *keywords[MAX_KEYWORDS] = {
        "auto","break","case","char","const","continue","default",
        "do","double","else","enum","extern","float","for","goto",
        "if","int","long","register","return","short","signed",
        "sizeof","static","struct","switch","typedef","union",
        "unsigned","void","volatile","while"
    };

    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int findKeyword(struct keyword k[], int count, char word[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(k[i].word, word) == 0)
            return i;
    }
    return -1;
}

int main() {
    FILE *fp;
    char ch, word[MAX_WORD_LEN];
    struct keyword found[MAX_KEYWORDS];
    int i = 0, kcount = 0;

    fp = fopen("input.c", "r");
    if (fp == NULL) {
        printf("Error: File not found!\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {
            i = 0;
            while (isalpha(ch)) {
                word[i++] = ch;
                ch = fgetc(fp);
            }
            word[i] = '\0';

            if (isKeyword(word)) {
                int index = findKeyword(found, kcount, word);
                if (index == -1 && kcount < MAX_KEYWORDS) {
                    strcpy(found[kcount].word, word);
                    found[kcount].count = 1;
                    kcount++;
                } else if (index != -1) {
                    found[index].count++;
                }
            }
        }
    }

    fclose(fp);

    printf("\nKeyword\t\tCount\n");
    printf("----------------------\n");
    for (i = 0; i < kcount; i++) {
        printf("%-10s\t%d\n", found[i].word, found[i].count);
    }

    return 0;
}
