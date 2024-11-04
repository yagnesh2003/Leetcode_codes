class Solution {
public:
    string f(int a) {
        string str = "";
        for (int i = 7; i >= 0; i--) {
            int k = a >> i;
            if (k & 1)
                str += '1';
            else
                str += '0';
        }
        return str;
    }

    bool validUtf8(vector<int>& data) {
        int i = 0;
        while(i < data.size()) {
            if(data[i] < 128) i++;
            else {
                string bin = f(data[i]);
                if(bin.substr(0,3) == "110") {
                    i++;
                    if(i >= data.size()) return false;
                    string bin2 = f(data[i]);
                    if(bin2.substr(0,2) != "10") return false; 
                    i++;
                }
                else if(bin.substr(0,4) == "1110") {
                    if(i+2 >= data.size()) return false;
                    for(int a = i+1;a<=i+2;a++) {
                        string bin2 = f(data[a]);
                        if(bin2.substr(0,2) != "10") return false; 
                    }
                    i+=3;
                }
                else if(bin.substr(0,5) == "11110") {
                    if(i+3 >= data.size()) return false;
                    for(int a = i+1;a<=i+3;a++) {
                        string bin2 = f(data[a]);
                        if(bin2.substr(0,2) != "10") return false; 
                    }
                    i+=4;
                }
                else {
                    return false;
                }
            }
            
        }

        return true;
    }
};