class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int> mp;

        for(int i=0;i<arr1.size();i++){
            string num = to_string(arr1[i]);
            string temp = "";
            for(int j=0;j<num.size();j++){
                temp += num[j];
                mp[temp]++;
            }
        }
        int ans = 0;
        for(int i=0;i<arr2.size();i++){
            string num = to_string(arr2[i]);
            string temp = "";
            for(int j=0;j<num.size();j++){
                temp+=num[j];
                if(mp.find(temp)!=mp.end()) ans=max(ans,int(temp.size()));
            }
        }

        return ans;
    }
};