#include<stdio.h>
#define MAX 150

int Input(void);
void Search(void);
void Output(void);
void Put0(void);

int n,m,chk[MAX+1];

main()
{

  Put0();

  while(1){
    if(Input()==0) break;
    Search();
    Output();
    Put0();
  }


}

int Input(void){

  scanf("%d",&n);

  if(n==0) return 0;

  return 1;

}

void Search(void){

  int i,j,present=1,k,num_checked=1;
  int out=0;

  

  for(i=2;;i++){

    Put0();
    chk[1]=1;
    present=1;
    num_checked=1;
  
    while(num_checked!=n-1){
      for(k=0;k<i;k++){
	present++;
	
	if(present>n){ for(j=1;;j++) if(chk[j]==0) break; present=j; }
	if(chk[present]==1){
	  k--;
	  continue;
	}
      }
      if(present==2){ out=1; break; }
      chk[present]=1;
      num_checked++;
    }

    if(out==0) break;
    else out=0;

  }

  m=i;

  return;

}

void Output(void){

  printf("%d\n",m);

  return;

}

void Put0(void){

  int i;

  for(i=1;i<=n;i++) chk[i]=0;

  return;

}
