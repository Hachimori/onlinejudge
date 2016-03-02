#include<stdio.h>

int Input_Search(void);
void Output(void);

int nr_value;
double average_up,average_down;

main()
{

  while(1){

    if(Input_Search()==0) break;
    Output();

  }

}

int Input_Search(void){

  int i,prev_digit,digit;
  int after_up=0,after_down=0,num_same=0;
  double sum_up=0,num_up=0,sum_down=0,num_down=0;

  scanf("%d",&digit);
  if(digit==0) return 0;
  else prev_digit=digit;

  for(i=2;;i++){
    
    scanf("%d",&digit);
    
    if(digit==0) break;
    else{
      
      if(digit>prev_digit){
	if(num_same>0){ sum_up+=num_same; num_same=0; }
	sum_up++;
	if(after_up==0){ after_up=1; num_up++; }
	after_down=0;
	prev_digit = digit;
      }
      else if(digit<prev_digit){
	if(num_same>0){ sum_down+=num_same; num_same=0; }
	sum_down++;
	if(after_down==0){ after_down=1; num_down++; }
	after_up=0;
	prev_digit = digit;
      }
      else if(digit==prev_digit){

	if(after_up==1){
	  sum_up++;
	}
	else if(after_down==1){
	  sum_down++;
	}
	else if(after_up==0 && after_down==0){
	  num_same++;
	}

      }
    
    }

  }

  /*
  printf("sum_up = %lf  num_up = %lf  sum_down = %lf  num_down = %lf\n"
	 ,sum_up,num_up,sum_down,num_down);
	 */ 

  nr_value = i-1;
  if(num_up==0) average_up = 0;
  else average_up = sum_up/num_up;
  if(num_down==0) average_down = 0;
  else  average_down = sum_down/num_down;

  return 1;

}

void Output(void){

  printf("Nr values = %d:  %lf %lf\n",nr_value,average_up,average_down);

  return;

}
