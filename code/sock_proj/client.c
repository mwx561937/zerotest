#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(){
  int clnt_sock = socket(AF_INET,SOCK_STREAM,0);
  char buf[] = "This is client!";
  if(clnt_sock == -1)
  {
    printf("%d\n",errno);
    return -1;
  }
  struct sockaddr_in addr;
  memset(&addr,0,sizeof(addr));
  addr.sin_addr.s_addr = inet_addr("106.13.61.223");
  addr.sin_port = htons(12345);
  addr.sin_family = AF_INET;
  
  int ret = connect(clnt_sock,(struct sockaddr*)&addr,sizeof(struct sockaddr_in));
  if(ret == -1){
    printf("%d\n",errno);
    return -1;
  }
  while(1){
    ret = write(clnt_sock,buf,strlen(buf));
    printf("已经发送%d个数据!\n",ret);
    sleep
  }
  close(clnt_sock);


}
