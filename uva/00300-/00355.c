#include<stdio.h>
#include<string.h>

#define MAX 20000
#define A 10
#define B 11
#define C 12
#define D 13
#define E 14
#define F 15

unsigned long long target_digit[MAX],source_digit[MAX];
unsigned long long digit;
char str[MAX];
int target_base,source_base;

int input(){

  int i;
  unsigned long long multiple;


  if(scanf("%d%d%s",&source_base,&target_base,str)==EOF) return -1;

  str[MAX-1] = '\0';
  digit=0;

  for(i=0;i<strlen(str);i++){
    if(str[i]=='A'){
      source_digit[i]=A;
    }
    else if(str[i]=='B'){
      source_digit[i]=B;
    }
    else if(str[i]=='C'){
      source_digit[i]=C;
    }
    else if(str[i]=='D'){
      source_digit[i]=D;
    }
    else if(str[i]=='E'){
      source_digit[i]=E;
    }
    else if(str[i]=='F'){
      source_digit[i]=F;
    }
    else if(str[i]>='0' && str[i]<='9'){
      source_digit[i] = str[i]-'0';
    }
  }

  for(i=strlen(str)-1,multiple=1;i>=0;i--,multiple*=source_base){
    if(source_digit[i]>=source_base){
      printf("%s is an illegal base %d number\n",str,source_base);
      return -2;
    }
    digit+=source_digit[i]*multiple;
  }

  /* printf("%lldn",digit); */

  return 1;
}

void work(){

  int max,i;
  unsigned long long multiple,division;

  max=0;

  for(i=0;i<MAX;i++) target_digit[i]=0;

  while(1){
    if(digit==0) break; 

    for(i=0,multiple=1;;multiple*=target_base,i++){
      if(multiple>digit){
	multiple/=target_base;
	i--;
	if(max<i) max = i;
	break;
      } 
    }

    division = digit/multiple;
    target_digit[i] = division;
    digit-= division*multiple;

  }

  printf("%s base %d = ",str,source_base);
  for(i=max;i>=0;i--){
    if(target_digit[i]==A){
      printf("A");
    }
    else if(target_digit[i]==B){
      printf("B");
    }
    else if(target_digit[i]==C){
      printf("C");
    }
    else if(target_digit[i]==D){
      printf("D");
    }
    else if(target_digit[i]==E){
      printf("E");
    }
    else if(target_digit[i]==F){
      printf("F");
    }
    else if(target_digit[i]>=0 && target_digit[i]<=9){
      printf("%lld",target_digit[i]);
    }
  }
  printf(" base %d\n",target_base);

  return;
}

main(){

  int ret;

  while(1){
    if((ret=input())==-2) continue;
    else if(ret==-1) break;
    work();
  }

}
