#include<stdio.h>
#define MAX 105

void Input(void);
void Search(void);
void Search_oil(int,int);
void Output(void);

int oils=0,x,y;
char array[MAX][MAX];

main()
{
	
	while(scanf("%d%d",&y,&x)){
		oils=0;
		if(x==0 && y==0) break;
		Input();
		/* Output(); */
		Search();
		printf("%d\n",oils);
	}

}

void Input(void){

	int i;

	for(i=0;i<y;i++){
			scanf("%s\n",array[i]);
	}

	return;

}

void Search(void){

	int i,j;

	for(i=0;i<y;i++){
		for(j=0;j<x;j++){
			if(array[i][j] == '@'){
				oils++;
				array[i][j] = 'W';
				Search_oil(i,j);
			}
		}
	}
	
	return;

}

void Search_oil(int tmp_y, int tmp_x){

	/* printf("y=%d  x=%d\n",tmp_y,tmp_x); */

	if( array[tmp_y+1][tmp_x] == '@' && tmp_y+1!=y){ 
		array[tmp_y+1][tmp_x] = 'W';
		Search_oil(tmp_y+1,tmp_x);
	}
	if( array[tmp_y+1][tmp_x+1] == '@' && tmp_y+1!=y && tmp_x+1!=x){ 
		array[tmp_y+1][tmp_x+1] = 'W';
		Search_oil(tmp_y+1,tmp_x+1);
	}
	if( array[tmp_y][tmp_x+1] == '@' && tmp_x+1!=x){ 
		array[tmp_y][tmp_x+1] = 'W';
		Search_oil(tmp_y,tmp_x+1);
	}
	if( array[tmp_y-1][tmp_x+1] == '@' && tmp_y-1!=-1 && tmp_x+1!=x){ 
		array[tmp_y-1][tmp_x+1] = 'W';
		Search_oil(tmp_y-1,tmp_x+1);
	}
	if( array[tmp_y-1][tmp_x] == '@' && tmp_y-1!=-1){ 
		array[tmp_y-1][tmp_x] = 'W';
		Search_oil(tmp_y-1,tmp_x);
	}
	if( array[tmp_y-1][tmp_x-1] == '@' && tmp_y-1!=-1 && tmp_x-1!=-1){ 
		array[tmp_y-1][tmp_x-1] = 'W';
		Search_oil(tmp_y-1,tmp_x-1);
	}
	if( array[tmp_y][tmp_x-1] == '@' && tmp_x-1!=-1){ 
		array[tmp_y][tmp_x-1] = 'W';
		Search_oil(tmp_y,tmp_x-1);
	}
	if( array[tmp_y+1][tmp_x-1] == '@' && tmp_y+1!=y && tmp_x-1!=-1){ 
		array[tmp_y+1][tmp_x-1] = 'W';
		Search_oil(tmp_y+1,tmp_x-1);
	}

	return;
}

void Output( void ){

	int i;

	for(i=0;i<y;i++){
			printf("%s\n",array[i]);
	}
	printf("\n");

	return;
}