#include<stdio.h>
#define MAX 201

void Input_Output(void);
void Delete_Box(int,int,int);

int num_box,num_delete=0,score=0;
int box[MAX];
int priority[MAX]; 

main(){

  int i,n;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    Input_Output();
    printf("Case %d: %d\n",i,score);
    score=0;
    num_delete=0;
  }

}

void Input_Output(void){

  int i,max_priority=0,delete,left,right,tmp;

  scanf("%d",&num_box);
  for(i=0;i<=num_box;i++) priority[i]=0;

  for(i=0;i<num_box;i++){
    scanf("%d",&box[i]);
    priority[box[i]]++;
  }
  
  /* ͥ���٤ι⤤�ܥå�������ä��Ƥ��� */
  while(num_delete!=num_box){
    max_priority=0;
    
    for(i=0;i<num_box;i++)
      if(max_priority<priority[i]){
	max_priority = priority[i];
	delete=box[i];
      }
    printf("%d %d %d\n",delete,num_delete,num_box);
    /* ͥ���٤ι⤤���򣲤ĸ��Ĥ��� */
    i=0;
    if(box[0]!=delete) for(;box[i]!=delete && i<num_box;i++){}
    for(;box[i]==delete && i<num_box;i++){}
    
    left=i;
    
    /* ͥ���٤ι⤤���ϰ�Ĥ����ʤ� */
    if(left==num_box) Delete_Box(delete,0,0);
    else{

      for(i=left;box[i]!=delete && i<num_box;i++){}
      right=i;
      
      /* ͥ���٤ι⤤���ϰ�Ĥ����ʤ� */
      if(right==num_box) Delete_Box(delete,0,0);
      else{
	
	/* ͥ���٤ι⤤���ϣ��İʾ夢�� */
	Delete_Box(delete,left,right);
      
      }

    }

  }

  return;

}

void Delete_Box(int delete, int left, int right){

  int i,j,max_priority,delete2,left2,right2;
  int tmp,tmp2;

  if( left==0 && right == 0){ /* �֥�å���ä� */
  
    if(box[0]!=delete){ 
      for(i=0;box[i]!=delete && i<num_box;i++){}
      tmp = i;
    }
    else tmp = 0;
    
    for(i=tmp;box[i]==delete && i<num_box;i++){}
    tmp2=i;
    
    score += (tmp2-tmp)*(tmp2-tmp);
    num_delete += tmp2-tmp;

    priority[delete]=-1;
    
    return;
  
  }


  /* ͥ���٤ι⤤�ܥå������椫��ܥå�����ä��Ƥ��� */
  max_priority=0;
    
  for(i=left;i<right;i++)
    if(max_priority<priority[i]){
      max_priority = priority[i];
      delete2=i;
    }
    
  /* ͥ���٤ι⤤���򣲤ĸ��Ĥ��� */
  for(i=left;box[i]!=delete2 && i<num_box;i++){}
  for(;box[i]==delete2 && i<num_box;i++){}
  
  left2=i;
  
  /* ͥ���٤ι⤤���ϰ�Ĥ����ʤ� */
  if(left2==num_box) Delete_Box(delete2,0,0);
  else{
    
    for(i=left;box[i]!=delete2 && i<num_box;i++){}
      right2=i;
      
      /* ͥ���٤ι⤤���ϰ�Ĥ����ʤ� */
      if(right2==num_box) Delete_Box(delete2,0,0);
      else{
	
	/* ͥ���٤ι⤤���ϣ��İʾ夢�� */
	Delete_Box(delete2,left2,right2);
	
      }
      
  }
  
  return;

}
