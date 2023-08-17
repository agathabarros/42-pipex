#include <stdio.h>
#include <unistd.h>

int main()
{
    if (access("example.txt", R_OK) != -1)
        printf("I have Permission\n");
    else
        printf("I don't have permission\n");

    return (0);
}
/**
 * checks whether the process has 
 * read permission for the file example.txt
*/