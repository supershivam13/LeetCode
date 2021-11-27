class Solution {
private:
    string countAndSay(const string& str) {
        string result;
        int counter = 1;
        char curDigit = str[0];
        
        for(int i = 1; i < str.size(); i++) {
            if(str[i] != curDigit) {
                result += to_string(counter);
                result.push_back(curDigit);
                curDigit = str[i];
                counter = 1;
            }
            else
                counter++;
        }
        result += to_string(counter);
        result.push_back(curDigit);
        return result;
    }
    
public:
    string countAndSay(int n) {
        string result = "1";
        for(int i = 1; i < n; i++)
            result = countAndSay(result);
        
        return result;
    }
};