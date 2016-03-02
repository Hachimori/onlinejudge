// LIS  O(n log k)
// k: ‘‰Á—ñ‚Ì’·‚³
// n: ”š‚ª‰½ŒÂ‚ ‚é‚©
// 481


#include<iostream>
#include<utility>
#include<set>
#include<vector>
#include<algorithm>

#define BUF 100000

using namespace std;

class Node{
public:

  int val, id, prev;

  Node(){}
  Node(int v, int i, int p): val(v), id(i), prev(p) {}
  
  bool operator< (const Node &n) const {
    return val<n.val;
  }
};

int nNum;
int num[BUF];

void read(){
  nNum=0;
  while(cin >> num[nNum]) 
    nNum++;
}

void LIS(){
  int tail = 0;
  static Node node[BUF], seq[BUF];
  
  node[0] = seq[tail++] = Node(num[0],0,-1);
  
  for(int i=1;i<nNum;i++){
    Node toCmp = Node(num[i],0,0);
    int pos = lower_bound(seq,seq+tail,toCmp)-seq;
    
    if(pos==tail){
      node[i] = seq[tail] = Node(num[i],i,seq[tail-1].id);
      tail++;
    }
    else if(pos==0)
      node[i] = seq[0] = Node(num[i],i,-1);
    else
      node[i] = seq[pos] = Node(num[i],i,seq[pos-1].id);
  }  
  
  cout << tail << endl;
  cout << '-' << endl;
  
  vector<int> path;
  for(int i=seq[tail-1].id;i!=-1;i=node[i].prev)
    path.push_back(node[i].val);
  
  reverse(path.begin(),path.end());
  
  for(int i=0;i<path.size();i++)
    cout << path[i] << endl;
}

int main(){
  
  read();
  LIS();
  
  return 0;
}
