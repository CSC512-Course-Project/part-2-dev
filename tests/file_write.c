#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    char filename[100];
    char data[100];

    printf("Enter the filename to create: ");
    scanf("%s", filename);

    // Open file in write mode
    fptr = fopen(filename, "w");
    if (fptr == NULL)
    {
        printf("Error! File cannot be created.\n");
        exit(1);
    }

    printf("Enter data to write into the file: ");
    getchar(); // Consume newline character left by scanf
    fgets(data, 100, stdin);

    fprintf(fptr, "%s", data);
    fclose(fptr);

    printf("Data written successfully.\n");
    return 0;
}