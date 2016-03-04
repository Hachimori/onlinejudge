// DP
//
// 
// depodを左から置いていく。
// depodを置いたときに追加されるコストが決まるが、
// 追加されるコストは、新たに置いたdepodとそれより一つ前に置いたdepodの間の
// レストランの距離に応じてきまる。
//
// つまり、これから置くdepodによって決まるコストは
// 直前に置いたdepodより前のdepodの置き方に依存しない。
// 
// なので、最後に置いたdepodの位置とそのときのコストを保存するテーブルを
// 作成し、新たにdepodを置く際に、最小のコストを得られる直前に置いたdepodの位置を
// 選んでテーブルの更新をしていく。

#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>

#define INF 200000000
#define MAX_SIZE 205
#define MAX_DEPOT 35

using namespace std;

int nPoint, toPut;
int point[MAX_SIZE];


bool read(){
  cin >> nPoint >> toPut;
  if(nPoint==0 && toPut==0) return false;
  
  for(int i=0;i<nPoint;i++)
    cin >> point[i];
  
  return true;
}

// mid[i][j]:      i, jの位置にdepotがあるとき、jのdepotを使うレストランの最小のid
// sum[i][j]:      iの位置にあるdepotを、iからjのレストランが使うときのコスト
// adjList[i][j]:  iの位置にあるdepotを、jのレストランが使うときのコスト
// table[i][j][k]: i個目のdepotをjに置いたとき、 kのレストランが使うコスト
// cost[i][j]:     i個目のdepotをjに置いたとき、 0からjのレストランが使うコストの合計
void work(int cases){
  int adjList[MAX_SIZE][MAX_SIZE];
  int table[MAX_DEPOT][MAX_SIZE][MAX_SIZE];
  int mid[MAX_SIZE][MAX_SIZE], sum[MAX_SIZE][MAX_SIZE];
  int cost[MAX_DEPOT][MAX_SIZE];

  for(int i=0;i<toPut;i++)
    for(int j=0;j<nPoint;j++)
      for(int k=0;k<nPoint;k++)
	table[i][j][k] = INF;
  
  for(int i=0;i<nPoint;i++)
    for(int j=0;j<nPoint;j++)
      adjList[i][j] = abs(point[i]-point[j]);
  
  for(int i=0;i<nPoint;i++){
    sum[i][i] = 0;

    for(int j=i+1;j<nPoint;j++)
      sum[i][j] = sum[i][j-1] + adjList[i][j];

    for(int j=i-1;j>=0;j--)
      sum[i][j] = sum[i][j+1] + adjList[i][j];
  }

  
  for(int i=0;i<nPoint;i++)
    for(int j=0;j<nPoint;j++){
      if(i+1>j){
	mid[i][j] = -INF;
	continue;
      }
      
      int pos = j-1;
      while(pos>i && adjList[i][pos]>adjList[pos][j])
	pos--;
      
      mid[i][j] = pos+1;
    }
  
  for(int i=0;i<nPoint;i++)
    for(int j=0;j<nPoint;j++){
      table[0][i][j] = adjList[i][j];
      cost[0][j] = sum[j][0];
    }

  for(int i=1;i<toPut;i++){
    for(int currPut=i;currPut<nPoint;currPut++){
      int minVal = INF, bestPrev;
    
      for(int prevPut=0;prevPut<currPut;prevPut++){
	int middle = mid[prevPut][currPut];
	
	if(minVal>cost[i-1][prevPut]+sum[prevPut][middle-1]+sum[currPut][middle]){
	  minVal = cost[i-1][prevPut]+sum[prevPut][middle-1]+sum[currPut][middle];
	  bestPrev = prevPut;
	}
      }

      int middle = mid[bestPrev][currPut];
      for(int j=0;j<nPoint;j++)
	if(j<middle) table[i][currPut][j] = table[i-1][bestPrev][j];
	else table[i][currPut][j] = table[i-1][currPut][j];
      cost[i][currPut] = minVal;
    }
  }
  
  
  int minVal = INF;
  vector<int> putPos;

  for(int i=0;i<nPoint;i++){
    int total = 0;
    vector<int> tmpPut;
    if(table[toPut-1][i][0]==INF) continue;
    
    for(int j=0;j<nPoint;j++){
      total += table[toPut-1][i][j];
      if(table[toPut-1][i][j]==0) tmpPut.push_back(j);
    }

    if(minVal>total){
      minVal = total;
      putPos = tmpPut;
    }
  }
  

  cout << "Chain " << cases << endl;
  if(toPut==1){
    if(nPoint==1)
      cout << "Depot 1 at restaurant 1 serves restaurant 1" << endl;
    else
      cout << "Depot 1 at restaurant " << putPos[0]+1 
	   << " serves restaurants 1 to " << nPoint << endl;

    cout << "Total distance sum = " << minVal << endl;
    return;
  }
  
  for(int i=0;i<toPut;i++){
    cout << "Depot " << i+1 << " at restaurant " << putPos[i]+1;

    if(i==0){
      if(putPos[i]==0 && putPos[i]==mid[putPos[i]][putPos[i+1]]-1) 
	cout << " serves restaurant 1" << endl;
      else
	cout << " serves restaurants 1 to " << mid[putPos[i]][putPos[i+1]] << endl;
    }
    else if(i==toPut-1){
      if(putPos[i]==nPoint-1 && putPos[i]==mid[putPos[i-1]][putPos[i]]) 
	cout << " serves restaurant " << nPoint << endl;
      else
	cout << " serves restaurants " << mid[putPos[i-1]][putPos[i]]+1
	     << " to " << nPoint << endl;
    }
    else {
      if(mid[putPos[i-1]][putPos[i]]==putPos[i] &&
	 putPos[i]==mid[putPos[i]][putPos[i+1]]-1)
	cout << " serves restaurant " << putPos[i]+1 << endl;
      else
	cout << " serves restaurants " << mid[putPos[i-1]][putPos[i]]+1
	     << " to " << mid[putPos[i]][putPos[i+1]] << endl;
    }
  }
  
  cout << "Total distance sum = " << minVal << endl;
}

int main(){
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }
  
  return 0;
}
