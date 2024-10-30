class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> a(nums.size(),0) , v;
        for(int i = 0;i<nums.size();i++) {
            int x = nums[i];
            auto it = lower_bound(begin(v), end(v), x);
            a[i] = it - v.begin();
            if(it != v.end()) *it = x;
            else v.push_back(x);
        }
        int lis_length = *max_element(a.begin(), a.end()) + 1;
        return lis_length;
    }
};