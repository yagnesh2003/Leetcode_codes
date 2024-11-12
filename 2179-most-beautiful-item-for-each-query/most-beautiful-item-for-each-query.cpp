class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int> dp;
        sort(items.begin(), items.end());
        int maxi = -1;
        for(auto it : items) {
            int price = it[0];
            int beauty = it[1];
            if(dp.find(price) == dp.end()) {
                maxi = max(maxi, beauty);
                dp[price] = maxi;
            }
            else {
                maxi = max(maxi, beauty);
                dp[price] = maxi;
            }
        }
        vector<int> ans;
        for(int i : queries) {
            if(dp.find(i) != dp.end()){
                ans.push_back(dp[i]);
            }
            else {
                auto it = dp.upper_bound(i);
                if(it == dp.begin()) ans.push_back(0);
                else {
                    it--;
                    ans.push_back((*it).second);
                }
                
            }
        }
        return ans;
    }
};