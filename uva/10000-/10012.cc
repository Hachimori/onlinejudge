#include<iostream>
#include<cstdio>
#include<cmath>
#include<cfloat>

using namespace std;

class Point{
public:

        double x,y;

        Point(){}
        Point(double x, double y) : x(x), y(y) {}

        double distance(Point &p){
                return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
        }

};

int n;
double ans;
double L[9];

void calc(int C[9]){

        Point P[9];


        P[0] = Point(L[C[0]], L[C[0]]);

        for(int i=1;i<n;i++){

                double h = fabs(L[C[i]]-L[C[i-1]]);
                double d = L[C[i]]+L[C[i-1]];
                P[i] = Point(sqrt(d*d-h*h)+P[i-1].x,L[C[i]]);


                for(int j=i-2;j>=-1;j--){
                        if(j>=0 && P[i].distance(P[j])<L[C[i]]+L[C[j]]){
                                double h2 = fabs(L[C[i]]-L[C[j]]);
                                double d2 = L[C[i]]+L[C[j]];
                                P[i] = Point(sqrt(d2*d2-h2*h2)+P[j].x,L[C[i]]);
                        }
                        else if(j==-1 && P[i].x-L[C[i]]<0){
                                P[i] = Point(L[C[i]], L[C[i]]);
                        }
                }

        }


        double maxWidth=-1;

        for(int k=0;k<n;k++)
                if(maxWidth<P[k].x+L[C[k]])
                        maxWidth = P[k].x+L[C[k]];

        //for(int z=0;z<n;z++){
        //      cout << P[z].x << " " << P[z].y << endl;
        //}cout << endl;

        if(ans>maxWidth) ans = maxWidth;

}

void rec(int curr, int chosenL[9], bool alreadyUsed[9]){

        if(curr==n){
                calc(chosenL);
                return;
        }

        for(int i=0;i<n;i++){
                
                if(!alreadyUsed[i]){
                        alreadyUsed[i] = true;
                        chosenL[curr] = i;
                        
                        rec(curr+1,chosenL,alreadyUsed);

                        alreadyUsed[i] = false;
                }
                
        }

}

void work(){

        bool alreadyUsed[9];
        int chosenL[9];

        for(int i=0;i<n;i++)
                alreadyUsed[i]=false;

        rec(0,chosenL,alreadyUsed);

        printf("%.3f\n",ans);
}

int main(){

        int cases;
        
        cin >> cases;

        for(int i=0;i<cases;i++){
                cin >> n;

                if(n==0) continue;
                
                for(int j=0;j<n;j++)
                        cin >> L[j];
                
                ans = DBL_MAX;

                work();
        }

        return 0;
}
