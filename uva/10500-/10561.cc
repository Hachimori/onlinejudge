/*
 Grundy number

 Nimのような２人ゲームにおいて、特定の場面において必勝法があるかどうか
 を高速に判定するアルゴリズム。

 「3つの石の積み重なりが与えられ、任意の積み重なりから、整数の累乗個の
 　石を二人が交互にとってゆき、最後に石をとった人が勝ち」というゲームに
 　ついて考える。これは通常のNimに、「任意の石の積み重なりから石をとって良い」
 というルールを加えたものである。
 
 
 はじめに、通常のNimにおけるGrundy-Numberついて説明する。
 
 ゲームの終端の状態（勝負が決まる状態）のGrundy-Numberを0とする。
 終端より前の状態に関して、任意の個数の石をとったときの状態における
 Grundy-Numberの集合をSとする。そのSに含まれない、0以上の最小の数が
 その状態のGrundy-Numberである。
 
 ------Topcoder より抜粋----------
 int grundyNumber(position pos) {
    moves[] = possible positions to which I can move from pos
    set s;
    for (all x in moves) insert into s grundyNumber(x);
 
    int ret=0;
    while (s.contains(ret)) ret++;
    return ret;
 }
 --------------------------------
 
 ある状態においてGrundy-Numberが0でないということは、
 その時の最初のプレイヤーは必勝法があるということである。
 逆にGrundy-Numberが0であるときは、最初のプレイヤーはどのような
 手を使っても負けるということである。
 
 
 変則Nimに関して、3つの石の積み重なりがあることから、通常のNimと一緒にするのは
 難しいと思われるが、1つの石の積み重なりのGrundy-Numberをしらべて、
 3つの状態のGrundy-NumberのXORをとると、その状態において必勝法があるかどうか
 がわかる。XORの結果がOならば必敗、そうでなければ必勝である。
 その原理については、以下のURLにおいて詳しく述べられている。
 
 http://www.topcoder.com/tc?module=Static&d1=tutorials&d2=algorithmGames
 http://sps.nus.edu.sg/~limchuwe/cgt/cgt3.htm


 Treblecross のゲームにおいて、ゲームの途中でサブゲームが発生することから、
 はじめに、任意の長さのボードのGrundy-Numberをしらべ、サブゲームのGrundy-Number
 のXORをとることが正着といえる。
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define BUF 205
using namespace std;

int val[BUF];  // このゲームにおけるgrundy-number

void makeTable(){
  val[0] = 0;
  val[1] = val[2] = 1;

  for(int i=3;i<BUF;i++){
    bool avail[BUF];
    for(int j=0;j<BUF;j++) 
      avail[j] = false;
      
    for(int j=0;j<i;j++){
      int a = max(0,j-2);
      int b = max(0,i-j-3);
      avail[val[a]^val[b]] = true;
    }

    for(int j=0;j<BUF;j++)
      if(!avail[j]){
	val[i] = j;
	break;
      }
  }
}

string init;

void read(){
  cin >> init;
}

char get(string str, int cur){
  for(int i=max(0,cur-2);i<min((int)str.size(),cur+3);i++)
    if(str[i]=='X')
      return 'X';

  return '.';
}

vector<int> check(string str){
  vector<int> ret;

  for(int i=0;i<str.size();i++){
    if(str[i]=='.'){
      str[i] = 'X';
      
      int maxV = 0;
      for(int j=0;j<str.size();j++){
	int cur = j, cnt = 0;
	while(cur<str.size() && str[cur]=='X'){
	  cur++;
	  cnt++;
	}

	maxV = max(maxV,cnt);
	j = cur;
      }
      
      if(maxV>=3)
	ret.push_back(i);
      
      str[i] = '.';
    }
  }
  
  return ret;
}


bool isWin(string str){
  int num = 0;
  for(int i=0;i<str.size();i++){
    int cur = i, cnt = 0;
    while(cur<str.size() && get(str,cur)=='.'){
      cur++;
      cnt++;
    }

    num ^= val[cnt];
    i = cur;
  }
 
  return num==0;
}

void work(){
  vector<int> ans = check(init);

  if(ans.size()==0)
    for(int i=0;i<init.size();i++)
      if(get(init,i)=='.'){
	init[i] = 'X';
	if(isWin(init)) ans.push_back(i);
	init[i] = '.';
      }
  
  if(ans.size()==0)
    cout << "LOSING" << endl << endl;
  else {
    cout << "WINNING" << endl;
    for(int i=0;i<ans.size();i++){
      if(i) cout << ' ';
      cout << ans[i]+1;
    }
    cout << endl;
  }
}

int main(){
  makeTable();

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
