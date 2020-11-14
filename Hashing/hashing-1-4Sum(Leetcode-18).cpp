/* hashing -- https://leetcode.com/problems/4sum/ */


/* Solution-1 => Brute Force */
/* Time comp. - O(N^4) */
/* Space comp. - O(1) */


/* Solution-2 => Optimized Solution */
/* Time comp. - O(N^3) */
/* Space comp. - O(1) */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        int n = a.size();
        vector<vector<int>> v;
        if(n <= 3)
            return v;
        else{
            sort(a.begin(),a.end());
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    int sub_target = target - a[i] - a[j];
                    int left = j + 1;
                    int right = n -1;
                    
                    while(left < right){
                        
                        if(a[left]+a[right]<sub_target)
                            left++;
                        else if(a[left]+a[right]>sub_target)
                            right--;
                        else if(a[left]+a[right]==sub_target && left!=right){
                            
                            vector<int> temp(4);
                            
                            temp[0] = a[i];
                            temp[1] = a[j];
                            temp[2] = a[left];
                            temp[3] = a[right];
                            v.push_back(temp);
                            
                            while(left<right && a[left]==temp[2])
                                left++;

                            while(left<right && a[right]==temp[3])
                                right--;
                        }
                    }
                    while(j+1<n && a[j+1]==a[j]) j++;
                }
                while(i+1<n && a[i+1]==a[i]) i++;
            }
            return v;
        }
    }
};
