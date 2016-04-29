#include<iostream>
using namespace std;


int n, m;

void read() {
    cin >> n >> m;
}


void work() {
    if ((n - 1) % (m - 1) == 0) {
        cout << (n - 1) / (m - 1) << endl;
    }
    else {
        cout << "cannot do this" << endl;
    }
}


int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        read();
        work();
    }
    return 0;
}
