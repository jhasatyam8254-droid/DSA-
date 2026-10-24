
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        int n = g.size(), m = s.size();

        for (j = 0; j < m && i < n; j++) {
            if (s[j] >= g[i]) {
                i++;
            }
        }

        return i;
    }
};
