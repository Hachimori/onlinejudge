#include<iostream>
#include<vector>
using namespace std;

int sz;
vector< vector<int> > coeffL, coeffR, matrixR, boundary;

void read(){
  cin >> sz;

  coeffL = coeffR = vector< vector<int> >(3,vector<int>(3));
  matrixR = vector< vector<int> >(sz+1,vector<int>(sz+1));
  boundary = vector< vector<int> >(4,vector<int>(sz+1));

  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      cin >> coeffL[i][j];

  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      cin >> coeffR[i][j];
  
  for(int i=0;i<4;i++)
    for(int j=0;j<sz+1;j++)
      cin >> boundary[i][j];

  for(int i=0;i<sz+1;i++)
    for(int j=0;j<sz+1;j++)
      cin >> matrixR[i][j];
}

void work(){
  vector< vector<int> > matrixL = vector< vector<int> >(sz+1,vector<int>(sz+1));
  // boundary value
  for(int i=0;i<boundary[0].size();i++) matrixL[  sz][ i] = boundary[0][i];
  for(int i=0;i<boundary[1].size();i++) matrixL[   0][ i] = boundary[1][i];
  for(int i=0;i<boundary[2].size();i++) matrixL[sz-i][ 0] = boundary[2][i];
  for(int i=0;i<boundary[3].size();i++) matrixL[sz-i][sz] = boundary[3][i];


  // id of unknown value
  for(int r=1,id=0;r<sz;r++)
    for(int c=1;c<sz;c++)
      matrixL[r][c] = id++;

  vector< vector<int> > ansMat = vector< vector<int> >((sz-1)*(sz-1),vector<int>((sz-1)*(sz-1)));
  vector<int> ansVec = vector<int>((sz-1)*(sz-1));
  for(int r=1,ansIdx=0;r<sz;r++)
    for(int c=1;c<sz;c++,ansIdx++){
      for(int dr=-1;dr<=1;dr++)
        for(int dc=-1;dc<=1;dc++){
          int rr = r+dr, cc = c+dc;
          if(rr==0 || rr==sz || cc==0 || cc==sz)
            ansVec[ansIdx] -= coeffL[dr+1][dc+1]*matrixL[rr][cc]*sz*sz;
          else
            ansMat[ansIdx][matrixL[rr][cc]] += coeffL[dr+1][dc+1]*sz*sz;
          ansVec[ansIdx] += coeffR[dr+1][dc+1]*matrixR[rr][cc];
        }
    }

  for(int i=0;i<ansMat.size();i++){
    for(int j=0;j<ansMat.size();j++){
      if(j) cout << ' ';
      cout << ansMat[i][j];
    }
    cout << endl;
  }
  for(int i=0;i<ansVec.size();i++){
    if(i) cout << ' ';
    cout << ansVec[i];
  }cout << endl;
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
