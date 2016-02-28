#include<iostream>
#include<cctype>
#include<vector>
using namespace std;

void moveFront(int pos, vector<string> &sList){
  string toMov = sList[pos];
  sList.erase(sList.begin()+pos);
  sList.push_back(toMov);
}

int main(){
  vector<string> sList;
  while(1){
    string s;
    getline(cin,s);
    int idx = 0;
    while(idx<s.size()){
      if(isalpha(s[idx])){
        string word;
        while(idx<s.size() && isalpha(s[idx])) word += s[idx++];
        int pos = -1;
        for(int i=0;i<sList.size();i++)
          if(sList[i]==word)
            pos = i;
        if(pos==-1) {
          sList.push_back(word);
          cout << word;
        }
        else
          moveFront(pos,sList);
      }
      else if(isdigit(s[idx])){
        string num;
        while(idx<s.size() && isdigit(s[idx])) num += s[idx++];
        int val = atoi(num.c_str());
        if(val==0) return 0;
        cout << sList[sList.size()-val];
        moveFront(sList.size()-val,sList);
      }
      else
        cout << s[idx++];
    }
    cout << endl;
  }

  return 0;
}
