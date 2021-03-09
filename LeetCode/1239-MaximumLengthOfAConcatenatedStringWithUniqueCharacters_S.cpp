// refer to https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/discuss/414172
class Solution {
public:
    int maxLength(vector<string>& arr) {
        if (arr.size() == 1) return arr[0].length();

        int maxlen = 0;
        vector<bitset<26> > combs;
        combs.push_back(bitset<26>());

        for (int i=0; i<arr.size(); ++i) {
            bitset<26> bs;
            
            // has to be set one-by-one
            for (char c: arr[i]) bs.set(c-'a');

            if (bs.count() < arr[i].size()) continue;
            int cur_size = combs.size();

            for (int j=0; j<cur_size; ++j) {
                if ((bs & combs[j]).any()) continue;
                combs.push_back(bs | combs[j]);
                // cast to int is a must, because max() requires the two args with the same type
                maxlen = max(maxlen, static_cast<int>((combs.back()).count()));
            }
        }

        return maxlen;
    }
};
