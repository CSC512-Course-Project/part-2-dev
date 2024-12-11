#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    char filename[100], c;

    printf("Enter the filename to open: ");
    scanf("%s", filename);

    // Open file in read mode
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Error! File cannot be opened.\n");
        exit(1);
    }

    // Read and display contents
    while ((c = fgetc(fptr)) != EOF)
    {
        printf("%c", c);
    }

    fclose(fptr);
    return 0;
}