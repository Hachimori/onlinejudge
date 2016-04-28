#include<iostream>
#include<algorithm>
#define DATA 10000
#define EPS (1.0e-8)
#define LE(x,y) ((x)<=(y)+EPS)
#define LT(x,y) ((x)<=(y)-EPS)
using namespace std;

int nData, data[DATA][2];

bool read(){
  cin >> nData;
  if(nData==0) return false;
  
  for(int i=0;i<nData;i++){
    cin >> data[i][0] >> data[i][1];
    if(data[i][0]>data[i][1]) swap(data[i][0],data[i][1]);
  }

  return true;
}

void work(){
  double maxV = -1;
  int ans;

  for(int i=0;i<nData;i++){
    double a = data[i][0], b = data[i][1], score = 0;
    if(LE(a*4  ,b)) score = max(score,a  );
    if(LE(a/2*2,b)) score = max(score,a/2);
    if(LE(a/3*2,b)) score = max(score,a/3);
    
    if(LE(b/3*2,a)) score = max(score,b/3);
    if(LE(b/4  ,a)) score = max(score,b/4);
    
    if(LT(maxV,score)){
      maxV = score;
      ans = i;
    }
  }

  cout << ans+1 << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
