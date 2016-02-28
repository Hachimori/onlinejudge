#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<climits>
#include<cfloat>

#define MAX_SIZE 55

using namespace std;

class Node{
public:

	double pos, fillCost;

	Node(){}
	Node(double p, double c): pos(p), fillCost(c) {}

};

class Element{
public:

	int pos;
	double cost, remain;

	Element(){}
	Element(int p, double c, double r): pos(p), cost(c), remain(r) {}
	
	bool operator<( const Element &e ) const {
		return cost>e.cost;
	}

};

int nNode;
double destination, capacity, runCost;
Node nodeList[MAX_SIZE];

bool read(){
	
	cin >> destination;
	if(destination==-1) return false;

	cin >> capacity >> runCost >> nodeList[0].fillCost >> nNode;

	nodeList[0].pos = 0.0;

	nNode++;

	for(int i=1;i<nNode;i++)
		cin >> nodeList[i].pos >> nodeList[i].fillCost;	

	return true;

}

void dijkstra(){
	
	priority_queue<Element> Q;	
	double cost[MAX_SIZE];

	fill(cost,cost+nNode+1,INT_MAX);

	Q.push(Element(0,0,capacity));

	while(!Q.empty()){
		
		Element curr=Q.top();
		Q.pop();

		
		//cost[curr.pos] = curr.cost;
			

		if(curr.pos!=0){
			curr.cost+=(int)((capacity-curr.remain)*nodeList[curr.pos].fillCost+0.5);
			curr.cost+=200.0;
			curr.remain=capacity;
		}
		
		if(cost[nNode]<curr.cost) continue;	

		bool go=false;
		for(int k=curr.pos+1;k<nNode;k++)
			if(0>curr.remain-(nodeList[k].pos-nodeList[curr.pos].pos)/runCost) go=true;
		if(0>curr.remain-(destination-nodeList[curr.pos].pos)/runCost) go = true;

		/* ガソリンの量が半分になる場所に行く */ 
		if(!go)
			for(int j=1;j<nNode;j++){
				double costFuel;
				
				if(j>curr.pos)
					costFuel = (nodeList[j].pos-nodeList[curr.pos].pos)/runCost;
				else
					costFuel = (nodeList[curr.pos].pos-nodeList[j].pos)/runCost;
			
				if(curr.pos!=j && 0<=curr.remain-costFuel && curr.remain-costFuel<capacity/2){
					Q.push(Element(j,curr.cost,curr.remain-costFuel));
				}
			} 
		else	/* ガソリンの量が半分以上になる場所に行く */
		for(int i=1;i<nNode;i++){
			double costFuel;
			
			if(i>curr.pos)
				costFuel = (nodeList[i].pos-nodeList[curr.pos].pos)/runCost;
			else
				costFuel = (nodeList[curr.pos].pos-nodeList[i].pos)/runCost;

			if(curr.pos!=i && 0<=curr.remain-costFuel)
				Q.push(Element(i,curr.cost,curr.remain-costFuel));
		}
		
		if(0<=curr.remain-(destination-nodeList[curr.pos].pos)/runCost){
			if(cost[nNode]>(curr.cost+(int)(nodeList[0].fillCost*100+0.5)))
				cost[nNode] = (curr.cost+(int)(nodeList[0].fillCost*100+0.5));	
		}

	}

	printf("minimum cost = $%.2lf\n",cost[nNode]/100);
}

void work(int cases){

	cout << "Data Set #" << cases << endl;

	dijkstra();
	
}

int main(){

	for(int i=1;read();i++)
		work(i);

	return 0;
}