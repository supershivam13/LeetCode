class Solution {
public:
    int missingNumber(vector<int>& a) {
        
        int x=0;
        for(int i=1;i<=a.size();i++)
            x^=i;
        
        int y=0;
        for(int i=0;i<a.size();i++)
            y^=a[i];
        
        return x^y;
    }
};