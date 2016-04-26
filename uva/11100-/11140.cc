#include<iostream>
#include<algorithm>
#define PIECE 15
#define BUF 55
using namespace std;

int row, col, nPiece, pr[PIECE], pc[PIECE];
bool b[BUF][BUF], piece[PIECE][BUF][BUF];

void reconstruct(bool p[][BUF], int &pr, int &pc){
  int minR = BUF, maxR = -BUF, minC = BUF, maxC = -BUF;
  for(int i=0;i<pr;i++)
    for(int j=0;j<pc;j++){
      if(!p[i][j]) continue;
      minR = min(minR,i);
      maxR = max(maxR,i);
      minC = min(minC,j);
      maxC = max(maxC,j);
    }
  
  for(int r=0,rr=minR;rr<=maxR;r++,rr++)
    for(int c=0,cc=minC;cc<=maxC;c++,cc++)
      p[r][c] = p[rr][cc];

  pr = maxR-minR+1;
  pc = maxC-minC+1;
}

void read(){
  cin >> row >> col >> nPiece;

  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      char c;
      cin >> c;
      b[i][j] = (c!='*');
    }
  }

  for(int i=0;i<nPiece;i++){
    cin >> pr[i] >> pc[i];
    for(int j=0;j<pr[i];j++)
      for(int k=0;k<pc[i];k++){
	char c;
	cin >> c;
	piece[i][j][k] = (c=='*');
      }
    
    reconstruct(piece[i],pr[i],pc[i]);
  }
}

void work(){
  for(int q=0;q<nPiece;q++){
    bool putAble = false;
    for(int r=0;r<=row-pr[q];r++){
      for(int c=0;c<=col-pc[q];c++){
	bool ok = true;
	for(int rr=0;rr<pr[q];rr++)
	  for(int cc=0;cc<pc[q];cc++)
	    if(b[r+rr][c+cc] && piece[q][rr][cc])
	      ok = false;
	
	if(ok){
	  putAble = true;
	  goto finish;
	}
      }
    }
  finish:
    if(putAble) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
    cout << endl;
  }
  
  return 0;
}
