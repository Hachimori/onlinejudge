#include<iostream>

class Number{

 public:
  int chk;
  int symbols[101][5];
  
  Number(){
    chk=0;
    for(int i=0; i<101;i++)
      for(int j=0; j<5;j++)
	symbols[i][j]=0;
  }

  Number(int n){
    int i,j,tmp;
    
    for(i=1; i<n+1; i++){

      tmp = i;

      for(j=0;j<5;j++)
	symbols[i][j] = symbols[i-1][j];

      for(j=0;tmp>=10;j++,tmp-=10){}

      if(j==4){
	symbols[i][2]+=1;
	symbols[i][3]+=1;
      }
      else if(j==9){
	symbols[i][4]+=1;
	symbols[i][2]+=1;
      }
      else if(j>=5 && j<9){
	symbols[i][2]+=j-5;
	symbols[i][3]+=1;
      }
      else if(j==10){
	symbols[i][4]+=1;
      }
      else if(j>0 && j<4){
	symbols[i][2]+=j;
      }
      else if(j==0){}
      else cout << "aaa";

      for(j=0;tmp>0;j++,tmp--){}
      
      if(j==4){
	symbols[i][0]+=1;
	symbols[i][1]+=1;
      }
      else if(j==9){
	symbols[i][0]+=1;
	symbols[i][2]+=1;
      }
      else if(j>=5 && j<9){
	symbols[i][0]+=j-5;
	symbols[i][1]+=1;
      }
      else if(j>0 && j<4){
	symbols[i][0]+=j;
      }
      else if(j==10){
	symbols[i][2]+=1;
      }
      else if(j==0){}
      else cout << "aaa";
 
    }

  }

  void output(int n){
    cout << n << ": " << symbols[n][0] << " i, " << symbols[n][1] << " v, " 
	 << symbols[n][2] << " x, " << symbols[n][3] << " l, " << symbols[n][4] << " c" << endl;
  }

};

main()
{

  int n;
  Number num = Number();
  
  num = Number(101);
  
  while(1){
    cin >> n;
    if(n==0) break;
    num.output(n);
  }

}
