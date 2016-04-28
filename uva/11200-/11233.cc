#include<iostream>
#include<string>
#define DICT 25
#define QUERY 105
using namespace std;

int nDict, nQuery;
string dict[DICT][2], query[QUERY];

void read(){
  cin >> nDict >> nQuery;

  for(int i=0;i<nDict;i++)
    cin >> dict[i][0] >> dict[i][1];

  for(int i=0;i<nQuery;i++)
    cin >> query[i];
}

bool isConsonant(char ch){
  static string vowel = "aiueo";
  return vowel.find(ch)==string::npos;
}

void work(){
  for(int k=0;k<nQuery;k++){
    string &q = query[k];

    for(int i=0;i<nDict;i++)
      if(dict[i][0]==q){
        cout << dict[i][1] << endl;
        goto finish;
      }

    if(q.size()>=2 && isConsonant(q[q.size()-2]) && q[q.size()-1]=='y'){
      cout << q.substr(0,q.size()-1) << "ies" << endl;
      goto finish;
    }
    
    if(q.size()>=1 && (q[q.size()-1]=='o' || q[q.size()-1]=='s' || q[q.size()-1]=='x')){
      cout << q << "es" << endl;
      goto finish;
    }
    
    if(q.size()>=2 && 
       (q.substr(q.size()-2)=="ch" || q.substr(q.size()-2)=="sh")){
      cout << q << "es" << endl;
      goto finish;
    }
    
    cout << q << 's' << endl;
  
  finish:;
  }
}

int main(){
  read();
  work();
  return 0;
}
