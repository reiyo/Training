class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mymap;
        
        for (int i=0; i<strs.size(); ++i) {
            string inStr = getNormalizeStr(strs[i]);
            
            if (mymap.count(inStr) == 0) mymap[inStr] = vector<string>();
            mymap[inStr].push_back(strs[i]);
        }
        
        vector<vector<string>> output(mymap.size());
        int index = 0;
        
        for (auto it=mymap.begin(); it!=mymap.end(); ++it) {
            output[index++].swap(it->second);
        }
        
        return output;
    }
    
    string getNormalizeStr(const string& s) {
        int myarray[27] = {0};
        
        for (string::const_iterator it=s.begin(); it!=s.end(); ++it) {
            ++ myarray[*it-'a'];
        }
        
        string out;
        
        for (int i=0; i<27; ++i) {
            if (myarray[i] > 0) out += string(myarray[i], i+'a');
        }
        
        return out;
    }
};
