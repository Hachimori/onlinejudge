//673

#include<iostream>
#include<string>

using namespace std;

string source;

void read(){

  getline(cin,source);

}    


void work(){

  for(int i=0;i<(int)source.length();i++){
    if(i<0) i=0;
    if(source[i]==' '){
      source.erase(i,1);
      i--;
      continue;
    }
    
    if(i+1<source.length() &&
       source[i]=='(' && source[i+1]==')'){
      source.erase(i,1);
      source.erase(i,1);
      i-=2;
      continue;
    }

    else if(i+1<source.length() &&
	  source[i]=='[' && source[i+1]==']'){
      source.erase(i,1);
      source.erase(i,1);
      i-=2;
      continue;
    }
  }

  if(source.length()==0) cout << "Yes" << endl;
  else cout << "No" << endl;

}

int main(){
  
  int cases;
  cin >> cases; getline(cin,source);

  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
