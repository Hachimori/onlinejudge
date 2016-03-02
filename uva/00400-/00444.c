/*

     "A"  65   "a"  97   " "  32
     "B"  66   "b"  98   "!"  33
      .         .        ","  44
      .         .        "."  46
      .         .        ":"  58
     "Y"  89   "y"  121  ";"  59
     "Z"  90   "z"  122  "?"  63

 */

#include<stdio.h>
#include<string.h>
#define MAX_word 80
#define MAX_message 300

int Input(void);
void Encode(void);
void UnEncode(void);
char My_itoa(int *);
int My_atoi(char);

int word_length,message_i[MAX_message];
char word[MAX_word+1];
char message[MAX_message];

main()
{

  int swich;

  while(1){

    swich = Input(); 
    
    if(swich==0) break;
    else if(swich==1) Encode();      /* Encode,UnEncode 関数内で出力する */
    else if(swich==2) UnEncode();    


  }

}

int Input(void){

  if(gets(word)==NULL) return 0;
  
  word_length = strlen(word);
 
  if(word[0]>='0' && word[0]<='9') return 2;
  else return 1;

}

void Encode(void){

  int i,message_length=0;

  for(i=word_length-1;i>=0;i--){
    
    if(word[i]>=100){
      message_i[message_length]=(int)word[i]%10; message_length++;
      message_i[message_length]=(int)word[i]/10%10; message_length++;
      message_i[message_length]=(int)word[i]/10/10%10; message_length++;
    }
    else{
      message_i[message_length]=(int)word[i]%10; message_length++;
      message_i[message_length]=(int)word[i]/10%10; message_length++;
    }
    
  }

  /* Output */
  for(i=0;i<message_length;i++) printf("%d",message_i[i]);
  printf("\n");

  return;

}

void UnEncode(void){

  int i,j=0,message_length=0;
  int ascii_code[3]={0,0,1000};
  char tmp;

  for(i=word_length-1;i>=0;i--){
    
    ascii_code[j]=My_atoi(word[i]);    
    j++;
    
    if(j==2){
      tmp=My_itoa(ascii_code);
      if(tmp!='*'){
	message[message_length]=tmp;
	message_length++;
	j=0;
      }
    }
    else if(j==3){
      message[message_length]=My_itoa(ascii_code);
      message_length++;
      j=0;
      ascii_code[2]=1000;
    }

  }

  /* Output */
  for(i=0;i<message_length;i++) printf("%c",message[i]);
  printf("\n");

  return;

}

char My_itoa(int *ascii_code){

  int sum=0;

  sum+=ascii_code[0]*10;
  sum+=ascii_code[1];

  if( !(sum>='A' && sum<='Z') && !(sum>='a' && sum<='z') &&
     sum!=' ' && sum!='!' && sum!=',' && sum!='.' && 
     sum!=':' && sum!=';' && sum!='?' ){
    sum=0;
    sum+=ascii_code[0]*100;
    sum+=ascii_code[1]*10;
    sum+=ascii_code[2];
    
    if( !(sum>='A' && sum<='Z') && !(sum>='a' && sum<='z') &&
     sum!=' ' && sum!='!' && sum!=',' && sum!='.' && 
     sum!=':' && sum!=';' && sum!='?' ) return '*';
    
  }
  
  return (char)sum;

}
  
int My_atoi(char c){

  if(c=='0') return 0;
  if(c=='1') return 1;
  if(c=='2') return 2;
  if(c=='3') return 3;
  if(c=='4') return 4;
  if(c=='5') return 5;
  if(c=='6') return 6;
  if(c=='7') return 7;
  if(c=='8') return 8;
  if(c=='9') return 9;

}
