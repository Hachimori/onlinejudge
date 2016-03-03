// knapsack
//
// MAX_BUF �� �R�C���̍ő�̖���*�R�C���̍ő�̉��l/2�ł悢�B
// ����� 100*500/2 = 25005 �ƂȂ�B
// 
// �Ȃ������ōςނ̂��Ƃ����ƁA����̎�蕪�����l�̍��v����
// �������Ƃł�������̎�蕪�����܂�A���l�̍��v�̔������J�o�[�����
// ����̎�蕪�Ƃ�������̎�蕪�̑S�Ă̑g�ݍ��킹�����߂��邩��B


#include<iostream>

#define MAX_SIZE 105
#define MAX_BUF 25005

using namespace std;

int nCoin, coin[MAX_SIZE];
bool isAvail[MAX_SIZE][MAX_BUF];

void read(){
  cin >> nCoin;
  
  for(int i=0;i<nCoin;i++)
    cin >> coin[i];
}

void work(){
  int sum = 0;
  for(int i=0;i<nCoin;i++)
    sum += coin[i];
  
  for(int i=0;i<nCoin+1;i++)
    for(int j=0;j<=sum/2;j++)
      isAvail[i][j] = false;
  
  isAvail[0][0] = true;
  
  for(int curr=0;curr<nCoin;curr++){
    for(int val=0;val<=sum/2;val++){
      if(!isAvail[curr][val]) continue;
      
      isAvail[curr+1][val] = true;
      
      if(val+coin[curr]<=sum/2)
	isAvail[curr+1][val+coin[curr]] = true;
    }
  }
  
  int maxVal = 0;
  for(int i=0;i<=sum/2;i++)
    if(isAvail[nCoin][i])
      maxVal = i;

  cout << (sum-maxVal)-maxVal << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
