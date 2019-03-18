class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) return 0;
        
        int myarray[256] = {0};
        myarray['I'] = 1;
        myarray['V'] = 5;
        myarray['X'] = 10;
        myarray['L'] = 50;
        myarray['C'] = 100;
        myarray['D'] = 500;
        myarray['M'] = 1000;
        
        int len = s.length();
        int result = myarray[s[len-1]];
        
        for (int i=len-2; i>=0; --i) {
            if (myarray[s[i+1]] > myarray[s[i]]) {
                result -= myarray[s[i]];
            } else {
                result += myarray[s[i]];
            }
        }
        
        return result;
    }
};
