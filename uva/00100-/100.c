#include<stdio.h>

#define MAX 1000000

int Input(void);
void Koukan(void);
void Search(void);
int Operation(long long);
void Output(void);

int begin,end,longest=0,koukan_chk=0;
int length[MAX];
int ashiato[MAX];

main()
{

  length[1]=1;

  while(1){

    if(Input()==0) break;
    Koukan();
    Search();
    Output();
    koukan_chk=0;
    longest=0;
  }

}

int Input(void){

  if(scanf("%d%d",&begin,&end)==EOF) return 0;

  return 1;

}

void Koukan(void){

  int tmp;

  if(begin>end){
    tmp = begin;
    begin = end;
    end = tmp;
    koukan_chk=1;
  }

  return;

}

void Search(void){

  int i,tmp;

  for(i=begin;i<=end;i++){
    tmp = Operation(i);
    if(longest<tmp) longest = tmp;
  }

  return;

}

int Operation( long long n ){

  int i,tmp,tmp2,chk=0;

  for(i=0;;i++){
    if(n>MAX) chk=1;
    if(i<MAX) ashiato[i]=n;
    if(n<MAX) 
      if(length[n]>=1){
	/* printf("i=%d  n=%d length[%d]=%d\n",i,n,n,length[n]); */
	tmp=i;
	i+=length[n];
	tmp2=i;
	break;
      }
    if(n%2==1) n=3*n+1;
    else n/=2;
  }
  
  if(tmp<MAX && chk==0)
    for(tmp--;tmp>0;tmp--) 
      if(ashiato[tmp]<MAX && ashiato[tmp+1]<MAX ) 
	length[ashiato[tmp]]=length[ashiato[tmp+1]]+1; 

  return tmp2;

}

void Output(void){
  if(koukan_chk==1) printf("%d %d %d\n",end,begin,longest);
  else printf("%d %d %d\n",begin,end,longest);

  return;

}
