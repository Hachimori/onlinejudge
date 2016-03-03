#include<iostream>
#include<queue>
#include<string>
#define A first
#define B second
using namespace std;
typedef pair<int,int> Data;
const int BUF = 1005;

enum Ope{FILL_A,FILL_B,EMPTY_A,EMPTY_B,POUR_A_B,POUR_B_A};

class PiData{
public:
  Data pre;
  int ope;
  PiData(){}
  PiData(Data p, int o): pre(p), ope(o){}
};


int capA, capB, goal;

bool read(){
  return cin >> capA >> capB >> goal;
}


void update(int nexA, int nexB, int ope, Data cur, PiData pi[BUF][BUF], queue<Data> &Q){
  pi[nexA][nexB] = PiData(cur,ope);
  Q.push(Data(nexA,nexB));
}


void work(){
  Data last;
  queue<Data> Q;
  static PiData pi[BUF][BUF];

  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++) 
      pi[i][j] = PiData(Data(-1,-1),-1);
  pi[0][0] = PiData(Data(-2,-2),-2);
  Q.push(Data(0,0));

  while(!Q.empty()){
    Data cur = Q.front();
    Q.pop();
    if(cur.B==goal){
      last = cur;
      break;
    }
    if(pi[capA][cur.B].ope==-1) update(capA,cur.B,FILL_A,cur,pi,Q);
    if(pi[cur.A][capB].ope==-1) update(cur.A,capB,FILL_B,cur,pi,Q);
    if(pi[0][cur.B].ope==-1) update(0,cur.B,EMPTY_A,cur,pi,Q);
    if(pi[cur.A][0].ope==-1) update(cur.A,0,EMPTY_B,cur,pi,Q);
    int nexA, nexB;
    nexB = min(capB,cur.B+cur.A);
    nexA = cur.A-(nexB-cur.B);
    if(pi[nexA][nexB].ope==-1) update(nexA,nexB,POUR_A_B,cur,pi,Q);
    nexA = min(capA,cur.A+cur.B);
    nexB = cur.B-(nexA-cur.A);
    if(pi[nexA][nexB].ope==-1) update(nexA,nexB,POUR_B_A,cur,pi,Q);
  }

  vector<string> ans;
  while(1){
    PiData piLast = pi[last.A][last.B];
    if(piLast.ope==-2) break;
    switch(piLast.ope){
    case FILL_A: ans.push_back("fill A"); break;
    case FILL_B: ans.push_back("fill B"); break;
    case EMPTY_A: ans.push_back("empty A"); break;
    case EMPTY_B: ans.push_back("empty B"); break;
    case POUR_A_B: ans.push_back("pour A B"); break;
    case POUR_B_A: ans.push_back("pour B A"); break;
    }
    last = piLast.pre;
  }

  for(int i=ans.size()-1;i>=0;i--)
    cout << ans[i] << endl;
  cout << "success" << endl;
}


int main(){
  while(read()) work();
  return 0;
}
