// The main idea to use here is to realize that -> when we choose the k terms from 
// the front and back, we are left with a continuous subarray of length n-k.
// Now if we want to maximize this sum from the front and back elemetns, we need to 
// minimize the sum of this continous subarray.
// So this problem breaks down to ->
// Find the the subarray of size (n-k) with the minimum sum

class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        
        if(k==a.size()){
            return accumulate(a.begin(),a.end(),0);
        }
        int n=a.size();
        int total_sum=accumulate(a.begin(),a.end(),0);
        
        int window=n-k;
        
        int sum=accumulate(a.begin(),a.begin()+window,0);
        int mn=INT_MAX;
        
        for(int i=0;i<=n-window;i++){
            if(i==0){
                mn=min(mn,sum);
                cout<<mn<<endl;
            }
            else{
                sum = sum + a[i+window-1]- a[i-1];
                mn=min(mn,sum);
            }
        }        
        
        return total_sum-mn;
    }
};