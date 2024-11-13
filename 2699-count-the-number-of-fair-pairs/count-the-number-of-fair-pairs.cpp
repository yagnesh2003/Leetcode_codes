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
        // sort(nums.begin(), nums.end());
        // return f(nums, upper) - f(nums, lower-1);

        // Another method using lower bound and upper bound
        sort(begin(nums),end(nums));
        long long ans = 0,n = nums.size();
        for(int i=0;i<n;i++)
        {
            int low=lower_bound(begin(nums) + i + 1,end(nums),lower - nums[i]) - begin(nums);
            int high=upper_bound(begin(nums) + i + 1,end(nums),upper - nums[i]) - begin(nums);
            ans += 1LL*(high - low);
        }
        return ans;
    }
};