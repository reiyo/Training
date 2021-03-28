// Cascading
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        res.push_back(vector<int>());

        for (int n: nums) {
            int end = static_cast<int>(res.size());

            for (int i=0; i<end; ++i) {
                vector<int> temp = res[i];
                temp.push_back(n);
                res.emplace_back(temp);
            }
        }

        return res;
    }
};

// Bit-manipulation from https://leetcode.com/problems/subsets/discuss/27278
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        
        // subs.size()=8 for n=3
        vector<vector<int>> subs(p);
        
        // i can be viewed as 0, 01, 10, 11, ..., 111 
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                // every two, every four, every eight, ...
                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
};

// Backtracking
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> cur;
        
        output.push_back(vector<int>());
        
        for (int i=1; i<=nums.size(); ++i) {
            collect(nums, i, 0, cur, output);
        }
        
        return output;
    }
    
    void collect(const vector<int>& nums, int k, int c, vector<int> &cur, vector<vector<int>> &output)
    {
        if (k == 0) {
            output.push_back(cur);
            return;
        }
        
        for (int i=c; i<=nums.size()-k; ++i) {
            cur.push_back(nums[i]);
            collect(nums, k-1, i+1, cur, output);
            cur.resize(cur.size()-1);
        }
        
        return;
    }
};
