class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        
        int l=0;
        int r=arr.size()-1;
        int sum=accumulate(arr.begin(),arr.end(),0);
        
        if((sum%3)!=0){
            return false;
        }
        int req=sum/3;
        
        int pre[arr.size()];
        
        pre[0]=arr[0];
        
        for(int i=1;i<arr.size();i++)
            pre[i]=pre[i-1]+arr[i];
        
        int ind=-1;
        
        for(int i=0;i<arr.size();i++)
        {
            if(pre[i]==req){
                ind=i;
                break;
            }
        }
        
        if(ind==-1)
            return false;
        
        req+=req;
        int ind2=-1;
        
         for(int i=ind+1;i<arr.size();i++)
        {
            if(pre[i]==req){
                ind2=i;
                break;
            }
        }
        
        if(ind2==-1 or ind2==arr.size()-1)
            return false;
        
        return true;
        
        

        
    }
};