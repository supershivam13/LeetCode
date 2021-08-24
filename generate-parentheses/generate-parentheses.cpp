class Solution {
public:
    vector<string> ans;
    
    void solve(int open,int close,string output){
        
        if(open==0 and close==0){
            ans.push_back(output);
            return;
        }
        
        if(open>0){
            string out1 = output;
            out1+="(";
            solve(open-1,close,out1);
        }
        
        if(open<close){
            string out2 = output;
            out2+=")";
            solve(open,close-1,out2);
        }

    }
    
    vector<string> generateParenthesis(int n) {
        
        int open=n;
        int close=n;
        string output="";
        
        solve(open,close,output);
        
        return ans;
    }
};