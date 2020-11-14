/* hashing -- https://leetcode.com/problems/longest-consecutive-sequence/ */


/* Solution-1 => Brute Force */
/* Time comp. - O(N^3) */
/* Space comp. - O(1) */


/* Solution-2 => Map/Set */
/* Time comp. - O(N) */
/* Space comp. - O(N) */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> f;        
        for(auto i:nums)    f[i] = 1;
        int cnt = 0, curr = -1, curr_cnt = 0;
        for(auto pp:f){
            if(pp.first == curr + 1)
                curr_cnt++;
            else{
                cnt = max(cnt, curr_cnt);
                curr_cnt = 1;
            }
            curr = pp.first;
        }
        cnt = max(cnt, curr_cnt);
        return cnt;
    }
};
