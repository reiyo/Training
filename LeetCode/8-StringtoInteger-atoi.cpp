class Solution {
public:
    int myAtoi(string str) {
        str.erase(0, str.find_first_not_of(' '));
        if (str.empty()) return 0;
        bool isNeg = false;
        int i = 0;
        
        if (str[i] == '-') {
            isNeg = true;
            ++i;
        } else if (str[i] == '+') ++i;
        else if (!isdigit(str[i])) return 0;
        
        if (i >= str.size() || !isdigit(str[i])) return 0;
        int sum = str[i++] - '0';
        if (isNeg) sum *= -1;
        
        while (i < str.size()) {
            if (!isdigit(str[i])) break;
            
            if (isNeg) {
                int temp = sum * 10 - (str[i]-'0');
                int temp2 = (temp + (str[i]-'0'))/10;
                //if (temp > 0) return INT_MIN;
                if (temp > 0 || sum != temp2) return INT_MIN;
                else sum = temp;
            } else {
                int temp = sum * 10 + (str[i]-'0');
                int temp2 = (temp - (str[i]-'0'))/10;
                //if (temp < 0) return INT_MAX;
                if (temp < 0 || sum != temp2) return INT_MAX;
                else sum = temp;
            }
            
            ++ i;
        }
        
        return sum;
    }
};
