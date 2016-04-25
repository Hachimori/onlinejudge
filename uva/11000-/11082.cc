#include<iostream>
#include<algorithm>
#define BUF 25
using namespace std;

int row, col;
int rsum[BUF], csum[BUF];

void read(){
  cin >> row >> col;
  
  for(int i=0;i<row;i++) cin >> rsum[i];
  for(int i=0;i<col;i++) cin >> csum[i];

  for(int i=row-1;i>=1;i--) rsum[i] -= rsum[i-1];
  for(int i=col-1;i>=1;i--) csum[i] -= csum[i-1];
}

void work(int cases){
  int A[BUF][BUF];

  while(true){
  _fail:
    int rs[BUF], cs[BUF];
    for(int r=0;r<row;r++) rs[r] = rsum[r];
    for(int c=0;c<col;c++) cs[c] = csum[c];

    for(int r=0;r<row;r++)
      for(int c=0;c<col;c++){
        int lb = max( 1,max(cs[c]-(row-r-1)*20,rs[r]-(col-c-1)*20));
        int ub = min(20,min(cs[c]-(row-r-1)   ,rs[r]-(col-c-1)   ));
        if(lb>ub) goto _fail;
        
        int num = rand()%(ub-lb+1)+lb;
        A[r][c] = num;
        rs[r] -= num;
        cs[c] -= num;
      }

    for(int r=0;r<row;r++) if(rs[r]!=0) goto _fail;
    for(int c=0;c<col;c++) if(cs[c]!=0) goto _fail;
    break;
  }
  
      
  cout << "Matrix " << cases << endl;
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      if(j) cout << ' ';
      cout << A[i][j];
    }
    cout << endl;
  }
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
    cout << endl;
  }
  
  return 0;
}
