class Solution {
public:

    int KMP(string s, string p)
    {
        int m=s.size();
        int n=p.size();
         
        vector<int>lps(n,0);
        int len=0, i=1;
        
        while(i<n)
        {
            // if match happen
            if(p[len]==p[i]){ 
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0) 
                {
                    len=lps[len-1];
                }
                else 
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        
        // Now Searching part starts from here
        i=0;
        int j=0;
        while(i<m and j<n)
        {
            // if match happen then move both i and j
            if(s[i] == p[j])
            {
                i++;
                j++;
                if(j==n){ // we have an answer
                    return true;
                }
            }
            else
            {
                if(j!=0)
                {
                    j = lps[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string s = a;
        int ans = 1;
        while(s.size() < b.size()) {
            s += a;
            ans++;
        }
        if(KMP(s,b)) return ans;
        s = s+a;
        if(KMP(s, b)) return ans+1;
        return -1;
    }
};