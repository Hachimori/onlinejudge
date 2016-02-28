#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

string digit;

bool read(){
  
  cin >> digit;
  if(digit=="0") return false;

  return true;

}

void work(){

  set<int> visited;
  vector<int> result;
  int cntChain;
  long long resultNum, num1=0, num2=0;
  

  for(int i=0;i<digit.length();i++)
    result.push_back(digit[i]-'0');

  
  cout << "Original number was " << digit << endl;

  for(cntChain=0;;cntChain++){
    
    vector<int> digitList1, digitList2;
    digitList1.clear(), digitList2.clear();
    
    for(int i=0;i<result.size();i++)
      digitList2.push_back(result[i]);
    
    sort(digitList2.begin(),digitList2.end());
    
    for(int i=digitList2.size()-1;i>=0;i--)
      digitList1.push_back(digitList2[i]);

    
    num1=0, num2=0;
    for(int i=0;i<digitList1.size();i++){
      num1*=10;
      num1+=digitList1[i];
    }
    
    for(int i=0;i<digitList2.size();i++){
      num2*=10;
      num2+=digitList2[i];
    }  
    
    resultNum = num1-num2;
    cout << num1 << " - " << num2 << " = " << resultNum << endl;
    
    if(visited.find(resultNum)!=visited.end()) break;
    else visited.insert(resultNum);

    result.clear();
    for(;resultNum>0;resultNum/=10)
      result.push_back(resultNum%10);
    
    
  }

  cout << "Chain length " << cntChain+1 << endl;
  cout << endl;
}

int main(){

  for(int i=0;read();i++){
    work();
  }

  return 0;
}
