#include<iostream>
#include<string>
#include<vector>
#include<cassert>
#define OPE 5000
#define PEOPLE 30
#define ITEM 15
#define COLOR 1000
#define SAME 0
#define SET 1
#define NOT 2
#define UNKNOWN -1
using namespace std;

class Ope{
public:
  int type, color, item;
  vector<int> men;
  
  Ope(){}
  Ope(int t, int c, int i, vector<int> m):
    type(t), color(c), item(i), men(m){}
};

class Group{
public:
  int f[PEOPLE];
  
  Group(){}
  Group(int n){
    for(int i=0;i<n;i++)
      f[i] = i;
  }

  int find(int n){
    return (f[n]==n ? n : f[n]=find(f[n]));
  }
  
  void merge(int a, int b){
    f[find(a)] = find(b);
  }
};

int nMen, nItem, nColor, nOpe;
Ope ope[OPE];

vector<string> split(string &s){
  vector<string> ret;
  int cur = 0;

  while(cur<s.size()){
    string toPush;
    while(cur<s.size() && s[cur]==' ') cur++;
    while(cur<s.size() && s[cur]!=' ') toPush+=s[cur++];
    if(toPush.size()>0) ret.push_back(toPush);
  }
  
  return ret;
}

void read(){
  cin >> nMen >> nItem >> nColor >> nOpe;
  assert(nColor<COLOR);
  assert(nOpe<OPE);
  string dummy; getline(cin,dummy);
  
  for(int i=0;i<nOpe;i++){
    string str; getline(cin,str);
    vector<string> sList = split(str);

    int type, item, color;    
    vector<int> v;
    

    if(sList[0]=="Same"){
      type = SAME;
      item = atoi(sList[4].c_str());
      color = -1;
      for(int j=6;j<sList.size();j++)
	v.push_back(sList[j][0]-'A');
    }
    else if(sList[0]=="Colour"){
      type = SET;
      item = atoi(sList[4].c_str());
      color = atoi(sList[1].c_str());
      for(int j=6;j<sList.size();j++)
	v.push_back(sList[j][0]-'A');
    }
    else if(sList[0]=="Not"){
      type = NOT;
      item = atoi(sList[5].c_str());
      color = atoi(sList[2].c_str());
      for(int j=7;j<sList.size();j++)
	v.push_back(sList[j][0]-'A');
    }
    ope[i] = Ope(type,color,item,v);
  }
}

bool setColor(Group group[], bool setY[][ITEM][COLOR], 
	      bool setN[][ITEM][COLOR], int color[][ITEM]){
  
  for(int i=0;i<nItem;i++)
    for(int j=0;j<nMen;j++)
      for(int k=0;k<nMen;k++){
	if(group[i].find(j)!=group[i].find(k)) continue;
	for(int l=0;l<nColor;l++){
	  setY[k][i][l] |=  setY[j][i][l];
	  setN[k][i][l] |=  setN[j][i][l];
	}
      }
      
  for(int i=0;i<nMen;i++){
    for(int j=0;j<nItem;j++){
      color[i][j] = UNKNOWN;
      vector<int> possible;

      for(int k=0;k<nColor;k++){
	if(setY[i][j][k] && setN[i][j][k]) return false;
	if(setY[i][j][k]){
	  if(color[i][j]!=UNKNOWN) return false;
	  color[i][j] = k;
	}
	if(!setN[i][j][k])
	  possible.push_back(k);
      }
      
      if(color[i][j]==UNKNOWN && possible.size()==1)
	color[i][j] = possible[0]; 
    }
  }

  return true;
}

void work(){
  Group group[ITEM];
  bool setY[PEOPLE][ITEM][COLOR], setN[PEOPLE][ITEM][COLOR];

  for(int i=0;i<nItem;i++)
    group[i] = Group(nMen);
  
  for(int i=0;i<nMen;i++)
    for(int j=0;j<nItem;j++)
      for(int k=0;k<nColor;k++)
	setY[i][j][k] = setN[i][j][k] = false;

  for(int i=0;i<nOpe;i++){
    int &col = ope[i].color, &item = ope[i].item;
    vector<int> &v = ope[i].men;
    
    switch(ope[i].type){
    case SAME:
      for(int j=1;j<v.size();j++)
	group[item].merge(v[0],v[j]);
      break;
    case SET:
      for(int j=0;j<v.size();j++)
	setY[v[j]][item][col] = true;
      break;
    case NOT:
      for(int j=0;j<v.size();j++)
	setN[v[j]][item][col] = true;
      break;
    }
  }
  
  int color[PEOPLE][ITEM];
  if(!setColor(group,setY,setN,color)) cout << "Contradiction" << endl;
  else
    for(int i=0;i<nMen;i++){
      cout << (char)(i+'A');
      for(int j=0;j<nItem;j++)
	if(color[i][j]==UNKNOWN)
	  cout << " ?";
	else
	  cout << ' ' << color[i][j];
      cout << endl;
    }
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  
  return 0;
}
