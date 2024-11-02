class Solution {
public:
    bool isCircularSentence(string s) {
        if(s[0] == ' ' || s[s.size()-1] == ' ') {
            return false;
        }
        if(s[0] != s[s.size()-1]) return false;
        bool flag = false;
        stack<char> st;
        for(int i = 0;i<s.size();i++) {
            if(s[i] == ' ') {
                flag = true;
                char c = st.top();
                if(c != s[i+1]) {
                    return false;
                }
            }
            st.push(s[i]);
        }
        if(flag == false) return s[0] == s[s.size()-1];
        return true;
    }
};