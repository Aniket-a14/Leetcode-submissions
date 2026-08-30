class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        int firstMin = n, lastMin = -1;
        int firstMax = n, lastMax = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == mini) {
                firstMin = min(firstMin, i);
                lastMin = i;
            }

            if (nums[i] == maxi) {
                firstMax = min(firstMax, i);
                lastMax = i;
            }
        }
        int left = max(firstMin, firstMax) + 1;

        int right = n - min(lastMin, lastMax);

        int both = min(firstMin, firstMax) + 1
                 + n - max(lastMin, lastMax);

        return min({left, right, both});
    }
};