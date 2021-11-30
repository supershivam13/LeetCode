class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        unordered_set<int> s;
        
        for(int x: nums1)
            s.insert(x);
        
        for (auto y : nums2){
            if (s.count(y)>0) {
                ans.push_back(y);
                s.erase(y);
            }
        }   
        
        return ans;
    }
};