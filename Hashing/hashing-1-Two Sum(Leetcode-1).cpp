/* hashing -- https://leetcode.com/problems/two-sum/ */


/* Solution-1 => Brute Force */
/* Time comp. - O(N*N) */
/* Space comp. - O(1) */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> x;
        int sum;
        for(int i=nums.size()-1;i>=0;i--){
            sum=nums[i];
            for(int j=0;j<i;j++){
                if(sum+nums[j]==target){
                    x.push_back(i);
                    x.push_back(j);
                    break;
                }
            }
            if(x.size()!=0)
                break;
        }
        return x;
    }
};

/* Solution-2 => Hashmap(Two Pass) */
/* Time comp. - O(N) */
/* Space comp. - O(N) */


/* Solution-3 => Hashmap(One Pass) */
/* Time comp. - O(N) */
/* Space comp. - O(N) */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> freq;
        int n = nums.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            if(freq[target-nums[i]]!=0){
                v.push_back(freq[target-nums[i]]-1);
                v.push_back(i);
                break;
            } else
                freq[nums[i]] = i+1;
        }
        return v;
    }
};
