#include<iostream>
#include<utility>
#include<cfloat>
#include<algorithm>

using namespace std;

class Data{
public:

  int posW, posH, sizeW, sizeH;
  
  Data(){}
  Data(int pw, int ph, int sw, int sh): 
    posW(pw), posH(ph), sizeW(sw), sizeH(sh) {}
  
  bool isInside(int pw, int ph){
    return (posW<=pw && pw<posW+sizeW && posH<=ph && ph<posH+sizeH) ;
  }

  bool isInvade(int pw, int ph, int sw, int sh){
    return max(pw,posW)<min(pw+sw,posW+sizeW) &&
           max(ph,posH)<min(ph+sh,posH+sizeH);
  }

};

int width, height;
pair<int,int> sizeList[4];  //width, height

bool read(){
  
  cin >> width >> height;
  if(width==0 && height==0) return false;
  
  for(int i=0;i<4;i++)
    cin >> sizeList[i].first >> sizeList[i].second;
  
  return true;
}

void detectToFill(int &toFillH, int &toFillW, int nPut, Data putList[4]){
  for(int i=0;i<nPut;i++){
    bool succeed=true;
       
    if(putList[i].posW+putList[i].sizeW==width) succeed=false;
    
    for(int j=0;j<nPut;j++){
      if(i==j) continue;
      if(putList[j].isInside(putList[i].posW+putList[i].sizeW,putList[i].posH)){
	succeed = false;
	break;
      }
    }
      
    if(succeed){
      toFillH = putList[i].posH;	
      toFillW = putList[i].posW+putList[i].sizeW;
      break;
    }
  }
    
  if(toFillH==-1 && toFillW==-1){
    for(int i=0;i<nPut;i++){
      bool succeed=true;
	
    if(putList[i].posH+putList[i].sizeH==height) succeed=false;
    
      for(int j=0;j<nPut;j++){
	if(i==j) continue;
	if(putList[j].isInside(putList[i].posW,putList[i].posH+putList[i].sizeH) || 
	   putList[i].posH+putList[i].sizeH==height ){
	  succeed = false;
	  break;
	}
      }
	
      if(succeed){
	toFillH = putList[i].posH+putList[i].sizeH;	
	toFillW = putList[i].posW;
	break;
      }
    }
  }
}

bool invades(int nPut, int toFillW, int toFillH, int nsw, int nsh, Data putList[4]){
  for(int i=0;i<nPut;i++)
    if(putList[i].isInvade(toFillW,toFillH,nsw,nsh)) return true;
  
  return false;
}


bool fit(bool used[4], int nPut, Data putList[4], int currArea){
  /*
  for(int i=0;i<nPut;i++){
    cout << putList[i].posW << ' ' << putList[i].posH << ' ' 
	 << putList[i].sizeW << ' ' << putList[i].sizeH << endl;
  }cout << endl;
  */
  /*
  cout << nPut << endl;
  */
  if(nPut==4 && currArea==height*width) return true;
  
  if(nPut==0){
    
    for(int i=0;i<4;i++){
      
      used[i] = true;
      double ratio=(double)(sizeList[i].second)/sizeList[i].first;
      double nextSizeW=sizeList[i].first;
      double nextSizeH=sizeList[i].second;
      
      for(int j=0;(int)(nextSizeW+0.5)<=width && (int)(nextSizeH+0.5)<=height; 
	  j++,nextSizeW+=1,nextSizeH+=ratio){
	
	if(!(fabs((int)(nextSizeH+0.5)-nextSizeH)<FLT_EPSILON)) continue;
	
	int nsw = (int)(nextSizeW+0.5);
	int nsh = (int)(nextSizeH+0.5);
	
	putList[nPut] = Data(0,0,nsw,nsh);
	
	if(fit(used,nPut+1,putList,currArea+nsw*nsh)) return true;
      }
      
      used[i] = false;
    }
    
  }
  else if(nPut==1){
    
    int toFillH=-1, toFillW=-1;
    
    detectToFill(toFillH,toFillW,nPut,putList);
    
    if(toFillH!=-1 && toFillW!=-1){
      for(int i=0;i<4;i++){
	if(used[i]) continue;
	used[i] = true;
	
	if(putList[0].sizeH==height||putList[0].sizeW==width){
	  double ratio=(double)(sizeList[i].second)/sizeList[i].first;
	  double nextSizeW=sizeList[i].first;
	  double nextSizeH=sizeList[i].second;
	  
	  for(int j=0;(int)(toFillW+nextSizeW+0.5)<=width && (int)(toFillH+nextSizeH+0.5)<=height; 
	      j++,nextSizeW+=1,nextSizeH+=ratio){
	    
	    if(!(fabs((int)(nextSizeH+0.5)-nextSizeH)<FLT_EPSILON)) continue;
	    
	    int nsw = (int)(nextSizeW+0.5);
	    int nsh = (int)(nextSizeH+0.5);
	    
	    putList[nPut] = Data(toFillW,toFillH,nsw,nsh);
	    
	    if(fit(used,nPut+1,putList,currArea+nsw*nsh)) return true;
	  }
	}
	else{
	  double ratio=(double)(sizeList[i].second)/sizeList[i].first;
	  double nextSizeW=sizeList[i].first;
	  double nextSizeH=sizeList[i].second;
	  
	  for(int j=0;(int)(toFillW+nextSizeW+0.5)<=width && (int)(toFillH+nextSizeH+0.5)<=height; 
	      j++,nextSizeW+=1,nextSizeH+=ratio){
	    
	    if(!((int)(toFillW+nextSizeW+0.5)==width || (int)(toFillH+nextSizeH+0.5)==height || 
		 (int)(toFillH+nextSizeH+0.5)==putList[0].posH+putList[0].sizeH ) ) continue;
	    if(!(fabs((int)(nextSizeH+0.5)-nextSizeH)<FLT_EPSILON)) continue;
	    
	    int nsw = (int)(nextSizeW+0.5);
	    int nsh = (int)(nextSizeH+0.5);
	    
	    putList[nPut] = Data(toFillW,toFillH,nsw,nsh);
	    
	    if(fit(used,nPut+1,putList,currArea+nsw*nsh)) return true;
	  }
	}
	
	used[i] = false;
      }
    }
  }
  else if(nPut==2 || nPut==3){
    int toFillH=-1, toFillW=-1;
    
    detectToFill(toFillH,toFillW,nPut,putList);
    /*
    if(nPut==3 && putList[2].sizeW==200)
      cout << "detectToFill " << nPut << ' ' << toFillH << ' ' << toFillW << endl;
    */
    if(toFillH!=-1 && toFillW!=-1){

      for(int i=0;i<4;i++){
	
	if(used[i]) continue;
	used[i] = true;
	
	double ratio=(double)(sizeList[i].second)/sizeList[i].first;
	double nextSizeW=sizeList[i].first;
	double nextSizeH=sizeList[i].second;
	
	for(int j=0;(int)(toFillW+nextSizeW+0.5)<=width && (int)(toFillH+nextSizeH+0.5)<=height; 
	    j++,nextSizeW+=1,nextSizeH+=ratio){
	  
	  int nsw = (int)(nextSizeW+0.5);
	  int nsh = (int)(nextSizeH+0.5);
	  
	  if(nPut==2){
	    if(!((int)(toFillW+nextSizeW+0.5)==width || 
	         (int)(toFillH+nextSizeH+0.5)==height ||
		 (int)(toFillW+nextSizeW+0.5)==putList[1].posW ||
		 (int)(toFillH+nextSizeH+0.5)==putList[1].posH+putList[1].sizeH)) continue;
	  }
	  else{
	    if(!((int)(toFillW+nextSizeW+0.5)==width || 
		 (int)(toFillH+nextSizeH+0.5)==height)) continue;
	  }
	  
	  if(!(fabs((int)(nextSizeH+0.5)-nextSizeH)<FLT_EPSILON)) continue;
	  
	  if(invades(nPut,toFillW,toFillH,nsw,nsh,putList)) break;

	  putList[nPut] = Data(toFillW,toFillH,nsw,nsh);
	  
	  if(fit(used,nPut+1,putList,currArea+nsw*nsh)) return true;
	}
	
	used[i] = false;
      }
    }
  }
  
  return false;
}

void work(int cases){
  
  bool used[4];
  Data putList[4];
  
  for(int i=0;i<4;i++)
    used[i] = false;
  
  cout << "Set " << cases << ": ";
  
 if(fit(used,0,putList,0)) {
   cout << "Yes" << endl;
   return;
 }
  
  cout << "No" << endl;

}

int main(){
  
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
