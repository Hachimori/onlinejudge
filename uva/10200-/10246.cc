// Graph, dijkstra+�}���
//
//
// �O���t�̃m�[�h�� (���ݒn)*(����܂łɒH������ԉh���Ă����s�s�́A���Ԗڂɉh���Ă�����) 
// �Ɋg���B priority first search �Ǝ}��������B
//
// �}���́A����s�s�ɒ������Ƃ��A�����ɒ����܂łɂ��������R�X�g���ȑO���������A
// �������ɒ����܂łɒʂ�����ԉh���Ă����s�s�̓x�������ȑO���������ꍇ�A�T����ł��؂���́B
//�@�@����������
// if(maxCost[curr.pos]!=-1 && maxCost[curr.pos]<=curr.cost && maxCity[curr.pos]<=curr.order)
//
// ���ꂪ�AmaxCost[curr.pos]<=curr.cost ���AmaxCity[curr.pos]<=curr.order �̂ǂ��炩�����藧���Ȃ�
// �Ȃ�Ύ��̃m�[�h���X�V�ł���\��������̂����A�������藧���Ă��܂��Ǝ��ɒH��m�[�h�����m����
// �R�X�g�������Ȃ��Ă��܂�����ł���B

#include<iostream>
#include<map>
#include<set>
#include<utility>
#include<queue>

#define INF 1000000000
#define MAX_SIZE 85
#define MAX_QUERY 6400

using namespace std;

class Data{
public:

  int pos, order, cost;

  Data(){}
  Data(int p, int o, int c): pos(p), order(o), cost(c){}

  bool operator<(const Data &d) const {
    if(cost==d.cost) return order>d.order;
    return cost>d.cost;
  }
};

int nNode, nQuery, city[MAX_SIZE];
pair<int,int> query[MAX_QUERY];
int adjList[MAX_SIZE][MAX_SIZE];

bool read(){
  int nEdge;
  cin >> nNode >> nEdge >> nQuery;
  if(nNode==0 && nEdge==0 && nQuery==0) return false;
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++)
      adjList[i][j] = INF;
  
  for(int i=0;i<nNode;i++)
    cin >> city[i];
  
  for(int i=0;i<nEdge;i++){
    int s, t, c;
    cin >> s >> t >> c;
    s--, t--;
    adjList[s][t] = c;
    adjList[t][s] = c;
  }
  
  for(int i=0;i<nQuery;i++){
    cin >> query[i].first >> query[i].second;
    query[i].first--, query[i].second--;
  }

  return true;
}

void dijkstra(int s, int ans[][MAX_SIZE], int order[], int oToC[]){
  // cost �̉E���̓Y����n�́An�Ԗڂɉh���Ă���s�s��n
  int cost[MAX_SIZE][MAX_SIZE];
  int maxCost[MAX_SIZE], maxCity[MAX_SIZE];  // maxCost[n]: �s�sn��H�����Ƃ��̍ő�̃R�X�g
  priority_queue<Data> Q;                    // maxCost[n]: �s�sn��H�����Ƃ��Ɉ�ԉh���Ă����s�s
  
  for(int i=0;i<nNode;i++)
    for(int j=0;j<nNode;j++){
      cost[i][j] = INF;
      maxCost[i] = -1;
      maxCity[i] = -1;
    }

  Q.push(Data(s,order[s],0));

  while(!Q.empty()){
    Data curr = Q.top();
    Q.pop();

    if(cost[curr.pos][curr.order]<=curr.cost) continue;
    cost[curr.pos][curr.order] = curr.cost;
    
    if(maxCost[curr.pos]!=-1 && maxCost[curr.pos]<=curr.cost && maxCity[curr.pos]<=curr.order) continue;
    
    maxCost[curr.pos] = max(maxCost[curr.pos],curr.cost);
    maxCity[curr.pos] = max(maxCity[curr.pos],curr.order);
    
    for(int i=0;i<nNode;i++){
      if(adjList[curr.pos][i]==INF) continue;
      
      Data next = curr;

      next.pos = i;
      next.order = max(curr.order,order[i]);
      next.cost += adjList[curr.pos][i];

      if(cost[next.pos][next.order]<=next.cost) continue;
      Q.push(next);
    }
  }
 
  for(int i=0;i<nNode;i++){
    int minVal = INF;
    for(int j=0;j<nNode;j++)
      if(minVal>cost[i][j]+city[oToC[j]])
	minVal = cost[i][j]+city[oToC[j]];
      
    if(minVal!=INF)
      ans[s][i] = minVal;
    else
      ans[s][i] = -1;
  }
}

void work(int cases){
  int ans[MAX_SIZE][MAX_SIZE];
  int order[MAX_SIZE], oToC[MAX_SIZE];  // order[n] �͓s�sn�����Ԗڂɉh���Ă���̂���\���B
                                        // oToC[n] ��n�Ԗڂɉh���Ă���s�s�͂ǂ�����\���B
  for(int i=0;i<nNode;i++){
    int nLow = 0;
    for(int j=0;j<nNode;j++)
      if(city[i]>city[j]) nLow++;
    
    oToC[nLow] = i;
    order[i] = nLow;
  }
    
  for(int i=0;i<nNode;i++)
    dijkstra(i,ans,order,oToC);
  
  cout << "Case #" << cases << endl;
  for(int i=0;i<nQuery;i++)
    cout << ans[query[i].first][query[i].second] << endl;
}

int main(){
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }

  return 0;
}
