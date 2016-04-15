#include<iostream>
#include<algorithm>
#include<vector>

#define MAX_SIZE 22

using namespace std;

class News{
public:

  int source, target;
  int time;

  News(){}
  News(int source, int target, int time): source(source), target(target), time(time){}
  
  bool operator< (const News &n) const {
    return time<n.time;
  }
  
};

int nPeople;
vector<News> newsList;

bool read(){

  int nPair;
  cin >> nPeople >> nPair;

  newsList.clear();
  
  for(int i=0;i<nPair;i++){
    News tmpNews;
    int frequency;
    cin >> tmpNews.source >> tmpNews.target >> frequency;
    
    for(int i=0;i<frequency;i++){
      cin >> tmpNews.time;
      newsList.push_back(tmpNews);
    }

  }

  sort(newsList.begin(),newsList.end());
  
}

bool allVisited( bool visited[MAX_SIZE] ){
  
  for(int i=1;i<=nPeople;i++)
    if(!visited[i]) return false;
  
  return true;
}

void work(){
  
  /*
    for(int i=0;i<newsList.size();i++){
    cout << newsList[i].source << ' ' << newsList[i].target << ' ' << newsList[i].time << endl;
  }cout << endl;
  */

  int day, lastTime;
  bool succeed;
  bool visited[MAX_SIZE];
  
  for(int i=1;i<=nPeople;i++)
    visited[i]=false;
  visited[1] = true;

  for(day=0;;day++){
    succeed=false;
    lastTime=0;
    
    /*
    for(int i=1;i<=nPeople;i++)
      if(visited[i]) cout << "ok ";
      else cout << "no ";
    cout << endl;
    */

    for(int i=0;i<newsList.size();i++){
      int nSameTime=0;
      int pos=i;
      
      while(i+1<newsList.size() && newsList[i].time==newsList[i+1].time){
	nSameTime++;
	i++;
      }
      
      // 同じ時間に複数の人が出会うとき
      if(nSameTime>0){
	for(int j=0;j<=nSameTime;j++){
	  for(int k=pos;k<=pos+nSameTime;k++){
	    
	    if(visited[newsList[k].source] && !visited[newsList[k].target]){
	      visited[newsList[k].target] = true;     
	      if(lastTime<newsList[k].time)
		lastTime=newsList[k].time;
	      succeed=true;
	    }
	    else if(visited[newsList[k].target] && !visited[newsList[k].source]){
	      visited[newsList[k].source] = true;     
	      if(lastTime<newsList[k].time)
		lastTime=newsList[k].time;
	      succeed=true;
	    }
	    	    
	  }
	}
	if(allVisited(visited)) break;
	continue;
      }
      
      if(visited[newsList[i].source] && !visited[newsList[i].target]){
	visited[newsList[i].target] = true;     
	if(lastTime<newsList[i].time)
	  lastTime=newsList[i].time;
	succeed=true;
      }
      else if(visited[newsList[i].target] && !visited[newsList[i].source]){
	visited[newsList[i].source] = true;     
	if(lastTime<newsList[i].time)
	  lastTime=newsList[i].time;
	succeed=true;
      }

    }
    
    if(!succeed) break;
    if(allVisited(visited)) break;
  }
  
  if(!succeed) cout << "-1" << endl;
  else cout << day*100+lastTime << endl;

}

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
