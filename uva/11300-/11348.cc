#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int CARD = 10005, FRIEND = 55;

int main(){
  int cases;
  cin >> cases;
  for(int k=0;k<cases;k++){
    int nFriend;
    static int havingCard[FRIEND], friendCard[FRIEND][CARD], cntCard[CARD];
    memset(cntCard,0,sizeof(cntCard));
    
    cin >> nFriend;
    for(int i=0;i<nFriend;i++){
      cin >> havingCard[i];
      for(int j=0;j<havingCard[i];j++){
        cin >> friendCard[i][j];
      }
      sort(friendCard[i],friendCard[i]+havingCard[i]);
      havingCard[i] = unique(friendCard[i],friendCard[i]+havingCard[i])-friendCard[i];
      for(int j=0;j<havingCard[i];j++)
        cntCard[friendCard[i][j]]++;
    }
     
    cout << "Case " << k+1 << ":";
    int totalUnique = max(1,(int)count(cntCard,cntCard+CARD,1));
    for(int i=0;i<nFriend;i++){
      int nUnique = 0;
      for(int j=0;j<havingCard[i];j++)
        nUnique += cntCard[friendCard[i][j]]==1;
      printf(" %.6f%\%",100.0*nUnique/totalUnique);
    }cout << endl;
  }
  return 0;
}
