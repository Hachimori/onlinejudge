#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<cassert>
#define BUF 105
using namespace std;

void stableMarriage(int n, int rank2id[2][BUF][BUF], int id2rank[2][BUF][BUF],
                    string s[]){
  
  int cur[BUF], married[BUF];
  
  for(int i=0;i<BUF;i++){
    married[i] = -1;
    cur[i] = 0;
  }
  
  for(int i=0;i<n;i++){
    int self = i;
    
    while(cur[self]<n){
      int opp = rank2id[0][self][cur[self]];
      int rival = married[opp];
    
      if(rival==-1){
	married[opp] = self;
	break;
      }
      
      if(id2rank[1][opp][self]<id2rank[1][opp][rival]){
	married[opp] = self;
	cur[rival]++;
	self = rival;
      }
      else 
	cur[self]++;
    }

    if(cur[self]==n) assert(false); // impossible
  }

  for(int i=0;i<n;i++){
    if(i) cout << ' ';
    cout << s[married[i]].substr(0,2) << s[i].substr(2,2);
  }
  cout << endl << endl;
}

void work(string s[BUF], int n, int type2rank[2][BUF][BUF], int rank2type[2][BUF][BUF],
          map<string,int> n2type[2]){
  int type[2][BUF];
  
  for(int i=0;i<n;i++){
    string a = s[i].substr(0,2), b = s[i].substr(2,2);
    type[0][i] = n2type[0][a];
    type[1][i] = n2type[1][b];
  }

  int rank2id[2][BUF][BUF], id2rank[2][BUF][BUF];
  
  for(int bin=0;bin<2;bin++)
    for(int i=0;i<n;i++){
      int val[BUF], id[BUF];
      for(int j=0;j<n;j++){
        int a = type[bin][i], b = type[!bin][j];
        
        val[j] = type2rank[bin][a][b];
        id[j] = j;
      }

      for(int j=0;j<n;j++)
        for(int k=j+1;k<n;k++)
          if(val[j]>val[k]){
            swap(val[j],val[k]);
            swap(id[j],id[k]);
          }

      for(int j=0;j<n;j++){
        rank2id[bin][i][j] = id[j];
        id2rank[bin][i][id[j]] = val[j];
      }
    }

  stableMarriage(n,rank2id,id2rank,s);
}

int main(){
  for(int k=1;;k++){
    int nType[2], type2rank[2][BUF][BUF], rank2type[2][BUF][BUF];
    map<string,int> n2type[2];
    map<int,string> type2n[2];
    
    for(int i=0;i<2;i++){
      cin >> nType[i];
      if(nType[0]==0) return 0;
      
      for(int j=0;j<nType[i];j++){
        string s;
        cin >> s;
        
        int sz = n2type[i].size();
        n2type[i][s] = sz;
        type2n[i][sz] = s;
      }
    }
    
    for(int i=0;i<nType[0];i++)
      for(int j=0;j<nType[1];j++){
        int t;  cin >> t;  t--;
        type2rank[0][i][j] = nType[1]-t-1;
        rank2type[0][i][nType[1]-t-1] = j;
      }
    
    for(int i=0;i<nType[1];i++)
      for(int j=0;j<nType[0];j++){
        int t;  cin >> t;  t--;
        type2rank[1][i][j] = nType[0]-t-1;
        rank2type[1][i][nType[0]-t-1] = j;
      }

    for(int cases=1;;cases++){
      int n; cin >> n;
      if(n==0) break;
      
      string s[BUF];
      for(int i=0;i<n;i++)
        cin >> s[i];
      
      cout << "Scenario " << k << ", Mixture " << cases << ":" << endl;
      work(s,n,type2rank,rank2type,n2type);
    }
  }
  
  return 0;
}
