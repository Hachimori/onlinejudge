#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<list>

#define MAX 30000

typedef struct{
  list<int> people;
}Group;


void Input_Output(void);

main()
{
  
  int i,cases;

  scanf("%d",&cases);

  for(i=0;i<cases;i++)
    Input_Output();

}

void Input_Output(void){
  
  int i,j,N,M,left,right,num_group=0,max=0,tmp;
  int where_1,where_2,chk1=0,chk2=0;
  int place[MAX];
  list<int>::iterator list1_ret,list2_ret,first,last;
  Group friends[MAX];

  scanf("%d%d",&N,&M);

  for(i=1;i<=N;i++) place[i]=-1;

  for(i=0;i<M;i++){
    
    chk1=0; chk2=0;

    cin >> left >> right;
    
    if(place[left]!=-1) chk1=1;
    if(place[right]!=-1) chk2=1;

    if(chk1==0 && chk2==0){
      friends[num_group].people.push_back(left);
      friends[num_group].people.push_back(right);
      place[left]=num_group;
      place[right]=num_group;
      num_group++;
    }
    else if(chk1==0 && chk2==1){
      friends[place[right]].people.push_back(left);
      place[left]=place[right];
    }
    else if(chk1==1 && chk2==0){
      friends[place[left]].people.push_back(right);
      place[right]=place[left];
    }
    else if(chk1==1 && chk2==1){

      if(place[left]!=place[right]){
	first = friends[place[right]].people.begin();
	last = friends[place[right]].people.end();
	tmp = place[right];
	
	for(;first!=last;first++){
	  //printf("right first = %d\n",*first);
	  place[*first] = place[left];
	}	

	friends[place[left]].people.merge(friends[tmp].people);
	
      }

    }
  }

  for(i=0;i<num_group;i++){
    //printf("size=%d\n",friends[i].people.size());
    friends[i].people.unique();
    if(max<friends[i].people.size()) max = friends[i].people.size();
  }

  printf("%d\n",max);


  return;

}
