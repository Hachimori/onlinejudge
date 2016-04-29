#include<iostream>
#include<queue>
using namespace std;
const int BUF = 1000005;

class Data{
public:
  int isZero, remain;
  Data(){}
  Data(int i, int r): isZero(i), remain(r){}

  bool notVisited(){
    return isZero==-1;
  }
};

int mod;

bool read(){
  return cin >> mod;
}

void work(){
  static Data pi[2][BUF];
  queue<Data> Q;

  for(int i=0;i<2;i++)
    for(int j=0;j<mod;j++)
      pi[i][j] = Data(-1,-1);

  pi[0][3%mod] = Data(-2,-2);
  Q.push(Data(0,3%mod));

  while(!Q.empty()){
    Data cur = Q.front();
    Q.pop();

    static int toAdd[] = {3,0};
    if(cur.remain==0){
      int len = 0, cnt[2] = {};
      while(cur.isZero>=0){
        cnt[cur.isZero]++;
        len++;
        cur = pi[cur.isZero][cur.remain];
      }
      cout << len << ' ' << cnt[0] << ' ' << cnt[1] << endl;
      break;
    }

    for(int i=0;i<2;i++){
      if(toAdd[i]==3 && cur.isZero) continue;
      Data nex = Data(i,(cur.remain*10+toAdd[i])%mod);
      if(pi[nex.isZero][nex.remain].notVisited()){
        pi[nex.isZero][nex.remain] = cur;
        Q.push(nex);
      }
    }
  }
}

int main(){
  while(read()) work();
  return 0;
}
