// here we need to return the indices of the vector if we found out the sum , for this purpose we need to create a map the by iterating all over the vector we will try to find out the target like
// target = nums[i] + some previous value (stored in the map with their indices)
// some previous value = target - nums[i];
// use find function in the map to find this key
// if(mp.find(target-nums[i]) != mp.end())
// than just simply return this indices which are stored in map

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        // iterate over whole vector
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(target-nums[i]) != mp.end()) {
                return {mp[target-nums[i]],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};