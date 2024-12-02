class Solution {
public:
    bool check(string sentence, int i, string searchWord) {
        if(searchWord == sentence.substr(i,searchWord.size())) return true;
        return false;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        int i = 0;
        int ans = 0;
        int cnt = 0;
        while(i < sentence.size()) {
            if(sentence[i] == ' ') {
                i++;
            }
            bool flag = check(sentence, i, searchWord);
            cnt++;
            if(flag) return cnt;
            while(i < sentence.size() && sentence[i] != ' ') i++;
        }
        return -1;
    }
};