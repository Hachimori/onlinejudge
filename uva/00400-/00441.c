#include<stdio.h>

#define EoF -1

#define MAX_lotto 12
#define MAX_ignore 6

int Input_Output(void);
void Sort(int,int,int *);
void Case1(int,int *);
void Case2(int,int *);
void Case3(int,int *);
void Case4(int,int *);
void Case5(int,int *);
void Case6(int,int *);

int first=1;

main()
{

  while(1){

    if(Input_Output()==EoF) break;

  }

}

int Input_Output(void){

  int i;
  int num_lotto,lotto[MAX_lotto];


  scanf("%d",&num_lotto);
  if(num_lotto==0) return EoF;

  if(first==0) printf("\n");
  first=0;

  for(i=0;i<num_lotto;i++) scanf("%d",&lotto[i]);

  Sort(0,num_lotto,lotto);
  
  if(num_lotto-6==1) Case1(num_lotto,lotto);
  else if(num_lotto-6==2) Case2(num_lotto,lotto);
  else if(num_lotto-6==3) Case3(num_lotto,lotto);
  else if(num_lotto-6==4) Case4(num_lotto,lotto);
  else if(num_lotto-6==5) Case5(num_lotto,lotto);
  else if(num_lotto-6==6) Case6(num_lotto,lotto);

  return 1;

}

void Sort(int left,int right,int pairs[]){

  int i,j,num=left,tmp;
  int pairs2[MAX_lotto];


  if( right-left==1 ) return;
  else if( right-left==2 ){
    if(pairs[right-1]>pairs[left]){}
    else{ 
      tmp = pairs[right-1]; 
      pairs[right-1] = pairs[left];
      pairs[left] = tmp;
      
      return;
    }
  }
  
  Sort(left,left+(right-left)/2,pairs);
  Sort(left+(right-left)/2,right,pairs);
  
  for(i=left,j=left+(right-left)/2; i<left+(right-left)/2 || j<right;){
    
    if( pairs[i]>pairs[j] && j<right || i==left+(right-left)/2 ){
      pairs2[num]=pairs[j];
      j++;
      num++;
    }
    else if( pairs[i]<pairs[j] && i<left+(right-left)/2 || j==right ){
      pairs2[num]=pairs[i];
      i++;
      num++;
    }
    else if( pairs[i]==pairs[j] && j<right ){
      pairs2[num]=pairs[j];
      j++;
      num++;
    }
    else if( pairs[i]==pairs[j] && i<left+(right-left)/2  ){
      pairs2[num]=pairs[i];
      i++;
      num++;
    }

  }

  for(i=left;i<right;i++) pairs[i]=pairs2[i];
  

  return;

}

void Case1(int num_lotto, int x[]){

  int i,num,a;

  for(a=num_lotto-1;a>=0;a--)
    for(i=0,num=0;num<6;i++){
      if(i!=a && num!=5){
	printf("%d ",x[i]);
	num++;
      }
      else if(i!=a && num==5){
	printf("%d\n",x[i]);
	num++;
      }
    }

  return;

}

void Case2(int num_lotto, int x[]){

  int i,num,a,b;
  
  for(a=num_lotto-2;a>=0;a--)
    for(b=num_lotto-1;b>=a+1;b--)
      for(i=0,num=0;num<6;i++){
	if(i!=a && i!=b && num!=5){
	  printf("%d ",x[i]);
	  num++;
	}
	else if(i!=a && i!=b && num==5){
	  printf("%d\n",x[i]);
	  num++;
	}
      }
  
  return;

}

void Case3(int num_lotto, int x[]){

  int i,num,a,b,c;
  
  for(a=num_lotto-3;a>=0;a--)
    for(b=num_lotto-2;b>=a+1;b--)
      for(c=num_lotto-1;c>=b+1;c--)
	for(i=0,num=0;num<6;i++){
	  if(i!=a && i!=b && i!=c && num!=5){
	    printf("%d ",x[i]);
	    num++;
	  }
	  else if(i!=a && i!=b && i!=c && num==5){
	    printf("%d\n",x[i]);
	    num++;
	  }
	}
  
  return;
  
}

void Case4(int num_lotto, int x[]){
  
  int i,num,a,b,c,d;
  
  for(a=num_lotto-4;a>=0;a--)
    for(b=num_lotto-3;b>=a+1;b--)
      for(c=num_lotto-2;c>=b+1;c--)
	for(d=num_lotto-1;d>=c+1;d--)
	  for(i=0,num=0;num<6;i++){
	    if(i!=a && i!=b && i!=c && i!=d && num!=5){
	      printf("%d ",x[i]);
	      num++;
	    }
	    else if(i!=a && i!=b && i!=c && i!=d && num==5){
	      printf("%d\n",x[i]);
	      num++;
	    }
	  }
  
  return;
  
}

void Case5(int num_lotto, int x[]){

  int i,num,a,b,c,d,e;
  
  for(a=num_lotto-5;a>=0;a--)
    for(b=num_lotto-4;b>=a+1;b--)
      for(c=num_lotto-3;c>=b+1;c--)
	for(d=num_lotto-2;d>=c+1;d--)
	  for(e=num_lotto-1;e>=d+1;e--)
	    for(i=0,num=0;num<6;i++){
	      if(i!=a && i!=b && i!=c && i!=d && i!=e && num!=5){
		printf("%d ",x[i]);
		num++;
	      }
	      else if(i!=a && i!=b && i!=c && i!=d && i!=e && num==5){
		printf("%d\n",x[i]);
		num++;
	      }
	    }
  
  return;
  
}

void Case6(int num_lotto, int x[]){
  
  int i,num,a,b,c,d,e,f;
  
  for(a=num_lotto-6;a>=0;a--)
    for(b=num_lotto-5;b>=a+1;b--)
      for(c=num_lotto-4;c>=b+1;c--)
	for(d=num_lotto-3;d>=c+1;d--)
	  for(e=num_lotto-2;e>=d+1;e--)
	    for(f=num_lotto-1;f>=e+1;f--)
	      for(i=0,num=0;num<6;i++){
		if(i!=a && i!=b && i!=c && i!=d && i!=e && i!=f && num!=5){
		  printf("%d ",x[i]);
		  num++;
		}
		else if(i!=a && i!=b && i!=c && i!=d && i!=e &&  i!=f && num==5){
		  printf("%d\n",x[i]);
		  num++;
		}
	      }
  
  return;

}
