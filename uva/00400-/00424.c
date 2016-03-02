/*  '0'=48  '9'=57  */

#include<stdio.h>
#include<string.h>

#define MAX 1000

void Input(void);
void Plus(char *);
void Kuriage(int);
void Output(void);

char number[MAX];

main()
{

  int i; 
 
  for(i=0;i<MAX;i++) number[i]='0';
 
  Input();
  Output();

}

void Input(void){

  int i;
  char tmp[MAX/10];

  while(1){
    
    scanf("%s",tmp);
    if(strcmp(tmp,"0")==0) break;
    
    Plus(tmp);

  }

  return;

}

void Plus(char *tmp){

  int i,j,length;
  
  
  length=strlen(tmp);

  for(i=length-1,j=MAX-1;i>=0;i--,j--){

    number[j] += tmp[i] - 48;
    if(number[j] > '9' ) Kuriage(j);

  }


  return;

}

void Kuriage(int j){

  int i;

  if(number[j] > '9'){

    number[j]-=10;
    number[j-1]++;

    if(number[j-1] > '9'){

      Kuriage(j-1);
      return;
      
    }

  }

  return;

}

void Output(void){

  int i;

  for(i=0;i<MAX-1;i++) if(number[i]!='0') break;

  for(;i<MAX;i++) printf("%c",number[i]);

  printf("\n");

  return;

}
