#include<stdio.h>
#include<string.h>
#include<math.h>

void Input_Search(void);
void Input_array(int,char,char []);
int Keisan(char [],char [],char []);

main()
{

  int i,n;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    
    Input_Search();

  }

}
    
void Input_Search(void){

  int i,k,length;
  char a[4],b[4],hugou[2],A[14],B[14]; 

  for(i=0;i<13;i++){ A[i]='0'; B[i]='0'; }

  scanf("%s%s%s",a,hugou,b);

  hugou[1]='\0'; a[3]='\0'; b[3]='\0'; A[13]='\0'; B[13]='\0'; 
  
  length = strlen(a);

  for(i=length-1,k=0;i>=0;k++,i--){
    Input_array(k,a[i],A);
  }

  length = strlen(b);

  for(i=length-1,k=0;i>=0;k++,i--){
    Input_array(k,b[i],B);
  }
  
  for(i=strlen(A)-1;i>=0;i--) printf("%c",A[i]);
  printf(" %s ",hugou);
  for(i=strlen(B)-1;i>=0;i--) printf("%c",B[i]);  
  printf(" = %d\n",Keisan(hugou,a,b));

  return;

}

void Input_array(int part, char num, char x[]){

  int i=part*4;

  if(num=='0') return;
  else if(num=='1'){
    x[i]='1';
    return;
  }
  else if(num=='2'){
    x[i+1]='1';
    return;
  }
  else if(num=='3'){
    x[i]='1';
    x[i+1]='1';
    return;
  }  
  else if(num=='4'){
    x[i+2]='1';
    return;
  }   
  else if(num=='5'){
    x[i]='1';
    x[i+2]='1';
    return;
  }  
  else if(num=='6'){
    x[i+1]='1';
    x[i+2]='1';
    return;
  } 
  else if(num=='7'){
    x[i]='1';
    x[i+1]='1';
    x[i+2]='1';
    return;
  }
  else if(num=='8'){
    x[i+3]='1';
    return;
  } 
  else if(num=='9'){
    x[i]='1';
    x[i+3]='1';
    return;
  } 
  else if(num=='A'){
    x[i+1]='1';
    x[i+3]='1';
    return;
  }
  else if(num=='B'){
    x[i]='1';
    x[i+1]='1';
    x[i+3]='1';
    return;
  }
  else if(num=='C'){
    x[i+2]='1';
    x[i+3]='1';
    return;
  }
  else if(num=='D'){
    x[i]='1';
    x[i+2]='1';
    x[i+3]='1';
    return;
  }
  else if(num=='E'){
    x[i+1]='1';
    x[i+2]='1';
    x[i+3]='1';
    return;
  }
  else if(num=='F'){
    x[i]='1';
    x[i+1]='1';
    x[i+2]='1';
    x[i+3]='1';
    return;
  }

}

int Keisan(char hugou[],char a[],char b[]){

  int i,sum=0,k;

  for(i=strlen(a)-1,k=0;i>=0;k++,i--){
    if(a[i]=='A'){
      sum+= pow(16,k)*10;
    }
    else if(a[i]=='B'){
      sum+= pow(16,k)*11;
    }
    else if(a[i]=='C'){
      sum+= pow(16,k)*12;
    }
    else if(a[i]=='D'){
      sum+= pow(16,k)*13;
    }
    else if(a[i]=='E'){
      sum+= pow(16,k)*14;
    }
    else if(a[i]=='F'){
      sum+= pow(16,k)*15;
    }
    else sum+= pow(16,k)*(a[i]-48);

  }
  
  if(strcmp(hugou,"+")==0)
    for(i=strlen(b)-1,k=0;i>=0;k++,i--){
      if(b[i]=='A'){
	sum+= pow(16,k)*10;
      }
      else if(b[i]=='B'){
	sum+= pow(16,k)*11;
      }
      else if(b[i]=='C'){
	sum+= pow(16,k)*12;
      }
      else if(b[i]=='D'){
	sum+= pow(16,k)*13;
      }
      else if(b[i]=='E'){
	sum+= pow(16,k)*14;
      }
      else if(b[i]=='F'){
	sum+= pow(16,k)*15;
      }
      else sum+= pow(16,k)*(b[i]-48);
      
    }
  if(strcmp(hugou,"-")==0)
    for(i=strlen(b)-1,k=0;i>=0;k++,i--){
      if(b[i]=='A'){
	sum-= pow(16,k)*10;
      }
      else if(b[i]=='B'){
	sum-= pow(16,k)*11;
      }
      else if(b[i]=='C'){
	sum-= pow(16,k)*12;
      }
      else if(b[i]=='D'){
	sum-= pow(16,k)*13;
      }
      else if(b[i]=='E'){
	sum-= pow(16,k)*14;
      }
      else if(b[i]=='F'){
	sum-= pow(16,k)*15;
      }
      else sum-= pow(16,k)*(b[i]-48);
      
    }
    
  return sum;

}
