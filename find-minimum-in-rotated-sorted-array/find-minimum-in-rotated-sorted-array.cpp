// class Solution {
    
    
//     int binary_search(vector<int>& nums,int left,int right,int target)
//     {
//         int mid;
//         //Iterative binary search
//         while(left<=right)
//         {
//             mid = (left+right)/2;
//             if(nums[mid]==target)
//                 return mid;
//             else if(nums[mid]>target)
//                 right = mid-1;
//             else
//                 left = mid+1;
//         }
//         return -1;
//     }
// public:
//     int search(vector<int>& nums, int target) {
        
        
//         if(nums[pivot]==target)
//             return pivot;
        
//         return target>nums[n-1]?binary_search(nums,0,pivot,target):binary_search(nums,pivot+1,n-1,target);
//     }
// };













class Solution {
    
    int find_pivot(vector<int>& nums,int left,int right)
    {
        if(nums[left] < nums[right])
            return right;
        
        int mid;
        //Iterative binary search
        while(left<right)
        {
            mid = (left+right)/2;
            if(nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid]<nums[0])
                right = mid;
            else
                left = mid+1;
        }
        return mid;
    }
    
public:
    int findMin(vector<int>& a) {
        
        int n=a.size();
        int start = 0;
        int end = n - 1;
        int mid;
        
        if(n==1)
            return a[0];
        
        int pivot = find_pivot(a,0,n-1);
        cout<<pivot;
        
        return a[(pivot+1)%n];
        
        
        
    }
};