#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp, *fp1;
    char line[500];
    int lineNo = 0;
    int inBlockComment = 0;

    fp = fopen("input.c", "r");
    fp1 = fopen("output.c", "w");

    if (fp == NULL || fp1 == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp))
    {
        lineNo++;
        int i = 0;

        // Check for single-line comment
        if (!inBlockComment && strstr(line, "//"))
        {
            printf("Single-line comment found at line %d\n", lineNo);
        }

        while (line[i] != '\0')
        {

            // Start of block comment
            if (!inBlockComment && line[i] == '/' && line[i + 1] == '*')
            {
                printf("Block comment starts at line %d\n", lineNo);
                inBlockComment = 1;
                i += 2;
                continue;
            }

            // End of block comment
            if (inBlockComment && line[i] == '*' && line[i + 1] == '/')
            {
                printf("Block comment ends at line %d\n", lineNo);
                inBlockComment = 0;
                i += 2;
                continue;
            }

            // Skip characters inside block comment
            if (inBlockComment)
            {
                i++;
                continue;
            }

            // Skip single-line comment
            if (line[i] == '/' && line[i + 1] == '/')
            {
                break;
            }

            // Write non-comment characters to output file
            fputc(line[i], fp1);
            i++;
        }

        // Write newline if not inside block comment
        if (!inBlockComment)
            fputc('\n', fp1);
    }

    fclose(fp);
    fclose(fp1);

    printf("\nComment-free code written to output.c\n");
    return 0;
}
