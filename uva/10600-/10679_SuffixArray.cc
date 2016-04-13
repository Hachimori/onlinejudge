#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define STR 100005
#define QUERY 1005
using namespace std;


bool mycmp(const char *a, const char *b){
  return strcmp(a,b)<0;
}

class SuffixArray{
public:
  int N, *V, *pos, *buf;
  char *str, **ptr;
  
  SuffixArray(){}
  SuffixArray(char *str): str(str){}
  ~SuffixArray(){
    delete [] ptr;
  }

  void mqsort(int b, int e, int h){
    if(b+1==e || b==e) return;

    int L = b, R = e-1, mid = b;

    for(int i=b;i<e;i++)
      if(V[pos[i]+h]<V[pos[(b+e)/2]+h])
        buf[L++] = pos[i];
      else if(V[pos[i]+h]>V[pos[(b+e)/2]+h])
        buf[R--] = pos[i];
      else{
        buf[L++] = buf[mid];
        buf[mid++] = pos[i];
      }
    
    for(int i=b;i<mid;i++) swap(buf[--L],buf[i]);
    for(int i=b;i<e;i++) pos[i] = buf[i];

    mqsort(b,L,h);
    mqsort(R+1,e,h);
  }

  void construct(char *_str){
    str = _str;
    N = strlen(str)+1;
    V = new int[N];
    pos = new int[N];
    buf = new int[N];

    for(int i=0;i<N;i++){
      pos[i] = i;
      V[i] = str[i];
    }
    mqsort(0,N,0);

    for(int h=1;h<N;h<<=1){
      for(int i=0;i<N;){
        int bgn = i;
        while(i<N && V[pos[bgn]]==V[pos[i]]) i++;
        mqsort(bgn,i,h);
      }

      buf[0] = 0;
      for(int i=1;i<N;i++)
        buf[i] = buf[i-1] + !(V[pos[i-1]]==V[pos[i]] && V[pos[i-1]+h]==V[pos[i]+h]);

      for(int i=0;i<N;i++)
        V[pos[i]] = buf[i];
    }
    
    ptr = new char* [N];
    for(int i=0;i<N;i++)
      ptr[i] = str+pos[i];

    delete [] pos;
    delete [] buf;
    delete [] V;
  }
  
  int count(char query[]){
    char *q = query;
    int bgn = lower_bound(ptr,ptr+N,q,mycmp)-ptr;
    q[strlen(q)-1]++;
    int end = lower_bound(ptr,ptr+N,q,mycmp)-ptr;
    q[strlen(q)-1]--;
    return end-bgn;
  }
};

int main(){
  int cases;
  scanf("%d",&cases);
  
  for(int k=0;k<cases;k++){
    char str[STR];
    scanf("%s",str);
    int nQuery;
    scanf("%d",&nQuery);

    SuffixArray *sary = new SuffixArray();
    sary->construct(str);

    for(int i=0;i<nQuery;i++){
      char query[QUERY];
      scanf("%s",query);
      cout << (sary->count(query)?'y':'n') << endl;
    }

    delete sary;
  }

  return 0;
}
