// Greedy
//
// �Ō�̎Ԃ�K��capacity�̎Ԃƈꏏ�ɉ^�Ԃ��Ƃ��l����B
// 
// ������O�̎Ԃ����́Acapacity���^�Ԃ��A
// nCar%capacity!=0 �Ȃ��1�x����nCar%capacity�̎Ԃ��^�ԁB

#include<iostream>

#define MAX_SIZE 1445

using namespace std;

int capacity, cost, nCar;
int car[MAX_SIZE];

void read(){
  cin >> capacity >> cost >> nCar;
  
  for(int i=0;i<nCar;i++)
    cin >> car[i];
}

void work(){
  int currTime=0, idx=0, carStack=0, nSent=0;
  bool isFirst;
  
  if(nCar%capacity==0) isFirst = false;
  else isFirst = true;

  while(nSent<nCar){
    if(isFirst){
      currTime = car[idx];
      
      idx++;
      carStack++;
      
      if(carStack==nCar%capacity){
	carStack = 0;
	nSent += nCar%capacity;
	currTime += cost*2;
	isFirst = false;
      }
      continue;
    }
    
    while(idx<nCar && currTime>=car[idx]){
      idx++;
      carStack++;
    }

    if(carStack>=capacity){
      carStack -= capacity;
      nSent += capacity;
      currTime += cost*2;
    }
    else{
      currTime = car[idx];
      idx++;
      carStack++;
    }
      
  }
  
  currTime -= cost;

  if(nCar%capacity==0)
    cout << currTime << ' ' << nCar/capacity << endl;
  else
    cout << currTime << ' ' << nCar/capacity+1 << endl;
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
