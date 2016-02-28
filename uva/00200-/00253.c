#include<stdio.h>
#include<string.h>
#define MAX_s 12
#define MAX_cube 6

void cpy_cube( void );
int Judge( void );
int Iro_hantei( void );
void Vertical_rotate( void );
void Vertical_rotate2( void );
void Horizontal_rotate( void );

char s[MAX_s],cube1[MAX_cube+1],cube2[MAX_cube+1];

main()
{

  while( scanf("%s",s) != EOF ){
    cpy_cube();
    if(Judge()==1) printf("TRUE\n");
    else printf("FALSE\n");
  }

}

void cpy_cube( void ){

  int i,k;

  cube1[6]='\0';
  cube2[6]='\0';

  for(i=0;i<MAX_cube;i++){
    cube1[i]=s[i];
  }  

  for(k=0,i=MAX_cube;i<MAX_s;i++,k++){
    cube2[k]=s[i];
  }

  return;
}

int Judge(void){

  int i,k,j;

  if(Iro_hantei()==0) return -3;
  if(strcmp(cube1,cube2)==0) return 1;
  /* printf("%s %s\n",cube1,cube2); */
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      for(k=0;k<4;k++){
	if(strcmp(cube1,cube2)==0) return 1;
	Vertical_rotate();
	if(strcmp(cube1,cube2)==0) return 1;
      }
      if(strcmp(cube1,cube2)==0) return 1;
      Vertical_rotate2();
      if(strcmp(cube1,cube2)==0) return 1;
    }
    if(strcmp(cube1,cube2)==0) return 1;
    Horizontal_rotate();
    if(strcmp(cube1,cube2)==0) return 1;
  }

  /* printf("%s %s\n",cube1,cube2); */

  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      for(k=0;k<4;k++){
	if(strcmp(cube1,cube2)==0) return 1;
	Vertical_rotate();
	if(strcmp(cube1,cube2)==0) return 1;
      }
      if(strcmp(cube1,cube2)==0) return 1;
      Horizontal_rotate();
      if(strcmp(cube1,cube2)==0) return 1;
    }
    if(strcmp(cube1,cube2)==0) return 1;
    Vertical_rotate2();
    if(strcmp(cube1,cube2)==0) return 1;
  }

  /* printf("%s %s\n",cube1,cube2);  */

  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      for(k=0;k<4;k++){
	if(strcmp(cube1,cube2)==0) return 1;
	Horizontal_rotate();
	if(strcmp(cube1,cube2)==0) return 1;
      }
      if(strcmp(cube1,cube2)==0) return 1;
      Vertical_rotate2();
      if(strcmp(cube1,cube2)==0) return 1;
    }
    if(strcmp(cube1,cube2)==0) return 1;
    Vertical_rotate();
    if(strcmp(cube1,cube2)==0) return 1;
  }

  /* printf("%s %s\n",cube1,cube2);  */

  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      for(k=0;k<4;k++){
	if(strcmp(cube1,cube2)==0) return 1;
	Horizontal_rotate();
	if(strcmp(cube1,cube2)==0) return 1;
      }
      if(strcmp(cube1,cube2)==0) return 1;
      Vertical_rotate();
      if(strcmp(cube1,cube2)==0) return 1;
    }
    if(strcmp(cube1,cube2)==0) return 1;
    Vertical_rotate2();
    if(strcmp(cube1,cube2)==0) return 1;
  }

  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      for(k=0;k<4;k++){
	if(strcmp(cube1,cube2)==0) return 1;
	Vertical_rotate2();
	if(strcmp(cube1,cube2)==0) return 1;
      }
      if(strcmp(cube1,cube2)==0) return 1;
      Vertical_rotate();
      if(strcmp(cube1,cube2)==0) return 1;
    }
    if(strcmp(cube1,cube2)==0) return 1;
    Horizontal_rotate();
    if(strcmp(cube1,cube2)==0) return 1;
  }

  /* printf("%s %s\n",cube1,cube2); */

  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      for(k=0;k<4;k++){
	if(strcmp(cube1,cube2)==0) return 1;
	Vertical_rotate2();
	if(strcmp(cube1,cube2)==0) return 1;
      }
      if(strcmp(cube1,cube2)==0) return 1;
      Horizontal_rotate();
      if(strcmp(cube1,cube2)==0) return 1;
    }
    if(strcmp(cube1,cube2)==0) return 1;
    Vertical_rotate();
    if(strcmp(cube1,cube2)==0) return 1;
  }
  
  /* printf("%s %s\n",cube1,cube2); */ 

  return 0;
}

int Iro_hantei(void){
  
  int i;
  int num_green=0,num_red=0,num_blue=0;
  int num_green2=0,num_red2=0,num_blue2=0;

  for(i=0;i<MAX_cube;i++){
    if( cube1[i]=='g' ) num_green++;
    else if( cube1[i]=='r' ) num_red++;
    else if( cube1[i]=='b' ) num_blue++;
  }

  for(i=0;i<MAX_cube;i++){
    if( cube2[i]=='g' ) num_green2++;
    else if( cube2[i]=='r') num_red2++;
    else if( cube2[i]=='b') num_blue2++;
  }
  
  if(num_green == num_green2 && num_red == num_red2 && num_blue == num_blue2) return 1;
  else return 0;

}

void Vertical_rotate( void ){

  char tmp,tmp2;

  tmp=cube2[0];
  tmp2=cube2[5];
  cube2[0]=cube2[4];
  cube2[5]=cube2[1];
  cube2[1]=tmp;
  cube2[4]=tmp2;
   
  return;

}

void Vertical_rotate2( void ){

  char tmp,tmp2;

  tmp=cube2[2];
  tmp2=cube2[3];
  cube2[2]=cube2[0];
  cube2[3]=cube2[5];
  cube2[5]=tmp;
  cube2[0]=tmp2;
   
  return;

}

void Horizontal_rotate( void ){

  char tmp,tmp2;

  tmp=cube2[1];
  tmp2=cube2[4];
  cube2[1]=cube2[3];
  cube2[4]=cube2[2];
  cube2[2]=tmp;
  cube2[3]=tmp2;

  return;

}
