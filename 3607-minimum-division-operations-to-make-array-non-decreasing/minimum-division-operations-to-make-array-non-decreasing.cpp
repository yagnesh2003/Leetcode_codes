static bool flag = true;
static vector<int> spf; 
class Solution {
   

public:
   
    void computeSPF(int maxN) {
        spf.resize(maxN + 1);
        for (int i = 0; i <= maxN; ++i) {
            spf[i] = i;
        }

        for (int i = 2; i * i <= maxN; ++i) {
            if (spf[i] == i) { 
                for (int j = 2 * i; j <= maxN; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    int greatestProperDivisor(int x) {
        if (x == 1) return 1; 
        return x / spf[x];
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        

       if(flag){
            computeSPF(1e6);
           flag = false;
       }
       

        for (int i = n - 2; i >= 0; --i) {
            while (nums[i] > nums[i + 1]) {
                int gpd = greatestProperDivisor(nums[i]);
                if (gpd == 1) {
                    
                    return -1;
                }
                nums[i] = nums[i] / gpd; 
                ans++;
                if (nums[i] == 1 && nums[i] > nums[i + 1]) {
                  
                    return -1;
                }
            }
        }

        return ans;
    }
};