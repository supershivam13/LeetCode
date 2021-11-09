bool comp(vector<int> &a,vector<int> &b)
{
    if(a[1]==b[1])
        return a[0]<b[0];
    return a[1]<b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),comp);
        int c=1;
        int ep=points[0][1];
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]<=ep)
                 continue;
            else
            {
                c++;
                ep=points[i][1];
            }
        }
        
        return c;
    }
};