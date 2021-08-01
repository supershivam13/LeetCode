class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        int i=0,j=0,ans=0;
        
        unordered_map<char,int> mp;
        
        while(j<n){
            
            mp[s[j]]++;
            
            // this if statement will never will be executed
            // as it never will be true
            if(mp.size()>j-i+1){
                j++;  
            }
            
            else if(mp.size()==j-i+1){
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    
                    i++;
                }
                
                j++;
                
            }
        }
        return ans;
        
    }
};