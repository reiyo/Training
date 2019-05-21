class Solution {
public:
    string frequencySort(string s) {
        int count[256] = {0};
        
        for (char c: s) ++ count[c];
        
        const int len = static_cast<int>(s.size());
        vector<string> bins(len+1);
        
        for (int i=0; i<256; ++i) {
            const string& s = string(count[i], i);
            bins[count[i]].append(s);
        }
        
        string output;
        
        for (int i=len; i>0; --i) {
            if (bins[i].empty()) continue;
            output.append(bins[i]);
        }
        
        return output;
    }
};
