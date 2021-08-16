class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        
        int n=a.size();
        int start = 0;
        int end = n-1;
        int first = -1;
        int last = -1;
        
        while(start<=end){
            
            int mid = start + ((end-start)/2);
            
            if(target==a[mid]){
                first = mid;
                end = mid-1;
            }
            else if(target > a[mid])
                start = mid+1;
            else
                end = mid-1;
        }
        
        start=0;
        end=n-1;
        
        while(start<=end){
            
            int mid = start + ((end-start)/2);
            
            if(target==a[mid]){
                last = mid;
                start = mid+1;
            }
            else if(target > a[mid])
                start = mid+1;
            else
                end = mid-1;
        }
        
        vector<int> ans;
        ans.push_back(first);
        ans.push_back(last);
        
        return ans;
        
        
    }
};