#include<stdio.h>
#define MAX 100

int Count( int, int, int [MAX][MAX]);   
/* �ӥåȤ򴹤���ɬ�פ��ʤ��ʤ�У����֤�   */ 
/* �ӥåȤ򴹤��뤳�Ȥ��Ǥ���ʤ�У����֤� */ 
/* �ӥåȤ򴹤��ƽ����Բ�ǽ�ʤ�У����֤�   */

int x,y,n;

main()
{
  
  int i,j,array[MAX][MAX],num_changeable=0,tmp,check_corrupt=0;
  
  
  while(1){

    /* �ѿ��ν���� */
    num_changeable = 0;
    check_corrupt = 0;
    

    /* Input n=0 �ʤ�����Ͻ�λ */
    scanf("%d",&n);
    if(n==0) break;

    /* ��������� */
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	scanf("%d",&array[i][j]);
      }
    }

    /* �����Ĵ�٤� */
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	tmp = Count(i,j,array);
	/* printf("n = %d , tmp = %d , i = %d , x = %d , y = %d\n",n,tmp,i,x,y); */
	if(tmp == 1) num_changeable++;
	else if( tmp == 2 ) check_corrupt = 1;
      }
    }

    /* Output */
    if(check_corrupt == 0 && num_changeable==0) printf("OK\n");
    else if(check_corrupt == 1 && num_changeable==1) printf("Change bit (%d,%d)\n",y,x);
    else printf("Corrupt\n");
    /* else if(num_changeable >1) printf("Corrupt\n"); */
  }

}

int Count( int tate, int yoko, int array[MAX][MAX]){
  
  int i,j,sum=0,sum2=0;
  
  for(j=0;j<n;j++){  /* ��Ĥ���ι�פ�Ĵ�٤� */
    sum+=array[tate][j];
    /* printf("array[%d][%d]=%d\n",num,j,array[num][j]); */
  }

  for(i=0;i<n;i++){  /* ��ĤιԤι�פ�Ĵ�٤� */
    sum2+=array[i][n-yoko-1];
    /* printf("array[%d][%d]=%d\n",i,n-num-1,sum2+=array[i][n-num-1]); */
  }

  if(sum%2 == 1 && sum2%2 == 1){
    y=tate+1;
    x=n-yoko;
    return 1;
  }
  else if(sum%2 == 0 && sum2%2 == 1 || sum%2 == 1 && sum2%2 == 0) return 2;
  else return 0; 

}
