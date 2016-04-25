// DP
// 
// 
// �푈������Ƃ��́A�U���A������ɐl���̑����ق����L���ł��邩��A
// �R���o�b�g�̍ۂ͏o���邾�������̐퓬��(�������ő�3�l)�𑗂�B
//
//
// �U���A����̐l���ɉ������R���o�b�g�̌��ʂ��e�[�u��pp�ɕۑ�����B
// pp[nAtt][nDef][nAttLost][nDefLose]:   �U���l��: nAtt  ����l��: nDef 
//                                       �̂Ƃ���, 
//                                       �U������nAttLost�l���������A
//                                       �������nDefLost�l���������m���B
// 
//
// �Q�����͈ȉ��̒ʂ�:
// 
// dp[nAtt][nDef] = ���� pp[nAttCombat][nDefCombat][i][j]*dp[nAtt-i][nDef-j];

#include<iostream>
#include<algorithm>
#include<cmath>
#define MAN 1005
#define EPS (1.0e-8)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define GT(x,y) ((x)>=(y)+EPS)
#define GE(x,y) (GT(x,y) || EQ(x,y))
using namespace std;

// nAtt, nDef, nAttLost, nDefLost
double pp[4][4][4][4];

void throwDice(int limitA, int limitD, int curA, int curD, 
	       int diceA[], int diceD[]){
  if(limitD==curD){
    int workA[3], workD[3];
    for(int i=0;i<limitA;i++) workA[i] = diceA[i];
    for(int i=0;i<limitD;i++) workD[i] = diceD[i];
    sort(workA,workA+limitA);
    sort(workD,workD+limitD);
    reverse(workA,workA+limitA);
    reverse(workD,workD+limitD);
    
    int nALost = 0, nDLost = 0;
    for(int i=0;i<min(limitA,limitD);i++)
      if(workA[i]>workD[i]) 
	nDLost++;
      else
	nALost++;

    pp[limitA][limitD][nALost][nDLost] += 1;

    return;
  }
  else if(limitA==curA){
    for(int i=1;i<=6;i++){
      diceD[curD] = i;
      throwDice(limitA,limitD,curA,curD+1,diceA,diceD);
    }
  }
  else{
    for(int i=1;i<=6;i++){
      diceA[curA] = i;
      throwDice(limitA,limitD,curA+1,curD,diceA,diceD);
    }
  }
}

void makeTable(){
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      for(int k=0;k<4;k++)
	for(int l=0;l<4;l++)
	  pp[i][j][k][l] = 0;
  
  for(int na=1;na<=3;na++)
    for(int nd=1;nd<=3;nd++){
      int diceA[3],diceD[3];
      throwDice(na,nd,0,0,diceA,diceD);

      for(int i=0;i<=3;i++)
	for(int j=0;j<=3;j++)
	  pp[na][nd][i][j] /= pow(6.0,1.0*na)*pow(6.0,1.0*nd);
    }
}

int num;

bool read(){
  cin >> num;
  return num!=0;
}

double dp[MAN*3][MAN];

double rec(int nAtt, int nDef){
  if(nAtt<0 || nDef<0) return 0;
  if(GE(dp[nAtt][nDef],0)) return dp[nAtt][nDef];
  if(nAtt==0) return dp[nAtt][nDef] = 0;
  if(nDef==0) return dp[nAtt][nDef] = 1;
  
  double sum = 0;

  for(int i=0;i<=3;i++)
    for(int j=0;j<=3;j++){
      if(i==0 && j==0) continue;
      int nac = min(nAtt,3), ndc = min(nDef,3);
      sum += pp[nac][ndc][i][j]*rec(nAtt-i,nDef-j);
    }
  
  return dp[nAtt][nDef] = sum;
}

void work(){
  for(int i=num;;i++)
    if(GT(rec(i,num),0.5)){
      cout << i+1 << endl;
      break;
    }
}

int main(){
  for(int i=0;i<MAN*3;i++)
    for(int j=0;j<MAN;j++)
      dp[i][j] = -1;
  
  makeTable();

  while(read())
    work();
  
  return 0;
}
