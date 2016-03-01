#include<stdio.h>
#include<iostream>

double X1,Y1,X2,Y2,X3,Y3,X4,Y4;
double tend1,tend2;
bool infinity1,infinity2;

double absDouble(double number)
{
   if(number < 0) return (-1.0 * number);
   else return number;
} 

class Solver{

 public:

  void read(){

    cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3 >> X4 >> Y4;

  }

  void work(){

    if(X1==X2) infinity1 = true;
    if(X3==X4) infinity2 = true;

    if(infinity1==false) tend1 = (Y2-Y1)/(X2-X1);
    if(infinity2==false) tend2 = (Y3-Y4)/(X3-X4);

    if(infinity1==true && infinity2==true){
      if(X1==X3) cout << "LINE" << endl;
      else cout << "NONE" << endl;
      return;
    }

    if(absDouble(tend1-tend2) < 0.00001 && infinity1==false && infinity2==false){
      if( absDouble((Y1-tend1*X1)-(Y3-tend2*X3))<0.00001 )
	cout << "LINE" << endl;
      else cout << "NONE" << endl;
      return;
    }
    
    if(infinity1==false && infinity2==false){
      
      double point_x = (tend1*X1-tend2*X3+Y3-Y1)/(tend1-tend2);
      double point_y = point_x*tend1 - tend1*X1 + Y1;

      printf("POINT %.2lf %.2lf\n",point_x,point_y);
      
    }
    else if(infinity1==true && infinity2==false){

      double point_x = X1;
      double point_y = tend2*X1 - tend2*X3 + Y3;

      printf("POINT %.2lf %.2lf\n",point_x,point_y);
      
    }
    else if(infinity1==false && infinity2==true){
      
      double point_x = X3;
      double point_y = tend1*X3 - tend1*X1 + Y1;

      printf("POINT %.2lf %.2lf\n",point_x,point_y);

    }

  }


};

main(){

  Solver solver;
  int cases;

  cin >> cases;

  
  cout << "INTERSECTING LINES OUTPUT" << endl;

  
  for(int i=0;i<cases;i++){

    infinity1=false;
    infinity2=false;

    solver.read();
    solver.work();

  }

  
  cout << "END OF OUTPUT" << endl;


}
