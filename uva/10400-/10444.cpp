#include<iostream>
#include<algorithm>
//#include<fstream>

//#define cin fin
#define INF 500000000
#define TILE 205
#define PEG 25

using namespace std;

//ifstream fin("tmp.txt");
int N, P, table[TILE][PEG];

int mypow(int n){
    if(n==0) return 1;
    int t = mypow(n/2);
    return t*t*(n&1?2:1);    
}

int calc(int n){
    if(n>=30) return INF;
    return mypow(n)-1;
}

int rec(int n, int p, int table[][PEG]){
     if(table[n][p]!=-1) return table[n][p];
     if(n==0) return 0;
     if(n==1) return 1;
     if(p==3) return table[n][p] = calc(n);
     
     int minV = INF;
     for(int i=1;i<n;i++){
             if(rec(i,p,table)<INF && rec(n-i,p-1,table)<INF)
                   minV = min(minV,rec(i,p,table)*2+rec(n-i,p-1,table));
     }
     
     return table[n][p] = minV;
}

bool read(){
     cin >> N >> P;
     if(N==0 && P==0) return false;
     return true;
}

void work(int cases){
     cout << "Case " << cases << ": ";
     cout << rec(N,P,table) << endl;
}

int main(){
    for(int i=0;i<=200;i++)
            for(int j=3;j<=20;j++)
                    table[i][j] = -1;
    
    for(int i=0;i<=200;i++)
            for(int j=3;j<=20;j++)
                    rec(i,j,table);
    
    for(int i=0;read();i++){
            work(i+1);
    }
    //system("PAUSE");    
    return 0;    
}
