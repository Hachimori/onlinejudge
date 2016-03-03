#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int ITEM = 30005;


int nItem, item[ITEM];
int nOutPos, outPos[ITEM];

void read() {
    cin >> nItem >> nOutPos;
    for (int i = 0; i < nItem; ++i) {
        cin >> item[i];
    }
    
    for (int i = 0; i < nOutPos; ++i) {
        cin >> outPos[i];
    }
}


void work() {
    priority_queue<int, vector<int>, less<int> > LQ;
    priority_queue<int, vector<int>, greater<int> > RQ;
    
    int curOutPos = 0;
    for (int curItem = 0; curItem < nItem || curOutPos < nOutPos;) {
        if (curOutPos < nOutPos && curItem == outPos[curOutPos]) {
            cout << LQ.top() << endl;
            if (!RQ.empty()) {
                LQ.push(RQ.top());
                RQ.pop();
            }
            ++curOutPos;
        }
        else {
            if (LQ.size() <= curOutPos) {
                LQ.push(item[curItem]);
            }
            else if (item[curItem] < LQ.top()) {
                RQ.push(LQ.top());
                LQ.pop();
                LQ.push(item[curItem]);
            }
            else {
                RQ.push(item[curItem]);
            }
            ++curItem;
        }
    }
}


int main(){
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        if (i) cout << endl;
        read();
        work();
    }
}
