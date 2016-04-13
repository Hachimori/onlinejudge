#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> words;
int num_word;

int word_difference(string str1, string str2){
  
  for(int i=0,j=0;i<str1.size() && j<str2.size();i++,j++){
    if(str1[i]!=str2[j]) return str2.size()-j;
  }

  return str2.size()-str1.size();

}


class Solver{

 public:

  void init(){

    words.clear();

  }

  void read(){
    
    cin >> num_word;

    string str;

    for(int i=0;i<num_word;i++){
      cin >> str;
      words.push_back(str);
    }

  }

  void work(){

    sort(words.begin(),words.end());

    vector<string>::iterator i_ret;
    int sum=0;

    sum+=words.begin()->length();

    for(i_ret=words.begin()+1;i_ret!=words.end();i_ret++)
      sum += word_difference(*(i_ret-1),*i_ret);

    
    /* Output */
    cout << sum << endl;
    
    for(i_ret=words.begin();i_ret!=words.end();i_ret++)
      cout << *i_ret << endl;
  }

};

main(){

  int cases;
  Solver solver;

  cin >> cases;

  for(int i=0;i<cases;i++){

    solver.init();
    solver.read();
    solver.work();

  }

}
