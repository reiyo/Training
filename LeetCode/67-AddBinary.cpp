class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) a.swap(b);
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        bool carry = false;        
        size_t i=0;
        
        for (; i<b.length(); ++i) {
            if (a[i] == b[i]) {
                if (a[i] == '1') {
                    if (!carry) {
                        carry = true;
                        a[i] = '0';
                    } 
                } else {
                    if (carry) {
                        carry = false;
                        a[i] = '1';
                    }
                }
            } else {
                if (carry) {
                    carry = true;
                    a[i] = '0';
                } else {
                    a[i] = '1';
                }
            }
        }
        
        while (carry && i<a.length()) {
            if (a[i] == '1') {
                a[i++] = '0';
            }
            else {
                a[i++] = '1';
                carry = false;
            }
        }
        
        if (carry) {
            a.push_back('1');
        }
        
        reverse(a.begin(), a.end());
        return a;
    }
};
