/*array -- https://leetcode.com/problems/missing-number/ */

/* Solution-1 */
/* Space comp. - o(1) */
/* Time comp. - o(N) */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int txor = nums.size();
        int n = txor;
        for(int i = 0; i < n;i++){
            txor ^= i;
            txor ^= nums[i];
        }
        return txor;
    }
};

/* Solution-2 */
/* Space comp. - o(1) */
/* Time comp. - o(N) */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(auto i:nums)
            sum += i;
        int n = nums.size();
        
        return (n*(n+1)/2) - sum;
    }
};
