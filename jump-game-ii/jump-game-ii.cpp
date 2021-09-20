class Solution {
public:
  int jump(vector<int> a) {
    
    int n=a.size();
    if (n == 1)
      return 0;

    int limit = a[0];
    int bestpos = 0;
    int ans = 1;

    int i = 1;
    while (i < n) {

      if (i > limit) {

        if (i > bestpos)
          return -1;

        limit = bestpos;
        ans++;
      }
        
      bestpos = max(bestpos, a[i] + i);
      i++;
    }

    return ans;
  }
};