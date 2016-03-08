package leetcode;

public class Solution_0004 {
    
    public double findMedianSortedArrays(int[] N, int[] M) {
        
        int n = N.length;
        int m = M.length;
        
        if ((n + m) % 2 == 0) {
            return (rec(N, 0, n - 1, M, 0, m - 1, (n + m) / 2 - 1) + rec(N, 0, n - 1, M, 0, m - 1, (n + m) / 2)) / 2.0;
        }
        else {
            return rec(N, 0, n - 1, M, 0, m - 1, (n + m) / 2);
        }
    }
    
    
    int rec(int[] N, int ln, int rn, int[] M, int lm, int rm, int K) {
        
        if (rn - ln < rm - lm) {
            return rec(M, lm, rm, N, ln, rn, K);
        }
        
        if (lm > rm) {
            return N[ln + K];
        }
        
        if (K == 0) {
            return Math.min(N[ln], M[lm]);
        }
        
        int midK = (K - 1) / 2;
        int nIdx = Math.min(rn, ln + midK);
        int mIdx = Math.min(rm, lm + midK);
        if (N[nIdx] < M[mIdx]) {
            return rec(N, nIdx + 1, rn, M, lm, rm, K - (nIdx - ln + 1));
        }
        else {
            return rec(N, ln, rn, M, mIdx + 1, rm, K - (mIdx - lm + 1));
        }
    }
}
