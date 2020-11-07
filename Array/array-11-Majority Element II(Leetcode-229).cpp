/* array -- https://leetcode.com/problems/majority-element-ii/ */


/* Solution-1 => Brute Force */
/* Time comp. - O(N*N) */
/* Space comp. - O(1) */


/* Solution-2 => Hash Map */
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


/* Solution-3 => Boyer-Moore Voting Algorithm */
/* Time comp. - O(N) */
/* Space comp. - O(1) */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int maj1 = INT_MIN, maj2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;
        for(int num : nums)
            if(num == maj1)         cnt1++;
            else if (num == maj2)   cnt2++;
            else if (cnt1 == 0)     maj1 = num, cnt1++;
            else if (cnt2 == 0)     maj2 = num, cnt2++;
            else                    cnt1--, cnt2--;
        
        cnt1 = cnt2 = 0;
        for(int num : nums)
            if(num == maj1)         cnt1++;
            else if(num == maj2)    cnt2++;
        
        vector<int> v;
        int n = nums.size()/3;
        if(cnt1 > n)    v.push_back(maj1);
        if(cnt2 > n)   v.push_back(maj2);
        
        return v;
    }
};
