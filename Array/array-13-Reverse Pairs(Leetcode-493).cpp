* array -- https://leetcode.com/problems/reverse-pairs/ */


/* Solution-1 => Brute Force, Verdict-TLE */
/* Time comp. - O(N*N) */
/* Space comp. - O(1) */

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        if(n <= 1)
            return 0;
        
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++){
                long long x = 2LL * nums[j];
                if(nums[i] > x)
                    cnt ++;
            }
        return cnt;
            
    }
};


/* Solution-2 => BST */
/* Time comp. - O(NLogN) */
/* Space comp. - O(N) */

