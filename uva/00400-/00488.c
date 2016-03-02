#include<stdio.h>
#define EoF -1

int Input(void);
void Output(void);

long long amplitude,frequency;

main()
{
  
  int n,i;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    if(Input()==EoF) break;
    Output();
    if(i!=n-1) printf("\n");
  }

}

int Input(void){

  if(scanf("%lld",&amplitude)==EOF) return EoF;
  if(scanf("%lld",&frequency)==EOF) return EoF;

  return 1;

}

void Output(void){

  long long k,i,j;

  if(amplitude<0) return;

  for(k=0;k<frequency;k++){

    if(k!=0) printf("\n");

    for(i=1;i<=amplitude;i++){
      
      for(j=0;j<i;j++){
	
	printf("%lld",i);

      } printf("\n");

  
    }

    for(i=amplitude-1;i>0;i--){
      
      for(j=0;j<i;j++){
	
	printf("%lld",i);

      } printf("\n");

  
    }

   
  }


  return;

}
