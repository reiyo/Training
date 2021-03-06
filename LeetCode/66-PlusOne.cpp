// Note that no need to reverse: https://leetcode.com/problems/plus-one/discuss/24084/Is-it-a-simple-code(C%2B%2B)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        
        int carry = 1;
        size_t i = 0;
        
        while (carry && i < digits.size()) {
            if (digits[i] == 9) {
                digits[i++] = 0;
                carry = 1;
            } else {
                digits[i] += 1;
                carry = 0;
            }
        }
        
        if (carry) digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
