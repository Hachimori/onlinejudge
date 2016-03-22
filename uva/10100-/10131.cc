#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1005

class Element{
 public:

  int score;
  int num;
  int prev;
  int weight;
  int IQ;
  
  Element(){}
  Element(int num, int weight, int IQ) : num(num), weight(weight), IQ(IQ) {}

  bool operator< (const Element &e) const{
    if(weight < e.weight) return true;
    else if(weight == e.weight && IQ > e.IQ) return true;
    else return false;
  }

};

bool isValid(Element elephants[MAX], int i, int j, int maxScore){
  if(elephants[i].weight>elephants[j].weight && 
     elephants[i].IQ<elephants[j].IQ  &&
     maxScore<elephants[j].score+1 ) return true;
  return false;
}

int numEle;

void read(Element elephants[MAX]){

  for(numEle=0;;numEle++){
    int IQ, weight;
    
    if(!(cin >> weight >> IQ)) return ;
    
    elephants[numEle] = Element(numEle,weight,IQ);

  }

}

void work(Element elephants[MAX]){
  
  sort(&elephants[0],&elephants[numEle]);
  
  /*
    for(int i=0;i<numEle;i++){
    cout << elephants[i].weight << ' ' << elephants[i].IQ << endl;
    }
    */
  
  elephants[0].score = 1;
  elephants[0].prev = -1;

  for(int i=1;i<numEle;i++){
    
    int maxScore=1;
    for(int j=i-1;j>=0;j--){
      if( isValid(elephants,i,j,maxScore) ){
	maxScore = elephants[j].score+1;
	elephants[i].prev = j;
      }
    }
    elephants[i].score = maxScore;

  }


  int maxAns=0;
  int maxPos;
  for(int i=0;i<numEle;i++)
    if(maxAns<elephants[i].score){
      maxAns = elephants[i].score;
      maxPos = i;
    }


  vector<int> posList;
  for(int p=maxPos;elephants[p].prev!=-1;p=elephants[p].prev)
    posList.push_back(elephants[p].num);
  

  vector<int>::reverse_iterator i_ret;
  
  cout << posList.size() << endl;
  for(i_ret=posList.rbegin();i_ret!=posList.rend();i_ret++)
    cout << *i_ret+1 << endl;

}

int main(){

  Element elephants[MAX];

  read(elephants);
  work(elephants);

  return 0;
}

