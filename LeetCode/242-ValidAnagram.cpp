class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()) return false;
        int record[26] = {0};
        
        for (char c: s) {
            record[c-'a'] += 1;
        }
        
        for (char c: t) {
            if (record[c-'a'] <= 0) return false;
            else -- record[c-'a'];
        }
        
        return true;
        
        /* sorting is also a solution
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
        */
    }
};
