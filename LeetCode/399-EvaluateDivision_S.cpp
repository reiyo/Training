class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> lut;
        
        for (size_t i=0; i<equations.size(); ++i) {
            const string& op1 = equations[i][0];
            const string& op2 = equations[i][1];
            const double val = values[i];
            
            lut[op1][op2] = val;
            lut[op2][op1] = 1.0/val;
        }
        
        vector<double> output;
        
        for (size_t i=0; i<queries.size(); ++i) {
            set<string> s;
            double result = dfs(lut, queries[i][0], queries[i][1], s, 1.0);
            
            if (result >= 0) output.push_back(result);
            else output.push_back(-1.0);
        }
        
        return output;
    }
    
    // this problem can be modeled as a graph problem that finds a path from a source node to a target node
    // "visited" is something like that used for BFS to avoid a node is visited twice
    double dfs(unordered_map<string, unordered_map<string, double>>& lut, string& source, string& target, set<string>& visited, double val) {
        // can use -1.0 because values must be positive!
        if (lut.find(source)==lut.end()) return -1.0;
        if (visited.find(source)!=visited.end()) return -1.0;
        
        // this cannot be placed earlier, considering the case that both source and target are the same
        // but they are not shown in equations
        if (source == target) return val;
        
        visited.insert(source);
        unordered_map<string, double>& tmp = lut[source];
        
        for (auto it=tmp.begin(); it!=tmp.end(); ++it) {
            string next = it->first;
            
            double result = dfs (lut, next, target, visited, val * (it->second));
            if (result >= 0.0) return result; 
        }
        
        // not needed to erase source from visited
        // visited.erase(source);
        
        return -1.0;
    }
};
