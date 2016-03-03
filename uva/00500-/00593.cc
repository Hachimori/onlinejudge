// graph simulation

#include<iostream>
#include<set>
#include<string>
#include<map>
#include<algorithm>
#include<vector>

#define MAX_QUERY 1005
#define INF 10000000
#define MAX_SIZE 15

using namespace std;

class Query{
public:

  string command;
  int ttl, host, group, packet;
};

class Message{
public:

  int host, packet, ttl;

  Message(){}
  Message(int h, int p, int t): host(h), packet(p), ttl(t) {}

  bool operator< (const Message &m) const {
    if(host==m.host) return packet<m.packet;
    return host<m.host;
  }
};

map<string,int> land2id; // id: “‡‚Ìid
map<int,int> host2id;    // id: “‡‚Ìid
set<int> land2host[MAX_SIZE];
int nIsland;
int adjList[MAX_SIZE][MAX_SIZE];
int nQuery;
Query query[MAX_QUERY];

bool read(){
  cin >> nIsland;
  if(nIsland==0) return false;
  
  for(int i=0;i<MAX_SIZE;i++){
    for(int j=0;j<MAX_SIZE;j++)
      adjList[i][j] = INF;
    land2host[i].clear();
  }
  land2id.clear();
  host2id.clear();
  
  for(int i=0;i<nIsland;i++){
    string name;
    int nCommand;

    cin >> name >> nCommand;
    
    int id;
    if(!land2id.count(name)){
      int size = land2id.size();
      land2id[name] = size;
    }
    id = land2id[name];

    for(int j=0;j<nCommand;j++){
      string command; cin >> command;

      if(command=="T"){
	int cost;
	string t;
	cin >> cost >> t;

	if(!land2id.count(t)){
	  int size = land2id.size();
	  land2id[t] = size;
	}

	adjList[id][land2id[t]] = cost;
      }
      else {
	int host;  cin >> host;
	
	host2id[host] = id;
	land2host[id].insert(host);
      }
    }
  }
  
  cin >> nQuery;
  for(int i=0;i<nQuery;i++){
    cin >> query[i].command;
    if(query[i].command=="J" || query[i].command=="L" )
      cin >> query[i].host >> query[i].group;
    else
      cin >> query[i].host >> query[i].group
	  >> query[i].packet >> query[i].ttl;
  }
  
  return true;
}

void warshall(int cost[][MAX_SIZE]){
  for(int i=0;i<nIsland;i++)
    for(int j=0;j<nIsland;j++)
      cost[i][j] = adjList[i][j];
  
  for(int i=0;i<nIsland;i++)
    cost[i][i] = 0;
  
  for(int k=0;k<nIsland;k++)
    for(int i=0;i<nIsland;i++)
      for(int j=0;j<nIsland;j++)
	cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
}

void work(int cases){
  /*
  for(int i=0;i<nIsland;i++){
    for(int j=0;j<nIsland;j++){
      if(adjList[i][j]==INF) cout << "#  ";
      else cout << adjList[i][j] << "  ";
    }cout << endl;
  }cout << endl;

  for(map<string,int>::iterator i=land2id.begin();i!=land2id.end();i++)
    cout << i->first << " id: " << i->second << endl;
  cout << endl;

  for(map<int,int>::iterator i=host2id.begin();i!=host2id.end();i++)
    cout << i->first << " joins id: " << i->second << endl;
  cout << endl;

  for(int i=0;i<nIsland;i++){
    for(set<int>::iterator j=land2host[i].begin();j!=land2host[i].end();j++){
      cout << i << " have host: " << *j << endl;
    }
  }
  cout << endl << endl;
  */
  
  int cost[MAX_SIZE][MAX_SIZE];
  warshall(cost);
  
  map<int, set<int> > group2host;
  vector<Message> message;

  for(int i=0;i<nQuery;i++){
    if(query[i].command=="J")
      group2host[query[i].group].insert(query[i].host);

      
    if(query[i].command=="L")
      group2host[query[i].group].erase(query[i].host);
    
    if(query[i].command=="S"){
      for(int j=0;j<nIsland;j++){
	if(query[i].ttl<cost[host2id[query[i].host]][j]) continue;
	
	int remain = query[i].ttl-cost[host2id[query[i].host]][j];
	
	for(set<int>::iterator k=land2host[j].begin();k!=land2host[j].end();k++){

	  if(!group2host[query[i].group].count(*k)) continue;

	  message.push_back(Message(*k,query[i].packet,remain));
	  
	}

      }
    }
  }

  sort(message.begin(),message.end());

  cout << "Network #" << cases << endl;
  for(int i=0;i<message.size();i++){
    cout << message[i].host << ' ' << message[i].packet << ' ' << message[i].ttl << endl;
  }
}

int main(){
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }
  
  return 0;
}
