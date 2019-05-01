class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> answers(queries.size(), 0);
        int sum = 0;
        
        for (int n: A) { 
            if (n % 2 == 0) sum += n;
        }
        
        //int sum = accumulate(A.begin(), A.end(), 0, [](int s, int a) { return s + (a % 2 == 0 ? a : 0); });
        
        for (size_t i=0; i<queries.size(); ++i) {
            const int index = queries[i][1];
            if (A[index] % 2 == 0) sum -= A[index];
            
            A[index] += queries[i][0];
            if (A[index] % 2 == 0) sum += A[index];
            
            answers[i] = sum;
        }
        
        return answers;
    }
};
