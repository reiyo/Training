class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty()) return num2;
        if (num2.empty()) return num1;
        const int m = num1.length();
        const int n = num2.length();
        int array[m+n] = {0};
        
        for (int i=m-1; i>=0; --i) {
            for (int j=n-1; j>=0; --j) {
                int product = (num1[i]-'0') * (num2[j]-'0');
                int sum = product + array[i+j+1];
                array[i+j+1] = sum % 10;
                array[i+j] += sum / 10;
            }
        }
        
        string output;
        
        for (int i=0; i<m+n; ++i) {
            if (array[i] == 0) {
                if (!output.empty()) output += (char)(array[i]+'0');
            } else output += (char)(array[i]+'0');
        }

        return (output.empty())? "0" : output;
    }
};
