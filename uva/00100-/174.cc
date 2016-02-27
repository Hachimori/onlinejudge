#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

const int PROGRAM = 11, NODE = 100;

enum COMMAND{IF, THEN, ELSE, AND, OR, EQ, NEQ, 
             NUL, MY, YOUR, LAST, ONE, TWO, TRADE, CHEAT};

class Program{
public:
  int nNode;

  int adj[NODE][2];  // adj[i][0]: if statement is true
                     // adj[i][1]: otherwise

  vector<int> stat[NODE]; // statement

  int cmd[NODE];          // {TRADE|CHEAT}
  
  Program(){
    nNode = 0;
    memset(adj,-1,sizeof(adj));
  }

  int genProgram(int &idx, vector<int> &v){
    int curNode = nNode++;
    if(v[idx]==IF){
      idx++; // IF
      while(v[idx]!=THEN)
        stat[curNode].push_back(v[idx++]);
      idx++; // THEN
      adj[curNode][0] = genProgram(idx,v);
      idx++; // ELSE
      adj[curNode][1] = genProgram(idx,v);
    }
    else
      cmd[curNode] = v[idx++];
    return curNode;
  }
  
  bool judgeState(int &idx, vector<int> &st, vector<int> &sCmd, vector<int> &oCmd){
    vector<int> vec = st[idx]==MY?sCmd:oCmd;

    idx += 2; // MY LAST
    int nPre = st[idx++]-ONE+1; 

    bool ok, reverse = (st[idx++]==NEQ);
    if(st[idx]==NUL){
      idx++; // NULL
      ok = (nPre>vec.size());
    }
    else{
      ok = (nPre<=vec.size()) && (vec[vec.size()-nPre]==st[idx]);
      idx++; // TRADE, CHEAT
    }

    if(reverse) ok = !ok;

    if(idx<st.size() && st[idx]==AND){
      idx++;
      return ok && judgeState(idx,st,sCmd,oCmd);
    }
    else if(idx<st.size() && st[idx]==OR){
      idx++;
      return ok || judgeState(idx,st,sCmd,oCmd);
    }
    else
      return ok;
  }
  
  int run(vector<int> &sCmd, vector<int> &oCmd){
    int curr = 0;
    while(1){
      if(adj[curr][0]==-1) return cmd[curr];
      int idx = 0;
      if(judgeState(idx,stat[curr],sCmd,oCmd))
        curr = adj[curr][0];
      else
        curr = adj[curr][1];
    }
  }
};

vector<string> read(){
  vector<string> ret;
  while(1){
    string toPush;
    while(1){
      string s;
      cin >> s;
      if(s=="#") return ret;
      toPush += s;
      if(s[s.size()-1]=='.') break;
    }
    ret.push_back(toPush.substr(0,toPush.size()-1));
  }
}

vector<int> parse(string s){
  static string cmd[15] = {"I","TH","E","A","O","=","#","N","M",
                           "Y","L","1","2","TR","C"};
  static int togo[15] = {2,4,4,3,2,1,1,4,2,4,4,1,1,5,5};
  
  vector<int> ret;
  int idx = 0;
  while(idx<s.size()){
    for(int i=0;i<15;i++)
      if(cmd[i]==s.substr(idx,cmd[i].size())){
        ret.push_back(i);
        idx += togo[i];
        break;
      }
  }
  return ret;
}

int calc(Program self, Program opp){
  vector<int> sCmd, oCmd;
  for(int i=0;i<10;i++){
    int s = self.run(sCmd,oCmd);
    int o = opp.run(oCmd,sCmd);
    sCmd.push_back(s);
    oCmd.push_back(o);
  }
  int sum = 0;
  for(int i=0;i<10;i++){
    if(sCmd[i]==TRADE && oCmd[i]==TRADE) sum += 1;
    if(sCmd[i]==TRADE && oCmd[i]==CHEAT) sum -= 2;
    if(sCmd[i]==CHEAT && oCmd[i]==TRADE) sum += 2;
    if(sCmd[i]==CHEAT && oCmd[i]==CHEAT) sum -= 1;
  }
  return sum;
}

void work(vector<string> st){
  Program program[PROGRAM];

  for(int i=0;i<st.size();i++){
    vector<int> v = parse(st[i]);
    Program p = Program(); 
    int idx = 0;
    program[i].genProgram(idx,v);
  }

  int sum[PROGRAM] = {0};
  for(int i=0;i<st.size();i++)
    for(int j=i+1;j<st.size();j++){
      sum[i] += calc(program[i],program[j]);
      sum[j] += calc(program[j],program[i]);
    }

  for(int i=0;i<st.size();i++)
    printf("%3d\n",sum[i]);
}

int main(){
  work(read());
  return 0;
}
