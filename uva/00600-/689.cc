#include<iostream>
#include<string>
#include<cctype>
#include<list>

using namespace std;

string str;

bool read(){
  
  str = "";
  
  string strTmp;
  if(getline(cin,strTmp)==NULL) return false;
  
  for(int i=0;i<strTmp.size();i++)
    if(isalpha(strTmp[i]))
      str+=toupper(strTmp[i]);
  
  return true;
}

bool myGreater(const string &a, const string &b){
  return a.length()>b.length();
}

bool contain(string a, string b){
  
  int aBegin,aEnd, bBegin, bEnd;
  
  aBegin=a.size()/2-1, aEnd=(a.size()+1)/2;
  bBegin=b.size()/2-1, bEnd=(b.size()+1)/2;
  
  if(a.size()%2==1 && a[aBegin+1]!=b[bBegin+1]) return false;
    
  for(;bBegin>=0;aBegin--,bBegin--,aEnd++,bEnd++)
    if(a[aBegin]!=b[bBegin] || a[aEnd]!=b[bEnd]) return false;

  return true;
}

void deleteContain(list<string> &sList){

  list<string>::iterator i=sList.begin();
  i++;

  for(;i!=sList.end();){
    list<string>::iterator j=i;
    j--;
    
    bool deleted=false;
    
    for(;j!=sList.begin();j--)
      if(contain(*j,*i)){
	i=sList.erase(i);
	deleted=true;
	break;
      }
    
    if(!deleted){
      if(contain(sList.front(),*i))
	i=sList.erase(i);
      else
	i++;
    }
    
  }

}

void work(){
  
  list<string> sListOdd, sListEven;
  
  for(int i=1;i<(int)(str.length()-1);i++){
    
    if(str[i-1]!=str[i+1]) continue;
    
    int begin=i-1, end=i+1;
    
    while(begin-1>=0 && end+1<str.length() && str[begin-1]==str[end+1])
      begin--, end++;

    sListOdd.push_back(str.substr(begin,end-begin+1));
  }
  
  for(int i=1;i<(int)(str.length()-1);i++){
    
    if(str[i]!=str[i+1]) continue;
    
    int begin=i, end=i+1;
    
    while(begin-1>=0 && end+1<str.length() && str[begin-1]==str[end+1])
      begin--, end++;
    
    if(end-begin+1>2)
      sListEven.push_back(str.substr(begin,end-begin+1));
  }
  
  /*
  for(int i=0;i<sListOdd.size();i++){
    cout << sListOdd[i] << endl;
  }
  for(int i=0;i<sListEven.size();i++){
    cout << sListEven[i] << endl;
  }
  cout << endl;
  */

  sListOdd.sort(myGreater);
  sListEven.sort(myGreater);

  deleteContain(sListOdd);
  deleteContain(sListEven);
  
  sListOdd.merge(sListEven);

  sListOdd.sort();

  int cnt=0;
  for(list<string>::iterator i=sListOdd.begin();i!=sListOdd.end();i++){
    if(i!=sListOdd.begin()) cout << ' ';
    cout << *i;
  }
  cout << endl;
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
