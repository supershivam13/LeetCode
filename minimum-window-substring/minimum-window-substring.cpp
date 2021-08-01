class Solution {
public:
    string minWindow(string s, string p) {
        
        int n=s.length();
        int n1=p.length();
        
        if(n1>n)
        return "";
        
        unordered_map<char,int> mp;
        for(int i=0;i<n1;i++)
        mp[p[i]]++;
        
        int count=mp.size();
        int i=0,j=0,ans=INT_MAX,ind=INT_MAX;
        
        while(j<n){
            
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                
                if(mp[s[j]]==0)
                count--;
            }
            
            if(count>0){
                j++;
            }
            
            else if(count==0){
                
                if(ans>j-i+1){
                    ans=j-i+1;
                    ind=i;
                }
                
                while(count==0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        
                        if(mp[s[i]]==1){
                        
                            count++;
                        
                            if(ans>j-i+1){
                                ans=j-i+1;
                                ind=i;
                            }
                        }
                        
                        i++;
                    }
                    else
                        i++;
                }
            
            j++;
            }
        }
        
        if(ans==INT_MAX)
        return "";
        
        string res="";
        // cout<<ans<<" "<<ind<<endl;
        for(int i=ind;ans>0;i++){
            res+=s[i];
            ans--;
        }
        
        return res;
    }
};