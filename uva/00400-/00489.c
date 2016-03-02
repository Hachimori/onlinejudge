/* 'a'=97  'z'=122 */  

#include<stdio.h>

#define EoF -1
#define Wrong_point 7
#define MAX_alphabet 26

int Input_Output(void);
void Put0(int*);

main()
{

  while(1){

    if(Input_Output()==EoF) break;

  }

}

int Input_Output(void){

  int i,round,abc_chk[MAX_alphabet];
  int num_clear=0,num_char=0,num_wrong=0,chk_win=0,chk_lose=0;
  char c;

  Put0(abc_chk);

  scanf("%d",&round);
  if(round==-1) return EoF;

  while(1){ scanf("%c",&c); if(c=='\n') break; }

  while(1){
    
    scanf("%c",&c);  
    if(c=='\n') break;

    if(abc_chk[c-97]==0){
      abc_chk[c-97]=1;
      num_char++;
    }
  
  }

  while(1){

    scanf("%c",&c);
    if(c=='\n') break;

    if(abc_chk[c-97]==1 && chk_lose==0){
      abc_chk[c-97]=0;
      num_clear+=1;
      if(num_clear==num_char) chk_win=1;
    }
    else if(abc_chk[c-97]==0 && chk_win==0){
      num_wrong+=1;
      if(num_wrong==Wrong_point) chk_lose=1;
    }

  }

  
  printf("Round %d\n",round);
  if(chk_win==1) printf("You win.\n");
  else if(chk_lose==1) printf("You lose.\n");
  else printf("You chickened out.\n");

  return;

}


void Put0(int x[]){

  int i;

  for(i=0;i<MAX_alphabet;i++) x[i]=0;

  return;

}
