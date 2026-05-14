#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
    int fd[2];
    
    char msg[] = "Hello";
    char buf[20];

    pipe(fd);

    if (fork() > 0){
        write(fd[1],msg,strlen(msg)+1);
    }
    else{
        read(fd[0],buf,sizeof(buf));
        printf("Received: %s\n",buf);
    }

    return 0;
}
