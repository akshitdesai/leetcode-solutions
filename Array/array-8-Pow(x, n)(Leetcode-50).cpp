
/* array -- https://leetcode.com/problems/powx-n/ */


/* Solution-1 */
/* Time comp. - O(log(N)) */
/* Space comp. - O(log(N)) ==> call stack */

class Solution {
public:
    double myPow(double x, int n) {
        
        if(n < 0){
            x = 1 / x;
            if(n == INT_MIN)
                x = x * x, n++;
            n *= -1;
        }
        
        if(n == 0)
            return 1;
            
        double ans = myPow(x,n/2);
        ans = ans*ans;
        if(n%2)
            ans *= x;
        return ans;
    }
};
