class Solution {
public:
    int trailingZeroes(int N) {
        
        int f=0;
        int m=5;
        while(m<=N){
            f+=(N/m);
            m*=5;
        }
     return f;
        
    }
};