// Concept - Nearest Greater Element in Right

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        vector<int> NGR;

        stack<pair<int, int>> s;
        int n = temp.size();
        
        for (int i = n - 1; i >= 0; i--) {

            if (s.size() == 0)
                NGR.push_back(-1);

            // comparision is done using elements a[i] and
            // indexes i of NSR are getting stored in vector NSR
            else if (s.size() > 0 and s.top().first > temp[i])
                NGR.push_back(s.top().second);

            else if (s.size() > 0 and s.top().first <= temp[i]) {

                while (s.size() > 0 and s.top().first <= temp[i])
                    s.pop();

                // Assuming a 0-height building at the index n, instead of -1 to help in calculations
                if (s.size() == 0)
                    NGR.push_back(-1);
                else
                    NGR.push_back(s.top().second);
            }

            // pushing the { elemennt, index } into the stack after its processing is done
            s.push({temp[i], i});
        }

        reverse(NGR.begin(), NGR.end());
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(NGR[i]==-1)
                ans.push_back(0);
            else
                ans.push_back(abs(i-NGR[i]));
        }
        
        return ans;
    }
};