class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 1);

        for (auto& vec: edges) {
            int u = vec[0], v = vec[1];
            int p_u = find(parent, u), p_v = find(parent, v);
            
            if (p_u == p_v) {
                return {{u, v}};
            }
            
            parent[p_u - 1] = p_v;
        }

        return {{-1, -1}};
    }

private:
    int find(const vector<int>& parent, int i) {
        while (parent[i - 1] != i) {
            i = parent[i - 1];
        }
        return i;
    }
};
