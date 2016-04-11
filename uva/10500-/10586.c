#include<stdio.h>
#define MAX 10002
#define EoF -1
#define CONTINUE 1

int Input_Output(void);
void Wari(long long *, long long, long long, long long); 

main()
{

  while(1){
    if(Input_Output()==EoF) break;
  }

}


int Input_Output(void){

  long long n,k,a[MAX];
  long long i,j;
  
  scanf("%lld%lld",&n,&k);
  if(n==-1 && k==-1) return EoF;

  for(i=0;i<n+1;i++)
    scanf("%lld",&a[i]);
  
  Wari(a,n,k,n);

  return CONTINUE;

}


void Wari(long long a[MAX], long long n, long long k, long long pos){

  long long i,j;

  /*
  for(i=0;i<=n;i++) printf("%lld ",a[i]);
  printf("\n");
  */

  if( pos>=0 &&  pos-k>=0 && a[pos] >0 ){
  
    a[pos-k] -= a[pos];
    a[pos] = 0;
    Wari(a,n,k,pos-1);
  
  }
  else if( pos>=0 &&  pos-k>=0 && a[pos] < 0 ){
  
    a[pos-k] -= a[pos];
    a[pos] = 0;
    Wari(a,n,k,pos-1);
  
  }
  else if( pos>=0 && a[pos] == 0 ){
   
    Wari(a,n,k,pos-1);

  }
  else if( pos-k<0 ){
    
    for(i=n; i>=0 && a[i]==0 ;i--){}
    for(j=0;j<i;j++){
      printf("%lld ",a[j]);
    }
    printf("%lld\n",a[j]);

    return;
  }

  return;

}
