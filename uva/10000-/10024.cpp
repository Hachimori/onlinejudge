#include<iostream>
#include<string>

char board[6][6];
char cube_list[10][3][5];
char extra_cube[2][6];

void make_cube(){
  
  strcpy(cube_list[0][0],"1000");
  strcpy(cube_list[0][1],"1111");
  strcpy(cube_list[0][2],"1000");

  strcpy(cube_list[1][0],"1000");
  strcpy(cube_list[1][1],"1111");
  strcpy(cube_list[1][2],"0100");

  strcpy(cube_list[2][0],"1000");
  strcpy(cube_list[2][1],"1111");
  strcpy(cube_list[2][2],"0010");

  strcpy(cube_list[3][0],"1000");
  strcpy(cube_list[3][1],"1111");
  strcpy(cube_list[3][2],"0001");

  strcpy(cube_list[4][0],"0100");
  strcpy(cube_list[4][1],"1111");
  strcpy(cube_list[4][2],"0100");

  strcpy(cube_list[5][0],"0100");
  strcpy(cube_list[5][1],"1111");
  strcpy(cube_list[5][2],"0010");

  strcpy(cube_list[6][0],"0100");
  strcpy(cube_list[6][1],"0111");
  strcpy(cube_list[6][2],"1100");

  strcpy(cube_list[7][0],"0010");
  strcpy(cube_list[7][1],"0111");
  strcpy(cube_list[7][2],"1100");

  strcpy(cube_list[8][0],"0001");
  strcpy(cube_list[8][1],"0111");
  strcpy(cube_list[8][2],"1100");

  strcpy(cube_list[9][0],"0011");
  strcpy(cube_list[9][1],"0110");
  strcpy(cube_list[9][2],"1100");

  strcpy(extra_cube[0],"11100");
  strcpy(extra_cube[1],"00111");

}

bool search_horizontal(int row, int column){
  
  bool flg;

  for(int num_list=0;num_list<10;num_list++){

    flg=true;
    for(int k=0,i=row;i<row+3;k++,i++){
      for(int l=0,j=column;j<column+4;l++,j++){
	if(cube_list[num_list][k][l]!=board[i][j]){ flg=false; break; }
      }
      if(flg==false) break;
    }
    if(flg==true) return true;

    flg=true;
    for(int k=0,i=row;i<row+3;k++,i++){
      for(int l=3,j=column;j<column+4;l--,j++){
	if(cube_list[num_list][k][l]!=board[i][j]){ flg=false; break; }
      }
      if(flg==false) break;
    }
    if(flg==true) return true;   

    flg=true;
    for(int k=2,i=row;i<row+3;k--,i++){
      for(int l=0,j=column;j<column+4;l++,j++){
	if(cube_list[num_list][k][l]!=board[i][j]){ flg=false; break; }
      }
      if(flg==false) break;
    }
    if(flg==true) return true;   

    flg=true;
    for(int k=2,i=row;i<row+3;k--,i++){
      for(int l=3,j=column;j<column+4;l--,j++){
	if(cube_list[num_list][k][l]!=board[i][j]){ flg=false; break; }
      }
      if(flg==false) break;
    }
    if(flg==true) return true;   

  }

  return false;

}

bool search_vertical(int row, int column){

  bool flg;

  for(int num_list=0;num_list<10;num_list++){

    flg=true;
    for(int l=0,i=row;i<row+4;l++,i++){
      for(int k=0,j=column;j<column+3;k++,j++){
	if(cube_list[num_list][k][l]!=board[i][j]){ flg=false; break; }
      }
      if(flg==false) break;
    }
    if(flg==true) return true;

    flg=true;
    for(int l=3,i=row;i<row+4;l--,i++){
      for(int k=0,j=column;j<column+3;k++,j++){
	if(cube_list[num_list][k][l]!=board[i][j]){ flg=false; break; }
      }
      if(flg==false) break;
    }
    if(flg==true) return true;

    flg=true;
    for(int l=0,i=row;i<row+4;l++,i++){
      for(int k=2,j=column;j<column+3;k--,j++){
	if(cube_list[num_list][k][l]!=board[i][j]){ flg=false; break; }
      }
      if(flg==false) break;
    }
    if(flg==true) return true;

    flg=true;
    for(int l=3,i=row;i<row+4;l--,i++){
      for(int k=2,j=column;j<column+3;k--,j++){
	//cout << "l = " << l << "  k = " << k << endl;
	if(cube_list[num_list][k][l]!=board[i][j]){ flg=false; break; }
      }
      if(flg==false) break;
    }
    if(flg==true) return true; 

  }

  return false;  

}

bool extra_horizontal(int row, int column){
  
  bool flg;

  flg=true;
  for(int k=0,i=row;i<row+2;k++,i++){
    for(int l=0,j=column;j<column+5;l++,j++){
      if(extra_cube[k][l]!=board[i][j]){flg=false; break;}
    }
    if(flg==false) break;
  }
  if(flg==true) return true;

  flg=true;
  for(int k=1,i=row;i<row+2;k--,i++){
    for(int l=0,j=column;j<column+5;l++,j++){
      if(extra_cube[k][l]!=board[i][j]){flg=false; break;}
    }
    if(flg==false) break;
  }
  if(flg==true) return true;

  flg=true;
  for(int k=0,i=row;i<row+2;k++,i++){
    for(int l=4,j=column;j<column+5;l--,j++){
      if(extra_cube[k][l]!=board[i][j]){flg=false; break;}
    }
    if(flg==false) break;
  }
  if(flg==true) return true;

  flg=true;
  for(int k=1,i=row;i<row+2;k--,i++){
    for(int l=4,j=column;j<column+5;l--,j++){
      if(extra_cube[k][l]!=board[i][j]){flg=false; break;}
    }
    if(flg==false) break;
  }
  if(flg==true) return true;

  return false;

}

bool extra_vertical(int row, int column){
    
  bool flg;
  
  flg=true;
  for(int l=0,i=row;i<row+5;l++,i++){
    for(int k=0,j=column;j<column+2;k++,j++){
      if(extra_cube[k][l]!=board[i][j]){flg=false; break;}
    }
    if(flg==false) break;
  }
  if(flg==true) return true;
  
  flg=true;
  for(int l=4,i=row;i<row+5;l--,i++){
    for(int k=0,j=column;j<column+2;k++,j++){
      if(extra_cube[k][l]!=board[i][j]){flg=false; break;}
    }
    if(flg==false) break;
  }
  if(flg==true) return true;
  
  flg=true;
  for(int l=0,i=row;i<row+5;l++,i++){
    for(int k=1,j=column;j<column+2;k--,j++){
      if(extra_cube[k][l]!=board[i][j]){flg=false; break;}
    }
    if(flg==false) break;
  }
  if(flg==true) return true;
  
  flg=true;
  for(int l=4,i=row;i<row+5;l--,i++){
    for(int k=1,j=column;j<column+2;k--,j++){
      if(extra_cube[k][l]!=board[i][j]){flg=false; break;}
    }
    if(flg==false) break;
  }
  if(flg==true) return true;

  return false;
}


class Solver{
 public:

  void read(){

    int ones=0;

    for(int i=0;i<6;i++){
      for(int j=0;j<6;j++){

	int letter;
	cin >> letter;

	if(letter==1){
	  board[i][j]='1';
	  ones++;
	}
	else if(letter==0){
	  board[i][j]='0';
	}

      }
    }

  }

  void work(){
    /*
    for(int i=0;i<6;i++){
      for(int j=0;j<6;j++){
	cout << board[i][j];
      }cout << endl;
    }cout << endl;
    */
    /*
    for(int i=0;i<3;i++){
      for(int j=0;j<4;j++){
	cout << cube_list[2][i][j];
      }cout << endl;
    }cout << endl;
    */

    for(int i=0;i<6-2;i++){
      for(int j=0;j<6-3;j++){
	//cout << "i = " << i << "  j = " << j << endl;
	if(search_horizontal(i,j)==true){
	  cout << "correct" << endl;
	  return;
	}
      }
    }

    for(int i=0;i<6-3;i++){
      for(int j=0;j<6-2;j++){
	if(search_vertical(i,j)==true){
	  cout << "correct" << endl;
	  return;
	}
      }
    }    

    for(int i=0;i<6-1;i++){
      for(int j=0;j<6-4;j++){
	if(extra_horizontal(i,j)==true){
	  cout << "correct" << endl;
	  return;
	}
      }
    }

    for(int i=0;i<6-4;i++){
      for(int j=0;j<6-1;j++){
	if(extra_vertical(i,j)==true){
	  cout << "correct" << endl;
	  return;
	}
      }
    }


    cout << "incorrect" << endl;
    
    return;

  }

};

main(){

  int cases;
  Solver solver;

  cin >> cases;

  make_cube();

  for(int i=0;i<cases;i++){
    cout << endl;
    solver.read();
    solver.work();
  }

}
