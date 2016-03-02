/* A=65 Z=90 a=97 z=122 */

#include<stdio.h>

#define Num_alphabet 58
#define CONTINUE 1
#define EoF -1

int Input_Output(void);
void Put0(int *);

main()
{

  while(1){
    
    if(Input_Output()==EoF) break;

  }

}

int Input_Output(void){

  int i,alphabet[Num_alphabet],max=0;
  char c;

  Put0(alphabet);

  while(1){

    if(scanf("%c",&c)==EOF) return EoF;
    if(c=='\n') break;

    if( (c>='A' && c<='Z') || (c>='a' && c<='z') ){
      alphabet[c-65]+=1;
      if(alphabet[c-65]>max) max = alphabet[c-65];
    }

  }


  /* Output */
  if(max!=0){
    for(i=0;i<Num_alphabet;i++) if(alphabet[i]==max) printf("%c",i+65);
    printf(" %d\n",max);
  }

  return CONTINUE;

}

void Put0(int *x){

  int i;

  for(i=0;i<Num_alphabet;i++) x[i]=0;

  return;

}
