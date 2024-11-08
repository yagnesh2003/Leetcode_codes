class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        vector<long long> prefixXOR(nums.size(), 0);
        long long maxXOR = (1<<maximumBit) - 1;
        prefixXOR[0] = nums[0];
        for(int i = 1;i<nums.size();i++) {
            prefixXOR[i] = prefixXOR[i-1]^nums[i];
        }
        for(int i = nums.size()-1;i>=0;i--) {
            long long curr_XOR = prefixXOR[i];
            int k = maxXOR ^ curr_XOR;
            ans.push_back(k);
        }
        return ans;
    }
};