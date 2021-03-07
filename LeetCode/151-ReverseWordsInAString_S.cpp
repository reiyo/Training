class Solution {
public:
    void reverseWords(string &s) {
        shrink(s);
        if (s.empty()) return;
        
        int k = 0;
        
        for (int i=0; i<s.length(); ++i) {
            if (s[i] == ' ') {
                reverseWord(s, k, i-1);
                k = i+1;
            }
        }
        
        reverseWord(s, k, s.length()-1);
        reverseWord(s, 0, s.length()-1);
    }
    
    void reverseWord(string& s, int i, int j) {
        while (i < j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            ++i;
            --j;
        }
    }
    
    void shrink(string& s) {
        int k = 0;
        bool sflag = true;
        
        for (int i=0; i<s.length(); ++i) {
            if (s[i] != ' ') {
                sflag = false;
                s[k++] = s[i];
            } else {
                if (sflag == false) {
                    s[k++] = ' ';
                    sflag = true;
                }
            }
        }
        
        if (sflag == false) s.resize(k);
        else {
            if (k > 0) s.resize(k-1);
            else s.clear();
        }
    }
};

// refer to https://leetcode.com/problems/reverse-words-in-a-string/discuss/47740
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int start=0;

        for (int i=0; i<s.length(); ++i) {
            if (s[i] != ' ') {
                if (start!=0) s[start++] = ' ';
                int j=i;

                while (j < s.length() && s[j]!=' ') s[start++] = s[j++];
                reverse(s.begin() + start - (j-i), s.begin() + start);
                i = j;
            }
        }

        s.erase(s.begin()+start, s.end());
        return s;
    }
};
