#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Data{
public:

  int digit;
  string ans;

  Data(){}
  Data(int d, string a): digit(d), ans(a){}

};

vector<Data> dataList;

bool read(){

  dataList.clear();

  while(true){
    int n;
    string ans;

    cin >> n;
    if(n==0) return false;
    cin >> ans; cin >> ans;


    dataList.push_back(Data(n,ans));
    
    if(ans=="on") break;
  }
  
  return true;
}

void work(){
  
  for(int i=0;i<(int)dataList.size()-1;i++){
    if(dataList[i].ans=="high" && dataList[i].digit<=dataList.back().digit){
      cout << "Stan is dishonest" << endl;
      return;
    }
    
    if(dataList[i].ans=="low" && dataList[i].digit>=dataList.back().digit){
      cout << "Stan is dishonest" << endl;
      return;
    }
  }
 
  cout << "Stan may be honest" << endl;
 

}

int main(){

  while(read())
    work();

  return 0;
}
