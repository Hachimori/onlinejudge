// Geometry
//
// �ŏ��̑��p�`�̕ӂ̃��X�g�A��Ԗڂ̑��p�`�̕ӂ̃��X�g��
// ���ꂼ�� dst, src �Ƃ���B src �� dst �̍ŏ��̓_�ɍ��킹�ĕ��s�ړ��A
// 2�Ԗڂ̓_�ɍ��킹��1�Ԗڂ̓_�𒆐S�ɉ�]�A�g��i�k���j����
// ���p�`�S�̂���v���Ă��邩�ǂ������ׂ�B
//
// ���̃v���O�����́A��������]�ɂ�葽�p�`����v���Ă�����̂̌�₪��������
// �Ȃ���p�x�����������̂�D�悵�Č��肵�Ă��邪�A���ɂ͂�������Ƃ�����ĂȂ��Ǝv���B

#include<iostream>
#include<cstdio>
#include<cmath>
#include<complex>
#include<cassert>
#include<utility>
#include<cfloat>
#include<climits>

#define EPS FLT_EPSILON
#define PI acos(-1.0)
#define MAX_SIZE 100
#define EQ(x,y) (fabs((x)-(y))<(FLT_EPSILON*100))

using namespace std;

int nPolygon, nVertex;
complex<double> dst[MAX_SIZE][MAX_SIZE];
complex<double> src[MAX_SIZE][MAX_SIZE];

bool read(){
  if(!(cin >> nPolygon >> nVertex)) return false;
  assert(nPolygon<MAX_SIZE && nVertex<MAX_SIZE);
  
  for(int i=0;i<nPolygon;i++)
    for(int j=0;j<nVertex;j++){
      double r;
      cin >> r;

      dst[i][j] = polar(r,PI/2-PI*2/nVertex*j);
    }
  
  for(int i=0;i<nPolygon;i++)
    for(int j=0;j<nVertex;j++){
      double x,y;
      cin >> x >> y;

      src[i][j] = complex<double>(x,y);
    }

  return true;
}

double calcDegree(complex<double> &o, complex<double> &a, complex<double> &b){
  complex<double> ret = ((b-o)/abs(b-o))/((a-o)/abs(a-o));
  return arg(ret);
}

double calcRadius(complex<double> &o, complex<double> &a, complex<double> &b){
  return abs((b-o)/(a-o));
}

void rotate(complex<double> &o, complex<double> &c, double &radius, double &angle){
  c = (c-o)*polar(radius,angle)+o;
}

void work(){

  complex<double> toSet[MAX_SIZE];
  complex<double> diff;
  bool used[MAX_SIZE];
  
  for(int i=0;i<MAX_SIZE;i++)
    used[i] = false;
  
  for(int curr=0;curr<nPolygon;curr++){
    double minVal = INT_MAX;
    int minPos;
    
    for(int opp=0;opp<nPolygon;opp++){
      if(used[opp]) continue;
      
      for(int start=0;start<nVertex;start++){
	
	int prev = (start-1+nVertex)%nVertex;
	int next = (start+1)%nVertex;
	
	// dest, src�̊J�n�_���Ȃ��p�x�͈�v���ĂȂ��Ă͂Ȃ�Ȃ��B
	// ���������邽�ߕK�v
	if(!EQ(calcDegree(src[curr][start],src[curr][prev],src[curr][next]),
	       calcDegree(dst[opp][0],dst[opp][nVertex-1],dst[opp][1])) ) continue;
	
	for(int i=0;i<nVertex;i++)
	  toSet[i] = src[curr][i];
	

	diff = dst[opp][0] - toSet[start];
	for(int i=0;i<nVertex;i++)
	  toSet[i] += diff;
	

	
	double angle  = calcDegree(toSet[start],toSet[next],dst[opp][1]);
	double radius = calcRadius(toSet[start],toSet[next],dst[opp][1]);
	
	
	for(int i=next,j=0;j<nVertex-1;i=(i+1)%nVertex,j++)
	  rotate(toSet[start],toSet[i],radius,angle);
	

	
	bool succeed = true;
	for(int i=0,j=start;i<nVertex;i++,j=(j+1)%nVertex)
	  if(abs(toSet[j]-dst[opp][i])>abs(dst[opp][i])*0.001){
	    succeed = false;
	    break;
	  }
	
	if(succeed) {
	  angle *= (-1);
	  if(angle<0)
	    angle += PI*2;
	  
	  if(minVal>angle){
	    minVal = angle;
	    minPos = opp;
	  }
	}
	
      }

    }
    
    used[minPos] = true;
    assert(!EQ(minVal,INT_MAX));
    printf("%d %.1lf\n",minPos+1,180*(minVal)/PI);

  }
  
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
