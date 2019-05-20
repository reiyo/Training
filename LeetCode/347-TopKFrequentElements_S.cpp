class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        
        for (int n: nums) ++ m[n];
        
        // bins[i] keeps the number(s) with frequency i
        // impossible to be a number with frequency > nums.size()
        vector<vector<int> > bins(nums.size()+1);
        
        for (auto it=m.begin(); it!=m.end(); ++it) {
            bins[it->second].push_back(it->first);
        }
        
        vector<int> output;
        
        for (int i=nums.size(); i>=0 && k>0; --i) {
            if (bins[i].empty()) continue;
            
            const vector<int>& cur = bins[i];
            k -= cur.size();
            output.insert(output.end(), cur.begin(), cur.end());
        }
        
        return output;
    }
};
