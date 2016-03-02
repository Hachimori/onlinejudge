#include<iostream>
#include<string>
#include<algorithm>

#define MAX 5000


class Info{
 public:

  string title;
  string first_name;
  string last_name;
  string address;
  string department;
  string homephone;
  string workphone;
  string campusbox;

  bool operator <( Info const &info) const{
    
    for(int i=0;i<last_name.length() && i<info.last_name.length();i++){
      if(last_name[i]<info.last_name[i]) return true;
      else if(last_name[i]>info.last_name[i]) return false;
    }

    if(last_name.length() < info.last_name.length()) return true;
    else return false;

  }


};


int num_department;
int num_person;
Info person[MAX];

class Solver{
 public:

  void read(){
    
    cin >> num_department;

    string tmp;
    getline(cin,tmp);

    for(int i=0,curr_department=0;curr_department<num_department;curr_department++){
      
      string tmp_department;

      getline(cin,tmp_department);

      while(true){
	string str;
	int arg_str=0;
	
	person[i].department = tmp_department;

	getline(cin,str);
	if(str.length()==0) break;

	for(;;arg_str++){
	  if(str[arg_str]==',') break;  
	  person[i].title += str[arg_str];
	}
	arg_str++;
	for(;;arg_str++){
	  if(str[arg_str]==',') break;  
	  person[i].first_name += str[arg_str];
	}	
	arg_str++;
	for(;;arg_str++){
	  if(str[arg_str]==',') break;  
	  person[i].last_name += str[arg_str];
	}
	arg_str++;
	for(;;arg_str++){
	  if(str[arg_str]==',') break;  
	  person[i].address += str[arg_str];
	}
	arg_str++;
	for(;;arg_str++){
	  if(str[arg_str]==',') break;  
	  person[i].homephone += str[arg_str];
	}
	arg_str++;
	for(;;arg_str++){
	  if(str[arg_str]==',') break;  
	  person[i].workphone += str[arg_str];
	}
	arg_str++;
	for(;;arg_str++){
	  if(arg_str==str.length()) break;  
	  person[i].campusbox += str[arg_str];
	}

	i++;
	num_person = i;
      }

    }

  }

  void work(){
    
    sort(&person[0],&person[num_person]);

    for(int i=0;i<num_person;i++){
      cout << "----------------------------------------" << endl;
      
      cout << person[i].title << ' ' << person[i].first_name << ' ' << person[i].last_name << endl;
      cout << person[i].address << endl;
      cout << "Department: " << person[i].department << endl;
      cout << "Home Phone: " << person[i].homephone << endl;
      cout << "Work Phone: " << person[i].workphone << endl;
      cout << "Campus Box: " << person[i].campusbox << endl;
    }

  }


};

main(){

  Solver solver;

  solver.read();
  solver.work();

}
