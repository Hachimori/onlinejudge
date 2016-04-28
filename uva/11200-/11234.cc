#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
public:
  char ch;
  int depth;
  Node *l, *r;

  Node(){}
  Node(char c){
    ch = c;
    l = NULL;
    r = NULL;
  }
  Node(char c, Node *L, Node *R){
    ch = c;
    l = L;
    r = R;
  }
  
  void trav(int d, vector<Node> &order){
    if(l!=NULL){
      r->trav(d+1,order);
      l->trav(d+1,order);
    }
    depth = d;
    order.push_back(*this);
  }
  
  bool operator< (const Node &n) const {
    return depth>n.depth;
  }

  void operator~ () {
    if(l!=NULL){
      delete l;
      delete r;
    }
  }
};

string str;

void read(){
  cin >> str;
}

void work(){
  stack<Node*> S;
  
  for(int i=0;i<str.size();i++){
    if(islower(str[i])){
      S.push(new Node(str[i]));
    }
    else{
      Node *a = S.top(); S.pop();
      Node *b = S.top(); S.pop();

      Node *ope = new Node(str[i],b,a);
      S.push(ope);
    }
  }

  Node *root = S.top(); S.pop();

  vector<Node> order;
  root->trav(0,order);

  stable_sort(order.begin(),order.end());
  
  for(int i=0;i<order.size();i++)
    cout << order[i].ch;
  cout << endl;

  delete root;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
