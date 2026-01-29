class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;

        for (int i = 0; i < k; i++) mp[nums[i]]++;
        for (auto& it : mp) pq.push({it.second, it.first});

        auto getSum = [&](unordered_map<int,int>& mp, int x) {
            priority_queue<pair<int,int>> temp;
            for (auto& it : mp) temp.push({it.second, it.first});
            int sum = 0;
            for (int i = 0; i < x && !temp.empty(); i++) {
                sum += temp.top().first * temp.top().second;
                temp.pop();
            }
            return sum;
        };

        ans.push_back(getSum(mp, x));

        for (int i = k; i < nums.size(); i++) {
            mp[nums[i]]++;
            mp[nums[i - k]]--;
            if (mp[nums[i - k]] == 0) mp.erase(nums[i - k]);
            ans.push_back(getSum(mp, x));
        }

        return ans;
    }
};
