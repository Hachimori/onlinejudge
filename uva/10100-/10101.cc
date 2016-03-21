#include<iostream>
#include<string>
#include<cstdio>
#include<vector>

using namespace std;

string digit;

bool read(){
  if(!(cin >> digit)) return false;

  return true;
}

bool allZero(string str){

  for(int i=0;i<str.length();i++)
    if(str[i]!='0') return false;

  return true;
}

void work(int cases){
  
  vector<int> nList;

  for(int i=digit.length()-1;i>=0;){
    
    int sum=0,p=1;
    for(int j=0;j<2 && i>=0;i--,j++,p*=10){
      sum+=(digit[i]-'0')*p;
    }
    
    nList.push_back(sum);
    if(i==-1) break;

    sum=0,p=1;
    for(int j=0;j<1 && i>=0;i--,j++,p*=10){
      sum+=(digit[i]-'0')*p;
    }
    
    nList.push_back(sum);
    if(i==-1) break;

    sum=0,p=1;
    for(int j=0;j<2 && i>=0;i--,j++,p*=10){
      sum+=(digit[i]-'0')*p;
    }

    nList.push_back(sum);
    if(i==-1) break;

    sum=0,p=1;
    for(int j=0;j<2 && i>=0;i--,j++,p*=10){
      sum+=(digit[i]-'0')*p;
    }

    nList.push_back(sum);
    if(i==-1) break;


  }

  printf("%4d.",cases);

  if(allZero(digit)){ 
    cout << " " << 0 << endl;
    return;
  }

  for(int i=nList.size()-1;i>=0;i--){
    if(nList[i]!=0) break;
    else nList.pop_back();
  }

  for(int i=nList.size()-1,j=0;i>=0;i--,j++){
    if(nList[i]!=0){
      cout << ' ' << nList[i];

      
      if(i%4==1) cout << " shata";
      else if(i%4==2) cout << " hajar";
      else if(i%4==3) cout << " lakh";
    }
    
    if(i!=0 && i%4==0) cout << " kuti";
    
  }
  cout << endl;

}

int main(){

  for(int i=1;read();i++)
    work(i);

  return 0;
}
