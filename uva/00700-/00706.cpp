#include<iostream>
#include<string>

#define EoF -1
#define CONTINUE 1
#define MAX 23

int Input_Output(void);

main()
{
	while(1){
	  if(Input_Output()==EoF) break;
	  cout << endl;
	}
}

int Input_Output(void){

  int n;
  
  string s,disp[MAX];
  
  cin >> n >> s;
  if(n==0 && s=="0") return EoF;

  for(int k=0;k<s.size();k++){
    for(int i=0;i<2*n+3;i++){

      if(k!=0) disp[i]+=' ';

      if(i==0 && (s[k]=='1' || s[k]=='4')){
	for(int j=0;j<n+2;j++) disp[i]+=' ';
      }
      else if(i==0){
	disp[i]+=' ';
	for(int j=0;j<n;j++) disp[i]+='-';
	disp[i]+=' ';
      }
      else if(i==n+1 && (s[k]=='1' || s[k]=='7' || s[k]=='0')){
	for(int j=0;j<n+2;j++) disp[i]+=' ';
      }
      else if(i==n+1){
	disp[i]+=' ';
	for(int j=0;j<n;j++) disp[i]+='-';
	disp[i]+=' ';
      }
      else if(i==2*n+2 && (s[k]=='1'||s[k]=='4'||s[k]=='7')){
	for(int j=0;j<n+2;j++) disp[i]+=' ';
      }
      else if(i==2*n+2){
	disp[i]+=' ';
	for(int j=0;j<n;j++) disp[i]+='-';
	disp[i]+=' '; 
      }
      else if(i>0 && i<n+1 && (s[k]=='5'||s[k]=='6')){
	disp[i]+='|';
	for(int j=0;j<n+1;j++) disp[i]+=' ';
      }
      else if(i>0 && i<n+1 && (s[k]=='3'||s[k]=='1'||s[k]=='2'||s[k]=='7')){
	for(int j=0;j<n+1;j++) disp[i]+=' ';
	disp[i]+='|';
      }      
      else if(i>0 && i<n+1){
	disp[i]+='|';
	for(int j=0;j<n;j++) disp[i]+=' ';
	disp[i]+='|';
      }
      else if(s[k]=='2'){
	disp[i]+='|';
	for(int j=0;j<n+1;j++) disp[i]+=' ';
      }
      else if(s[k]=='6'||s[k]=='0'||s[k]=='8'){
	disp[i]+='|';
	for(int j=0;j<n;j++) disp[i]+=' ';
	disp[i]+='|';
      }
      else{
	for(int j=0;j<n+1;j++) disp[i]+=' ';
	disp[i]+='|';
      }
    }
  }

  for(int i=0;i<n*2+3;i++){
    cout << disp[i] << endl;
  }

  return CONTINUE;

}
