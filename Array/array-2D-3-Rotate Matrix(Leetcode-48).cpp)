/* 2D-array -- https://leetcode.com/problems/rotate-image/ */


/* Solution-1 => (Ectra loop for revrse) */
/* Time comp. - O(N^2) */
/* Space comp. - O(1) */

class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(a[i][j],a[j][i]);
            }
            reverse(a[i].begin(),a[i].end());
        }
        return;
    }
};


/* Solution-2 =>(One pass) */
/* Time comp. - O(N^2) */
/* Space comp. - O(1) */

class Solution {
public:
    void rotate(vector<vector<int>>& input) {
        int n = input.size();
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-i-1;j++){
                int temp = input[i][j];
                input[i][j] = input[n-j-1][i];
                input[n-j-1][i] = input[n-i-1][n-j-1];
                input[n-i-1][n-j-1] = input[j][n-i-1];
                input[j][n-i-1]  = temp;
            }
        }
    }
};
