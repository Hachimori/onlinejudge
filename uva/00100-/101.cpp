#include<stdio.h>
#include<string.h>
#include<vector>
#define MAX 25
#define MAX_c 5

void Input_Output(void);

using namespace std;

main()
{

  Input_Output();

}

void Input_Output(void){

  int i,j,n,a,b,chk=0,a_num,b_num,counter=0;
  char command1[MAX_c],command2[MAX_c];
  vector<int> block[MAX];
  vector<int>::iterator j_ret,k_ret,tmp;

  scanf("%d",&n);
  for(i=0;i<n;i++) block[i].push_back(i);

  while(1){
    
    scanf("%s",command1);
    if(strcmp(command1,"quit")==0) break;
    
    scanf("%d%s%d",&a,command2,&b);
    
    if(a==b) continue;
    
    /* Search A */
    for(i=0;i<n;i++){
      for(j_ret=block[i].begin();j_ret!=block[i].end();j_ret++){
	if(*j_ret==a){
	  a_num=i;
	  chk=1;
	  break;
	}
      }
      if(chk==1){chk=0; break;}
    }
    /* Search B */
    for(i=0;i<n;i++){  
      for(k_ret=block[i].begin();k_ret!=block[i].end();k_ret++){
	if(*k_ret==b){
	  b_num=i;
	  chk=1;
	  break;
	}
      }
      if(chk==1){chk=0; break;}
    }
    if(a_num == b_num) continue;

    if(strcmp(command1,"move")==0){
      
      for(tmp=j_ret+1;tmp!=block[a_num].end();tmp++){
	block[*tmp].push_back(*tmp);
	counter++;
      }
      for(;counter>0;counter--) block[a_num].pop_back();

      for(i=0;i<n;i++){  /* Search B */
	for(k_ret=block[i].begin();k_ret!=block[i].end();k_ret++){
	  if(*k_ret==b){
	    b_num=i;
	    chk=1;
	      break;
	  }
	}
	if(chk==1){chk=0; break;}
      }
     
      if(a_num == b_num) break;

      if(strcmp(command2,"onto")==0){
	
	/* B 上にあるものを元の場所へ */
	for(tmp=k_ret+1;tmp!=block[b_num].end() && tmp!=j_ret;tmp++){
	  block[*tmp].push_back(*tmp);
	  counter++;
	}
	for(;counter>0;counter--) block[b_num].pop_back();

	block[b_num].push_back(*j_ret);
	block[a_num].pop_back();

      }
      else if(strcmp(command2,"over")==0){      
	block[b_num].push_back(*j_ret);
	block[a_num].pop_back();
      }

    }
    else if(strcmp(command1,"pile")==0){

      for(i=0;i<n;i++){  /* Search B */
	for(k_ret=block[i].begin();k_ret!=block[i].end();k_ret++){
	  if(*k_ret==b){
	    b_num=i;
	    chk=1;
	    break;
	  }
	}
	if(chk==1){chk=0; break;}
      }

      //printf("j_ret=%d block[%d].end() = %d\n",*j_ret,a_num,block[a_num].end());
      
      if(strcmp(command2,"onto")==0){
	for(tmp=k_ret+1;tmp!=block[b_num].end();tmp++){
	  block[*tmp].push_back(*tmp);
	  counter++;
	}
	for(;counter>0;counter--) block[b_num].pop_back();
      
	for(tmp=j_ret;tmp!=block[a_num].end();tmp++){
	  block[b_num].push_back(*tmp);
	  counter++;
	}
	for(;counter>0;counter--) block[a_num].pop_back();     
      }
      else if(strcmp(command2,"over")==0){
	for(tmp=j_ret;tmp!=block[a_num].end();tmp++){
	  block[b_num].push_back(*tmp);
	  counter++;
	}
	for(;counter>0;counter--) block[a_num].pop_back();
      }
    
    }

  }

  /* Output */
  for(i=0;i<n;i++){
    printf("%d:",i);
    for(j_ret=block[i].begin();j_ret!=block[i].end();j_ret++)
      printf(" %d",*j_ret);
    printf("\n");
  }
  
  return;

}


