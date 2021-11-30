class Solution {
public:
    double myPow(double x, int n) {
        
        bool isNegativePower=false;
        long long temp = n;
        
        if(temp<0){
            isNegativePower=true;
            temp = abs(temp);
        }

        double ans=1;
        
        while(temp){
            
            if(temp%2==1){
                ans = ans*x;
                temp--;
            }
            else{
                x=x*x;
                temp/=2;
            }   
        }
        
        if(isNegativePower)
            return 1/ans;
        else
            return ans;
    }
};