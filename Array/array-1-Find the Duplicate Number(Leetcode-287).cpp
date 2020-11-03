/*array -- https://leetcode.com/problems/find-the-duplicate-number/ */

/* Solution-1 */
/* Space comp. - o(1) */
/* Time comp. - o(NLogN) */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
            if(nums[i]==nums[i-1])
                return nums[i];
        
        return -1;
    }
};

/* Solution-2 */
/* Space comp. - o(1) */
/* Time comp. - o(N) */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while(fast!=slow);
        
        fast = nums[0];
        
        while(fast!=slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return slow;
    }
};
