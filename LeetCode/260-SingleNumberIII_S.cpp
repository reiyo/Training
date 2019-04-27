class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int comp=0;
        
        // finally, comp is the XOR of the desired two elements;
        // comp must not be 0 because the two are distinct, and thus
        // some bit(s) of comp must be set
        for (int n: nums) {
            comp ^= n;
        }
        
        // the above can be replaced with
        // int comp = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        
        const int temp = comp & (comp-1); // temp is comp without the left-most 1
        const int leftone = comp ^ temp;  // find the left-most 1, i.e., last set bit
        
        // the above can be replaced with
        // leftone = comp & -comp;
        
        int group1=0, group2=0;
        
        // the desried two elements must be placed in different groups
        // because the last-most 1 comes from XOR, i.e., comes from their difference
        for (int n: nums) {
            if (n & leftone) {
                group1 ^= n;
            }
            else {
                group2 ^= n;
            }
        }
        
        return {group1, group2};
    }
};
