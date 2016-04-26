#include<iostream>
#include<set>
#include<cstdio>
#include<algorithm>
#define BUF 1000005
#define DAY 5005
using namespace std;

int main(){
  int nDay;

  while(scanf("%d",&nDay)){
    if(nDay==0) break;
    
    set<int, greater<int>,  allocator<int> > GS;   
    set<int,    less<int>,  allocator<int> > LS;   
    static int cnt[BUF];
    fill(cnt,cnt+BUF,0);
    
    long long ans = 0;
    for(int k=0;k<nDay;k++){
      int nBill;
      scanf("%d",&nBill);
      for(int i=0;i<nBill;i++){
	int v;
	scanf("%d",&v);
	
	if(cnt[v]==0) GS.insert(v), LS.insert(v);
	cnt[v]++;
      }

      ans += *GS.begin()-*LS.begin();
      cnt[*GS.begin()]--, cnt[*LS.begin()]--;
      
      int a = *GS.begin(), b = *LS.begin();
      if(cnt[a]==0){ GS.erase(a); LS.erase(a); }
      if(cnt[b]==0){ GS.erase(b); LS.erase(b); }
    }
    
    printf("%lld\n",ans);
  }
  return 0;
}
