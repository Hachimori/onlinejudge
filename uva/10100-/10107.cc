#include<iostream>
#include<set>
#include<climits>

using namespace std;

int n, prevMedian;
multiset<int> S;

void work(){
  
  S.insert(n);

  /*
  for(set<int>::iterator i=S.begin();i!=S.end();i++)
    cout<< *i << ' ';
  cout << endl;
  */

  set<int>::iterator pos=S.upper_bound(prevMedian);
  /*
   cout << "upper_bound of " << prevMedian << " is " << *pos <<  "  n = " << n << endl << endl;;  
  */
  /*
  if(S.size()==1){
    prevMedian = n;
    cout << n << endl;
    return ;
  }
  */
  if(S.size()%2==1){ 
    if(prevMedian>n){
      pos--;
      prevMedian = *pos;
    }
    else {
      //  pos++;
      prevMedian = *pos;
    }
  }
  else {
    if(prevMedian>n){
      pos--;
      prevMedian = *pos;
      pos--;      
      prevMedian += *pos;       
      prevMedian /= 2;
    }
    else {
      pos--;
      prevMedian = *pos;
      pos++;
      prevMedian += *pos;
      prevMedian /= 2;
    }
  }
  
  cout << prevMedian << endl;
}

int main(){
  
  prevMedian=INT_MAX;

  while(cin >> n)
    work();  
  
  return 0;
}
