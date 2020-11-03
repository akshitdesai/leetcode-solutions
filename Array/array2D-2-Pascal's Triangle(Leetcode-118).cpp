/* 2D-array -- https://leetcode.com/problems/pascals-triangle/ */


/* Solution-1 */
/* Time comp. - O(M*N) */
/* Space comp. - O(M*N) */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        
        for(int i = 0; i < numRows; i++){
            
            ans[i].resize(i+1);
            ans[i][0] = ans[i][i] = 1;
            
            for(int j = 1; j < i; j++){
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];    
            }
        }
        return ans;
    }
};
