class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int j=0;
        int ans=0;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]==1){
                j++;
                ans=max(ans,j);
            }
            else
                j=0;
        }
        
        return ans;
    }
};