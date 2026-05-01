class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans;
        vector<pair<int,int>> temp;

        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            temp.push_back({start, i});
        }

        sort(temp.begin(), temp.end());

        for (int i = 0; i < intervals.size(); i++) {
            int end = intervals[i][1];

            int low = 0;
            int high = intervals.size() - 1;

            int res = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (temp[mid].first>=end) {
                    res = temp[mid].second;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            ans.push_back(res);
        }

        return ans;
    }
};