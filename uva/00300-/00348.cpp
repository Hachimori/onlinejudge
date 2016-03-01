#include<iostream>
#include<climits>

#define MAX 11

using namespace std;

class Array{
public:

        int row;
        int column;

};

Array array[MAX];
bool charPrinted;

void Output(int split[MAX][MAX], int left, int right, bool printMulti){
        
        if(left==right){

                if(printMulti){
                        cout << " x ";
                }
                cout << 'A' << left+1 ;
                charPrinted = true;
                

        }
        else {          
                
                if(charPrinted){ 
                        cout << " x ";
                        charPrinted = false;
                }

                cout << '(' ;
                
                Output(split,left,split[left][right],false);
                Output(split,split[left][right]+1,right,true);
                
                cout << ')' ;
        }

}

void makeMin(int numArray, int minCost[MAX][MAX], int split[MAX][MAX]){
        
        for(int i=0;i<numArray;i++)
                        minCost[i][i] = 0;

        for(int len=1;len<numArray;len++){
                for(int l=0;l<numArray-len;l++){
                
                        int r = l + len;
                        int minVal = INT_MAX;
                        int minPos;
                        for(int k=l;k<r;k++)
                                if(minVal > minCost[l][k] + minCost[k+1][r] + array[l].row*array[k].column*array[r].column){
                                        minVal = minCost[l][k] + minCost[k+1][r] + array[l].row*array[k].column*array[r].column;
                                        minPos = k;
                                }
                        
                        minCost[l][r] = minVal;
                        split[l][r] = minPos;
                }
        }

}

bool read(int &numArray){

        cin >> numArray;
        if(numArray==0) return false;
        
        for(int i=0;i<numArray;i++)
                cin >> array[i].row >> array[i].column;

        return true;
}

void work(int numArray, int cases){
        
        int minCost[MAX][MAX];
        int split[MAX][MAX];    

        charPrinted = false;

        cout << "Case " << cases << ": " ; 

        makeMin(numArray,minCost,split);
        Output(split,0,numArray-1,false);

        cout << endl;
}

int main(){
        int numArray;

        for(int cases=1;read(numArray);cases++)
                work(numArray,cases);

        return 0;
}
