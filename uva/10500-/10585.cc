// ad-hoc
//
// ���ׂĂ̓_��center of symmetry (CSP) �𒆐S�ɑΏۈړ������_�����Ɖ��肷��B
// ��������ƁA�ŏ���x�̒��̍ŏ���y�����_��CSP�𒆐S�ɑΏۈړ������Ƃ�
// �@�@�@�@�@�@�ő��x�̒��̍ő��y�����_�ɂȂ�͂��ł���B
//
// �������āACSP�����Ɍ��肵�āA�S�_��CSP�𒆐S�ɑΏۈړ������_�������ǂ����𔻒肷��B
//
//
// ���ׂĂ̓_�͊i�q�_��ɑ��݂��Ă��邱�Ƃ���A
// CSP�𒆐S�ɑΏۈړ������_���A�i�q�_��ɖ����Ƃ� no �Əo�͂��Ȃ��Ă͂Ȃ�Ȃ��B

#include<iostream>
#include<algorithm>
#include<cfloat>

#define EPS FLT_EPSILON
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define MAX_SIZE 10005

using namespace std;

class Point{
public:
  int x, y;

  Point(){}
  Point(int x, int y): x(x), y(y){}

  bool operator< ( const Point &p ) const {
    if(x==p.x) return y<p.y;
    return x<p.x;
  }
};

int nPoint;
Point point[MAX_SIZE];

void read(){
  cin >> nPoint;
  
  for(int i=0;i<nPoint;i++)
    cin >> point[i].x >> point[i].y;
}

void work(){
  double centerX, centerY;
  
  sort(point,point+nPoint);
  
  centerX = (point[0].x+point[nPoint-1].x)/2;
  centerY = (point[0].y+point[nPoint-1].y)/2;
  
  for(int i=0;i<nPoint;i++){
    double doubleX = (point[i].x + 2*(centerX-point[i].x));
    double doubleY = (point[i].y + 2*(centerY-point[i].y));
    
    int intX, intY;
    
    if(doubleX<0)
      intX = (int)(doubleX-0.5);
    else
      intX = (int)(doubleX+0.5);

    if(doubleY<0)
      intY = (int)(doubleY-0.5);
    else
      intY = (int)(doubleY+0.5);
    

    
    if( !EQ(intX,doubleX) || !EQ(intY,doubleY) ){ 
      cout << "no" << endl;
      return;
    }

    if(!binary_search(point,point+nPoint,Point(intX,intY))){
      cout << "no" << endl;
      return;
    }
  }

  cout << "yes" << endl;
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
