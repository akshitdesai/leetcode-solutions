/*array -- https://leetcode.com/problems/merge-sorted-array/ */


/* Solution-1 => Insertion type sort*/
/* Time comp. - O(N*M) */
/* Space comp. - O(1) */

/* Solution-2 => GAP algo/Shell sort */
/* Space comp. - o(1) */
/* Time comp. - o(NLogN) */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m;
        for(auto j:nums2)
            nums1[i++] = j;
        
        int gap = (m+n)/2+(m+n)%2, first, second;
        while(gap>=1){
            first = 0;
            second = gap;
            while(second<(n+m)){
                if(nums1[first]>nums1[second])
                    swap(nums1[first], nums1[second]);
                first++;
                second++;                
            }
            if(gap == 1)
                break;
            gap = gap / 2 + gap % 2;
        }
    }
};
