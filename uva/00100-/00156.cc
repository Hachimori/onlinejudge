/*** sort ***/
/*
  sort�͂���z��̒��g�̐��������B
  #include<algorithm> �̒���sort�֐��������Ă���B
�@
�@sort(������J�n����A�h���X, ������I������A�h���X);
  �Ő�������Ă����B

�Q��:
  http://cppreference.com/ �� C++ Algorithms 
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<string>
#include<algorithm>

#define MAX_SIZE 85
#define MAX_WORD 1005

using namespace std;

int main(){
  int i, j, k;
  int nWord = 0, nAnana = 0, isAnana, cnt[MAX_WORD][27];
  char word[MAX_WORD][MAX_SIZE];
  string anana[MAX_WORD];

  for(i=0;i<MAX_WORD;i++)
    for(j=0;j<27;j++)
      cnt[i][j] = 0;

  while(1){
    scanf("%s",word[nWord]);
    if(strcmp(word[nWord],"#")==0) break;
    
    for(i=0;i<strlen(word[nWord]);i++)
      cnt[nWord][toupper(word[nWord][i])-'A']++;
    nWord++;
  }
  
  for(i=0;i<nWord;i++){
    isAnana = 1;
    for(j=0;j<nWord;j++){
      if(i==j) continue;
      
      for(k=0;k<27;k++)
	if(cnt[i][k]!=cnt[j][k])
	  break;
      
      if(k==27){
	isAnana = 0;
	break;
      }
    }
    
    if(isAnana)
      anana[nAnana++] = string(word[i]);
  }
  
  sort(anana,anana+nAnana);

  for(i=0;i<nAnana;i++)
    printf("%s\n",anana[i].c_str());
  
  return 0;
}
