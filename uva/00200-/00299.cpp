#include<iostream>
#include<vector>
using namespace std;

void Input_Output(void);

main()
{
	int n;
	cin >> n;

	for(int i=0;i<n;i++){
		Input_Output();
	}

}

void Input_Output(void){

	int L,tmp,sum=0,j;
	vector<int> v;
	vector<int>::iterator j_ret;
	
	cin >> L;

	for(int i=0;i<L;i++){
		cin >> tmp;
		v.push_back(tmp);
	}

	for(int i=0;i<L;i++){
		for(j=0,  j_ret=v.begin(); j_ret!=v.end(); j++,j_ret++){
			if(v[j]==i+1){
				sum+=j;
				v.erase(j_ret);
				break;
			}
			//cout << "oo";
		}
	}

	cout << "Optimal train swapping takes " << sum << " swaps." << endl;

	return;

}
