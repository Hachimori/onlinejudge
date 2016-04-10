#include<iostream>
#include<vector>
#include<algorithm>

#define MAX_SIZE 1004

using namespace std;

class Fract{
public:

  int nume, deno;
  
  Fract(){}
  Fract(int nume, int deno): nume(nume), deno(deno){}

  bool operator<( const Fract &f ) const {
    return ((double)(nume)/deno <  (double)(f.nume)/f.deno);
  }

};

int n,k;
vector<Fract> fList;


bool read(){
  
  if(!(cin >> n >> k)) return false;
  fList.clear();
  return true;
}

int gcd(int a, int b){
  
  if(b==0) return a;
  else return gcd(b,a%b);
  
}

void makeTable(){

  bool inserted[MAX_SIZE][MAX_SIZE];

  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      inserted[i][j] = false;

  for(int i=n;i>=1;i--){
    for(int j=1;j<=i/2;j++){
      
      if(gcd(i,j)==1 && !inserted[j][i]){
	
	fList.push_back(Fract(j,i));
	inserted[j][i] = true;
      }
      
    }
  }

}

void work(){
  
  makeTable();

  sort(fList.begin(),fList.end());
  /*
  for(int i=0;i<fList.size();i++){
    cout << fList[i].nume << '/' << fList[i].deno << endl;
  }
  */

  if(fList.size()*2==k){
    cout << "1/1" << endl;
    return;
  }
  if(k-1<fList.size())
    cout << fList[k-1].nume << '/' << fList[k-1].deno << endl;
  else
    cout << abs(fList[fList.size()-(k-fList.size())-1].deno-fList[fList.size()-(k-fList.size())-1].nume) << '/' <<
      fList[fList.size()-(k-fList.size())-1].deno << endl;
  
}

int main(){
  
  while(read())
    work();

  return 0;
}
