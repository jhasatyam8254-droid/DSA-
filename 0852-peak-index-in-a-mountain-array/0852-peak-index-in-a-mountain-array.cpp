class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // We are on the increasing side
                start = mid + 1;
            }
            else {
                // We are on the decreasing side
                end = mid;
            }
        }

        return start;
    }
};