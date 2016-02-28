#include<stdio.h>
#define MAX 10000
#define check 1

void put0( int *);
void Output( int *, int );

main()
{

	int i,left,hight,right,last=0;
	int sky[MAX];

	put0(sky);

	while( scanf("%d%d%d",&left,&hight,&right) == 3 ){
		if(last<right) last = right;
		for(i=left;i<right;i++){
			if(hight>sky[i]) sky[i]=hight;
		}
	}

	Output(sky,last);

}

void put0(int x[MAX]){

	int i;

	for(i=0;i<MAX;i++){

		x[i]=0;

	}

	return;
}

void Output(int x[MAX], int last){

	int i,tmp,nPrint=0;

	if(x[0]!=0){
		printf("0 %d",x[0]);
	}

	tmp = x[0];
	for(i=0;i<last+1;i++){
		if( tmp != x[i] ){
                        if(nPrint) printf(" ");
			printf("%d %d",i,x[i]);
			tmp = x[i];
                        nPrint++;
		}
	}
	printf("\n");

}
