#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>


int main(){





  int serv_sock = socket(AF_INET,SOCK_STREAM,0);
  if(serv_sock == -1){
    puts("socket create failed");
    printf("%d\n",errno);
    return -1;
  }
  struct sockaddr_in addr;
  memset(&addr,0,sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(12345);
  addr.sin_addr.s_addr = INADDR_ANY;
  int ret = bind(serv_sock,(struct sockaddr*)&addr,sizeof(struct sockaddr));
  if(ret == -1){
    puts("bind failed");
    printf("%d\n",errno);
    return -1;
  }
  ret = listen(serv_sock,5);
  if(ret == -1)
  {
    puts("listen failed");
    return -1;
  }


  char buf[256] = {0};
  while(1){
    memset(buf,0,256);
    puts("正在等待连接...");
    int clnt_sock = accept(serv_sock,NULL,NULL);
    puts("连接成功!");
    int readLen = read(clnt_sock,buf,256);
    buf[readLen] = '\0';
    printf("%d -- %s\n",readLen,buf);
    close(clnt_sock);
  }


  close(serv_sock);

  return 0;
}
