#include<stdio.h>


int cases;
int num_val;
int length;
char tree[100];
char list_val[10][5];
char operation[10];

void search_rec(int arg, int left, int right){

  if(arg==num_val){
    if(tree[left]=='0') printf("0");
    else if(tree[left]=='1') printf("1");
    return;
  }

  if(operation[list_val[arg][1]-'0'-1]=='0'){
    search_rec(arg+1,left,(left+right)/2);
  }
  else if(operation[list_val[arg][1]-'0'-1]=='1'){
    search_rec(arg+1,(left+right)/2,right);
  }

}

int input(){

  int i;

  length=1;

  scanf("%d",&num_val); 

  if(num_val==0) return -1;

  for(i=0;i<num_val;i++){
    scanf("%s",list_val[i]);
  }

  scanf("%s",tree);

  for(i=0;i<num_val;i++) length*=2;

  return 1;
}

void work(){

  int i;
  int test_case;


  scanf("%d",&test_case);

  printf("S-Tree #%d:n",cases);
  for(i=0;i<test_case;i++){
    scanf("%s",operation);

    search_rec(0,0,length);
  }

  printf("nn");

}

main(){

  for(cases=1;;cases++){
    if(input()==-1) break;
    work();
  }
}
