/* array -- https://leetcode.com/problems/merge-intervals/ */


/* Solution-1 */
/* Time comp. - O(NlogN) */
/* Space comp. - O(N) */
class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<vector<int>> ans;
        vector<int> temp(2);
        
        if(n==0) return ans;
            
        sort(intervals.begin(),intervals.end());
        
        int c_start = intervals[0][0];
        int c_end   = intervals[0][1];
        
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= c_end){
                c_end = max(c_end,intervals[i][1]);
            } else {
                temp[0] = c_start;
                temp[1] = c_end;
                ans.push_back(temp);
                c_start = intervals[i][0];
                c_end = intervals[i][1];
            }
        }
        temp[0] = c_start;
        temp[1] = c_end;
        ans.push_back(temp);
        
        return ans;
    }
};
