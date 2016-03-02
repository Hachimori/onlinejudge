#include<iostream>
#include<string>
#include<vector>
#include<map>

class City{
 public:

  int Node;
  string C;
  string ADMD;
  string PRMD;
  string O;

  City(){}

  City( int node, string c, string admd, string prmd, string o ){
    Node = node, C = c, ADMD = admd, PRMD = prmd, O = o;
  } 


};

map<string, int> cityList;
map<int,string> str_cityList;
City source;
int curr_num_city;
int num_city;
int cases,scenario;
string start,C,ADMD,PRMD,O;

class Graph{
 public:

   vector< vector<City> > adjList;
   vector< vector<City>::iterator > pos;
   vector< int > visited;

   Graph(){}

   Graph(int n){
     adjList.assign( n+1, vector<City>() );
     visited.assign( n+1, false );
     pos.assign( n+1, vector<City>::iterator() );
   }

   void insert(int city1, int city2, string city2_c, string city2_admd, string city2_prmd, string city2_O ){
     adjList[city1].push_back( City(city2,city2_c,city2_admd,city2_prmd,city2_O) );
   } 

   void reset(int n){
     for(int i=0;i<=n;i++)
       pos[i] = adjList[i].begin();

     for(int i=0;i<=n;i++) visited[i] = false;
   }

   City next(int n){
     if( pos[n] != adjList[n].end() ) return *pos[n]++;
     else return City(-1," "," "," "," ");
   }

};

class Solver{
 public:

  bool read_graph(Graph &g){
    
    cin >> num_city;
    if(cin.eof()) return false;

    g = Graph(num_city);

    str_cityList.clear();
    cityList.clear();

    curr_num_city=0;

    for(int i=0;i<num_city;i++){
      string stat_city;
      int num_node;
      int source_node;

      cin >> stat_city >> num_node;
      
      if(cityList.find(stat_city)==cityList.end()){ 
	cityList[stat_city] = curr_num_city;
	str_cityList[curr_num_city] = stat_city;
	source_node = curr_num_city;
	curr_num_city++;
      } 
      else{
	source_node = cityList[stat_city];
      }
      
      for(int j=0;j<num_node;j++){
	string cityName,C,ADMD,PRMD,O;
	int target_node;

	cin >> cityName >> C >> ADMD >> PRMD >> O;

	if(cityList.find(cityName)==cityList.end()){ 
	  cityList[cityName] = curr_num_city;
	  str_cityList[curr_num_city] = cityName;
	  target_node = curr_num_city;
	  curr_num_city++;
	} 
	else{
	  target_node = cityList[cityName];
	}

	g.insert(source_node,target_node,C,ADMD,PRMD,O);

      }

    }

  }

  void read(Graph &g){
    /*
    cout << curr_num_city << endl;
    g.reset(num_city);
    while(true){
      string tmp;
      City curr;
      cin >> tmp;
      while(true){
	curr = g.next(cityList[tmp]);
	if(curr.Node == -1) break;
	else {
	  cout << str_cityList[curr.Node] << "  " << curr.C << "  " << curr.ADMD << "  " << curr.PRMD << "  " << curr.O << endl;
	}
      } 
    }
    */

    g.reset(num_city);
    
    cin >> start >> C >> ADMD >> PRMD >> O;

    int curr_num = cityList[start];

    source = City(curr_num,C,ADMD,PRMD,O);

  }

  void work(Graph &g){
    
    City next;
    

    while(true){
      
      next = g.next(source.Node);
      
      if(next.Node==-1){ 
	cout << cases << " -- unable to route at " << str_cityList[source.Node] << endl;
	return;
      }
      else if(source.Node==next.Node){
	if(next.C.compare("*")==0 || next.C.compare(source.C)==0 )
	  if(next.ADMD.compare("*")==0 || next.ADMD.compare(source.ADMD)==0 )
	    if(next.PRMD.compare("*")==0 || next.PRMD.compare(source.PRMD)==0 )
	      if(next.O.compare("*")==0 || next.O.compare(source.O)==0 ){
		cout << cases << " -- delivered to " << str_cityList[source.Node] << endl;
		return;
	      }
      }
      else if(g.visited[next.Node] == true){
	if(next.C.compare("*")==0 || next.C.compare(source.C)==0 )
	  if(next.ADMD.compare("*")==0 || next.ADMD.compare(source.ADMD)==0 )
	    if(next.PRMD.compare("*")==0 || next.PRMD.compare(source.PRMD)==0 )
	      if(next.O.compare("*")==0 || next.O.compare(source.O)==0 ){
		cout << cases << " -- circular routing detected by " << str_cityList[next.Node] << endl;
		return;	
	      }
      }

      
      g.visited[source.Node] = true;
      
      if(next.C.compare("*")==0 || next.C.compare(source.C)==0 ){
	if(next.ADMD.compare("*")==0 || next.ADMD.compare(source.ADMD)==0 ){
	  if(next.PRMD.compare("*")==0 || next.PRMD.compare(source.PRMD)==0 ){
	    if(next.O.compare("*")==0 || next.O.compare(source.O)==0 ){
	      //cout << next.C << "  " << next.ADMD << "  " << next.PRMD << "  " << next.O << endl;
	      //cout << source.C << "  " << source.ADMD << "  " << source.PRMD << "  " << source.O << endl;
	      source.Node = next.Node;
	    }
	  }
	}
      }
      
      
    }

  }

};

main(){

  int test_cases;
  Solver solver;
  Graph g;

  for(scenario=1;;scenario++){

    if(solver.read_graph(g)==false) break;
    
    cin >> test_cases;


    cout <<"Scenario # " << scenario << endl ;
 

    for(cases=1;cases<=test_cases;cases++){
      solver.read(g);
      solver.work(g);
    }
    
    cout << endl;

  }

}
