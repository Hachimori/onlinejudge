#include<stdio.h>

#define MAX_city 100
#define MAX_color 5
#define EoF -1
#define CONTINUE 1

int Input_Output(void);
int Search(int,int,char [MAX_city][MAX_color]);
void My_strcpy(char *, char *);

main()
{
  while(1){
    if(Input_Output()==EoF) break;
  }

}

int Input_Output(void){
  
  int i=0,j,num_city,num_tmp,min=1000000,tmp_city,ctr=0;
  int pre[100];
  char array[MAX_city][MAX_color],tmp,chk;
  

  pre['P']=0; pre['G']=1; pre['S']=2; pre['A']=3; pre['N']=4;


  while(1){
    
    scanf("%c",&tmp);
    
    if(tmp=='\n' && ctr==5){ i++; ctr=0; continue; }
    else if(tmp=='r'||tmp=='o'||tmp=='y'||tmp=='g'||tmp=='b') chk=tmp;
    else if(tmp=='P'||tmp=='G'||tmp=='S'||tmp=='A'||tmp=='N'){
      array[i][pre[tmp]]=chk;
      ctr++;
    }
    else if(tmp=='e' && i!=0){ /* End Of Case */
      while(1){
	scanf("%c",&tmp);
	if(tmp=='\n') break;
      }
      break;
    }
    else if(tmp=='e' && i==0) return CONTINUE;
    else if(tmp=='#') return EoF;
    
  }

  
  num_city=i;

  /*
    for(i=0;i<num_city;i++){
    for(j=0;j<MAX_color;j++){
    printf("%c ",array[i][j]);
    }
    printf("\n");
    }
    printf("\n");
    */

  for(i=0;i<num_city;i++){
    num_tmp = Search(num_city,i,array);
    if(min>num_tmp){
      tmp_city = i+1;
      min = num_tmp;
    }
  }

  printf("%d\n",tmp_city);

  return CONTINUE;

}

int Search(int num_city, int num_search, char array[MAX_city][MAX_color]){

  int i,j,k,num_ctr=0;
  char tmp_array[MAX_color],tmp;

  
  for(i=0;i<num_city;i++){
    if(i==num_search) continue;
    
    
    for(j=0;j<MAX_color;j++)
      if(array[i][j]!=array[num_search][j]) num_ctr++;
    
  }
  

  
  /* printf("num_swap=%d\n",num_swap);  */

  return num_ctr;

}
