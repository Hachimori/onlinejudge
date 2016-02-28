#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<cstdlib>
#include<set>
#define x first
#define y second
using namespace std;
typedef pair<int,int> Point;
const int BUF = 32767, INF = 1<<30;

Point id2pos[BUF];

void makeTable(){
  for(int i=0,cnt=0;cnt<BUF;i++){
    Point cur = Point(i,0);
    for(int j=0;j<=i && cnt<BUF;j++){
      id2pos[cnt++] = cur;
      cur.x--;
      cur.y++;
    }
  }
}


vector<int> idList;

bool read(){
  idList.clear();
  string s;
  if(!getline(cin,s)) return false;
  stringstream in(s);
  int num;
  while(in >> num) idList.push_back(num-1);
  return true;
}


int getR(vector<Point> pos){
  int r = INF;
  for(int i=0;i<pos.size();i++)
    for(int j=i+1;j<pos.size();j++){
      if(pos[i].x==pos[j].x) r = min(r,abs(pos[i].y-pos[j].y));
      if(pos[i].y==pos[j].y) r = min(r,abs(pos[i].x-pos[j].x));
    }
  return r;
}


bool validTri(){
  if(idList.size()!=3) return false;
  vector<Point> pos;
  for(int i=0;i<3;i++) pos.push_back(id2pos[idList[i]]);
  int r = getR(pos);
  if(r==0) return false;
  for(int self=0;self<3;self++){
    set<Point> S;
    for(int opp=0;opp<3;opp++){
      if(opp==self) continue;
      S.insert(Point(pos[opp].x-pos[self].x,pos[opp].y-pos[self].y));
    }
    if((S.count(Point( r,0)) && S.count(Point(0, r))) ||
       (S.count(Point(-r,0)) && S.count(Point(0,-r))))
      return true;
  }
  return false;
}


bool validPar(){
  if(idList.size()!=4) return false;
  vector<Point> pos;
  for(int i=0;i<4;i++) pos.push_back(id2pos[idList[i]]);
  int r = getR(pos);
  if(r==0) return false;
  for(int self=0;self<4;self++){
    set<Point> S;
    for(int opp=0;opp<4;opp++){
      if(opp==self) continue;
      S.insert(Point(pos[opp].x-pos[self].x,pos[opp].y-pos[self].y));
    }
    if((S.count(Point(r,0)) && S.count(Point( 0,r)) && S.count(Point(-r,  r))) ||
       (S.count(Point(0,r)) && S.count(Point(-r,r)) && S.count(Point(-r,2*r))) ||
       (S.count(Point(r,0)) && S.count(Point( 0,r)) && S.count(Point( r,  r))))
      return true;
  }
  return false;
}


bool validHex(){
  if(idList.size()!=6) return false;
  vector<Point> pos;
  for(int i=0;i<6;i++) pos.push_back(id2pos[idList[i]]);
  int r = getR(pos);
  if(r==0) return false;
  for(int self=0;self<6;self++){
    set<Point> S;
    for(int opp=0;opp<6;opp++){
      if(opp==self) continue;
      S.insert(Point(pos[opp].x-pos[self].x,pos[opp].y-pos[self].y));
    }
    if(S.count(Point(-r,r)) && S.count(Point(-r,2*r)) && S.count(Point(0,2*r)) &&
       S.count(Point( r,r)) && S.count(Point( r,  0)))
      return true;
  }
  return false;
}


void work(){
  for(int i=0;i<idList.size();i++){
    cout << idList[i]+1 << ' ';
  }
  if(validTri())
    cout << "are the vertices of a triangle" << endl;
  else if(validPar())
    cout << "are the vertices of a parallelogram" << endl;
  else if(validHex())
    cout << "are the vertices of a hexagon" << endl;
  else
    cout << "are not the vertices of an acceptable figure" << endl;
}


int main(){
  makeTable();
  while(read()) work();
  return 0;
}
