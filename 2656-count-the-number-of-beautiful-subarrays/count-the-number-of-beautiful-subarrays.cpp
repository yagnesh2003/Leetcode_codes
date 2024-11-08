class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        vector<long long> pref(nums.size(),0);
        unordered_map<int, int> mp;
        long long cnt = 0;
        pref[0] = nums[0];
        if(pref[0] == 0) cnt++;
        mp[pref[0]]++;
        for(int i = 1;i<nums.size();i++) {
            pref[i] = pref[i-1]^nums[i];
            cout<<"pref [i]] is "<<pref[i]<<endl;
            if(pref[i] == 0) {
                cnt++;
                cout<<"here"<<endl;
            }
            mp[pref[i]]++;
            if(mp[pref[i]] > 1) {
                cnt+= mp[pref[i]]-1;
            }
        }

        return cnt;
    }
};