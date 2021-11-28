int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int m,n;

class Solution {

    vector<vector<int>> mat;
    vector<vector<int>> vis2d;
    queue<pair<int, int> > q;

public:
    bool isvalid(int x, int y) {

        if (x<0 or y<0 or x >= n or y >= m)
            return false;

        if (vis2d[x][y] == 1 or mat[x][y] == 0)
            return false;

        return true;
    }

    void dfs2d(int x, int y) {
        vis2d[x][y] = 1;
        q.push({x, y});

        for (int i = 0; i < 4; i++)
            if (isvalid(x + dx[i], y + dy[i]))
                dfs2d(x + dx[i], y + dy[i]);
    }

    int shortestBridge(vector<vector<int>>& A) {

        m = A.size();
        if (m == 0)
            return 0;

        n = A[0].size();

        mat = A;
        vis2d.resize(m, vector<int>(n, 0));
        int flag = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    dfs2d(i, j);
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }

        int ans = 0;

        while (!q.empty()) {
            int len = q.size();
            ans++;

            while (len--) {
                pair<int, int> poi = q.front();
                q.pop();

                vis2d[poi.first][poi.second] = 1;

                for (int i = 0; i < 4; i++) {
                    int x = poi.first + dx[i];
                    int y = poi.second + dy[i];

                    if (x >= 0 && y >= 0 && x <= m - 1 && y <= n - 1) {
                        if (vis2d[x][y] == 0 && mat[x][y] == 1)
                            return ans - 1;
                        else if (vis2d[x][y] == 0 && mat[x][y] == 0) {
                            vis2d[x][y] = 1;
                            q.push({x, y});
                        }
                    }
                }
            }
        }

        return -1;
    }
};