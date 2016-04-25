#include<iostream>
using namespace std;

int szHole, szPipe, sz;

bool read(){
  cin >> szHole >> szPipe >> sz;
  return szHole!=0 || szPipe!=0 || sz!=0;  
}

void work(int cases){
  cout << "Case " << cases << ":" << endl;

  for(int i=0;i<sz;i++){
    for(int j=0;j<szPipe;j++){
      for(int k=0;k<sz*(szPipe+szHole)+szPipe;k++)
	cout << '*';
      cout << endl;
    }
    
    for(int j=0;j<szHole;j++){
      for(int k=0;k<sz;k++){
	for(int j=0;j<szPipe;j++)
	  cout << '*';
	for(int j=0;j<szHole;j++)
	  cout << '.';
      }
      for(int j=0;j<szPipe;j++)
	cout << '*';
      cout << endl;
    }
  }

  for(int j=0;j<szPipe;j++){
    for(int k=0;k<sz*(szPipe+szHole)+szPipe;k++)
      cout << '*';
    cout << endl;
  }
}

int main(){
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }

  return 0;
}
