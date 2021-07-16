class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        
        vector<int> result;
        
        int carry = 1, sum = 0;
        int i=digits.size()-1;
        while(i>=0) {
            
            sum = digits[i] + carry;
            result.push_back(sum % 10);
            
            carry = sum/10;
            i--;
        }
        
        if (carry) {
            result.push_back(carry);
        }
        
        reverse(begin(result), end(result));
        return result;
    }
};