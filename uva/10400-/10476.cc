#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<cctype>
#include<cstdlib>
#include<cassert>

#define MAX_SIZE 15

using namespace std;

int nMessage;
map<string,int> spam, nonSpam, message[MAX_SIZE];

void getFreq(map<string,int> &M){
  
  string str;

  while(true){
    
    getline(cin,str);
    if(str=="ENDMESSAGE") break;
    
    for(int i=0;i<((int)str.length()-2);i++){
      
      string subStr = str.substr(i,3);
      
      if(M.find(subStr)==M.end())
	M[subStr] = 1;
      else
	M[subStr]++;
      
    }
    
  }
  
}

double getSim( map<string,int> &F1, map<string,int> &F2){
  
  double sum1=0, sum2=0, sum3=0;

  for(map<string,int>::iterator i=F1.begin();i!=F1.end();i++)
    sum1+=(i->second)*(i->second);

  for(map<string,int>::iterator i=F2.begin();i!=F2.end();i++)
    sum2+=(i->second)*(i->second);
  
  assert(F1.size()>0 && F2.size()>0);
  
  for(map<string,int>::iterator i=F1.begin();i!=F1.end();i++)
    if(F2.find(i->first)!=F2.end())
      sum3+=i->second*F2[i->first];
    
  return sum3/(sqrt(sum1)*sqrt(sum2));
}

bool read(){

  for(int i=0;i<MAX_SIZE;i++)
    message[i].clear();
  spam.clear();
  nonSpam.clear();

  int nSpam, nNonSpam;
  cin >> nSpam >> nNonSpam >> nMessage;
  
  if(nSpam==0 && nNonSpam==0 && nMessage==0) return false;
  
  string dummy;
  getline(cin,dummy);

  for(int i=0;i<nSpam;i++)
    getFreq(spam);

  for(int i=0;i<nNonSpam;i++)
    getFreq(nonSpam);

  for(int i=0;i<nMessage;i++)
    getFreq(message[i]);
  
  return true;
}

void work(int cases){
  
  cout << "Set " << cases << ":" << endl;
  
  for(int i=0;i<nMessage;i++){
    
    double spamSim, nonSpamSim;

    spamSim = getSim(message[i],spam);
    nonSpamSim = getSim(message[i],nonSpam);

    printf("%.5lf %.5lf\n",spamSim,nonSpamSim);

    if(spamSim>nonSpamSim) cout << "spam" << endl;
    else cout << "non-spam" << endl;
    
  }
  
  
}

int main(){
  
  for(int i=0;read();i++)
    work(i+1);

  return 0;

}
