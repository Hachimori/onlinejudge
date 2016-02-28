#include<stdio.h>
#include<string.h>
#define CATEGORIES 3

void sort(int,int,int,int,int,int);

typedef struct{
  int brown;
  int green;
  int clear;
}category;

int highest_category,higher_category,last_category;
char highest_color[2],higher_color[2],last_color[2];

main()
{

  int i,sum=0,check=0,largest; 
  category group[CATEGORIES];
  

  while( scanf("%d%d%d%d%d%d%d%d%d",&group[0].brown,&group[0].green,&group[0].clear,
	       &group[1].brown,&group[1].green,&group[1].clear,
	       &group[2].brown,&group[2].green,&group[2].clear) == 9 ){
    

    for(i=0;i<CATEGORIES;i++){  /* ƒrƒ“‚Ì‘”‚ð’²‚×‚é */
      sum+=group[i].brown;
      sum+=group[i].green;
      sum+=group[i].clear;
    }

    largest = group[0].brown + group[1].clear + group[2].green;
    sort(group[0].brown,group[1].clear,group[2].green,0,1,2);
    if( largest < group[0].brown + group[2].clear + group[1].green){
      largest = group[0].brown + group[2].clear + group[1].green;
      sort(group[0].brown,group[2].clear,group[1].green,0,2,1);
    }
    if( largest < group[1].brown + group[0].clear + group[2].green){
      largest = group[1].brown + group[0].clear + group[2].green;
      sort(group[1].brown,group[0].clear,group[2].green,1,0,2);
    }
    if( largest < group[1].brown + group[2].clear + group[0].green){
      largest = group[1].brown + group[2].clear + group[0].green;
      sort(group[1].brown,group[2].clear,group[0].green,1,2,0);
    }  
   if( largest < group[2].brown + group[0].clear + group[1].green){
      largest = group[2].brown + group[0].clear + group[1].green;
      sort(group[2].brown,group[0].clear,group[1].green,2,0,1);
    }
   if( largest < group[2].brown + group[1].clear + group[0].green){
      largest = group[2].brown + group[1].clear + group[0].green;
      sort(group[2].brown,group[1].clear,group[0].green,2,1,0);
    }  

    sum -= largest;
    
    /* Output */ 
    for(i=0;i<CATEGORIES;i++){
      if(i==highest_category) printf("%s",highest_color);
      if(i==higher_category) printf("%s",higher_color);
      if(i==last_category) printf("%s",last_color);
    }
    printf(" %d\n",sum);

    largest = 0; 
    sum = 0;
  }
  
}

void sort(int brown, int clear, int green, int brown_category, int clear_category, int green_category){
  
  if( brown >= clear && clear >= green ){
    highest_category = brown_category;
    higher_category = clear_category;
    last_category = green_category;
    strcpy(highest_color,"B");
    strcpy(higher_color,"C");
    strcpy(last_color,"G");
  }
  else if( brown >= green && green >= clear ){
    highest_category = brown_category;
    higher_category = green_category;
    last_category = clear_category;
    strcpy(highest_color,"B");
    strcpy(higher_color,"G");
    strcpy(last_color,"C");
  }
  else if( clear >= brown && brown >= green ){
    highest_category = clear_category;
    higher_category = brown_category;
    last_category = green_category;
    strcpy(highest_color,"C");
    strcpy(higher_color,"B");
    strcpy(last_color,"G");
  }
  else if( clear >= green && green >= brown ){
    highest_category = clear_category;
    higher_category = green_category;
    last_category = brown_category;
    strcpy(highest_color,"C");
    strcpy(higher_color,"G");
    strcpy(last_color,"B");
  }
  else if( green >= brown && brown >= clear ){
    highest_category = green_category;
    higher_category = brown_category;
    last_category = clear_category;
    strcpy(highest_color,"G");
    strcpy(higher_color,"B");
    strcpy(last_color,"C");
  }
  else if( green >= clear && clear >= brown ){
    highest_category = green_category;
    higher_category = clear_category;
    last_category = brown_category;
    strcpy(highest_color,"G");
    strcpy(higher_color,"C");
    strcpy(last_color,"B");
  }

  return;
}
