#include<stdio.h>
#include<string.h>
#include<assert.h>

#define MAX 80

int key;
int length;
char str[MAX];

int before[MAX],after[MAX];

int input(){

  int i;

  scanf("%d",&key);

  if(key==0) return -1;

  scanf("%s",str);
  length = strlen(str);

  for(i=0;i<length;i++){
    if(str[i]>='a' && str[i]<='z') before[i] = str[i]-'a'+1;
    else if(str[i]=='_') before[i]=0;
    else if(str[i]=='.') before[i]=27;
    else assert(0);
  }

  return 1;

}

void work(){

  int i;

  for(i=0;i<length;i++){
    after[(key*i)%length] = (before[i]+i)%28;
  }

  for(i=0;i<length;i++){

    if(after[i]+'a'-1=='`') printf("_");
    else if(after[i]+'a'-1=='{') printf(".");
    else printf("%c",after[i]+'a'-1);
  }
  printf("n");

}

main(){

  while(1){
    if(input()==-1) break;
    work();
  }

}
