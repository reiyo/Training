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

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dict({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100},
                                       {'D', 500}, {'M', 1000}});
        if (1 == s.length()) return dict[s[0]];
        int res = 0;
        int i=0;
        for (; i+1<static_cast<int>(s.length()); ++i) {
            if (dict[s[i]] < dict[s[i+1]]) res -= dict[s[i]];
            else res += dict[s[i]];
        }

        res += dict[s[i]];
        return res;
    }
};
