/* hashing -- https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1 */


/* Solution-1 => Brute Force */
/* Time comp. - O(N^2) */
/* Space comp. - O(1) */


/* Solution-2 => Map */
/* Time comp. - O(N) */
/* Space comp. - O(N) */

int maxLen(int A[], int n){
    
    unordered_map<int,int> f;
    int pre[n], len = 0;
    
    f[0] = -1;
    f[A[0]] = 0;
    pre[0] = A[0];
    
    for(int i = 1; i<n; i++){
        pre[i] = pre[i-1] + A[i];
        if(f.find(pre[i])!=f.end())
            len = max(len, i - f[pre[i]]);
        else
            f[pre[i]] = i;
    }
    
    return len;
}
