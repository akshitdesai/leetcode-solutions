/* hashing -- https://leetcode.com/problems/3sum/ */


/* Solution-1 => Brute Force */
/* Time comp. - O(N^3) */
/* Space comp. - O(1) */


/* Solution-2 => Hash */
/* Time comp. - O(N^2) */
/* Space comp. - O(1) */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        
        int n = a.size();
        sort(a.begin(), a.end());
        
        vector<vector<int>> result;
        unordered_map <int, int> lastIndex;
        
        for(int i=0;i<n;i++)    lastIndex[a[i]] = i;
        
        for(int i=0;i<n;i++){
            if(i>0 && a[i]==a[i-1]) continue; 
            for(int j = i+1;j<n;j++){
                if(j>i+1 && a[j]==a[j-1])   continue; 
                if(lastIndex[-(a[i] + a[j])] > j){ 
                    result.push_back({a[i], a[j], -(a[i] + a[j])});
                } 
            }
        }
        return result;
    }
};
