#include<iostream>
using namespace std;
const int BUF = 105;

int n;
double x[BUF], p[BUF];

void read(){
  cin >> n;
  for(int i=0;i<n;i++)
    cin >> x[i] >> p[i];
}

void work(int cases){
  double nume = 0, deno = 1;
  for(int i=0;i<n;i++){
    if(x[i]<0){
      deno -=  p[i];
      nume += -x[i]*p[i];
    }
    else
      nume +=  x[i]*p[i];
  }
  cout << "Case " << cases << ": ";
  if(deno<=0)
    cout << "God! Save me" << endl;
  else
    printf("%.2lf\n",nume/deno);
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
