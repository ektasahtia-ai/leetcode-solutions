class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;

        for (int i = 1; i < n; i++) {
            fact *= i;
        }

        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        k--; // Convert to 0-based indexing
        string ans = "";

        while (!nums.empty()) {
            int index = k / fact;
            ans += to_string(nums[index]);

            nums.erase(nums.begin() + index);

            if (nums.empty()) break;

            k %= fact;
            fact /= nums.size();
        }

        return ans;
    }
};