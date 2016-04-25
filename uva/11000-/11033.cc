#include<iostream>
#include<vector>
#define VALID 100000
using namespace std;

int N, M, P;

bool read(){
  cin >> N >> M >> P;
  return (N|M|P)!=0;
}

void work(int cases){
  static int nValid, valid[VALID][2][4];
  static long long mul[VALID];
  vector<int> id[15][15][15][15];  // [rSum_0][rSum_1][rSum_2][rSum_3]
  
  nValid = 0;
  for(int i=1;i<=7;i++)
    for(int j=1;j<=7;j++)
      for(int k=1;k<=7;k++)
	for(int l=1;l<=7;l++)
	  if(i+j+k+l==N)
	    for(int ii=1;ii<=7;ii++)
	      for(int jj=1;jj<=7;jj++)
		for(int kk=1;kk<=7;kk++)
		  for(int ll=1;ll<=7;ll++){
		    int c1 =  N-i-ii, c2 = N-j-jj, c3 = N-k-kk, c4 = N-l-ll;
		    if(c1<2 || c1>14 || c2<2 || c2>14 || c3<2 || c3>14 || c4<2 || c4>14) continue;
		    if(ii+jj+kk+ll!=N) continue;
		    
		    valid[nValid][0][0]=i , valid[nValid][0][1]=j , valid[nValid][0][2]=k , valid[nValid][0][3]=l ;
		    valid[nValid][1][0]=ii, valid[nValid][1][1]=jj, valid[nValid][1][2]=kk, valid[nValid][1][3]=ll;
		    id[i+ii][j+jj][k+kk][l+ll].push_back(nValid);
		    mul[nValid] = i*ii*j*jj*k*kk*l*ll;
		    nValid++;
		  }

  
  int ans[2][4][4], cnt = 0;
  
  for(int n=0;n<nValid;n++){
    int  &i = valid[n][0][0],  &j = valid[n][0][1],  &k = valid[n][0][2],  &l = valid[n][0][3];
    int &ii = valid[n][1][0], &jj = valid[n][1][1], &kk = valid[n][1][2], &ll = valid[n][1][3];
    int c1 =  N-i-ii, c2 = N-j-jj, c3 = N-k-kk, c4 = N-l-ll;
    //if(c1<2 || c1>14 || c2<2 || c2>14 || c3<2 || c3>14 || c4<2 || c4>14) continue;
		    
    typedef vector<int>::iterator iter;
    for(iter m=id[c1][c2][c3][c4].begin();m!=id[c1][c2][c3][c4].end();m++){
      int &mId = *m;
      
      // diagonal chk
      if(i+jj+valid[mId][0][2]+valid[mId][1][3]!=N) continue;
      if(l+kk+valid[mId][0][1]+valid[mId][1][0]!=N) continue;
      
      // mod chk
      if((mul[n]*mul[mId])%M>P) continue;
      
      if(cnt<2){
	ans[cnt][0][0] = i , ans[cnt][0][1] = j , ans[cnt][0][2] = k , ans[cnt][0][3] = l ;
	ans[cnt][1][0] = ii, ans[cnt][1][1] = jj, ans[cnt][1][2] = kk, ans[cnt][1][3] = ll;
	for(int r=0;r<2;r++)
	  for(int c=0;c<4;c++)
	    ans[cnt][r+2][c] = valid[mId][r][c];
      }
      cnt++;
    }
  }
  cout << "Set " << cases << ":" << endl;
  cout << cnt << endl;
  for(int i=0;i<min(cnt,2);i++){
    for(int r=0;r<4;r++){
      for(int c=0;c<4;c++)
	cout << ans[i][r][c];
      cout << endl;
    }
    cout << "...." << endl;
  }
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
