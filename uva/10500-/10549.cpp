#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

int num_doll;

class Doll_info{
 public:
  int height,diameter,wall;

  Doll_info(){}
  
  Doll_info(int h,int d,int w){
    height = h, diameter = d, wall = w;
  }

  bool isInside(Doll_info &doll){
    if( height - wall*2 >= doll.height && diameter - wall*2 >= doll.diameter )
      return true;
    else return false;
  }

  bool operator < ( const Doll_info &doll) const{
    if(height > doll.height) return true;
    else return false;
  }

};



class Solver{
  
 public:
  
  bool read( vector<Doll_info> &list ){
    
    int height,diameter,wall;

    cin >> num_doll;
    if(num_doll==0) return false;

    list.assign(num_doll*2,Doll_info());

    for(int i=0;i<num_doll*2;i++){
      cin >> height >> diameter >> wall;
      list[i]=Doll_info(height,diameter,wall);
    }
    
    sort(list.begin(),list.end());

    /*
    vector<Doll_info>::iterator i_ret;
    for(i_ret=list.begin();i_ret!=list.end();i_ret++) 
      cout << i_ret->height << ' ';
    cout << endl;
    */

    return true;
	
  }

  bool search_rec(vector<Doll_info> &list, vector<Doll_info> &set1, vector<Doll_info> &set2, int arg){
    /*
    vector<Doll_info>::iterator i_ret;
    cout << '1' << endl;
    for(i_ret=set1.begin();i_ret!=set1.end();i_ret++) 
      cout << i_ret->height << ' ' << i_ret->diameter << ' ' << i_ret->wall << endl;
    cout << endl;
     cout << '2' << endl;
    for(i_ret=set2.begin();i_ret!=set2.end();i_ret++) 
      cout << i_ret->height << ' ' << i_ret->diameter << ' ' << i_ret->wall << endl;
    */
    if(arg==num_doll*2) return true;

    if( set1.empty() || ( (*(set1.end()-1)).isInside(list[arg]) && set1.size()<num_doll ) ){
      
      set1.push_back(list[arg]);
      if(search_rec(list,set1,set2,arg+1) == true ) return true;
      set1.pop_back();
    }
    
    if( set2.empty() || ( (*(set2.end()-1)).isInside(list[arg]) && set2.size()<num_doll ) ){

      set2.push_back(list[arg]);
      if(search_rec(list,set1,set2,arg+1) == true ) return true;
      set2.pop_back();
    }
  
    return false;

  }

  void work(vector<Doll_info> &list){
    
    vector<Doll_info>::iterator i_ret;
    vector<Doll_info> set1,set2;

    search_rec(list,set1,set2,0);

    
    for(i_ret=set1.begin();i_ret!=set1.end();i_ret++) 
      cout << i_ret->height << ' ' << i_ret->diameter << ' ' << i_ret->wall << endl;
    
    cout << '-' << endl;
    
    for(i_ret=set2.begin();i_ret!=set2.end();i_ret++) 
      cout << i_ret->height << ' ' << i_ret->diameter << ' ' << i_ret->wall << endl;

    cout << endl;

    return;
    
  }

};

main(){

  Solver solver;
  vector<Doll_info> list;

  while(1){
    if(solver.read(list)==false) break;
    solver.work(list);
  }

}
