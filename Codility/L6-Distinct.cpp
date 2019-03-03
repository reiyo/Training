#include <set>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::set<int> myset;
    
    for (auto it=A.begin(); it!=A.end(); ++it) {
        if (0==myset.count(*it)) myset.insert(*it);
    }
    
    return static_cast<int>(myset.size());
}
