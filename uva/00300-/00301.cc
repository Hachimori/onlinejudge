#include<iostream>
#include<algorithm>

#define MAX_SIZE 10
#define MAX_ORDER 30

using namespace std;

class Order{
public:
  
  int start, end, score;
  
  Order(){}
  Order(int s, int e, int sc): start(s), end(e), score(sc){}

  bool operator< (const Order &o) const {
    if(start<o.start) return true;
    else if(start==o.start){
      
      if(end<o.end) return true;
      else if(end==o.end){
	
	return score>o.score;
	
      }
      
    }
    
    return false;
  }
};

int capacity, nNode, nOrder;
Order orderList[MAX_ORDER];

bool read(){
  
  cin >> capacity >> nNode >> nOrder;
  if(capacity==0 && nNode==0 && nOrder==0) return false;
  
  for(int i=0;i<nOrder;i++)
    cin >> orderList[i].start >> orderList[i].end >> orderList[i].score;
  
  return true;
}

void rec(int curr, int currScore, int nPeople[MAX_SIZE], int &maxScore){
    
  if(curr==nOrder){ 
    maxScore = max(maxScore,currScore);
    return;
  }
  
  bool succeed=true;
  
  for(int i=orderList[curr].start+1;i<=orderList[curr].end;i++){
    nPeople[i]+=orderList[curr].score;
    
    if(nPeople[i]>capacity)
      succeed=false;
  }
  
  if(succeed){
    rec(curr+1,currScore+(orderList[curr].end-orderList[curr].start)*orderList[curr].score,
	nPeople,maxScore);
  }
  
  for(int i=orderList[curr].start+1;i<=orderList[curr].end;i++)
    nPeople[i]-=orderList[curr].score;
    
  rec(curr+1,currScore,nPeople,maxScore);
}


void work(){
  
  int nPeople[MAX_SIZE];
  int maxScore=0;
  
  for(int i=0;i<=nNode;i++)
    nPeople[i] = 0;
  
  sort(orderList,orderList+nOrder);
  
  rec(0,0,nPeople,maxScore);
  
  cout << maxScore << endl;
}

int main(){
  
  while(read())
    work();
  
  return 0;

}

