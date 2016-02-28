#include<iostream>


int term;
int bunbo,bunshi;

class Solver{
 public:
  
  bool read(){

    cin >> term;
    if(cin.eof()) return false;

    return true;
  }

  void work(){

    int counter=2;
    bunbo = 2, bunshi = 1;

    if(term==1){
      cout << "TERM 1 IS 1/1" << endl;
      return;
    }

    while(true){
      
      for(;bunbo!=1;bunbo--,bunshi++,counter++){
	if(counter==term){
	  cout << "TERM " << term << " IS " << bunshi << '/' << bunbo << endl;
	  return;
	}
      }      
 
      if(counter==term){
	cout << "TERM " << term << " IS " << bunshi << '/' << bunbo << endl;
	return;
      }
     
      bunshi++;
      counter++;

      if(counter==term){
	cout << "TERM " << term << " IS " << bunshi << '/' << bunbo << endl;
	return;
      }      


      for(;bunshi!=1;bunbo++,bunshi--,counter++){
	if(counter==term){
	  cout << "TERM " << term << " IS " << bunshi << '/' << bunbo << endl;
	  return;
	}
      }
      
      if(counter==term){
	cout << "TERM " << term << " IS " << bunshi << '/' << bunbo << endl;
	return;
      }

      bunbo++;
      counter++;

      if(counter==term){
	cout << "TERM " << term << " IS " << bunshi << '/' << bunbo << endl;
	return;
      }   
      
    }

  }

};

main(){

  Solver solver;

  while(true){
    
    if(solver.read()==false) break;
    solver.work();

  }


}
