#include<iostream>
#include<algorithm>
#include<string>
#include<map>

#define MAX 101

class Contestant{
 public:

  int num;
  int num_solved;
  int time;
  bool solved_problem[10];
  int num_penalty[10];

  Contestant(){}

  void init(){
    for(int i=0;i<10;i++){
      solved_problem[i]=false;
      num_penalty[i]=0;
    }
    time=0;
    num_solved=0;
    
  }

  bool operator< (Contestant const &c) const {
    if(num_solved>c.num_solved) return true;
    else if(num_solved==c.num_solved && time<c.time) return true;
    else if(num_solved==c.num_solved && time==c.time && num<c.num) return true;
    else return false;
  }

};

int num_contestant;
map<string,int> name_list;
map<int,string> num_list;
Contestant list[MAX];

int myatoi(string str){
  
  int num=0;

  for(int i=0;i<str.length();i++){
    num*=10;
    num+=str[i]-'0';
  }

  return num;

}

class Solver{
 public:

  void init(){
    for(int i=0;i<MAX;i++)
      list[i].init();
    name_list.clear();
    num_list.clear();
  }

  void read(){

    int arg;
    int id,num_problem,time;
    char letter;
    string str;

    num_contestant=0;

    while(true){

      getline(cin,str);
      if(str.length()==0) break;
      
      arg=0;
      while(str[arg]==' ') arg++;

      string name;
      for(;;arg++){
	
	if(str[arg]==' '){
	  if(name_list.find(name)==name_list.end()){
	    name_list[name] = num_contestant;
	    num_list[num_contestant] = name;
	    num_contestant++;
	  }
	  id = name_list[name];
	  list[id].num=myatoi(name);
	  break;
	}
	name+=(char)str[arg];
      }
      while(str[arg]==' ') arg++;
      

      num_problem=0;
      for(;;arg++){
	if(str[arg]==' ') break;
	num_problem*=10;
	num_problem+=str[arg]-'0';
      }
      while(str[arg]==' ') arg++;

      time=0;
      for(;;arg++){
	if(str[arg]==' ') break;
	time*=10;
	time+=str[arg]-'0';
      }
      while(str[arg]==' ') arg++;
     
      
      letter = str[arg];
 
      if(letter=='C'){
	if(list[id].solved_problem[num_problem]==false){
	  list[id].num_solved++;
	  list[id].solved_problem[num_problem]=true;
	  list[id].time+=time;
	}
      }
      else if(letter=='I'){ 
	if(list[id].solved_problem[num_problem]==false){ 
	  list[id].num_penalty[num_problem]++;
	}
      }

    }

    for(int i=0;i<num_contestant;i++){
      for(int j=0;j<10;j++){
	if(list[i].solved_problem[j]==true && list[i].num_penalty[j]>0)
	  list[i].time += list[i].num_penalty[j]*20;
      }
    }

  }

  void work(){
    sort(&list[0],&list[num_contestant]);

    for(int i=0;i<num_contestant;i++){
      cout << list[i].num << ' ' << list[i].num_solved << ' ' << list[i].time << endl;
    }
    
  }

};



main(){
  
  Solver solver;
  int cases;
  string str;

  cin >> cases;
  getline(cin,str);
  getline(cin,str);

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    solver.init();
    solver.read();
    solver.work();
  }

}
