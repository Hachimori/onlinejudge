#include<stdio.h>
#include<string.h>

#define MAX_words 11
#define MAX_length 25

void put0(void);
int Search_common( void ); /* ２つの文字から共有する文字を探し
			      何文字,何番めか代入２つのクロスが無ければ０返す */
void Input_array( void );  /* 座標入力 */
void Output( void );       /* 座標出力 */
int Cmp(int,int);           /* 数字を比べて大きい方を返す */

int length1,length2,length3,length4,w1_common,w2_common,w3_common,w4_common;
int vertical_xbegin1,vertical_ybegin1,vertical_xbegin2,vertical_ybegin2;
int horizontal_xbegin1,horizontal_ybegin1,horizontal_xbegin2,horizontal_ybegin2;

char word1[MAX_words],word2[MAX_words],word3[MAX_words],word4[MAX_words];
char array[MAX_length][MAX_length];

main()
{
  
  int check=0;
  
  while(1){

    put0();

    scanf("%s",word1);    
    if( strcmp(word1,"#")==0 ) break;
    scanf("%s%s%s",word2,word3,word4);
    
    if(check==1) printf("\n");
    check=1;
    
    if(Search_common()==0){ 
      printf("Unable to make two crosses\n");
      continue;
    }

    /*
    printf("word1=%s, word2=%s, word3=%s, word4=%s\n",word1,word2,word3,word4);
    printf("w1_com=%d, w2_com=%d, w3_com=%d, w4_com=%d\n",w1_common,w2_common,w3_common,w4_common);
    */

    Input_array();
    
    Output();
  }

}

void put0(void){

  int i,j;

  for(i=0;i<MAX_length;i++){
    for(j=0;j<MAX_length;j++){
      array[i][j]='0';
    }
  }
  return;
}

int Search_common( void ){

  int i,j,check=0,num_cross=0;

  length1 = strlen(word1);
  length2 = strlen(word2);
  length3 = strlen(word3);
  length4 = strlen(word4);

  for(i=0;i<length1;i++){
    for(j=0;j<length2;j++){
      if(word1[i]==word2[j]){
	w1_common = i;
	w2_common = j;
	num_cross++;
	check = 1;
	break;
      }
    }
    if(check==1){ check=0; break; }
  }

  for(i=0;i<length3;i++){
    for(j=0;j<length4;j++){
      if(word3[i]==word4[j]){
	w3_common = i;
	w4_common = j;
	check = 1;
	num_cross++;
	break;
      }
    }
    if(check==1){ check=0; break; }
  }
    
  if(num_cross == 2) return 1;
  else return 0;

}

void Input_array( void ){

  int i,j,k;
  
  if(w2_common > w4_common){ /* 最初のクロスは,二番目よりも上に長い */
    vertical_xbegin1 = w1_common;
    vertical_ybegin1 = 0;
    vertical_xbegin2 = length1 + w3_common + 3;
    vertical_ybegin2 = w2_common - w4_common;
    horizontal_xbegin1 = 0;
    horizontal_ybegin1 = w2_common;
    horizontal_xbegin2 = length1 + 3;
    horizontal_ybegin2 = w2_common;
  }
  else { /* 二番目のクロスは,最初のよりも上に長い */
    vertical_xbegin1 = w1_common;
    vertical_ybegin1 = w4_common - w2_common;
    vertical_xbegin2 = length1 + w3_common + 3;
    vertical_ybegin2 = 0;
    horizontal_xbegin1 = 0;
    horizontal_ybegin1 = w4_common;
    horizontal_xbegin2 = length1 + 3;
    horizontal_ybegin2 = w4_common;
  }

  /*
  printf("v_x1=%d, v_y1=%d, v_x2=%d, v_y2=%d\n",vertical_xbegin1,vertical_ybegin1,vertical_xbegin2,vertical_ybegin2);
  printf("h_x1=%d, h_y1=%d, h_x2=%d, h_y2=%d\n",horizontal_xbegin1,horizontal_ybegin1,horizontal_xbegin2,horizontal_ybegin2); */

  /* word1 インプット */
  for(k=0,i=horizontal_ybegin1,j=horizontal_xbegin1;k<length1;j++,k++) array[i][j] = word1[k];
  /* word2 インプット */
  for(k=0,i=vertical_ybegin1,j=vertical_xbegin1;k<length2;i++,k++) array[i][j] = word2[k];
  for(k=0,i=vertical_ybegin1;k<length2;i++,k++){
    for(j=0;j<vertical_xbegin1;j++){
      if(array[i][j]=='0') array[i][j]=' ';
    }
  }
  /* word3 インプット */
  for(k=0,i=horizontal_ybegin2,j=horizontal_xbegin2;k<length3;j++,k++) array[i][j] = word3[k];
  for(j=length1;j<horizontal_xbegin2-length1;j++) if(array[i][j]=='0') array[horizontal_ybegin2][j]=' ';

  /* word4 インプット */
  for(k=0,i=vertical_ybegin2,j=vertical_xbegin2;k<length4;i++,k++) array[i][j] = word4[k];
  for(k=0,i=vertical_ybegin2;k<length4;i++,k++){
    for(j=0;j<vertical_xbegin2;j++){
      if(array[i][j]=='0') array[i][j]=' ';
    }
  }

  return;

}

void Output( void ){

  int i,j;

  if(w2_common > w4_common){ /* 最初のクロスは,二番目よりも上に長い */

    for(i=0;i<Cmp(w2_common+length4-w4_common,length2);i++){
      for(j=0;j<length1+3+length3;j++){
	if(array[i][j] != '0') printf("%c",array[i][j]);
      }
      printf("\n");
    }
    
  }
  else { /* 二番目のクロスは,最初のよりも上に長い */

    for(i=0;i<Cmp(w4_common+length2-w2_common,length4);i++){
      for(j=0;j<length1+3+length3;j++){
	if(array[i][j] != '0') printf("%c",array[i][j]);
      }
      printf("\n");
    }
    
  }

  return;

}

int Cmp(int a, int b){

  if(a>b) return a;
  else return b;
}
