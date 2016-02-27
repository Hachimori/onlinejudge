#include<stdio.h>

#define MAX 100
#define EoF -1

void Put0(int, int *);
int Input_Saearch(void);

main()
{

  int answer;

  while(1){

   answer= Input_Search();
   if(answer==EoF) break;

   printf("%d\n",answer);

  }

}

int Input_Search(void){

  int N,M;
  int i,j,k,num,chk[MAX];

  scanf("%d",&N);
  if(N==0) return EoF;  


  for(i=1;;i++){
    
    k=1;
    num=1;
    Put0(N,chk);

    while(1){      
      for(j=0;j<i;j++){
	k++;
	if(k>N) k=1;
	if(chk[k]==1)
	  while(1){ k++; if(k>N)k=1; if(chk[k]==0)break; }
	
      }/* printf("%d\n",k); */
      chk[k]=1;
      num++;
      
      if(num==N && k==13) return i;
      else if(num!=N && k==13) break;
    }
  
  }


}


void Put0(int n, int *chk){

  int i;

  chk[1]=1;
  for(i=2;i<=n;i++) chk[i]=0;

  return;

}
