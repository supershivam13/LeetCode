class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        
        int n=a.size();
        
        vector<int> ans;
        deque <int> d;

        // Pre-processing for the first window of size k
        // only storing the potential numbers which can be maximum at some point of time
        for (int i = 0; i < k; i++) {

            // removing all the numbers smaller than a[i] as they can never be maximum
            while (d.size() > 0 and d.back() < a[i])
                d.pop_back();

            d.push_back(a[i]);
        }

        // SLIDING WINDOW TECHNIQUE
        for (int i = 0; i <= n - k; i++) {

            // case of first window of size k
            if (i == 0)
                ans.push_back(d.front());

            // for subsequent windows of size k ( except the first window )
            else {

                // Remember i is already incremented by the for loop

                // processing the recently removed element from the window
                if (d.front() == a[i - 1])
                    d.pop_front();

                // processing the newly added element in the window
                while (d.size() > 0 and d.back() < a[i + k - 1])
                    d.pop_back();

                d.push_back(a[i + k - 1]);

                // NOW PRE-PROCESSING IS DONE, CALCULATING THE ANS FROM THE WINDOW
                ans.push_back(d.front());
            }
        }
    
    return ans;

        
    }
};