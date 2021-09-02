class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        
        if(a.size()<3)
            return false;
        
        int first=INT_MAX,second=INT_MAX;
        
        for(int i=0;i<a.size();i++){
            
            if(a[i]<=first)
                first=a[i];
            else if(a[i]<=second)
                second=a[i];
            else
                return true;
        }
        
    return false; 
        
    }
};