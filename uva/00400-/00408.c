#include<stdio.h>

#define EoF -1
#define CONTINUE 1

int Input_Output(void);

main()
{

  while(1){

    if(Input_Output()==EoF) break;

  }

}

int Input_Output(void){

  int i,j,num=1,tmp=0;
  int STEP,MOD;

  
  if(scanf("%d%d",&STEP,&MOD)==EOF) return EoF;

  
  while(1){
    tmp=(STEP+tmp)%MOD;
    
    if(tmp==0) break;
    num++;
  }



  if(num==MOD) printf("%10d%10d    Good Choice\n\n",STEP,MOD);
  else printf("%10d%10d    Bad Choice\n\n",STEP,MOD);
    
  return CONTINUE;

}
