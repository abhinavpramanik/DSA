#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        vector<int> ans;
        ans.reserve(m + n);

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            ans.push_back(nums2[j]);
            j++;
        }

        nums1.clear();
        nums1.assign(ans.begin(), ans.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3, 5, 0, 0};
    vector<int> nums2 = {2, 4};
    int m = 3;
    int n = 2;

    sol.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int x : nums1) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}