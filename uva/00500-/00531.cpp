#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<limits.h>

class Graph{
 public:
  vector<vector<int> > adjList;
  vector<vector<int> > list;
  map<int,string> word_map;

  Graph(){}

  Graph(int n){
    list.assign(n,vector<int>()); 
    adjList.assign(n,vector<int>()); 
   
  }  

};

void bfs(Graph g){

  int pos;
  int max_point=0,tmp_max;
  bool first,first_first=true,first_first_first=true;;
  
  for(pos=g.adjList.size()-1;pos>=0;pos--){
   
    if(g.adjList[pos][0]!=-1){
      g.list[pos].assign(g.adjList[pos].size(),-1);
      for(int j=g.adjList[pos].size()-1;j>=0;j--){
	
	if(first_first==true && g.adjList[pos][j]>=0){ 
	  g.list[pos][j]=1;
	  max_point++;
	  tmp_max=0;
	}
	
	if(g.adjList[pos][j]>=0 && first_first!=true){
	  if(first==true){ tmp_max=INT_MIN; first=false; }

	  for(int k=pos+1;k<g.adjList.size();k++){
	    
	    if(g.adjList[k][0]!=-1)
	      for(int l=0;l<g.adjList[k].size();l++){
		if(g.adjList[pos][j]<g.adjList[k][l] && tmp_max<g.list[k][l]) tmp_max=g.list[k][l];
	      }
	  }

	}
	
	if(tmp_max!=INT_MIN) g.list[pos][j] = tmp_max+1;
	else  g.list[pos][j] = 1;
	first=true; 
	  
      }
    }
    else{ g.list[pos].assign(g.adjList[pos].size(),-1); g.list[pos][0] = 0; continue; }
    first_first=false;
  }

  /*
  for(int i=0;i<g.adjList.size();i++){ cout <<i;
    for(int j=0;j<g.list[i].size();j++){
      cout <<' '<< g.list[i][j] << ' ';
    }cout << endl;
  }
  cout << endl;
  */

  for(int i=0;i<g.adjList.size();i++)
    for(int j=0;j<g.list[i].size();j++) if(g.list[i][j]>max_point) max_point = g.list[i][j];

  for(int i=0;i<g.adjList.size();i++){
    for(int j=0;j<g.list[i].size();j++){
      if(g.list[i][j]==max_point && first_first_first!=true){ cout << ' ' << g.word_map[i]; max_point--;}
      else if(g.list[i][j]==max_point && first_first_first==true){ cout << g.word_map[i]; max_point--; first_first_first=false;}
    }
  }
  cout << endl;

  return;
  
}
          

bool Input(void);
void Work(map<int,string>,map<int,string>);

main(){
  while(1){
    if(Input()==false) break;
  }
}
                 
bool Input(void){

  map<int,string> word_idx;
  map<int,string> word_idx2;
  typedef map<int,string>::value_type VT;

  string word;

  for(int i=0;;i++){

    cin >> word;
    if(cin.eof()) return false;
    if(word=="#") break;
    
    word_idx.insert(VT(i,word));
    
  }

  for(int i=0;;i++){

    cin >> word;
    if(cin.eof()) return false;
    if(word=="#") break;

    word_idx2.insert(VT(i,word) );
    
  } 

  /*
  for(int i=0;i<word_idx.size();i++){
    cout << word_idx[i] << " ";
  } cout << endl;
  for(int i=0;i<word_idx2.size();i++){
    cout << word_idx2[i] << " ";
  } cout << endl;
  */

  if(word_idx.size()<word_idx2.size()) Work(word_idx,word_idx2);
  else Work(word_idx2,word_idx);

  return true;

}

void Work(map<int,string> word_idx, map<int,string> word_idx2){

  bool flg;
  Graph g(word_idx.size());
  
  for(int i=0;i<word_idx.size();i++){
    flg = false;
    
    for(int j=0;j<word_idx2.size();j++){
      if(word_idx[i]==word_idx2[j]){ g.adjList[i].push_back(j); flg=true;}
    }
    if(flg==false) g.adjList[i].push_back(-1);
    
  }

  g.word_map = word_idx;

  //cout << word_idx[21] << " " <<word_idx2.size() << endl ;
  /*
  for(int i=0;i<g.adjList.size();i++){
    for(int j=0;j<g.adjList[i].size();j++){
      cout << g.adjList[i][j] << " ";
    } cout << endl;
  } cout << endl;
  */  

  bfs(g);

  return;
}
