// refer to https://leetcode.com/problems/rle-iterator/discuss/645125
// Time Complexity: O(n)
// Space Complexity: O(n)
// note that binary search is also a solution, see, e.g., https://leetcode.com/problems/rle-iterator/discuss/203835
class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) {
        v = encoding;
        ind=0;
    }
    
    int next(int n) {
        while (ind<v.size()) {
            if (v[ind] >= n) {
                v[ind] -= n;
                return v[ind+1];
            }
            else {
                n -= v[ind];
                ind += 2;
            }
        }

        return -1;    
    }
private:
    vector<int> v;
    int ind;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
