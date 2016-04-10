#include<iostream>
#include<string>

#define MAX_OPE 1030
#define MAX_SIZE 7
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

class Element{
public:

  int t, n, w;

  Element(){}
  Element(int t, int n, int w): t(t), w(w), n(n) {}
  
};

int nOpe;
string opeList[MAX_OPE];
Element graph[MAX_SIZE][MAX_SIZE][MAX_SIZE][4];   // top, north, west, direction

void createGraph(){
  
  for(int i=1;i<MAX_SIZE;i++){
        
    for(int j=1;j<MAX_SIZE;j++){
      if(j==i) continue;
      
      for(int k=1;k<MAX_SIZE;k++){
	if(k==i || k==j) continue;
	
	for(int d=0;d<4;d++){
	
	  if(d==NORTH)
	    graph[i][j][k][d]=Element(7-j,i,k);
	  if(d==EAST)
	    graph[i][j][k][d]=Element(k,j,7-i);
	  if(d==SOUTH)
	    graph[i][j][k][d]=Element(j,7-i,k);
	  if(d==WEST)
	    graph[i][j][k][d]=Element(7-k,j,i);
	  
	}
	
      }

    }

  }

}

bool read(){

  cin >> nOpe;
  if(nOpe==0) return false;

  for(int i=0;i<nOpe;i++)
    cin >> opeList[i];

  return true;
}

void work(){
  
  Element curr=Element(1,2,3);
  
  for(int i=0;i<nOpe;i++)
    if(opeList[i]=="north")
      curr = graph[curr.t][curr.n][curr.w][0];
    else if(opeList[i]=="east")
      curr = graph[curr.t][curr.n][curr.w][1];
    else if(opeList[i]=="south")
      curr = graph[curr.t][curr.n][curr.w][2];
    else if(opeList[i]=="west")
      curr = graph[curr.t][curr.n][curr.w][3];
  
  cout << curr.t << endl;
}

int main(){
  
  createGraph();

  while(read())
    work();
  
  return 0;
}
