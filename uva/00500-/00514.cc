#include<iostream>
#include<stack>
#include<queue>

#define MAX_TRAIN 1001

using namespace std;

int nTrain;

bool read(){

  cin >> nTrain;
  if(nTrain==0) return false;

  return true;
}

void work(){

  while(true){
    
    stack<int> rStack, mStack;
    int target[MAX_TRAIN];

    for(int i=nTrain;i>=0;i--)
      rStack.push(i+1);

    for(int i=0;i<nTrain;i++){
      cin >> target[i];
      if(target[0]==0) return;
    }

    int curr;
    for(curr=0;curr<nTrain;){
      if(rStack.size()==0) break;
      if(mStack.size()==0 || mStack.top()!=target[curr]){
	mStack.push(rStack.top());
	rStack.pop();
      }
      else if(mStack.top()==target[curr]){
	mStack.pop();
	curr++;
      }

    }
    if(curr==nTrain) cout << "Yes" << endl;
    else cout << "No" << endl;

  }

}

int main(){
  
  while(read()){
    work();
    cout << endl;
  }

  return 0;
}
