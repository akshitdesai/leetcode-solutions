/* 2D-array -- https://leetcode.com/problems/pascals-triangle-ii/ */


/* Solution-1 */
/* Time comp. - O(N) */
/* Space comp. - O(N) */

class Solution {
public:
    vector<int> getRow(int n) {
        long long int k=1;
        vector<int> v;
        for(int r=0;r<n+1;r++){
            if(r==0 || r==n){
                k = 1;
            }
            else{
                k = k*(n-r+1)/r;  //nCr = nC(r-1)*(n-r+1)/r
            }
            v.push_back(k);
        }
        return v;
    }
};
