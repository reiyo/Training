/* 
   Refer to https://leetcode.com/problems/guess-the-word/discuss/133862/Random-Guess-and-Minimax-Guess-with-Comparison
            https://leetcode.com/problems/guess-the-word/discuss/556075/How-to-explain-to-interviewer-843.-Guess-the-Word

   Keypoint 1: No one can guarantee to find the secret.

   Keypoint 2: Given a word, if the number of exact matches between the word and the secret is x, we may update the word list
   by keeping only the words with the same number of matches (i.e., x) to the given word.
   
   To reduce the solution space the most, an idea is to find the word, say w, with the minimum number of zero matches to the other words.
   If the number of matches between the secret and w is 0, we can then remove w and those words with >0 number of matches to w (as 
   the keypoint 2 above).
   
   I thought that the method works even if the number of matches between every pair of words > 0. This will be the case of picking a word randomly.
   Of course, we can further optimize for this case if desired.
*/
Take a word from wordlist and guess it.
Get the matches of this word
Update our wordlist and keep only the same matches to our guess.
is that we will only keep the words with the same number of exact matches

class Solution {
public:
    int matchCnt(string& w1, string& w2) {
        int cnt=0;

        // length of a word is 6
        for (int i=0; i<6; ++i) {
            if (w1[i] == w2[i]) ++ cnt;        
        }

        return cnt;
    }

    void findSecretWord(vector<string>& wordlist, Master& master) {
        if (wordlist.empty()) return;

        for (int i=0; i<10; ++i) {
            int n = wordlist.size();
            vector<int> cnts(n, 0);

            for (int j=0; j+1<n; ++j) {
                for (int k=j+1; k<n; ++k) {
                    if (matchCnt(wordlist[j], wordlist[k]) == 0) {
                        ++ cnts[j];
                        ++ cnts[k];
                    }
                }
            }

            int minCnt = cnts[0];
            int minId = 0;

            for (int j=1; j<n; ++j) {
                if (cnts[j] < minCnt) {
                    minCnt = cnts[j];
                    minId = j;
                } 
            }

            string& cand = wordlist[minId];
            int x = master.guess(cand);
            if (x == 6) return;

            vector<string> temp;

            for (string& w: wordlist) {
                if (matchCnt(cand, w) == x) temp.push_back(w);
            }

            wordlist.swap(temp);
        }
    }
};
