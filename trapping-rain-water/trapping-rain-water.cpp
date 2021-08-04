class Solution {
public:
    int trap(vector<int>& a) {
        
        int n=a.size();
        
        if(n==0)
            return 0;
        
        vector<int> max_in_left(n,0);
        vector<int> max_in_right(n,0);
        
        max_in_left[0]=a[0];
        
        for(int i=1;i<n;i++)
            max_in_left[i]=max(max_in_left[i-1],a[i]);
        
        max_in_right[n-1]=a[n-1];
        
        for(int i=n-2;i>=0;i--)
            max_in_right[i]=max(max_in_right[i+1],a[i]);
        
        vector<int> water(n,0);
        
        for(int i=0;i<n;i++){
            int level=min(max_in_left[i],max_in_right[i]);
            water[i]=level-a[i];
        }
        
        return accumulate(water.begin(),water.end(),0);
    }
};