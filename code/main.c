#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_INDEX 1000000
#define THREAD_NUM 10

void* thread_proc(void* param){
  int* index = (int*)param;
  for(int i=0;i<MAX_INDEX;++i){
    //printf("hello - %d\n",index);

    (*index)++;
    usleep(5);
  }
  printf("thread %lu is over!\n",pthread_self());
  return NULL;
}

int main(){

  int index = 0;
  pthread_t pt[THREAD_NUM];
  for(int i=0;i<THREAD_NUM;i++){
    int ret = pthread_create(&pt[i],NULL,thread_proc,&index);
  }
  for(int i=0;i<MAX_INDEX;++i){
    //printf("world - %d\n",index);
    index++;
    usleep(5);
  }
  puts("main thread is over!");
  for(int i=0;i<THREAD_NUM;++i){
    pthread_join(pt[i],NULL);
  }
  //sleep(10);
  printf("%d\n",index);


  return 0;
}
