/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:23:11 by agathabarro       #+#    #+#             */
/*   Updated: 2023/08/19 17:36:00 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/** the function check_envp() checks if the PATH 
 * variable is set in the environment
 * if not, it prints an error message and exits the program
 */
void	check_envp(char **envp)
{
	int	i;
	int	check;

	i = -1;
	check = 0;
	while (envp[++i])
		if (ft_strnstr(envp[i], "PATH=", 5) && envp[i][6])
			check = 1;
	if (!check)
	{
		error();
		exit(1);
	}
}

/**
 * the function execute() executes the command
 * it takes the command and the environment as parameters
 * it splits the command into an array of strings
 * it gets the path of the command
 * it executes the command
 */
void	child_process(char **argv, char **envp, int *fd)
{
	int	in;

	in = open(argv[1], O_RDONLY, 0777);
	if (in == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(in, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

/**
 * the function execute() executes the command
 * it takes the command and the environment as parameters
 * it splits the command into an array of strings
 * it gets the path of the command
 * it executes the command
*/
void	parent_process(char **argv, char **envp, int *fd)
{
	int	out;

	out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0755); 
	if (out == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}


int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	check_envp(envp);
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_process(argv, envp, fd);
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 2);
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 1);
		exit(1);
	}
}
