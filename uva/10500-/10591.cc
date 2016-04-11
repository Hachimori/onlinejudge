#include<iostream>
#include<set>

using namespace std;

long long source;

void read(){
  cin >> source;
}

long long cntDigits(long long n){
  long long sum=0;

  for(;n>0;n/=10)
    sum+=(n%10)*(n%10);

  return sum;
}

void work(int cases){
  
  int curr=cntDigits(source);

  set<long long> S;

  while(true){
    if(curr==1){
      cout << "Case #" << cases << ": " << source << " is a Happy number." << endl;
      break;
    }

    if(curr==source) {
      cout << "Case #" << cases << ": " << source << " is an Unhappy number." << endl;
      break;
    }
    

    if(S.find(curr)!=S.end()){
      cout << "Case #" << cases << ": " << source << " is an Unhappy number." << endl;
      break;
    }
    else{
      S.insert(curr);
    }

    
    
    curr=cntDigits(curr);
  }


}


int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
