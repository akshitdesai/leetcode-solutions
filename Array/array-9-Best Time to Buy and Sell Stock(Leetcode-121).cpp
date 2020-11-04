/* array -- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ */


/* Solution-1 */
/* Time comp. - O(N) */
/* Space comp. - O(1) */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far = INT_MAX,ans = 0;
        for(int i:prices){
            if(i < min_so_far)
                min_so_far = i;
            else
                ans = max(ans, i - min_so_far);
        }
        return ans;
    }
};
