// $B$3$NLdBj$,MW5a$7$F$$$k$3$H(B:
//
// 
// $BBg$-$$%P%C%0$K>.$5$$%P%C%0$r$D$a$F$f$-!"0lHV30B&$K$"$k(B
//    $B%P%C%/$N?t$r:G>.$K$9$k!#(B
// 
// $B%P%C%0$NCf$K$"$k%P%C%0$N?t$N:GBgCM$r:G>.$K$9$k!#(B
// $BNc(B:  
// 6
// 1 1 1 2 3 4
// $B$3$l$KBP$7!"(B
//
// 3
// 1 2 3 4
// 1
// 1
//
// $B$3$N$h$&$JEz$($O4V0c$$$G!"@5$7$$Ez$($O!"(B
//
// 3
// 1 2
// 1 3
// 1 4
//
//
//  
// $B2rK!(B:
// $BM?$($i$l$k%P%C%/$N%5%$%:$NCf$G0lHV8D?t$NB?$$$b$N$KCmL\$9$k!#(B
// $B$=$l$,0lHV30B&$K$"$k%P%C%0$N?t$HEy$7$/$J$k!#$^$?!"%P%C%0$O(B
// $BBg$-$5$N0c$&$b$N$r=8$a$l$P0l$D$N%P%C%0$K$^$H$a$k$3$H$,=PMh$k!#(B
// $B$=$NM}M3$O!"$"$k%P%C%/$h$j$bBg$-$$$b$N$,$"$l$P$=$A$i$K<h$j9~$^$l(B
// $B>.$5$$$b$N$,$"$l$P$=$A$i$r<h$j9~$`$N$G!"7k6I0l$D$K$^$H$^$k$+$i$G$"$k!#(B
// $B$J$N$G!"0lHV30B&$K$"$k%P%C%0$N?t$@$1$NF~$lJ*$rMQ0U$7$F!"(B
// $B$=$NF~$lJ*$KF1$8%5%$%:$N%P%C%/$rF~$l$J$$$h$&$K!"$^$?A4$F$N%P%C%0$r6QEy$K(B
// $BF~$lJ*$KF~$l$k$h$&$K$9$k$HMQ7o$rK~$?$;$k!#(B

#include<iostream>
#include<algorithm>
#include<vector>
#define BAG 100005
#define RANGE 1000005
using namespace std;

int maxCnt, cntSize[RANGE];

bool read(){
  int nBag;
  cin >> nBag;
  if(nBag==0) return false;
  
  maxCnt = 0;
  for(int i=0;i<RANGE;i++)
    cntSize[i] = 0;
  
  for(int i=0;i<nBag;i++){
    int n;
    cin >> n;
    cntSize[n]++;
    maxCnt = max(maxCnt,cntSize[n]);
  }

  return true;
}

void work(){
  int cur = 0;
  vector<int> ans[BAG];
  
  for(int i=0;i<RANGE;i++)
    for(int j=0;j<cntSize[i];j++,cur=(cur+1)%maxCnt)
      ans[cur].push_back(i);
    
  cout << maxCnt << endl;
  for(int i=0;i<maxCnt;i++){
    for(int j=0;j<ans[i].size();j++){
      if(j) cout << ' ';
      cout << ans[i][j];
    }
    cout << endl;
  }
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
  }
  
  return 0;
}
