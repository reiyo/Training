// refer to https://leetcode.com/problems/palindrome-removal/discuss/418881
// refer to https://leetcode.com/problems/palindrome-removal/discuss/424454
// refer to https://www.geeksforgeeks.org/minimum-steps-to-delete-a-string-after-repeated-deletion-of-palindrome-substrings/
class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        vector<vector<int> > table(n, vector<int>(n, 0));

        for (int i=0; i<n; ++i) table[i][i] = 1;
        
        for (int i=0; i+1<n; ++i) {
            if (arr[i] == arr[i+1]) table[i][i+1] = 1;
            else table[i][i+1] = 2; // must be two moves
        }
        
        for (int len=3; len<=n; ++len) {
            for (int i=0; i+len-1<n; ++i) {
                int j=i+len-1;
                
                // if len==2 is not handled earlier, len==2 will cause problems below
                if (arr[i] == arr[j]) table[i][j] = table[i+1][j-1]; // same as move of [i+1][j-1]
                else table[i][j] = 2 + table[i+1][j-1];
                
                // no matter arr[i] equals arr[j] or not; split is a possible solution
                for (int k=i; k+1<=j; ++k) table[i][j] = min(table[i][j], table[i][k] + table[k+1][j]);
            }
        } 

        return table[0][n-1];
    }
};
