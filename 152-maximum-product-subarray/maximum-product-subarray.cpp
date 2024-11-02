class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        vector<int> maxV(nums.size()), minV(nums.size());
        maxV[0] = nums[0];
        minV[0] = nums[0];

        for(int i = 1;i<nums.size();i++) {
            maxV[i] = max(maxV[i-1]*nums[i], max(minV[i-1]*nums[i], nums[i]));
            minV[i] = min(maxV[i-1]*nums[i], min(minV[i-1]*nums[i], nums[i]));
        }
        int ans = INT_MIN;
        for(int i : maxV) {
            ans = max(ans, i);
        }
        return ans;
    }
};