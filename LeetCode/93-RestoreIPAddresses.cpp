class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.empty()) return vector<string>();
        vector<string> results;
        string combination;
        collect(s, 0, 0, combination, results);
        return results;
    }
    
    void collect(string &s, int start, int numIndex, string &combination, vector<string> &results)
    {
        if (numIndex >= 4) {
            if (start >= s.length()) results.push_back(combination);
            return;
        }
        if (start >= s.length()) return;
        
        for (int i=1; i<=3; ++i) {
            if (start + i -1 >= s.length()) break;
            string sVal = s.substr(start, i);
            
            if (i==2 && sVal[0]=='0') continue;
            if (i==3) {
                if (sVal[0]=='2') {
                    if (sVal[1]-'0' > 5) continue;
                    else if (sVal[1]-'0' == 5 && sVal[2]-'0' > 5) continue;
                }
                else if (sVal[0]!='1') continue;
            }

            string backup = combination;
                
            if (numIndex>0) combination += ("." + sVal);
            else combination += sVal;
                
            collect(s, start+i, numIndex+1, combination, results);
            combination.swap(backup);
        }
        
        return;
    }
};
