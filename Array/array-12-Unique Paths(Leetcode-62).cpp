/* array -- https://leetcode.com/problems/unique-paths/ */


/* Solution-1 => DP */
/* Time comp. - O(N*N) */
/* Space comp. - O(N*N) */

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector(n,1));
        
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        
        return dp[m-1][n-1];
    }
};


/* Solution-2 => M-1th element of N+M-2th row of Pascal Triangle or (N+M-2)C(M-1) */
/* Time comp. - O(N) */
/* Space comp. - O(1) */

/* nCr using storing previous */

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n==1 || m==1)
            return 1;
        else{
            int N = n+m-2, r = m-1 ;
            double res=1;
            for(int i=1; i<=r; i++)
                res = res*(N-r+i)/i ;
            return (int)res ;
        }
    }
};

/* nCr using loop */

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        n = n + m - 2;
        int r = m - 1;
        
        long long p = 1, k = 1;
        if (n - r < r)  r = n - r;

        if (r != 0) {
            while (r) {
                p *= n;
                k *= r;

                long long m = __gcd(p, k);
                p /= m;
                k /= m;

                n--;
                r--;
            }
        }

        else
            p = 1;
        
        return p;
    }
};
