#include<stdio.h>
#include<string.h>

#define MAX 1000

typedef struct{
  char color;
  int num;
}data;

void Put0( int [MAX]);
void Output(int, int, char [MAX][MAX]);
/* 返り値 １:色を見つけて,そこはまだチェックされてない
          ２: 色を見つけたが,そこは既にチェックされてた */
int Search(int,int,int,int,int [MAX][MAX],char [MAX][MAX],char);


data mydata[MAX];
int chk_color[MAX][MAX];
int colors = 0;
int second=0;

main()
{

  int i,j,h;
  int world,x,y;
  char map[MAX][MAX];  

  scanf("%d",&world);
  
  for(i=0;i<world;i++){

    scanf("%d%d",&y,&x);
   
    for(j=0;j<y;j++){
	scanf("%s",&map[j]);
    }

    printf("World #%d\n",i+1);
    Output(x,y,map);

    colors = 0;
    for(j=0;j<MAX;j++){
      mydata[j].color = ' ';
      mydata[j].num = 0;
    } 
    for(j=0;j<MAX;j++) Put0(chk_color[j]);

  }


}
    
void Put0( int X[MAX]){

  int i;

  for(i=0;i<MAX;i++) X[i] = 0;

  return;

}
 
void Output(int x, int y, char X[MAX][MAX]){

  int i,j,h,w,z,k,l,chk=0,chk2=0,tmp;
  char tmp_c;

  for(i=0;i<y;i++){
    for(j=0;j<x;j++){
      
      //for(h=0;h<colors;h++){
	//if( X[i][j] == mydata[h].color ){
	  chk=Search(i,j,y,x,chk_color,X,X[i][j]);
	 // printf("chk = %d\n",chk);
	 // break;
	//}
      //}
      
//      for(z=0;z<y;z++){
//	for(w=0;w<x;w++){
//	  printf("%d ",chk_color[z][w]);
//	}printf("\n");
//      }printf("\n"); sleep(1);

      //for(z=0;z<colors;z++) printf("%c: %d\n",mydata[z].color,mydata[z].num);
//      if( chk == 0 ){
//	mydata[colors].color = X[i][j];
//	mydata[colors].num++;
//	chk_color[i][j] = 1;
//	colors++;
      //}
      //if( chk == 1 ) mydata[h].num++;
	
      if( chk == 1 ){
	for(z=0;z<colors;z++){
	  if(mydata[z].color == X[i][j]){
	    mydata[z].num++;
	    chk_color[i][j] = 2;
	    chk2=1;
	  }
	}
	if(chk2==0){
	  mydata[colors].color = X[i][j];
	  mydata[colors].num++;
	  colors++;
	}
	chk2=0;
	
      }
      chk = 0;
      second = 0;

      /*##### SORT ######*/
      for(k=0;k<colors;k++){
	for(l=k;l<colors;l++){
	  if( mydata[k].num < mydata[l].num ){

	    tmp = mydata[k].num;
	    mydata[k].num = mydata[l].num;
	    mydata[l].num = tmp;

	    tmp_c = mydata[k].color;
	    mydata[k].color = mydata[l].color;
	    mydata[l].color = tmp_c;

	  }
	}
      }

      for(k=0;k<colors;k++){
	for(l=k; mydata[k].num == mydata[l].num ;l++){
	  if( mydata[k].color > mydata[l].color ){

	    tmp_c = mydata[l].color;
	    mydata[l].color = mydata[k].color;
	    mydata[k].color = tmp_c;

	  }
	}
      }

    }
  }

  for(i=0;i<colors;i++) printf("%c: %d\n",mydata[i].color,mydata[i].num);
}

int Search(int i,int j,int y,int x,int chk_color[MAX][MAX],char X[MAX][MAX],char color){
  
  static int returner;
  int z,w;

  if( second == 0 ){ 
    returner = 2; 
    second = 1;
  }
  /* for(z=0;z<y;z++){
    for(w=0;w<x;w++){
      printf("%d ",chk_color[z][w]);
    }printf("\n");
  }printf("\n"); sleep(1); */
      
  //printf("i = %d, j = %d, second = %d\n",i,j,second); sleep(1);
  //while( chk_color[i+1][j] == 0 || chk_color[i][j+1] == 0 || chk_color[i-1][j] == 0 || chk_color[i][j-1] == 0 ){
  //  printf("i=%d,j=%d returner = %d\n",i,j,returner);
    if( X[i][j] == color && X[i+1][j] != color &&  X[i][j+1] != color && X[i-1][j] != color && X[i][j-1] != color ){
      chk_color[i][j] = 2;
      return 1; 
      
    }
    else if( X[i+1][j] == color && chk_color[i+1][j] != 2  && i != y-1 ){/* 一つにまとめる */
      chk_color[i][j] = 2;                                         /* 下にいったあと,上に行けるようにする*/
      //chk_color[i+1][j] = 2;
      returner=1;
      i++;
      Search(i,j,y,x,chk_color,X,color); i--;
    }
    else if( X[i][j+1] == color && chk_color[i][j+1] != 2  && j != x-1 ){
      chk_color[i][j] = 2;
      //chk_color[i][j+1] = 2;
      returner=1;
      j++;
      Search(i,j,y,x,chk_color,X,color); j--;

    }
    else if( X[i-1][j] == color && chk_color[i-1][j] != 2  && i != 0 ){
      chk_color[i][j] = 2;
      //chk_color[i-1][j] = 2;
      returner=1; 
      i--;
      Search(i,j,y,x,chk_color,X,color); i++;     
    }
    else if( X[i][j-1] == color && chk_color[i][j-1] != 2  && j != 0 ){
      chk_color[i][j] = 2;
      //chk_color[i][j-1] = 2;
      returner=1;
      j--;
      Search(i,j,y,x,chk_color,X,color); j++;     
    }
    else{ chk_color[i][j] = 2;  return returner; }
   

  //if(chk_color[i+1][j] == 0 || chk_color[i][j+1] == 0 || chk_color[i-1][j] == 0 || chk_color[i][j-1] == 0 ||
  //   i != y-1 || j != x-1 || i != 0 || j != 0){}
  
   Search(i,j,y,x,chk_color,X,color);
 
  
  return returner;

}
