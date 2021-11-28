class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> st;
        
        for(char c:s){
            
            if(st.size()==0 or st.top()!=c)
                st.push(c);
            else if(st.top()==c)
                    st.pop();
        
        }
        string ans="";
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};