// DP
//
// 
// depod$B$r:8$+$iCV$$$F$$$/!#(B
// depod$B$rCV$$$?$H$-$KDI2C$5$l$k%3%9%H$,7h$^$k$,!"(B
// $BDI2C$5$l$k%3%9%H$O!"?7$?$KCV$$$?(Bdepod$B$H$=$l$h$j0l$DA0$KCV$$$?(Bdepod$B$N4V$N(B
// $B%l%9%H%i%s$N5wN%$K1~$8$F$-$^$k!#(B
//
// $B$D$^$j!"$3$l$+$iCV$/(Bdepod$B$K$h$C$F7h$^$k%3%9%H$O(B
// $BD>A0$KCV$$$?(Bdepod$B$h$jA0$N(Bdepod$B$NCV$-J}$K0MB8$7$J$$!#(B
// 
// $B$J$N$G!":G8e$KCV$$$?(Bdepod$B$N0LCV$H$=$N$H$-$N%3%9%H$rJ]B8$9$k%F!<%V%k$r(B
// $B:n@.$7!"?7$?$K(Bdepod$B$rCV$/:]$K!":G>.$N%3%9%H$rF@$i$l$kD>A0$KCV$$$?(Bdepod$B$N0LCV$r(B
// $BA*$s$G%F!<%V%k$N99?7$r$7$F$$$/!#(B

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

// mid[i][j]:      i, j$B$N0LCV$K(Bdepot$B$,$"$k$H$-!"(Bj$B$N(Bdepot$B$r;H$&%l%9%H%i%s$N:G>.$N(Bid
// sum[i][j]:      i$B$N0LCV$K$"$k(Bdepot$B$r!"(Bi$B$+$i(Bj$B$N%l%9%H%i%s$,;H$&$H$-$N%3%9%H(B
// adjList[i][j]:  i$B$N0LCV$K$"$k(Bdepot$B$r!"(Bj$B$N%l%9%H%i%s$,;H$&$H$-$N%3%9%H(B
// table[i][j][k]: i$B8DL\$N(Bdepot$B$r(Bj$B$KCV$$$?$H$-!"(B k$B$N%l%9%H%i%s$,;H$&%3%9%H(B
// cost[i][j]:     i$B8DL\$N(Bdepot$B$r(Bj$B$KCV$$$?$H$-!"(B 0$B$+$i(Bj$B$N%l%9%H%i%s$,;H$&%3%9%H$N9g7W(B
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
