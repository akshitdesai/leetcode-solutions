/* array -- https://leetcode.com/problems/next-permutation/ */


/* Solution-1 => Using Inbuilt function */
/* Time comp. - O() */
/* Space comp. - O() */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // #include<algorithm>
        next_permutation(nums.begin(),nums.end());
    }
};


/* Solution-2 (Intuition - dictionary order)*/
/* Time comp. - O(N^2) */
/* Space comp. - O(1) */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;
        bool done = 0;
        
        for(int j = n - 2; j >= 0;j--){
            for(int k = n - 1; k > j;k--){
                if(nums[j] < nums[k]){
                    swap(nums[j],nums[k]);
                    reverse(nums.begin()+j+1,nums.end());
                    done = 1;
                    break;
                }
            }
            if(done) break;
        }
        if(!done) 
        {
            int i = 0, j = n-1;
            while(i<=j)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
    }
};

/* Solution-3 (Same as 2)*/
/* Time comp. - O(N) */
/* Space comp. - O(1) */

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size(), i, j;
        if(n<=1)    return;
        
        for(i = n-2; i>=0;i--)
            if(a[i] < a[i+1])
                break;
        
        if(i>=0){
            for(j = n-1; j > i; j--)
                if(a[j] > a[i])
                    break;
            swap(a[i],a[j]);
        }
        reverse(a.begin()+i+1,a.end()); 
    }
};
