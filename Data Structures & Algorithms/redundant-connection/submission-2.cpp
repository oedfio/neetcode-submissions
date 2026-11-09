class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, set<int>*> int_to_set;
        vector<set<int>> sets(edges.size());
        int n = 0;
        for (auto& vec: edges) {
            int u = vec[0], v = vec[1];
            if (int_to_set[u] && (*int_to_set[u]).find(v) != (*int_to_set[u]).end()) {
                return {{u, v}};
            }
            else {
                if (!int_to_set[u] && !int_to_set[v]) {
                    sets[n] = {u, v};
                    int_to_set[u] = &sets[n];
                    int_to_set[v] = &sets[n++];
                    continue;
                }

                if (int_to_set[v]) {
                    swap(u, v);
                }
                
                if (!int_to_set[v]) {
                    (*int_to_set[u]).insert(v);
                    int_to_set[v] = int_to_set[u];
                    continue;
                }

                for (auto n: *int_to_set[v]) {
                    if ((*int_to_set[u]).find(n) != (*int_to_set[u]).end()) {
                        return {{u, v}};
                    }
                    (*int_to_set[u]).insert(n);
                    int_to_set[n] = int_to_set[u];
                }
            }
        }

        return {{-1, -1}};
    }
};
