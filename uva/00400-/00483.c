#include<stdio.h>
#include<string.h>
#define MAX 10000

int Input_Output(void);
int after_n=0;
char word[MAX];

main()
{

  while(1){

    if(Input_Output()==0) break;
    
  }

}

int Input_Output(void){

  int chk=0,first_chk=0,after=0,tmp=1;
  int leng;
  
  
  while(1){
    
    

    for(leng=0;;leng++){
      if(scanf("%c",&word[leng])==EOF){ chk=2; break; }
      if(word[leng]==' '){
	break;
      }
      if(word[leng]=='\n'){ chk=1; break; }
    }
    tmp=leng;

    
    if(first_chk!=0 && tmp!=0) printf(" ");
    for(leng--;leng>=0;leng--){ printf("%c",word[leng]); first_chk=1; after_n=0;}
    
    if(chk==1||chk==2) break;
   
  }
  
  if(chk==1 && first_chk==1 && after_n==0){ printf("\n");  after_n=1; return 1; }
  if(chk==1 && first_chk==0 && after_n==0) return 1;
  if(chk==2 && after_n==0){ printf("\n"); return 0; }
  if(chk==2 && after_n==1) return 0;

}
