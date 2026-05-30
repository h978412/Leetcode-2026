#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        return max(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        
        // Limit size according to problem constraints (typically up to 50,000)
        int size = max(max_x, 50000) + 2;
        SegmentTree st(size);
        
        set<int> obs;
        obs.insert(0);
        obs.insert(size);
        
        // Initially, the gap at 'size' is 'size - 0'
        st.update(1, 0, size, size, size);
        
        vector<bool> ans;

        for (const auto& query : queries) {
            int type = query[0];
            int x = query[1];

            if (type == 1) {
                auto it = obs.upper_bound(x);
                int next_obs = *it;
                int prev_obs = *prev(it);

                obs.insert(x);

                // Update the split gaps in the segment tree
                st.update(1, 0, size, x, x - prev_obs);
                st.update(1, 0, size, next_obs, next_obs - x);
            } else {
                int sz = query[2];
                
                auto it = obs.lower_bound(x);
                int prev_obs = *prev(it);

                // Check max gap in completely built intervals up to prev_obs
                int max_gap = st.query(1, 0, size, 0, prev_obs);
                
                // Also check the potential space between prev_obs and x
                max_gap = max(max_gap, x - prev_obs);

                ans.push_back(max_gap >= sz);
            }
        }

        return ans;
    }
};