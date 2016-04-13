#include<iostream>
#include<string>
#include<map>

#define MAX_SIZE 11

using namespace std;

class Pattern{
public:

  char key;
  map<char,unsigned long long> value;

  Pattern(){}
  Pattern(char k, map<char,unsigned long long> v): key(k), value(v){}

};

int nPattern;
Pattern patternList[MAX_SIZE];

void read(){
  
  cin >> nPattern;
  
  for(int i=0;i<nPattern;i++){
    string str;
    char c,c2;
    
    cin >> patternList[i].key >> c >> c2 >> str;    

    
    map<char,unsigned long long> val;
    
    for(int j=0;j<str.size();j++){
      if(val.find(str[j])==val.end())
	val[str[j]]=1;      
      else 
	val[str[j]]++;      
    }
    
    patternList[i].value = val;
  }

  /*
  for(int i=0;i<nPattern;i++){
    cout << i << ": ";    
    map<char,int>::iterator j=patternList[i].value.begin();
    for(;j!=patternList[i].value.end();j++){
      cout << j->first << ' ' << j->second << "   ";
    }
    cout << endl;
  }cout << endl;
  */
}

void produce(unsigned long long nChar[127]){
  /*
  for(int i=33;i<=126;i++){
    cout << (char)i << ":" << nChar[i] << endl;
  }cout << endl << endl;
  */
  
  unsigned long long next[127];
  for(int i=33;i<=126;i++)
    next[i] = nChar[i];


  for(int i=0;i<nPattern;i++){

    unsigned long long nKey = nChar[patternList[i].key];
    
    next[patternList[i].key]-=nKey;

    map<char,unsigned long long>::iterator j=patternList[i].value.begin();
    for(;j!=patternList[i].value.end();j++)      
      next[j->first] += nKey*j->second;
    
    
  }
  
  for(int i=33;i<=126;i++)
    nChar[i] = next[i];

}

void work(){
  
  int nQuery;
  cin >> nQuery;

  for(int i=0;i<nQuery;i++){
    
    int workTime;
    unsigned long long nChar[127];
    char toCount;
    string init;

    for(int i=33;i<=126;i++)
      nChar[i]=0;

    cin >> init >> toCount >> workTime;
    
    for(int i=0;i<init.size();i++)
      nChar[init[i]]++;
    
    for(int i=0;i<workTime;i++)      
      produce(nChar);
    
    cout << nChar[toCount] << endl;
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
