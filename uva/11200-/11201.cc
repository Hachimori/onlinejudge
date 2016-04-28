#include<iostream>
#include<string>
#define LENG 8
#define WORD 10000
#define EPS (1.0e-9)
#define LT(x,y) ((x)<(y)-EPS)
using namespace std;

double mul[] = 
  {12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44, 0.00,
   4.97, 3.15, 6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.90,
   0.02, 0.22, 0.90, 0.52};

char vowel[] = "aiueo";
char consonant[] = "bcdfghjklmnpqrstvwxyz";
int cnt[256][LENG];
double average[256][LENG];

void rec(int len, double sum, int letter[256], double ave[LENG], int c[LENG]){
  
  c[len]++;
  ave[len] += sum;
  if(len==LENG-1) return;

  for(int i=0;i<(len%2==0?21:5);i++){
    char &ch = (len%2==0?consonant[i]:vowel[i]);
    if(letter[ch]==2) continue;
    letter[ch]++;
    rec(len+1,sum+(len+1)*mul[ch-'a'],letter,ave,c);
    letter[ch]--;
  }
}


int nWord;
string word[WORD];

void read(){
  cin >> nWord;

  for(int i=0;i<nWord;i++)
    cin >> word[i];
}

void work(){
  double score[WORD];
  
  for(int i=0;i<nWord;i++){
    double sum = 0;
    for(int j=0;j<word[i].size();j++)
      sum += (j+1)*mul[word[i][j]-'a'];
    score[i] = sum;
  }
  
  for(int i=0;i<nWord;i++)
    if(LT(score[i],average[word[i][0]][word[i].size()]))
      cout << "below" << endl;
    else
      cout << "above or equal" << endl;
}

int main(){
  int letter[256];
  for(int i=0;i<256;i++) letter[i] = 0;

  for(int i=0;i<256;i++)
    for(int j=0;j<LENG;j++){
      average[i][j] = 0;
      cnt[i][j] = 0;
    }

  for(int i=0;i<21;i++){
    letter[consonant[i]]++;
    rec(1,mul[consonant[i]-'a'],letter,average[consonant[i]],cnt[consonant[i]]);
    letter[consonant[i]]--;
  }

  for(int i=0;i<256;i++)
    for(int j=0;j<LENG;j++)
      average[i][j] /= cnt[i][j];
  
  read();
  work();
  
  return 0;
}
