/* 2D-array -- https://leetcode.com/problems/search-a-2d-matrix/ */


/* Solution-1 => Brute Force */
/* Time comp. - O(N*M) */
/* Space comp. - O(1) */

/* Solution-2 => Binary Search */
/* Time comp. - O(log(N*M)) */
/* Space comp. - O(1) */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n==0) return false;
        
        int m = matrix[0].size();
        if(m==0) return false;
        
        int l = 0;
        int r = n*m - 1, mid;
        
        while(l<=r){
            
            mid = (l+r)/2;
            int x = mid/m;
            int y = mid - m*x;
            
            if(matrix[x][y] == target)
                return true;
            else if(matrix[x][y]>target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return false;
    }
};
