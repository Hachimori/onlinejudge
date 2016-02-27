/*

         6         8
        35        49
       204       288
      1189      1681
      6930      9800
     40391     57121
    235416    332928
   1372105   1940449
   7997214  11309768
  46611179  65918161
  
*/


#include<stdio.h>
#define MAX_line 10

void Search(void);
void Output(void);

main()
{
  /*
  printf("%10d%10d\n",6,8);
  printf("%10d%10d\n",35,49);
  printf("%10d%10d\n",204,288);
  printf("%10d%10d\n",1189,1681);
  printf("%10d%10d\n",6930,9800);
  printf("%10d%10d\n",40391,57121);
  printf("%10d%10d\n",235416,332928);
  printf("%10d%10d\n",1372105,1940449);
  printf("%10d%10d\n",7997214,11309768);
  printf("%10d%10d\n",46611179,65918161);
  */
   Search(); 

}

void Search(void){

  long long i,j=2,num=0;

  for(i=2;num<MAX_line;i++){
    for(;;j++){
      if( j*(j+1)/2 - i*(i-1)/2 > i*(i+1)/2 ) break;
      else if( j*(j+1)/2 - i*(i-1)/2 == i*(i+1)/2 ){
	num++;
	printf("%10lld%10lld\n",i,j);
      }
    }
    
  }

  return;
}
