class Solution {
public:
    static bool comp (vector<int> &a, vector<int> &b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int ans = 0;

        int prev_end = intervals[0][1];
        for(int i = 1;i<intervals.size();i++) {
            int curr_start = intervals[i][0];
            if(curr_start < prev_end) {
                ans++;
            }
            else {
                prev_end = max(prev_end, intervals[i][1]);
            }
        } 
        return ans;
    }
};