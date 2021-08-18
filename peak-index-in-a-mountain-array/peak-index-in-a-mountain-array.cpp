class Solution {
public:
    int peakIndexInMountainArray(vector<int> a) {
        
        int n=a.size();
        int start = 0;
        int end = n-1;
        int mid;
        
        while(start<=end){
        
            mid= start + ((end-start)/2);
            
            if(mid>0 and mid<n-1){
                if(a[mid]>a[mid+1] and a[mid]>a[mid-1])
                    return mid;
                
                else if(a[mid]<a[mid+1])
                    start = mid+1;
                else
                    end = mid -1;
            }
            else if(mid==0){
                if(a[0]>a[1])
                    return 0;
                else
                    return 1;
            }
            else{
                if(a[n-1]>a[n-2])
                    return n-1;
                else
                    return n-2;
            }
        }
        
        return -1;
    }

};