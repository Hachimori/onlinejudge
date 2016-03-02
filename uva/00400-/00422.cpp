#include<iostream>
#include<stdio.h>
#include<string>

#define WALL -1
#define MAX 103

int length;
char matrix[MAX][MAX];
string word;

bool search_hor(int y, int x){

  int i,j,k;
  bool flg=true;


  for(i=y,j=x,k=0;k<word.length();j++,k++){
    if(matrix[i][j]==WALL || matrix[i][j]!=word[k]){
      flg=false;
      break;
    }
  }
  
  if(flg==false) flg=true;
  else{
    cout << y << ',' << x << ' ' << i << ',' << j-1 << endl;
    return true;
  }


  for(i=y,j=x,k=0;k<word.length();j--,k++){
    if(matrix[i][j]==WALL || matrix[i][j]!=word[k]){
      flg=false;
      break;
    }
  }
  
  if(flg==false) flg=true;
  else{
    cout << y << ',' << x << ' ' << i << ',' << j+1 << endl;
    return true;
  }


  return false;

}

bool search_ver(int y, int x){

  int i,j,k;
  bool flg=true;

  for(i=y,j=x,k=0;k<word.length();i++,k++){
    if(matrix[i][j]==WALL || matrix[i][j]!=word[k]){
      flg=false;
      break;
    }
  }
  
  if(flg==false) flg=true;
  else{
    cout << y << ',' << x << ' ' << i-1 << ',' << j << endl;
    return true;
  }

  return false;

}

bool search_diag(int y, int x){
  
  int i,j,k;
  bool flg=true;

  for(i=y,j=x,k=0;k<word.length();i++,j++,k++){
    if(matrix[i][j]==WALL || matrix[i][j]!=word[k]){
      flg=false;
      break;
    }
  }
  
  if(flg==false) flg=true;
  else{
    cout << y << ',' << x << ' ' << i-1 << ',' << j-1 << endl;
    return true;
  }


  for(i=y,j=x,k=0;k<word.length();i--,j++,k++){
    if(matrix[i][j]==WALL || matrix[i][j]!=word[k]){
      flg=false;
      break;
    }
  }
  
  if(flg==false) flg=true;
  else{
    cout << y << ',' << x << ' ' << i+1 << ',' << j-1 << endl;
    return true;
  }

  
  for(i=y,j=x,k=0;k<word.length();i++,j--,k++){
    if(matrix[i][j]==WALL || matrix[i][j]!=word[k]){
      flg=false;
      break;
    }
  }
  
  if(flg==false) flg=true;
  else{
    cout << y << ',' << x << ' ' << i-1 << ',' << j+1 << endl;
    return true;
  }


  for(i=y,j=x,k=0;k<word.length();i--,j--,k++){
    if(matrix[i][j]==WALL || matrix[i][j]!=word[k]){
      flg=false;
      break;
    }
  }
  
  if(flg==false) flg=true;
  else{
    cout << y << ',' << x << ' ' << i+1 << ',' << j+1 << endl;
    return true;
  }

  return false;

}

class Solver{
 public:

  void read_matrix(){
    
    cin >> length;

    for(int i=0;i<length+2;i++){
      for(int j=0;j<length+2;j++){
	matrix[i][j]=WALL;
      }
    }

    char c;

    for(int i=1;i<length+1;i++){
      for(int j=1;j<length+1;j++){
	scanf("%c",&c);
	if(c>='A' && c<='Z') matrix[i][j] = c;
	else{
	  j--;
	  continue;
	}
      }
    }

  }

  bool read(){

    cin >> word;
    if(word.compare("0")==0) return false;

    return true;

  }

  void work(){

    for(int i=1;i<length+1;i++){
      for(int j=1;j<length+1;j++){
	
	if(word[0]==matrix[i][j]){
	  
	  if(search_diag(i,j)==true) return;
	  else if(search_ver(i,j)==true) return;
	  else if(search_hor(i,j)==true) return;

	}
	
      }
    }

    cout << "Not found" << endl;
    return;
  }


};

main(){

  Solver solver;

  solver.read_matrix();

  while(true){

    if(solver.read()==false) break;
    solver.work();

  }

}
