/* array -- https://practice.geeksforgeeks.org/problems/inversion-of-array/ */


/* Solution-1 => Brute Force */
/* Time comp. - O(N*N) */
/* Space comp. - O(1) */

#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n], ans=0;
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	            if(a[j]<a[i])
	                ans++;
	        }
	    }
	    cout<<ans<<'\n';
	}
	return 0;
}


/* Solution-2 => Enhanced Merge Sort */
/* Time comp. - O(NLogN) */
/* Space comp. - O(N) */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll merge(int a[],int temp[],int l, int mid, int r){
    int i = l;
    int j = mid;
    int k = l;
    ll count = 0;
    while(i<=(mid-1) && j<=r){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
            count = count + (mid-i);
        }
    }
    
    while(i <= mid-1)
        temp[k++] = a[i++];
        
    while(j <= r)
        temp[k++] = a[j++];
        
    for(i=l;i<=r;i++)
        a[i] = temp[i];

    return count;
}
ll merge_sort(int a[],int temp[],int l,int r){
    int mid;
    ll count = 0;
    if(r>l){
        mid = (l+r)/2;
        
        count += merge_sort(a,temp,l,mid);
        count += merge_sort(a,temp,mid+1,r);
        
        count += merge(a,temp,l,mid+1,r);
    }
    return count;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n], ans=0;
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int temp[n];
	    cout<<merge_sort(a,temp,0,n-1)<<'\n';
	}
	return 0;
}
