/* hashing -- https://leetcode.com/problems/xor-queries-of-a-subarray/ */


/* Solution-1 => Brute Force */
/* Time comp. - O(N*Q) */
/* Space comp. - O(1) */


/* Solution-2 => Using Prefix-XOR */
/* Time comp. - O(N) */
/* Space comp. - O(N) */

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        const int n = arr.size();
        
        vector<int> prefix(n+1, 0);
        for(int i = 1 ; i <= n ; i++) {
            prefix[i] = (prefix[i-1] ^ arr[i-1]);
        }
        vector<int> sol;
        
        for(vector<int> v: queries)
        {
            int xorVal = prefix[v[1]+1] ^ prefix[v[0]];
            sol.push_back(xorVal);
        }
        return sol;
    }
};
