class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        int cnt = 0;
        int i = 0;
        while(i < s.size()) {
            while(i < s.size() && s[i] == '0') {
                cnt++;
                i++;
            }
            if(cnt %2 != 0) {
                ans++;
                i++;
                cout<<i<<" x ";
            }
            cnt = 0;
            while(i<s.size() && s[i] == '1') {
                cnt++;
                i++;
            }
            if(cnt % 2 != 0) {
                ans++;
                i++;
                cout<<i<<" y ";
            }
            cnt = 0;
        }
        return ans;
    }
};