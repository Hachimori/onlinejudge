#include<iostream>
#include<string>
#include<map>


string word;
string str="a";
map<string,int> list;

void Kuriage(int arg){

  //cout << "leng = " << str.length() << "  arg+1 = " << arg+1 << endl; 
  //cout << "str[arg+1] = " << str[arg+1] << "   str[arg] = " <<  str[arg] << endl;

  if(str.length()==arg+1) str += 'a';
  else if(str[arg+1]+1==str[arg]) Kuriage(arg+1);
  else str[arg+1]++;

  //if(str[arg+1]=='z'+1) Kuriage(arg+1);
  str[arg] = str[arg+1]+1; 


}

void make_list(){
  
  
  string tmp;
  
  for(int i=1;i<=83681;i++){

    tmp.erase(tmp.begin(),tmp.begin()+tmp.length());
    for(int j=str.length()-1;j>=0;j--){
      tmp+=str[j];
    }
    //cout << str << "  " << i <<endl;
    list[tmp] = i;

    str[0]++;

    if(str[0]=='z'+1){ 
      str[0]--;
      Kuriage(0);
    }
  }
 
}

class Solver{

 public:

  bool read(){

    cin >> word;

    if(cin.eof()) return false;

    return true;

  }

  void work(){
    if(list.find(word)==list.end()) cout << 0 << endl;
    else cout << list[word] << endl;
    
  }
  

};

main(){
  
  Solver solver;

  make_list();

  while(true){
    
    if(solver.read()==false) break;
    solver.work();
    
  }
  
}
