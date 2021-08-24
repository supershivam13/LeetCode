class Solution {
public:
    
    vector<string> ans;
    
    void solve(string input,string output){
        
        if(input.length()==0){
            ans.push_back(output);
            return;
        }
        
        int d=input[0];
        
        if(d<=57){
            output.push_back(input[0]);
            
            input.erase(0,1);
            
            solve(input,output);
        }
        else{
            
            if(d>=97){
                string out1 = output;
                string out2 = output;

                out1.push_back(input[0]);

                int cap=input[0]-32;
                char c=cap;
                out2.push_back(c);

                input.erase(0,1);

                solve(input,out1);
                solve(input,out2);
            }
            else{
                string out1 = output;
                string out2 = output;

                out1.push_back(input[0]);

                int cap=input[0]+32;
                char c=cap;
                out2.push_back(c);

                input.erase(0,1);

                solve(input,out1);
                solve(input,out2);
            }
            
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        
        string output="";
        
        solve(S,output);
        
        return ans;
    }
};