#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cassert>
#define LINE 10000
using namespace std;

char dirs[8][3]={"N","NE","E","SE","S","SW","W","NW"};
int dr[]={-1,-1,0,1,1,1,0,-1}, dc[]={0,1,1,1,0,-1,-1,-1};

int nLine, r, c, dir;
string line[LINE];

bool read(){
  char ch1, ch2;
  cin >> ch1 >> c >> ch2;
  if(ch1=='E') return false;
  if(ch2=='W') c *= -1;
  cin >> ch1 >> r >> ch2;
  if(ch2=='N') r *= -1;

  string s;
  cin >> s;

  for(dir=0;;dir++)
    if(strcmp(dirs[dir],s.c_str())==0)
      break;

  getline(cin,s);
  for(nLine=0;;){
    getline(cin,s);
    string t;
    stringstream in(s);
    in >> t;
    if(t=="STOP" && !(in>>t)) break;
    line[nLine++] = s;
  }

  return true;
}

bool exist(int next){
  if(!(-50<=r+dr[next] && r+dr[next]<=50 &&
       -50<=c+dc[next] && c+dc[next]<=50)) return false;
  

  /*
  if(r==-50 && (next==0 || next==1 || next==7)) return false;
  if(r== 50 && (next==3 || next==4 || next==5)) return false;
  if(c==-50 && (next==5 || next==6 || next==7)) return false;
  if(c== 50 && (next==1 || next==2 || next==3)) return false;
  */

  if(abs(r)%50==0 && abs(c)%50==0)  // on circle
    return true;

  if(abs(r)==25 && abs(c)==25)  // on cross
    return true;

  // on diagonal line1
  if(r==c)
    return next!=1 && next!=5;

  // on diagonal line2
  if(r==-c)
    return next!=3 && next!=7;

  // on normal diagonal line1
  if(abs(r-c)==50)
    return next!=1 && next!=5;

  // on normal diagonal line2
  if(abs(r+c)==50)
    return next!=3 && next!=7;

  return next%2==0;
}

/*
bool exist(int next){ 
  assert(-50<=r && r<=50 && -50<=c && c<=50);
  if(abs(r)%50==0 && abs(c)%50==0)  // on circle
    return true;

  if(abs(r)%50==25 && abs(c)%50==25)  // on cross
    return true;

  // on diagonal line1
  if(r==c)
    return next!=1 && next!=5;

  // on diagonal line2
  if(r==-c)
    return next!=3 && next!=7;

  // on normal diagonal line1
  if(abs(r-c)%50==0)
    return next!=1 && next!=5;

  // on normal diagonal line2
  if(abs(r+c)%50==0)
    return next!=3 && next!=7;


  return next%2==0;
} 
*/
bool valid(int turn, int prev, int next){
  if(!exist(next)) return false;
  
  if(abs(r)%50==0 && abs(c)%50==0)  // on circle
    return true;

  // on diagonal line1
  if(r==c){ 
    // enter|exit way
    if(turn==-3) return true;

    // go normal road
    if(!(prev==3||prev==7)){
      if(next==3 || next==7) return false;
      else return true;
    }

    return false;
  }

  // on diagonal line2
  if(r==-c){ 
    // enter|exit way
    if(turn==-3) return true;

    // go normal road
    if(!(prev==1||prev==5)){
      if(next==1 || next==5) return false;
      else return true;
    }

    return false;
  }
  
  // on horizontal line
  if(abs(r)%50==0){
    // enter|exit way
    if(turn==-2) return true;

    // go normal road
    if(!(prev==2||prev==6)){
      if(next==2 || next==6) return false;
      else return true;
    }
    
    return false;
  }

  // on vertical line
  if(abs(c)%50==0){
    // enter|exit way
    if(turn==-2) return true;

    // go normal road
    if(!(prev==0||prev==4)){
      if(next==0 || next==4) return false;
      else return true;
    }
    
    return false;
  }
  
  return true;
}

string result(){
  assert(-50<=r && r<=50 && -50<=c && c<=50); // does not happens
  if(!exist(dir)){ // does not happens
    assert(false);
    //return "Illegal stopping place";
  }
  /*
  if(abs(r)%50==0 && abs(c)%50==0){  // on circle
    //assert(false); // this happens
    return "Illegal stopping place";
    stringstream out;
    out << 'A' << abs(c) << (c<0?'W':'E') << ' ' 
        << 'S' << abs(r) << (r<=0?'N':'S') << ' '
        << dirs[dir];
    
    return out.str();
    }*/

  // on diagonal line1
  if(r==c && (dir==3 || dir==7)) return "Illegal stopping place";

  // on diagonal line2
  if(r==-c && (dir==1 || dir==5)) return "Illegal stopping place";

  // on horizontal line
  if(abs(r)%50==0 && (dir==2 || dir==6)) return "Illegal stopping place";

  // on vertical line
  if(abs(c)%50==0 && (dir==0 || dir==4)) return "Illegal stopping place";

  stringstream out;
  out << 'A' << abs(c) << (c<0?'W':'E') << ' ' 
      << 'S' << abs(r) << (r<=0?'N':'S') << ' '
      << dirs[dir];

  return out.str();
}

void work(){
  if(!exist(dir)){ // never happen
    assert(false);
    cout << "Illegal stopping place" << endl;
    return;
  }

  for(int k=0;k<nLine;k++){
    stringstream in(line[k]);
    //cout << r << ' ' << c << ' ' << dir << endl;
    string s;
    if(!(in >> s)) continue;
    
    if(s=="TURN"){
      if(!(in >> s)) continue;;
      int add = 2;
      if(s=="HALF"){ 
        add = 1; 
        if(!(in >> s)) continue;
      }
      else if(s=="SHARP"){
        add = 3;
        if(!(in >> s)) continue;
      }

      if(s=="LEFT") add *= -1;
      else if(s=="RIGHT"); 
      else continue;

      if(in>>s) continue;

      int next = (dir+8+add)%8;
      
      r += dr[dir];
      c += dc[dir];
      if(valid(add,dir,next))
        dir = next;
      else{
        r -= dr[dir];
        c -= dc[dir];
      }
    }
    else if(s=="GO"){
      if(!(in >> s)) continue;
      if(s=="STRAIGHT") 
        if(!(in >> s))
          continue;
      
      bool ok = true;
      for(int i=0;i<s.size();i++)
        if(!isdigit(s[i]))
          ok = false;

      int n = atoi(s.c_str());
      if(!ok || in >> s || n>=100) continue;
      //cout << r << ' ' << c << ' ' << n << "jjj" << endl;
      r += n*dr[dir];
      c += n*dc[dir];
      //cout << r << ' ' << c << ' ' << n << "jjj" << endl;
    }
  }
  
  cout << result() << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
