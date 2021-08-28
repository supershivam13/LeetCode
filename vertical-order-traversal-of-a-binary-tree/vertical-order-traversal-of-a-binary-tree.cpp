class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;
        map<int, map<int, vector<int>>> m;

        if (root == NULL)
            return ans;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {

            TreeNode* temp = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            m[x][y].push_back(temp->val);

            if (temp->left)
                q.push({temp->left, {x - 1, y + 1}});
            if (temp->right)
                q.push({temp->right, {x + 1, y + 1}});
        }

        for (auto col : m) {
            vector<int> v;

            for (auto row : col.second) {
                vector<int> v1 = row.second;
                sort(v1.begin(), v1.end());

                v.insert(v.end(), v1.begin(), v1.end());
            }

            ans.push_back(v);
        }

        return ans;
    }
};
