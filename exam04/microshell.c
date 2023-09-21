#include "microshell.h"

size_t	ft_strlen(char *str)
{
	size_t	i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_exit(void)
{
	if (write(2, "error: fatal\n", ft_strlen("error: fatal\n")) != 0)
		ft_exit();
	exit(1);
}

int	ft_put_strfd(char *str, int fd)
{
	if (write(fd, str, ft_strlen(str)) != 0)
		ft_exit();
	return (0);
}

int	cd(char **argv, int i)
{
	if (i != 2)
		return (ft_put_strfd("error: cd: bad arguments\n", 2), 1);
	else if (chdir(argv[1]) != 0)
	{
		ft_put_strfd("error: cd: cannot change directory to ", 2);
		ft_put_strfd(argv[1], 2);
		ft_put_strfd("\n", 2);
		return (1);
	}
	return (0);
}

int	exec(char **argv, char **envp, int i) 
{
	int		fd[2];
	int		status;
	bool	has_pipe = (argv[i] != NULL && strcmp(argv[i], "|") == 0);
	int		pid;

	if (has_pipe)
		if (pipe(fd) != 0)
			ft_exit();
	pid = fork();
	if (pid < 0)
		ft_exit();
	else if (pid == 0) //子プロセス
	{
		if (has_pipe)
		{
			close(fd[READ]);
			if (dup2(fd[WRITE], 1) == -1)
			{
				close(fd[WRITE]);
				ft_exit();
			}
		}
		argv[i] = NULL;
		execve(argv[0], argv, envp);
		ft_put_strfd("error: cannot execute ", 2);
		ft_put_strfd(argv[0], 2);
		ft_put_strfd("\n", 2);
		return (1);
	}
	//親プロセス
	if (has_pipe)
	{
		close(fd[WRITE]);
		if (dup2(fd[READ], 0) == -1) 
		{
			close(fd[READ]);
			ft_exit();
		}
	}
	waitpid(pid, &status, 0);
	if (has_pipe) 
		close(fd[READ]);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (1);
}

int main(int argc, char **argv, char **envp)
{
	int	i = 0;
	int	status = 0;

	if (argc <= 1)
		return (status);
	while (argv[i] != NULL && argv[++i] != NULL)
	{
		argv += i;
		i = 0;
		while (argv[i] != NULL
			&& strcmp(argv[i], "|") != 0
			&& strcmp(argv[i], ";") != 0)
			i++;
		if (strcmp(argv[0], "cd") == 0)
			status = cd(argv, i);
		else if (i != 0)
			status = exec(argv, envp, i);
	}
	return (status);
}
