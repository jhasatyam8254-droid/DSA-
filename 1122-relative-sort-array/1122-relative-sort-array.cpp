
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        sort(arr1.begin(), arr1.end());

        for (int x : arr2) {
            for (int i = 0; i < arr1.size(); i++) {
                if (arr1[i] == x) {
                    ans.push_back(x);
                    arr1[i] = -1;
                }
            }
        }

        for (int x : arr1) {
            if (x != -1)
                ans.push_back(x);
        }

        return ans;
    }
};
