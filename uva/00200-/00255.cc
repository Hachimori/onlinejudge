#include<iostream>
using namespace std;

int K, Q, newQ;
int kR, kC, qR, qC, nexQR, nexQC;

bool read(){
  if(!(cin >> K >> Q >> newQ)) return false;
  kR = K/8, kC = K%8;
  qR = Q/8, qC = Q%8;
  nexQR = newQ/8, nexQC = newQ%8;
  return true;
}

void work(){
  if(kR==qR && kC==qC){
    cout << "Illegal state" << endl;
    return;
  }

  if((qR==nexQR && qC==nexQC) || (qR!=nexQR && qC!=nexQC) || 
     (qR==kR && ((qC<=kC && kC<=nexQC) || nexQC<=kC && kC<=qC)) ||
     (qC==kC && ((qR<=kR && kR<=nexQR) || nexQR<=kR && kR<=qR))){
    cout << "Illegal move" << endl;
    return;
  }
  
  // king‚Ì—×‚Ì’Ê‰ß‚ð‹–‚µ‚Ä‚¢‚é
  if(abs(kR-nexQR)+abs(kC-nexQC)<=1){
    cout << "Move not allowed" << endl;
    return;
  }

  if((K==0 && newQ==9) || (K==7 && newQ==14) || 
     (K==56 && newQ==49) || (K==63 && newQ==54)){
    cout << "Stop" << endl;
    return;
  }
  
  cout << "Continue" << endl;
}

int main(){
  while(read()) work();
  return 0;
}

