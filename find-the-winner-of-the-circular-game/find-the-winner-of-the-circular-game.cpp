class Solution {
public:
    int findTheWinner(int n, int k) {
        
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
            v[i]=i+1;
        
        k--;
        int start=0;
        
        while(v.size()>1){
            int kill=(start+k)%(v.size());
            v.erase(v.begin()+kill);
            start = kill%v.size();
        }
        
        return v[0];
        
    }
};