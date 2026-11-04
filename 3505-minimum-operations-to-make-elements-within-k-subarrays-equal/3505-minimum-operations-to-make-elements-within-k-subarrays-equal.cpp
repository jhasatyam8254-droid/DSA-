class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long sumL = 0, sumR = 0;

        auto add = [&](int v) {
            if (left.empty() || v <= *left.rbegin()) {
                left.insert(v);
                sumL += v;
            } else {
                right.insert(v);
                sumR += v;
            }
        };

        auto remove = [&](int v) {
            auto it = left.find(v);

            if (it != left.end()) {
                left.erase(it);
                sumL -= v;
            } else {
                it = right.find(v);
                right.erase(it);
                sumR -= v;
            }
        };

        auto balance = [&]() {
            int target = (left.size() + right.size() + 1) / 2;

            while (left.size() > target) {
                int v = *left.rbegin();
                left.erase(prev(left.end()));
                sumL -= v;

                right.insert(v);
                sumR += v;
            }

            while (left.size() < target) {
                int v = *right.begin();
                right.erase(right.begin());
                sumR -= v;

                left.insert(v);
                sumL += v;
            }
        };

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x)
                remove(nums[i - x]);

            balance();

            if (i >= x - 1) {
                long long median = *left.rbegin();

                cost[i - x + 1] =
                    median * left.size() - sumL +
                    sumR - median * right.size();
            }
        }

        const long long INF = 4e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};