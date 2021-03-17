class Solution {
public:
    bool canPermutePalindrome(string s) {
        int array[256] = {0};

        for (char c: s) {
            ++ array[c-'a'];
        }

        int cnt=0;
        for (int i=0; i<256; ++i) {
            if (array[i] & 1) ++cnt;
        }

        // below if-else can be reduced to just return cnt<=1
        // Suppose exactly two characters are different in a string with an even length
        // this will result in cnt==2
        //if (s.length() & 1) return (cnt==1);
        //else return (cnt==0);
        return cnt <= 1;
    }
};

// from https://leetcode.com/problems/palindrome-permutation/discuss/69574
class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> b;
        for (char c : s)
            b.flip(c);
        return b.count() < 2;
    }
};
