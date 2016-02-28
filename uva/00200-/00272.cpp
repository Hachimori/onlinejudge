#include<stdio.h>

main()
{
	
	int chk=0;
	char c;
	
	while(1){
		if(scanf("%c",&c)==EOF) break;

		if(chk==0 && c== '\"'){
			 printf("``");
			 chk=1;
		}
		else if(chk==1 && c=='\"'){
			 printf("\'\'");
			 chk=0;
 		}
		else printf("%c",c);
	}	

}
