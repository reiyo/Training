// time complexity: O(n), where n is the number of employees
// space complexity: O(n)
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> dict;

        for (Employee* e: employees) dict[e->id] = e;

        return accuImportance(dict, id);
    }

    int accuImportance(unordered_map<int, Employee*>& dict, int id) {
        Employee* cur = dict[id];
        int sum = cur->importance;

        for (int e: cur->subordinates) sum += accuImportance(dict, e);

        return sum;
    }
};
