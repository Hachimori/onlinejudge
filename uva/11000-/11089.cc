// num��Fi-Binary number�̕������� fibonacci(leng)<=num<fibonacci(leng+1)
// �ƂȂ�leng�ł���B
//
// num           |  1   2    3    4     5     6     7
// ����          |  1   2    3    3     4     4     4
// fi-binary num |  1  10  100  101  1000  1001  1010
//
// num           |     8      9     10     11     12      13      14  
// ����          |     5      5      5      5      5       6       6  
// fi-binary num | 10000  10001  10010  10100  10101  100000  100001
// 
// 
// �܂��A����5��Fi-binary number�ɒ��ڂ���Ɛ擪��"10"���������̂�
// ����1,2,3��Fi-binary number�Ɠ��������Ƃ��킩��B
//
// �̂ŁA�擪���牽�Ԗڂ�1�������̂��A�Ƃ����v�Z�����ꂼ��̒�����
// Fi-binary number�ɂ����čs�����Ƃ�1��0�̔z�u������ł���B

#include<iostream>
#include<string>
#define FIBONACCI 55  // fib[54] = 8.6*(10^10)
using namespace std;
typedef long long ll;

ll fib[FIBONACCI];

ll rec(int n){
  if(n<=1) return fib[n]=1;
  if(fib[n]!=-1) return fib[n];
  return fib[n]=rec(n-1)+rec(n-2);
}

int num;

void read(){
  cin >> num;
}

void work(){
  int leng = 0;
  while(num>=fib[leng+1]) leng++;
  
  while(num>0){
    int toSub = 0;
    while(num>=fib[toSub+1]) toSub++;
    num -= fib[toSub];
    
    cout << string(leng-toSub,'0') << 1;
    
    if(num>0){
      cout << '0';
      leng = toSub-2;
    }
    else{
      leng = toSub-1;
      cout << string(leng,'0') << endl;
    }
  }
}

int main(){
  for(int i=0;i<FIBONACCI;i++) fib[i] = -1;
  rec(FIBONACCI-1);
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
