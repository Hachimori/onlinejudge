#include<iostream>
#include<string>

#define MAX 500

int cases;
int num_piece;
int height;
int height_left_piece[MAX],height_right_piece[MAX];

class Solver{
 public:

  bool read(){

    cin >> height;
    if(cin.eof()) return false;


    return true;
  }

  void work(){

    int searcher;
    string tower[MAX];

    for(searcher=1;searcher*(searcher+1)/2<=height;searcher++){} 
    num_piece = searcher-1;
    

    for(int i=0;i<num_piece;i++){
      if(i==num_piece-1) height_left_piece[i] = height-num_piece*(num_piece-1)/2;
      else height_left_piece[i] = i+1;
    }

    for(int i=0;i<num_piece-1;i++){
      if(i==num_piece-2) height_right_piece[i] = height-(num_piece-1)*(num_piece-2)/2;
      else height_right_piece[i] = i+1;
    }    

    /*    
    for(int i=0;i<num_piece-1;i++)
      cout << "left = " << height_left_piece[i] << "   right = " << height_right_piece[i] << endl;
    cout << endl;
    */
    
    for(int arg=0,curr_height=height-1,curr_piece=num_piece;curr_height>=0;arg++,curr_piece--){
      
      int num_space=(curr_piece-1)*2;

      for(int piece_height=0;piece_height<height_left_piece[arg];piece_height++,curr_height--){
	for(int i=0;i<num_space;i++) tower[curr_height]+=" ";
	
	tower[curr_height]+="#";
	if(piece_height==0){ 
	  tower[curr_height]+="**";
	}
	else tower[curr_height]+="..";
	
	int num_dot = arg*2;
	for(int i=0;i<num_dot;i++) tower[curr_height]+='.';
      }

    }
    
    for(int arg=0,curr_height=height-1;curr_height>=0;arg++){
      
      for(int piece_height=0;piece_height<height_right_piece[arg];piece_height++,curr_height--){
	
	int num_dot = arg*2;
	for(int i=0;i<num_dot;i++) tower[curr_height]+='.';
	
	if(piece_height==0){ 
	  tower[curr_height]+="**";
	}
	else tower[curr_height]+="..";
	
	tower[curr_height]+="#";

      }

    }
    
    cout << "Tower #" << cases << endl;
    for(int curr_height=height-1;curr_height>=0;curr_height--)
      cout << tower[curr_height] << endl;

    cout << endl;

  }

};


main(){
  Solver solver;

  for(cases=1;;cases++){
    if(solver.read()==false) break;
    solver.work();
  }

}
