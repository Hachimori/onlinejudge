/*
 Grundy number

 Nim�̂悤�ȂQ�l�Q�[���ɂ����āA����̏�ʂɂ����ĕK���@�����邩�ǂ���
 �������ɔ��肷��A���S���Y���B

 �u3�̐΂̐ςݏd�Ȃ肪�^�����A�C�ӂ̐ςݏd�Ȃ肩��A�����̗ݏ��
 �@�΂��l�����݂ɂƂ��Ă䂫�A�Ō�ɐ΂��Ƃ����l�������v�Ƃ����Q�[����
 �@���čl����B����͒ʏ��Nim�ɁA�u�C�ӂ̐΂̐ςݏd�Ȃ肩��΂��Ƃ��ėǂ��v
 �Ƃ������[�������������̂ł���B
 
 
 �͂��߂ɁA�ʏ��Nim�ɂ�����Grundy-Number���Đ�������B
 
 �Q�[���̏I�[�̏�ԁi���������܂��ԁj��Grundy-Number��0�Ƃ���B
 �I�[���O�̏�ԂɊւ��āA�C�ӂ̌��̐΂��Ƃ����Ƃ��̏�Ԃɂ�����
 Grundy-Number�̏W����S�Ƃ���B����S�Ɋ܂܂�Ȃ��A0�ȏ�̍ŏ��̐���
 ���̏�Ԃ�Grundy-Number�ł���B
 
 ------Topcoder ��蔲��----------
 int grundyNumber(position pos) {
    moves[] = possible positions to which I can move from pos
    set s;
    for (all x in moves) insert into s grundyNumber(x);
 
    int ret=0;
    while (s.contains(ret)) ret++;
    return ret;
 }
 --------------------------------
 
 �����Ԃɂ�����Grundy-Number��0�łȂ��Ƃ������Ƃ́A
 ���̎��̍ŏ��̃v���C���[�͕K���@������Ƃ������Ƃł���B
 �t��Grundy-Number��0�ł���Ƃ��́A�ŏ��̃v���C���[�͂ǂ̂悤��
 ����g���Ă�������Ƃ������Ƃł���B
 
 
 �ϑ�Nim�Ɋւ��āA3�̐΂̐ςݏd�Ȃ肪���邱�Ƃ���A�ʏ��Nim�ƈꏏ�ɂ���̂�
 ����Ǝv���邪�A1�̐΂̐ςݏd�Ȃ��Grundy-Number������ׂāA
 3�̏�Ԃ�Grundy-Number��XOR���Ƃ�ƁA���̏�Ԃɂ����ĕK���@�����邩�ǂ���
 ���킩��BXOR�̌��ʂ�O�Ȃ�ΕK�s�A�����łȂ���ΕK���ł���B
 ���̌����ɂ��ẮA�ȉ���URL�ɂ����ďڂ����q�ׂ��Ă���B
 
 http://www.topcoder.com/tc?module=Static&d1=tutorials&d2=algorithmGames
 http://sps.nus.edu.sg/~limchuwe/cgt/cgt3.htm


 Treblecross �̃Q�[���ɂ����āA�Q�[���̓r���ŃT�u�Q�[�����������邱�Ƃ���A
 �͂��߂ɁA�C�ӂ̒����̃{�[�h��Grundy-Number������ׁA�T�u�Q�[����Grundy-Number
 ��XOR���Ƃ邱�Ƃ������Ƃ�����B
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define BUF 205
using namespace std;

int val[BUF];  // ���̃Q�[���ɂ�����grundy-number

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
