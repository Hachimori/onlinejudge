#include<iostream>
#include<set>

#define MAX_SIZE 1000005

using namespace std;

class ThreeNum{
public:
	int a, b, c;

	ThreeNum(){}
	ThreeNum(int a, int b, int c): a(a), b(b), c(c){}

	bool operator< ( ThreeNum const &t ) const{
		
		if(a<t.a) return true;
		else if(a==t.a){
			if(b<t.b) return true;
			else if(b==t.b){
				return c<t.c;
			}
		}

		return false;
	}

};

int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

int n;

bool read(){
	if(!(cin >> n)) return false;

	return true;
}

void work(){
	
	int ansA=0;
	bool used[MAX_SIZE];
	set<ThreeNum> S;

	for(int i=0;i<=n;i++)
		used[i] = false;

	for(int b=1;b*b<=n;b++){
		for(int a=1;a<b && a*a+b*b<=n;a++){
			if(b%2==1 && a%2==1) continue;
			
			for(int c=1;c*(a*a+b*b)<=n;c++){
				used[c*(b*b-a*a)]=true;
				used[c*2*a*b]=true;
				used[c*(a*a+b*b)]=true;
			}

			if(gcd(b*b-a*a,2*b*a)!=1) continue;
			
			
			ansA++;
			
		}
	}

	int ansB=0;
	for(int j=1;j<=n;j++)
		if(!used[j]) 
			ansB++;

	cout << ansA << " " << ansB << endl;
}

int main(){

	while(read())
		work();
		
	return 0;
}