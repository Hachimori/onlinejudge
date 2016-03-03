#include<iostream>
#include<string>

#define MAX 100

char roll[MAX];
string str;


class Solver{

 public:

  bool read(){

    getline(cin,str);
    if(str.compare("Game Over")==0) return false;

    
    for(int i=0,j=0;i<str.size();i++){
      if( (str[i]>='0' && str[i]<='9') || str[i]=='/' || str[i]=='X'){
	roll[j]=str[i];
	roll[j+1]='\0';
	j++;
      }
    }


    return true;

  }

  void work(){

    int score=0;
    int frame=20;

    for(int i=0;i<frame;i++){
      if(roll[i]=='/' && i!=frame-1){
	score+=10-(roll[i-1]-'0');

	if(roll[i+1]=='X'){
	  score+=10;
	}
	else if(roll[i+1]>='0' && roll[i+1]<='9'){
	  score+=roll[i+1]-'0';
	}
      }
      else if(roll[i]=='/' && i==frame-1){
	score+=10-(roll[i-1]-'0');

	if(roll[i+1]=='X'){
	  score+=10;
	}
	else if(roll[i+1]>='0' && roll[i+1]<='9'){
	  score+=roll[i+1]-'0';
	}
	break;
      }
      else if(roll[i]=='X' && i!=frame-2){
	frame--;
	score+=10;

	if(roll[i+1]=='X'){
	  score+=10;
	}
	else if(roll[i+1]>='0' && roll[i+1]<='9'){
	  score+=roll[i+1]-'0';
	}
	
	if(roll[i+2]=='/'){
	  score+=10-(roll[i+1]-'0');
	}
	else if(roll[i+2]=='X'){
	  score+=10;
	}
	else if(roll[i+2]>='0' && roll[i+2]<='9'){
	  score+=roll[i+2]-'0';
	}
      }
      else if(roll[i]=='X' && i==frame-2){
	score+=10;

	if(roll[i+1]=='X'){
	  score+=10;
	}
	else if(roll[i+1]>='0' && roll[i+1]<='9'){
	  score+=roll[i+1]-'0';
	}
	
	if(roll[i+2]=='/'){
	  score+=10-(roll[i+1]-'0');
	}
	else if(roll[i+2]=='X'){
	  score+=10;
	}
	else if(roll[i+2]>='0' && roll[i+2]<='9'){
	  score+=roll[i+2]-'0';
	}
	break;
      }
      else if(roll[i]>='0' && roll[i]<='9'){
	  score+=roll[i]-'0';
      }
      
    }
    
    cout << score << endl;

  }

};

main(){
  Solver solver;

  while(true){
    
    if(solver.read()==false) break;
    solver.work();

  }
  
}
