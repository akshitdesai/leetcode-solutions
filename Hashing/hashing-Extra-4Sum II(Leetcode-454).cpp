/* hashing -- https://leetcode.com/problems/4sum-ii/ */


/* Solution-1 => Brute Force */
/* Time comp. - O(N^4) */
/* Space comp. - O(1) */

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int cnt = 0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                for(int k=0;k<C.size();k++){
                    for(int l=0;l<D.size();l++){
                        if(A[i]+B[j]+C[k]+D[l]==0)
                            cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};


/* Solution-2 => Hash */
/* Time comp. - O(N^2) */
/* Space comp. - O(1) */

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        unordered_map<int,int> f1, f2;
        int cnt = 0;
        
        for(int i=0;i<A.size();i++)
            for(int j=0;j<B.size();j++)
                f1[A[i]+B[j]]++;
        
        for(int k=0;k<C.size();k++)
            for(int l=0;l<D.size();l++)
                f2[C[k]+D[l]]++;
        
        for(auto pp:f1)
            cnt += (pp.second*f2[-(pp.first)]);
        
        return cnt;
    }
};
