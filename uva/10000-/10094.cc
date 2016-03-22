#include<iostream>
#include<vector>

#define MAX_SIZE 1001

using namespace std;

vector< vector<int> > table;
int size;

void createTable(){

  table.push_back(vector<int>());
  table.push_back(vector<int>());
  table.push_back(vector<int>());
  table.push_back(vector<int>());
  
  for(int i=4;i<1001;i++){
    
    if(i%2==1){      
      vector<int> tmp = table[i-1];
      
      tmp.push_back(i-1);
      
      table.push_back(tmp);
    }
    else if((i-4)%6==0 || i%6==0){      
      vector<int> tmp;

      for(int j=1;j<i;j+=2)
	tmp.push_back(j);
      
      for(int j=0;j<i;j+=2)
	tmp.push_back(j);
      
      table.push_back(tmp);
    }
    else {
      vector<int> tmp;
      vector<int> tmp2;

      for(int j=(i-1)/2,k=0;k<i/2;k++,j+=2)
	tmp.push_back(j%i);
      
      for(int j=i/2,k=0;k<i/2;k++,j-=2)
	tmp2.push_back((j+i)%i);
      
      for(int j=tmp2.size()-1;j>=0;j--)
	tmp.push_back(tmp2[j]);

      table.push_back(tmp);
    }

    
  }

}

bool read(){
  if(!(cin >> size)) return false;
  return true;
}

void work(){
  /*
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(table[size][j]==i) cout << "#";
      else cout << '-';
    }cout << endl;
  }cout << endl;
  */
  if(table[size].size()==0) cout << "Impossible" << endl;
  else {
    for(int i=0;i<table[size].size();i++){
      if(i==0) cout << table[size][i]+1;
      else cout << ' ' << table[size][i]+1;
    }cout << endl;
  }
  
}

int main(){

  createTable();

  while(read())
    work();

  return 0;
}
