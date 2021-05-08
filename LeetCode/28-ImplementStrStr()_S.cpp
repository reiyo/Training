// time complexity: O(m+n), where n is the length of haystack, and n is the length of needle
// space complexity: O(n)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = static_cast<int>(haystack.length());
        int n = static_cast<int>(needle.length());
        if (!n) return 0;
        if (m < n) return -1;

        const vector<int>& table = buildTable(needle);

        for (int i=0, j=0; i<m; ) {
            if (haystack[i] == needle[j]) {
                if (j == n-1) return i-n+1;             
                ++ i;
                ++ j;               
            }
            else {
                if (j == 0) ++i;
                else j = table[j-1];
            }
        }

        return -1;
    }

private:
    vector<int> buildTable(string pat) {
        vector<int> table(pat.size(), 0);
        
        // trick: i starts from 1
        // trick: i might not be incremented
        for (int i=1, j=0; i<pat.size(); ) {
            if (pat[i] == pat[j]) {
                table[i] = j+1;
                ++ i;
                ++ j;                
            }
            else {
                if (j == 0) {
                    table[i] = 0;
                    ++ i;
                }
                else j = table[j-1];
            }
        }

        return table;
    }
};

/*


Note 1: The table is to find the longest prefix which is also suffix (excluding the whole string, where the whole string must satisify the condition).
        The table is called, Failure Function.

Note 2: Below try to explain some about why the algorithm works.
        We are given a text and a pattern. In short, TXT and PAT. 
        Assume that '-' is a character different from any of a, b, c, and x. 
        Let F be the table.

        TXT abxxxab---abccc
        PAT abxxxab---abd
        F   0000012000120

        When we check the No. 12 character (0-based indexing), we found c!=d; that is,

        abxxxab---abccc
        abxxxab---abd

        Using the table, the No. 12 character of TXT will then be compared with F(12-1)=2, i.e., No. 2 character of PAT

        abxxxab---abc
                  abxxxab---abd

        This is because F(11)=2 shows that the 10 and 11 of TXT must equal the 0 and 1 of PAT, respectively
        We may continue the check from No. 12 character of TXT, why?
        Is it possible that the solution starts from the "ab" between xxx and ---?

        That is, 

        abxxxab---abc
             abxxxab---abd

        Impossible. The solution starts from that "ab" means "xxx" equals "---";
        but, F(11)=2 means "xxx" and "---" are different. So, proof by contradiction.

        By the way, F(11) will be 7 if "xxx" and "---" are the same.
        If this is the case, we will continue the check by comparing No. 12 character of TXT and No. 7 character of PAT 

        abxxxabxxxabc
             abxxxabxxxabd
Note 3: The time complexity is O(m+n). 
        It can be shown that the complexity is correct even if the text is "aa...a" (m number of a's) and the pattern is "aa..a" (n number of a's).
        See, https://stackoverflow.com/questions/9182651/whats-the-worst-case-complexity-for-kmp-when-the-goal-is-to-find-all-occurrence.
        In general cases, the index of the text stops moving forward when there is a mismatch. At the moment, the table will make the index of
        the pattern move backward. At first glance, the complexity becomes O(m*n). However, the number of moves on the pattern at most equals to
        the number of moves in previous iterations. So, O(m+n) still holds.
*/
