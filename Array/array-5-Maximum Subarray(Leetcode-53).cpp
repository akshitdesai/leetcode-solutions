/*array -- https://leetcode.com/problems/maximum-subarray/ */


/* Solution-1 => Kadane’s Algorithm */
/* Time comp. - O(N) */
/* Space comp. - O(1) */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN, sum_till = 0;
        for(int i:nums){
            sum_till += i;
            max_sum = max(max_sum,sum_till);
            if(sum_till<0)
                sum_till = 0;
        }
        return max_sum;
    }
};
