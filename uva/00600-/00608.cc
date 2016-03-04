#include<iostream>
using namespace std;

string result[3][3];

void read(){
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      cin >> result[i][j];
}

bool contains(char ch, string s){
  return s.find(ch)!=string::npos;
}

void work(){
  for(int i=0;i<3;i++){
    while(1){
      bool deleted = false;
      for(char ch='A';ch<='L';ch++){
        int idxA = result[i][0].find(ch), idxB = result[i][1].find(ch);
        if(idxA!=string::npos && idxB!=string::npos){
          result[i][0].erase(result[i][0].begin()+idxA);
          result[i][1].erase(result[i][1].begin()+idxB);
          deleted = true;
        }
      }
      if(!deleted) break;
    }
  }

  for(char counterfeit='A';counterfeit<='L';counterfeit++){
    for(int heavy=0;heavy<=1;heavy++){
      bool ok = true, found = false;
      for(char nonCounterfeit1='A';nonCounterfeit1<='L';nonCounterfeit1++){
        for(char nonCounterfeit2=nonCounterfeit1+1;nonCounterfeit2<='L';nonCounterfeit2++){
          if(counterfeit==nonCounterfeit1 || counterfeit==nonCounterfeit2) continue;
          for(int i=0;i<3;i++){
            if(result[i][2]=="even"){
              if(contains(counterfeit,result[i][0])) ok = false;
              if(contains(counterfeit,result[i][1])) ok = false;
            }
            if(result[i][2]=="up"){
              if(heavy==1 && contains(counterfeit,result[i][1])) ok = false;
              if(heavy==0 && contains(counterfeit,result[i][0])) ok = false;
              
              if(!((heavy==1 && contains(counterfeit,result[i][0])) || (heavy==0 && contains(counterfeit,result[i][1]))) &&
                 ((contains(nonCounterfeit1,result[i][0]) && contains(nonCounterfeit2,result[i][1])) ||
                  (contains(nonCounterfeit1,result[i][1]) && contains(nonCounterfeit2,result[i][0])))
                 )
                ok = false;
            }
            if(result[i][2]=="down"){
              if(heavy==1 && contains(counterfeit,result[i][0])) ok = false;
              if(heavy==0 && contains(counterfeit,result[i][1])) ok = false;

              if(!((heavy==0 && contains(counterfeit,result[i][0])) || (heavy==1 && contains(counterfeit,result[i][1]))) &&
                 ((contains(nonCounterfeit1,result[i][0]) && contains(nonCounterfeit2,result[i][1])) ||
                  (contains(nonCounterfeit1,result[i][1]) && contains(nonCounterfeit2,result[i][0])))
                 )
                ok = false;
            }
            found |= contains(counterfeit,result[i][0]) || contains(counterfeit,result[i][1]);
            if(!ok) goto _fail;
          }
        }
      }
      if(ok && found){
        cout << counterfeit << " is the counterfeit coin and it is ";
        cout << (heavy==0 ? "light." : "heavy.") << endl;
        return;
      }
    _fail:;
    }
  }
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
