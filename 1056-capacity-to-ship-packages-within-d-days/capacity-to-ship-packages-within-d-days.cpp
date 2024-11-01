class Solution {
public:
    bool is(int mid, vector<int> &weights, int days) {
        int temp = 0;
        int cnt = 1;
        for(int i = 0;i<weights.size();i++) {
            temp += weights[i];
            if(temp > mid) {
                cnt++;
                temp = 0;
                i--;
            }
        }
        if(cnt > days) return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int sum = 0;
        int ans = 0;
        for(int i : weights) {
            sum += i;
        }
        int high = sum;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(is(mid, weights, days)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};