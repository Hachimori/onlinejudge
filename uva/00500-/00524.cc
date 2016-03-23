#include<iostream>
using namespace std;
const int BUF = 17;


int n;

bool read() {
    return cin >> n;
}


bool isPrime(int v) {
    for (int i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}


void rec(int nVisited, int lastNum, int hist[BUF], bool used[BUF]) {
    
    if (nVisited == n) {
        if (isPrime(1 + lastNum)) {
            for (int i = 0; i < n; ++i) {
                if (i) cout << ' ';
                cout << hist[i];
            }
            cout << endl;
        }
        return;
    }

    for (int i = 2; i <= n; ++i) {
        if (used[i]) continue;
        if (isPrime(i + lastNum)) {
            hist[nVisited] = i;
            used[i] = true;
            rec(nVisited + 1, i, hist, used);
            used[i] = false;
        }
    }
}

         
void work(int cases) {
    cout << "Case " << cases << ":" << endl;
    int hist[BUF];
    bool used[BUF] = {};
    hist[0] = 1;
    used[1] = true;
    rec(1, 1, hist, used);
}


int main() {
    for (int i = 0; read(); ++i) {
        if (i) cout << endl;
        work(i + 1);
    }
    return 0;
}
