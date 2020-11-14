/* hashing -- https://www.geeksforgeeks.org/count-number-subarrays-given-xor/ */


/* Solution-1 => Brute Force */
/* Time comp. - O(N^2) */
/* Space comp. - O(1) */


/* Solution-2 => Map/Set */
/* Time comp. - O(N) */
/* Space comp. - O(N) */
long long subarrayXor(int arr[], int n, int m){

    long long ans = 0;
    int* xorArr = new int[n];
    unordered_map<int, int> mp;
 
    xorArr[0] = arr[0];
    
    for (int i = 1; i < n; i++)
        xorArr[i] = xorArr[i - 1] ^ arr[i];
        
    for (int i = 0; i < n; i++) {
    
        int tmp = m ^ xorArr[i];
        
        ans = ans + ((long long)mp[tmp]);
        
        if (xorArr[i] == m)
            ans++;
            
        mp[xorArr[i]]++;
    }
    
    return ans;
}
