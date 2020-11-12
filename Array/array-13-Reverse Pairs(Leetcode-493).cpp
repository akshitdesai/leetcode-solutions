/* array -- https://leetcode.com/problems/reverse-pairs */


/* Solution-1 => Brute Force, Verdict-TLE */
/* Time comp. - O(N*N) */
/* Space comp. - O(1) */

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        if(n <= 1)
            return 0;
        
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++){
                long long x = 2LL * nums[j];
                if(nums[i] > x)
                    cnt ++;
            }
        return cnt;
            
    }
};


/* Solution-2 => BST */
/* Time comp. - O(N*N) */
/* Space comp. - O(N) */
/* It can take NlogN in avg. case */

class Solution {
public:
    
    struct Node{
        int key;
        int tchild;
        struct Node *left;
        struct Node *right;
        
        Node(int val){   
            key = val;
            tchild = 1;
            left = NULL;
            right = NULL; 
        }
    };
    
    int search(struct Node* root, long long key){
        if (root == NULL)
            return 0;
        else if(root->key == key)
           return root->tchild;
        else if (root->key < key)
           return search(root->right, key);
        return root->tchild + search(root->left, key);
    }
    
    struct Node* insert(struct Node* node, int key){
        
        if (node == NULL)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key){
            node->tchild ++;
            node->right = insert(node->right, key);
        }
        else if (key == node->key)
            node->tchild ++;
        
        return node;
    }
    
    int reversePairs(vector<int>& nums) {
        Node* head = NULL;
        
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += search(head, nums[i] * 2LL + 1);
            head = insert(head, nums[i]);
        }
        return count;
    }
};

/* Solution-3 => Modified Merge Sort */
/* Time comp. - O(NLogN) */
/* Space comp. - O(N) */

class Solution {
public:
    void merge(vector<int>& A, int start, int mid, int end)
    {
        int n1 = (mid - start + 1);
        int n2 = (end - mid);
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++)
            L[i] = A[start + i];
        for (int j = 0; j < n2; j++)
            R[j] = A[mid + 1 + j];
        int i = 0, j = 0;
        for (int k = start; k <= end; k++) {
            if (j >= n2 || (i < n1 && L[i] <= R[j]))
                A[k] = L[i++];
            else
                A[k] = R[j++];
        }
    }

    int mergesort_and_count(vector<int>& A, int start, int end)
    {
        if (start < end) {
            int mid = (start + end) / 2;
            int count = mergesort_and_count(A, start, mid);
            count += mergesort_and_count(A, mid + 1, end);
            int j = mid + 1;
            for (int i = start; i <= mid; i++) {
                while (j <= end && A[i] > A[j] * 2LL)
                    j++;
                count += j - (mid + 1);
            }
            merge(A, start, mid, end);
            return count;
        }
        else
            return 0;
    }

    int reversePairs(vector<int>& nums)
    {
        return mergesort_and_count(nums, 0, nums.size() - 1);
    }
};

