#include<iostream>
#include<string>

#define MAX 13

int max;
char str1[MAX],str2[MAX],str3[MAX],str4[MAX];
int horizontal_used1,horizontal_used2;
int vertical_share_pos1,vertical_share_pos2;
int horizontal_share_pos1,horizontal_share_pos2;

void one_step3(){
  int distance = vertical_share_pos2-vertical_share_pos1;
  int horizontal_pos1 = horizontal_share_pos1+2;
  int horizontal_pos2 = horizontal_share_pos2+2;

  for(;horizontal_pos1<11 && horizontal_pos2<11;horizontal_pos1++,horizontal_pos2++){
    
    if(horizontal_used1!=2 && horizontal_used2!=2)
      for(int j=1,k=1+distance;k<11;j++,k++){
	if(horizontal_used1==3){
	  if(str2[j]==str3[horizontal_pos1] && str2[k]==str4[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }
	}
	else if(horizontal_used1==4){
	  if(str2[j]==str4[horizontal_pos1] && str2[k]==str3[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }	  
	}
      }

    if(horizontal_used1!=3 && horizontal_used2!=3)
      for(int j=1,k=1+distance;k<11;j++,k++){
	if(horizontal_used1==2){
	  if(str3[j]==str2[horizontal_pos1] && str3[k]==str4[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }
	}
	else if(horizontal_used1==4){
	  if(str3[j]==str4[horizontal_pos1] && str3[k]==str2[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }	  
	}
      }

    if(horizontal_used1!=4 && horizontal_used2!=4)
      for(int j=1,k=1+distance;k<11;j++,k++){
	if(horizontal_used1==2){
	  if(str4[j]==str2[horizontal_pos1] && str4[k]==str3[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	    
	  }
	}
	else if(horizontal_used1==3){
	  if(str4[j]==str3[horizontal_pos1] && str4[k]==str2[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }	  
	}
      }

  }
  
}

void two_step3(){
  int distance = vertical_share_pos2-vertical_share_pos1;
  int horizontal_pos1 = horizontal_share_pos1+2;
  int horizontal_pos2 = horizontal_share_pos2+2;

  for(;horizontal_pos1<11 && horizontal_pos2<11;horizontal_pos1++,horizontal_pos2++){
    
    if(horizontal_used1!=1 && horizontal_used2!=1)
      for(int j=1,k=1+distance;k<11;j++,k++){
	if(horizontal_used1==3){
	  if(str1[j]==str3[horizontal_pos1] && str1[k]==str4[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }
	}
	else if(horizontal_used1==4){
	  if(str1[j]==str4[horizontal_pos1] && str1[k]==str3[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }	  
	}
      }

    if(horizontal_used1!=3 && horizontal_used2!=3)
      for(int j=1,k=1+distance;k<11;j++,k++){
	if(horizontal_used1==1){
	  if(str3[j]==str1[horizontal_pos1] && str3[k]==str4[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }
	}
	else if(horizontal_used1==4){
	  if(str3[j]==str4[horizontal_pos1] && str3[k]==str1[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }	  
	}
      }

    if(horizontal_used1!=4 && horizontal_used2!=4)
      for(int j=1,k=1+distance;k<11;j++,k++){
	if(horizontal_used1==1){
	  if(str4[j]==str1[horizontal_pos1] && str4[k]==str3[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	    
	  }
	}
	else if(horizontal_used1==3){
	  if(str4[j]==str3[horizontal_pos1] && str4[k]==str1[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }	  
	}
      }

  }
  
}

void three_step3(){
  int distance = vertical_share_pos2-vertical_share_pos1;
  int horizontal_pos1 = horizontal_share_pos1+2;
  int horizontal_pos2 = horizontal_share_pos2+2;

  for(;horizontal_pos1<11 && horizontal_pos2<11;horizontal_pos1++,horizontal_pos2++){
    
    if(horizontal_used1!=1 && horizontal_used2!=1)
      for(int j=1,k=1+distance;k<11;j++,k++){
	if(horizontal_used1==2){
	  if(str1[j]==str2[horizontal_pos1] && str1[k]==str4[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }
	}
	else if(horizontal_used1==4){
	  if(str1[j]==str4[horizontal_pos1] && str1[k]==str2[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }	  
	}
      }

    if(horizontal_used1!=2 && horizontal_used2!=2)
      for(int j=1,k=1+distance;k<11;j++,k++){
	if(horizontal_used1==1){
	  if(str2[j]==str1[horizontal_pos1] && str2[k]==str4[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }
	}
	else if(horizontal_used1==4){
	  if(str2[j]==str4[horizontal_pos1] && str2[k]==str1[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }	  
	}
      }

    if(horizontal_used1!=4 && horizontal_used2!=4)
      for(int j=1,k=1+distance;k<11;j++,k++){
	if(horizontal_used1==1){
	  if(str4[j]==str1[horizontal_pos1] && str4[k]==str2[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	    
	  }
	}
	else if(horizontal_used1==2){
	  if(str4[j]==str2[horizontal_pos1] && str4[k]==str1[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }	  
	}
      }

  }
  
}

void four_step3(){
  int distance = vertical_share_pos2-vertical_share_pos1;
  int horizontal_pos1 = horizontal_share_pos1+2;
  int horizontal_pos2 = horizontal_share_pos2+2;

  for(;horizontal_pos1<11 && horizontal_pos2<11;horizontal_pos1++,horizontal_pos2++){
    
    if(horizontal_used1!=1 && horizontal_used2!=1)
      for(int j=1,k=1+distance;k<11;j++,k++){
	if(horizontal_used1==2){
	  if(str1[j]==str2[horizontal_pos1] && str1[k]==str3[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }
	}
	else if(horizontal_used1==3){
	  if(str1[j]==str3[horizontal_pos1] && str1[k]==str2[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }	  
	}
      }

    if(horizontal_used1!=2 && horizontal_used2!=2)
      for(int j=1,k=1+distance;k<11;j++,k++){
	if(horizontal_used1==1){
	  if(str2[j]==str1[horizontal_pos1] && str2[k]==str3[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }
	}
	else if(horizontal_used1==3){
	  if(str2[j]==str3[horizontal_pos1] && str2[k]==str1[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }	  
	}
      }

    if(horizontal_used1!=3 && horizontal_used2!=3)
      for(int j=1,k=1+distance;k<11;j++,k++){
	if(horizontal_used1==1){
	  if(str3[j]==str1[horizontal_pos1] && str3[k]==str2[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	    
	  }
	}
	else if(horizontal_used1==2){
	  if(str3[j]==str2[horizontal_pos1] && str3[k]==str1[horizontal_pos2]){
	    if(max<(distance-1)*(horizontal_pos1-horizontal_share_pos1-1))
	      max = (distance-1)*(horizontal_pos1-horizontal_share_pos1-1);
	  }	  
	}
      }

  }
  
}


void one_step2(){
  
  for(int i=vertical_share_pos1+2;i<11;i++){
    

    if(horizontal_used1!=2)
      for(int j=1;j<11;j++){
	if(str1[i]==str2[j]){
	  vertical_share_pos2 = i;
	  horizontal_share_pos2 = j;
	  horizontal_used2 = 2;
	  one_step3();
	}
      }
    
    
    if(horizontal_used1!=3)
      for(int j=1;j<11;j++){
	if(str1[i]==str3[j]){
	  vertical_share_pos2 = i;
	  horizontal_share_pos2 = j;
	  horizontal_used2 = 3;
	  one_step3();
	}
      }
    

    if(horizontal_used1!=4)
      for(int j=1;j<11;j++){
	if(str1[i]==str4[j]){
	  vertical_share_pos2 = i;
	  horizontal_share_pos2 = j;
	  horizontal_used2 = 4;
	  one_step3();
	}
      }
    
  }

}

void two_step2(){
  
  for(int i=vertical_share_pos1+2;i<11;i++){
    

    if(horizontal_used1!=1)
      for(int j=1;j<11;j++){
	if(str2[i]==str1[j]){
	  vertical_share_pos2 = i;
	  horizontal_share_pos2 = j;
	  horizontal_used2 = 1;
	  two_step3();
	}
      }
    
    
    if(horizontal_used1!=3)
      for(int j=1;j<11;j++){
	if(str2[i]==str3[j]){
	  vertical_share_pos2 = i;
	  horizontal_share_pos2 = j;
	  horizontal_used2 = 3;
	  two_step3();
	}
      }
    

    if(horizontal_used1!=4)
      for(int j=1;j<11;j++){
	if(str2[i]==str4[j]){
	  vertical_share_pos2 = i;
	  horizontal_share_pos2 = j;
	  horizontal_used2 = 4;
	  two_step3();
	}
      }
    
  }

}

void three_step2(){
  
  for(int i=vertical_share_pos1+2;i<11;i++){
    

    if(horizontal_used1!=1)
      for(int j=1;j<11;j++){
	if(str3[i]==str1[j]){
	  vertical_share_pos2 = i;
	  horizontal_share_pos2 = j;
	  horizontal_used2 = 1;
	  three_step3();
	}
      }
    
    
    if(horizontal_used1!=2)
      for(int j=1;j<11;j++){
	if(str3[i]==str2[j]){
	  vertical_share_pos2 = i;
	  horizontal_share_pos2 = j;
	  horizontal_used2 = 2;
	  three_step3();
	}
      }
    

    if(horizontal_used1!=4)
      for(int j=1;j<11;j++){
	if(str3[i]==str4[j]){
	  vertical_share_pos2 = i;
	  horizontal_share_pos2 = j;
	  horizontal_used2 = 4;
	  three_step3();
	}
      }
    
  }

}

void four_step2(){
  
  for(int i=vertical_share_pos1+2;i<11;i++){
    

    if(horizontal_used1!=1)
      for(int j=1;j<11;j++){
	if(str4[i]==str1[j]){
	  vertical_share_pos2 = i;
	  horizontal_share_pos2 = j;
	  horizontal_used2 = 1;
	  four_step3();
	}
      }
    
    
    if(horizontal_used1!=2)
      for(int j=1;j<11;j++){
	if(str4[i]==str2[j]){
	  vertical_share_pos2 = i;
	  horizontal_share_pos2 = j;
	  horizontal_used2 = 2;
	  four_step3();
	}
      }
    

    if(horizontal_used1!=3)
      for(int j=1;j<11;j++){
	if(str4[i]==str3[j]){
	  vertical_share_pos2 = i;
	  horizontal_share_pos2 = j;
	  horizontal_used2 = 3;
	  four_step3();
	}
      }
    
  }

}

void one_first(){

    for(int i=1;i<11;i++){

      for(int j=1;j<11;j++){
	if(str1[i]==str2[j]){
	  vertical_share_pos1 = i;
	  horizontal_share_pos1 = j;
	  horizontal_used1=2;
	  one_step2();
	}
      }     
      
      
      for(int j=1;j<11;j++){
	if(str1[i]==str3[j]){
	  vertical_share_pos1 = i;
	  horizontal_share_pos1 = j;
	  horizontal_used1=3;
	  one_step2();
	}
      }
      
      
      for(int j=1;j<11;j++){
	if(str1[i]==str4[j]){
	  vertical_share_pos1 = i;
	  horizontal_share_pos1 = j;
	  horizontal_used1=4;
	  one_step2();
	}
      }
      
    }

  
}

void two_first(){

    for(int i=1;i<11;i++){

      for(int j=1;j<11;j++){
	if(str2[i]==str1[j]){
	  vertical_share_pos1 = i;
	  horizontal_share_pos1 = j;
	  horizontal_used1=1;
	  two_step2();
	}
      }     
      
      
      for(int j=1;j<11;j++){
	if(str2[i]==str3[j]){
	  vertical_share_pos1 = i;
	  horizontal_share_pos1 = j;
	  horizontal_used1=3;
	  two_step2();
	}
      }
      
      
      for(int j=1;j<11;j++){
	if(str2[i]==str4[j]){
	  vertical_share_pos1 = i;
	  horizontal_share_pos1 = j;
	  horizontal_used1=4;
	  two_step2();
	}
      }
      
    }

  
}

void three_first(){

    for(int i=1;i<11;i++){

      for(int j=1;j<11;j++){
	if(str3[i]==str1[j]){
	  vertical_share_pos1 = i;
	  horizontal_share_pos1 = j;
	  horizontal_used1=1;
	  three_step2();
	}
      }     
      
      
      for(int j=1;j<11;j++){
	if(str3[i]==str2[j]){
	  vertical_share_pos1 = i;
	  horizontal_share_pos1 = j;
	  horizontal_used1=2;
	  three_step2();
	}
      }
      
      
      for(int j=1;j<11;j++){
	if(str3[i]==str4[j]){
	  vertical_share_pos1 = i;
	  horizontal_share_pos1 = j;
	  horizontal_used1=4;
	  three_step2();
	}
      }
      
    }

  
}

void four_first(){

    for(int i=1;i<11;i++){

      for(int j=1;j<11;j++){
	if(str4[i]==str1[j]){
	  vertical_share_pos1 = i;
	  horizontal_share_pos1 = j;
	  horizontal_used1=1;
	  four_step2();
	}
      }     
      
      
      for(int j=1;j<11;j++){
	if(str4[i]==str2[j]){
	  vertical_share_pos1 = i;
	  horizontal_share_pos1 = j;
	  horizontal_used1=2;
	  four_step2();
	}
      }
      
      
      for(int j=1;j<11;j++){
	if(str4[i]==str3[j]){
	  vertical_share_pos1 = i;
	  horizontal_share_pos1 = j;
	  horizontal_used1=3;
	  four_step2();
	}
      }
      
    }

  
}

class Solver{
  
 public:

  bool read(){

    cin >> str1;
    if(strcmp(str1,"Q")==0) return false;

    cin >> str2 >> str3 >> str4 ;
    
    return true;
  }

  void work(){
    
    max = 0;

    one_first();
    two_first();
    three_first();
    four_first();

    cout << max << endl;

  }


};

main(){

  Solver solver;

  while(true){
    if(solver.read()==false) break;
    solver.work();
  }

}
