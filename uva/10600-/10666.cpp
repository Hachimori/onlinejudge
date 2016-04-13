#include<iostream>

void Input_Output(void);
	
main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++) Input_Output();
}

void Input_Output(void){
  
  int N,X;
  int win=0,lose=0;

  cin >> N >> X;

  if(X!=0)
    for(int k=0;k<N;X=X/2,k++){
      if(X%2==0 && lose==0){
	win += (1<<k);
      }
      else if(X%2==1){
	lose++;
	X--;
      }
    }
  else {
    cout << "1 1"<< endl; 
    return;
  }
  
  cout << lose+1 << ' ' << (1<<N)-win << endl;
  return;
}
