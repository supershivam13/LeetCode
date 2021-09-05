class Solution {
public:
    double myPow(double x, int n) {
        
        bool f=false;
        
        long long p=n;
        if(p<0){
            f=true;
            p= p * (-1);
        }

        double res=1;
        
        while(p){
            
            if(p%2==1){
                res = res*x;
                p--;
            }
            else{
                x=x*x;
                p/=2;
            }
            // cout<<p<<" ";
        }
        
        cout<<res;
        
        if(f)
        return 1/res;
        
        return res;
        
    }
};