/* hashing -- https://leetcode.com/problems/longest-substring-without-repeating-characters/ */


/* Solution-1 => Brute Force */
/* Time comp. - O(N^2) */
/* Space comp. - O(1) */


/* Solution-2 => Map */
/* Time comp. - O(N) */
/* Space comp. - O(N) */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int curr_cnt = 0, cnt = 0;
        unordered_map<char,int> f;
        
        for(int i = 0; i< s.length();i++){
            if(f.find(s[i]) != f.end() && i-f[s[i]] <= curr_cnt)
                curr_cnt = i-f[s[i]];
            else
                curr_cnt++;
            f[s[i]] = i;
            cnt = max(cnt, curr_cnt);
        }
        return cnt;
    }
};
