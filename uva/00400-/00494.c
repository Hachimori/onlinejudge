#include<stdio.h>
#define EoF -1

int Input_search(void);
int Read_word(void);
void Output(void);

int num_word=0;

main()
{

  while(1){
    
    if(Input_seach()==0) break;
    Output();

  }

}

int Input_seach(void){

  int tmp;
  int present=0;

  num_word=0;

  while(1){

    tmp = Read_word();

    if(tmp==EoF) return 0;
    else if(tmp==0) break;
   
  }

  return 1;

}

int Read_word(void){

  int chk=0;
  char c;

  while(1){
    
    if(scanf("%c",&c)==EOF) return EoF;
    /* printf("chk = %d  c = %c  num_word = %d\n",chk,c,num_word); */
    if( c=='\n' ){
      if(chk==1) num_word++;
      return 0;
    }
    if( c<'A' || c>'Z' && c<'a' || c>'z' ){
      if(chk==1) num_word++;
      return 1;
    }

    chk=1;

  }
    

}

void Output(void){

  printf("%d\n",num_word);

  return;

}
