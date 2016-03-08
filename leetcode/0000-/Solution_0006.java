package leetcode;

import java.lang.StringBuilder;

public class Solution_0006 {
    
    public String convert(String s, int numRows) {
        
        if (numRows == 1) {
            return s;
        }
        
        StringBuilder[] sbArray = new StringBuilder [numRows];
        for (int i = 0; i < numRows; ++i) {
            sbArray[i] = new StringBuilder();
        }
        
        for (int i = 0; i < s.length(); ++i) {
            int row;
            int t = i % ((numRows - 1) * 2);
            if (t < numRows) {
                row = t;
            }
            else {
                row = (numRows - 1) * 2 - t;
            }
            
            sbArray[row].append(s.charAt(i));
        }
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < sbArray.length; ++i) {
            sb.append(sbArray[i].toString());
        }
        return sb.toString();
    }
}
