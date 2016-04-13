#include<stdio.h>
#include<string.h>

#define MAX 105

typedef struct{

  char name[20];
  int one;
  int half;
  int total_cost;

}Info;

int source,target,num_agent;
int cases;
Info list[MAX];

void sort(){

  int i,j,k;
  int tmp;
  char tmp_name[20];

  for(i=0;i<num_agent;i++){

    for(j=i+1;j<num_agent;j++){
      if(list[i].total_cost>list[j].total_cost){
	strcpy(tmp_name,list[i].name);
	strcpy(list[i].name,list[j].name);
	strcpy(list[j].name,tmp_name);

	tmp = list[i].total_cost;
	list[i].total_cost = list[j].total_cost;
	list[j].total_cost = tmp;
      }
      else if(list[i].total_cost==list[j].total_cost){

	for(k=0;;k++){
	  if(list[i].name[k]>list[j].name[k]){
	    strcpy(tmp_name,list[i].name);
	    strcpy(list[i].name,list[j].name);
	    strcpy(list[j].name,tmp_name);
	    break;
	  }
	  else if(list[i].name[k]==list[j].name[k]){}
	  else break;
	}
      }
    }
  }

}

void input(){

  int i,j;
  char c;
  char string[100];

  scanf("%d%d%d",&source,&target,&num_agent);

  for(i=0;i<num_agent;i++){

    gets(string);
    for(j=0;;j++){
      scanf("%c",&c);
      if(c==':') { list[i].name[j]='
else list[i].name[j] = c;
}
scanf("%d,%d",&list[i].one,&list[i].half);
list[i].total_cost=0;
}
/*
for(i=0;i<num_agent;i++){
printf("%s:%d,%dn",list[i].name,list[i].one,list[i].half);
}
*/
}

void work(){

int i,curr_work;

for(i=0;i<num_agent;i++){
curr_work=source;

while(1){
if(curr_work/2<target){
list[i].total_cost += (curr_work-target)*list[i].one;
break;
}
else{
if( (curr_work*list[i].one/2) < list[i].half){
list[i].total_cost += (curr_work-target)*list[i].one;
break;
}
else{
list[i].total_cost += list[i].half;
curr_work/=2;
}
}
if(curr_work==target) break;
}

}

sort();

printf("Case %dn",cases);
for(i=0;i<num_agent;i++){
printf("%s %dn",list[i].name,list[i].total_cost);
}

}

main(){

int test_cases;

scanf("%d",&test_cases);

for(cases=1;cases<=test_cases;cases++){

input();
work();

}

}
