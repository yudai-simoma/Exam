#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	int 	status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
	{
		printf("子プロセスの処理, fork_pid = %d, main_pid = %d\n", pid, getpid());
		sleep(3); // 子プロセスを3秒間スリープさせる
		exit(90); // 子プロセスが終了する際、終了ステータスとして42を返す
	}
	else
	{
		printf("親プロセスの処理, fork_pid = %d, main_pid = %d\n", pid, getpid());
		pid_t child_pid = waitpid(pid, &status, 0); // 親プロセスは子プロセスの終了を待つ
		if (child_pid > 0)
		{
			if (WIFEXITED(status))
			{
				printf("子プロセス、正常終了 %d exited with status: %d\n", child_pid,
						WEXITSTATUS(status));
			}
			else if (WIFSIGNALED(status))
			{
				printf("子プロセス、シグナル終了 %d was terminated by a signal: %d\n",
						child_pid, WTERMSIG(status));
			}
			else if (WIFSTOPPED(status))
			{
				printf("子プロセス、シグナル停止 %d was stopped by a signal: %d\n",
						child_pid, WSTOPSIG(status));
			}
		}
		else
		{
			perror("waitpid");
			return (1);
		}
	}
	return (0);
}
