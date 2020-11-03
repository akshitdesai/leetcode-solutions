/* 2D-array -- https://leetcode.com/problems/set-matrix-zeroes/ */


/* Solution-1 */
/* Time comp. - O(M*N) */
/* Space comp. - O(1) */

class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        
        int n = a.size();
        
        if(n==0)
            return;
        
        int m = a[0].size();
        int column = false;
        int row = false;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j]==0){
                    if(j==0)    column = true;
                    if(i==0)    row = true;
                    if(i!=0 && j!=0){
                        a[i][0] = 0;
                        a[0][j] = 0;
                    }
                }
            }
        }
        
        for(int i = n-1; i > 0; i--)
            for(int j = m-1; j > 0; j--)
                if(a[i][0] == 0 || a[0][j] == 0)
                    a[i][j] = 0;
        
        if(row)
            for(int j = 0; j < m; j++)
                a[0][j] = 0;
        
        if(column)
            for(int i = 0; i < n; i++)
                a[i][0] = 0;
            
    }
};
