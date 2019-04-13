class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.empty()) return vector<int>();
        vector<int> output;
        
        for (auto i=0; i<input.size(); ++i) {
            const char op = input[i];
            
            if (op == '+' || op == '-' || op == '*') {
                vector<int> part1 = diffWaysToCompute(input.substr(0, i));
                vector<int> part2 = diffWaysToCompute(input.substr(i+1));
                
                for (auto j=0; j<part1.size(); ++j) {
                    for (auto k=0; k<part2.size(); ++k) {
                        int result = 0;                        
                        if (op == '+')      result = part1[j]+part2[k];
                        else if (op == '-') result = part1[j]-part2[k];
                        else                result = part1[j]*part2[k];
                        output.push_back(result);
                    }
                }
            }
        }
        
        // important! input may be just a number
        if (output.empty())
            output.push_back(atoi(input.c_str()));
        
        return output;
    }
};
