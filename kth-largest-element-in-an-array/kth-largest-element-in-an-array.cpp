#define minheap         priority_queue<int,vector<int>,greater<int>>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        minheap minh;
        for(int i=0;i<nums.size();i++){
            
            minh.push(nums[i]);
            
            if(minh.size()>k){
                minh.pop();
            }
        }
        
        return minh.top();
        
    }
};