// �S�T�� + ���͂Ȏ}���
//
// 
// �}���P�A�s���Ɨ񐔂��݂��ɑf�Ȃ�΁A��ڂ�queen�ł��ׂẴ}�X�����܂�B
//           ����� (gcd(column,row)==1 && nQueen>1 �Ȃ�� "0 0" ���o�́B
//
// �}���Q�A�ŏ��̈�ڂ�queen�͈��ڂɒu���Ȃ�΂ǂ��ɂ����Ă������B
//           ����āA��ڂ�queen�͈ʒu���Œ肷��B
//
//
// �}���Q�́A�����������Ƃ�����
//
// 4*8 �̍s��ɂ����� 1�s1��ɒu�����Ƃ�
//
// ����������������
// ����������������
// ����������������
// ����������������
//
// 4*8 �̍s��ɂ����� 2�s1��ɒu�����Ƃ�
//
// ����������������
// ����������������
// ����������������
// ����������������
// 
// ���̂悤�ɁA�s�S�̂����Ɉ�s�V�t�g���邱�ƂƓ����ł���B 

#include<iostream>

#define MAX_SIZE 15

using namespace std;

class Point{
public:

  int r, c;
  
  Point(){}
  Point(int r, int c): r(r), c(c){}
};

int row, column, nQueen;

bool read(){
  if(!(cin >> column >> row >> nQueen)) return false;
  
  return true;
}

bool rec(int c, int nPut, bool isAvail[][MAX_SIZE], Point putList[]){
  

  static const int dr[3]={1,0,-1};
  
  /*
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      cout << !isAvail[i][j];
    }cout << endl;
  }cout<<endl;
  */
  
  
  if(nPut==nQueen) return true;
  if(c==column) return false;
  if(column-c<nQueen-nPut) return false;
  
  int limit;
  if(c==0) limit = 1;
  else limit = row;
  
  for(int i=0;i<limit;i++){
    if(!isAvail[i][c]) continue;
    
    bool next[MAX_SIZE][MAX_SIZE];

    for(int j=0;j<row;j++)
      for(int k=0;k<column;k++)
	next[j][k] = isAvail[j][k];
    
    for(int j=0;j<3;j++){
      int currR=(i+dr[j]+row)%row, currC=c+1;
      while(!(currR==i && currC==c)){
	next[currR][currC] = false;
	currR = (currR+dr[j]+row)%row;
	currC = (currC+1)%column;
      }
    }
    
    putList[nPut] = Point(i,c);
    if(rec(c+1,nPut+1,next,putList)) return true;
    
  }

  if(rec(c+1,nPut,isAvail,putList)) return true;

  return false;
}

int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b,a%b);
}

void work(){
  
  Point putList[MAX_SIZE];
  bool isAvail[MAX_SIZE][MAX_SIZE];
  
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++)
      isAvail[i][j] = true;
  
  if( !(gcd(column,row)==1 && nQueen>1) && rec(0,0,isAvail,putList))
    for(int i=0;i<nQueen;i++)
      cout << putList[i].c+1 << ' ' << putList[i].r+1 << endl;
  else
    cout << 0 << ' ' << 0 << endl;
  
}

int main(){

  while(read())
    work();

  return 0;
}
