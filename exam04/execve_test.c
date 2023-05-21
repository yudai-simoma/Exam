#include <stdio.h>
#include <unistd.h>

int main() {
    char* filename = "/bin/ls";
    char* argv[] = { "ls", "-l", NULL };
	//新しく実行するプロセスに環境変数を設定することができる
    char* envp[] = { "PATH=/usr/bin:/bin", "TERM=xterm", NULL };

    if (execve(filename, argv, envp) < 0) {
        perror("execve");
        return 1;
    }

    // execve()が成功すると、このプロセスは/bin/lsに置き換えられ、以下のコードは実行されません

    return 0;
}
