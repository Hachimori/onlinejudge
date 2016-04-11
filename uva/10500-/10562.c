#include<stdio.h>
#define MAX 201

void Input_Output(void);
void Search(char array[MAX][MAX],int,int);

int max_line;

main()
{

  int i,n;
  char tmp;

  scanf("%d",&n);
  
  while(1){
    scanf("%c",&tmp);
    if(tmp=='\n') break;
  }

  for(i=0;i<n;i++){
    printf("(");
    Input_Output();
    printf(")\n");
    scanf("%c",&tmp);
  }

}

void Input_Output(void){

  int i,j,chk=0;
  char array[MAX][MAX];

  for(i=0;i<MAX;i++) for(j=0;j<MAX;j++) array[i][j]=' ';

  for(i=0;;i++){
    for(j=0;;j++){
      scanf("%c",&array[i][j]);
      
      if(array[i][j]=='\n') break;
      else if(array[i][j]=='#'){ chk=1; break; }

    }

    if(chk==1) break;

  }

  max_line = i;

  /*
  chk=0;
  for(i=0;;i++){
    for(j=0;;j++){
      printf("%c",array[i][j]);
      if(array[i][j]=='\n') break;
      else if(array[i][j]=='#'){ chk=1; break; }
    }
    if(chk==1) break;
  }
  */

  chk=0;

  
  for(i=0;;i++){
    for(j=0;;j++){
      if(array[i][j]!='\n' && array[i][j]!='|' 
	 && array[i][j]!='-' && array[i][j]!=' ' && array[i][j]!='#'){
	Search(array,i,j);
	printf(")");
	chk=1;
      }
      else if(array[i][j]=='\n') break;
      else if(array[i][j]=='#'){ chk=1; break; }
    }

    if(chk==1) break;

  }
  
  
  return;

}

void Search(char array[MAX][MAX],int y,int x){
  
  int i,j,chk=0;
  

  /*
    printf("y=%d , x=%d\n",y,x);

    for(i=0;;i++){
    for(j=0;;j++){
    printf("%c",array[i][j]);
    if(array[i][j]=='\n') break;
    else if(array[i][j]=='#'){ chk=1; break; }
    }
    if(chk==1) break;
    }

    chk=0;
    */
    
  if(array[y][x]!='\n' && array[y][x]!='|' 
     && array[y][x]!='-' && array[y][x]!=' '){
    printf("%c(",array[y][x]);
  }

  
  /* º¸ */
  if(x>=1 && array[y][x-1]=='-'){
    array[y][x]=' ';
    Search(array,y,x-1);
    
  }

  /* ²¼ */
  if( y+1!=max_line && array[y+1][x]=='|' || array[y+1][x]=='-' ){
    array[y][x]=' ';
    Search(array,y+1,x);
    
  }
  else if( y+1!=max_line && array[y+1][x]!='\n' && array[y+1][x]!='|' 
	                 && array[y+1][x]!='-' && array[y+1][x]!=' '){
    array[y][x]=' ';
    Search(array,y+1,x);
    printf(")");
  }

  /* ±¦ */
  if(array[y][x+1]=='-'){
    array[y][x]=' ';
    Search(array,y,x+1);
  }

  return;
 
}
