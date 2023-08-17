#include <unistd.h>
#include <stdio.h>
 
int main()
{
	char *args[3];
 
	args[0] = "ls";
	args[1] = "-l";
	args[2] = NULL;
	execve("/bin/ls", args, NULL);
	printf("This line will not be executed.\n");
 
	return (0);
}
/**
 * In this code, the args array contains
 *  the command line arguments to be passed to the ls command. 
 * execve(2) is then called with the path to the ls command 
 * (/bin/ls), the args array, and NULL for the environment variables. 
*/