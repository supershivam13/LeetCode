// SWAP SORT 

// Time Complexity - O(n) { O(2n - 2) to be precise }

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> miss;
        
        int i=0;    
        
        // Swap Sort Algorithm 
        while(i<nums.size()){
            
            if(nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
            else
                i++;
        }
        
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=i+1)
                miss.push_back(i+1);
        
        return miss;
        
    }
};