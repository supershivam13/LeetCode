class Solution {
public:
    string reorganizeString(string s) 
    {
        int n=s.length(), ind=0;
        unordered_map<char,int> m;
        set<pair<int,char>> st;
        
        for(int i=0;i<n;i++)
            m[s[i]]++;
        
        for(auto p:m)
        {
            if(p.second > (n/2 + n%2))
                return "";
            
            st.insert({p.second,p.first});
        }
        
        while(ind<n)
        {
            if(ind+1==n)
            {
                s[ind]=(*st.begin()).second;
                break;
            }
            
            auto it = st.begin();
            auto it2 = st.end();
            it2--;
            pair <int, char> least=(*it), most=(*it2);
            s[ind]=most.second;
            s[ind+1]=least.second;
            ind+=2;
            
            char a=(*it).second, b=(*it2).second;
            st.erase(it);
            st.erase(it2);
            m[a]--;
            m[b]--;
            if(m[a])
                st.insert({m[a], a});
            if(m[b])
                st.insert({m[b], b});
        }
        
        return s;
    }
};