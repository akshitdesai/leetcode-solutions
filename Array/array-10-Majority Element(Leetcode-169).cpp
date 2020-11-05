/* array -- https://leetcode.com/problems/majority-element/ */


/* Solution-1 => Hahs Map */
/* Time comp. - O(N) */
/* Space comp. - O(N) */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size()/2;
        for(int i:nums){
            mp[i]++;
            if(mp[i]>n)
                return i;
        }
        return 1;
    }
};



/* Solution-2 => Inbuilt Sort */
/* Time comp. - O(NLogN) */
/* Space comp. - O(1) */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2];
    }
};

/* Solution-3 => Divide and conquer */
/* Time comp. - O(NLogN) */
/* Space comp. - O(logN) */


/* Solution-4 => Boyer-Moore Voting Algorithm */
/* Time comp. - O(N) */
/* Space comp. - O(1) */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = -1;
        for (int num : nums) {
            if (count == 0) 
                candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
