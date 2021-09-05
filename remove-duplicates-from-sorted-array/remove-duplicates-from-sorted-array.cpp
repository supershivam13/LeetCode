class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int j=0;
        for(int i=0;i<nums.size();i++){
            
            while(i+1<nums.size() and nums[i]==nums[i+1]){
                i++;
            }
            
            nums[j]=nums[i];
            j++;
        }
        
        return j;
    }
};