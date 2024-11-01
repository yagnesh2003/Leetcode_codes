class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        for(int i = 0;i<s.size()-1;i++) {
            if(res.size()==0) res.push_back(s[i]);
            else {
                if(res[res.size()-1] == s[i] && res[res.size()-1] == s[i+1]) {
                    continue;
                }
                else {
                    res.push_back(s[i]);
                }
            }
        }
        res.push_back(s[s.size()-1]);
        return res;
    }
};