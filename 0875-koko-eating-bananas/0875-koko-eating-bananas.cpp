class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0;
        int end = 0;

        for (int i = 0; i < piles.size(); i++) {
            sum += piles[i];
            end = max(end, piles[i]);
        }

        int start = max(1LL, sum / h);
        int ans = end;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            long long total_time = 0;

            for (int i = 0; i < piles.size(); i++) {
                total_time += (piles[i] + mid - 1) / mid;
            }

            if (total_time <= h) {
                // Speed is possible, try smaller speed
                ans = mid;
                end = mid - 1;
            } 
            else {
                // Speed is too slow
                start = mid + 1;
            }
        }

        return ans;
    }
};