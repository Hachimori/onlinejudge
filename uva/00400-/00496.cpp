#include<stdio.h>
#include<algorithm>
#define MAX 1000000

using namespace std;

/*                                                                      */
/*   Search 返り値                                                      */
/*   1...  A is a proper subset of B                                    */
/*   2...  B is a proper subset of A                                    */
/*   3...  A equals B                                                   */
/*   4...  A and B are disjoint                                         */
/*   5...  I'm confused!                                                */
/*                                                                      */

// bool Lessint(int *, int *);
int Search(void);

int endof_A,endof_B,listA[MAX],listB[MAX];

main(){

  int i,answer,check=0;
  char c;

  while(1){

    /* list A  読み込み */
    for(i=0;;i++){
      if(scanf("%d",&listA[i]) == EOF) check=1;
      if(scanf("%c",&c) == EOF) check=1;
      if(c=='\n') break;
    }
    endof_A = i;

    /* list B  読み込み */
    for(i=0;;i++){
      if( scanf("%d",&listB[i]) == EOF) check=1;
      if( scanf("%c",&c) == EOF) check=1;
      if(c=='\n') break;
    }
    endof_B = i;

    if(check==1) break;

    sort(&listA[0],listA+endof_A+1);
    sort(&listB[0],listB+endof_B+1);
   
    /*
    for(i=0;i<endof_A+1;i++) printf("%d ",listA[i]); printf("\n");
    for(i=0;i<endof_B+1;i++) printf("%d ",listB[i]); printf("\n");
    */ 

    answer = Search();

    if(answer == 1 ) printf("A is a proper subset of B\n");
    if(answer == 2 ) printf("B is a proper subset of A\n");
    if(answer == 3 ) printf("A equals B\n");
    if(answer == 4 ) printf("A and B are disjoint\n");
    if(answer == 5 ) printf("I'm confused!\n");

  }

}
/*
bool Lessint(const void* lhs, const void* rhs)
{
  if (*((int*)lhs) < *((int*)rhs)) {
    return -1;
  } else if (*((int*)rhs) < *((int*)lhs)) {
    return 1;
  } else {
    return 0;
  }
} */

/*   Search 返り値                     */
/*   1...  A is a proper subset of B   */
/*   2...  B is a proper subset of A   */
/*   3...  A equals B                  */
/*   4...  A and B are disjoint        */
/*   5...  I'm confused!               */

int Search( void ){

  int i=0,j=0,check=0,check2=0,check3=0;

  if(listA[0] > listB[0] || listA[0] == listB[0] && endof_A < endof_B ){

    for(;i<endof_A+1;){
      for(;j<endof_B+1;j++){
	//printf("i=%d j=%d listA=%d listB=%d\n",i,j,listA[i],listB[j]); 
	if(listA[i]==listB[j]){
	  check=1;
	  i++;
	  j++;
	  break;
	}
	else{
	  j++;
	  break;
	}

      }
      if(j==endof_B+1 && i != endof_A+1 && check != 0 ) return 5;
      else if(j==endof_B+1 && i != endof_A+1 && check == 0 ) return 4;
    }
  
  }
  else{
    
    for(;i<endof_B+1;){
      for(;j<endof_A+1;j++){
	// printf("i=%d j=%d\n",i,j);
	if(listA[j]==listB[i]){
	  check=1;
	  i++;
	  j++;
	  break;
	}
	else{
	  j++;
	  break;
	}

      }	  
      if(j==endof_A+1 && i != endof_B+1 && check != 0 ) return 5;
      else if(j==endof_A+1 && i != endof_B+1 && check == 0 ) return 4;
    }

  }

  if(endof_A == endof_B) return 3;
  if(endof_A > endof_B) return 2;
  if(endof_A < endof_B) return 1;

}
