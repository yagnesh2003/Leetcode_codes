class Solution {
public:
    long long f(vector<int>&nums, int a) {
        long long i = 0, res = 0;
        long long j = nums.size()-1;
        while(i < j) {
            while((i < j) && nums[i] + nums[j] > a) {
                j--;
            }
            res += j - i;
            i++;
        }
        return res;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return f(nums, upper) - f(nums, lower-1);
    }
};