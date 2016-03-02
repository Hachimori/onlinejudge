#include<stdio.h>
#include<string.h>
#define MAX 20000000

int Input(void);
void make_message(void);
void Take_word(int,int);
void Output(void);

int tmp_leng;
char word[MAX],message[MAX];
char tmp_word[MAX];

main()
{

  int chk=0;

  while(1){

    if(Input()==0) chk=1;
    make_message();
    Output();
    if(chk==1) break;
  }

}

int Input(void){

  int i;

  for(i=0;i<MAX;i++){ 
    if(scanf("%c",&word[i])==EOF){  word[i]='\0';  return 0; }
    if(word[i]=='\n') break;
  }
  
  /* gets(word); */

  return 1;

}

void make_message(void){

  int i,j,k,l,now;
  

  for(i=0,j=0,now=0;i<MAX;i++){
    /* printf("i=%d word[%d]=%c\n",i,i,word[i]); */
    if(word[i]>='A' && word[i]<='Z' || word[i]>='a' && word[i]<='z'){
      
      for(j=i;j<MAX;j++){
	
	if( !(word[j]>='A' && word[j]<='Z') && !(word[j]>='a' && word[j]<='z') ){
	  Take_word(i,j);
	  
	  
	  for(k=0;k<tmp_leng;k++,now++) message[now]=tmp_word[k];
	  /* printf("%s\n",message); */
	  if(word[j]=='\n' || word[j]=='\0') break;
	  else{
	    message[now]=word[j];
	    i=j;
	    now++;
	    break;
	  }
	  
	}
	
      }

      if(word[j]=='\n' || word[j]=='\0'){
	message[now]=word[j]; 
	message[now+1]='\0';
	
	break; 
      }

    }
    else if(word[i]=='\n' || word[i]=='\0'){
      message[now]=word[i]; 
      message[now+1]='\0';
      
      break; 
    }
    else{
      message[now]=word[i];
      now++;
    }
    
  }

  
  return;

}

void Take_word(int from,int end){

  int i,k;
  char first_char=' ',tmp_char[MAX];

  /*
  printf("from=%d end=%d\n",from,end);
  for(k=0,i=from;i<end;k++,i++) printf("%c",word[i]);
  printf("\n");
  */

  if(word[from]!='A'&&word[from]!='I'&&word[from]!='U'&&word[from]!='E'&&
     word[from]!='O'&&word[from]!='a'&&word[from]!='i'&&word[from]!='u'&&
     word[from]!='e'&&word[from]!='o' ){
    
    first_char = word[from];
    from++;

  }

  for(k=0,i=from;i<end;k++,i++) tmp_char[k] = word[i];
    
  if(first_char!=' '){ tmp_char[k]=first_char; k++; }

  tmp_char[k]='a';
  tmp_char[k+1]='y';

  tmp_leng=k+2;
  for(i=0;i<=k+1;i++) tmp_word[i]=tmp_char[i];

  return; 

}
  

void Output(void){

  printf("%s",message);
  
  message[0]='\0';

  return;

}
