/*array -- https://leetcode.com/problems/sort-colors/ */

/* Solution-1 */
/* Space comp. - o(1) */
/* Time comp. - o(N) */
class Solution {
public:
    void sortColors(vector<int>& a) {
        int low = 0, mid = 0, high = a.size()-1;
        while(mid<=high){
            if(a[mid] == 0){
                swap(a[mid],a[low]);
                low++;
                mid++;
            } else if (a[mid]==1){
                mid++;
            } else if(a[mid]==2){
                swap(a[mid], a[high]);
                high--;
            }
        }
    }
};
