class Solution {
public:
    bool rotateString(string s, string goal) {
        string str = s;
        if(s.size() > goal.size()) return false;
        str += s;
        for(int i = 0;i<=str.size()-goal.size();i++) {
            if(str.substr(i,s.size()) == goal) return true;
        }
        return false;
    }
};