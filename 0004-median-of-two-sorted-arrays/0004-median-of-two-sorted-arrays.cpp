class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;

        for(int x : nums1)
            a.push_back(x);

        for(int x : nums2)
            a.push_back(x);

        sort(a.begin(), a.end());

        int n = a.size();

        if(n % 2 == 1)
            return a[n/2];

        return (a[n/2 - 1] + a[n/2]) / 2.0;
    }
};