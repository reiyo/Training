// refer to https://leetcode.com/problems/sentence-screen-fitting/discuss/90845
// Time Complexity: O(n * m), where n is the number of rows, and m is the max word length among the words in the sentence
// Space Complexity: O(k), where k is the length of the sentence
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string str;

        // trick: add a space at the end of the sentence, and imagine an infinite sentence that repeats the given sentence
        // e.g., "hello world hello world ..." for ["hello", "world"]
        for (auto s: sentence) str += (s + " ");

        int len = str.length();

        // index of the first char of a word in the infinite sentence, in which the word is the beginning of a row
        int start = 0;

        for (int i=0; i<rows; ++i) {
            start += cols; // make "start" point to the char of a word for the next row

            // "start" may point to (1) a space between two words, (2) the first char of a word, or (3) an internal char of a word
            // below adjust the "start", so that "start" points to the first char of a word for the next row
            if (str[start % len] == ' ') {
                ++ start; // make "start" point to the first char of a word
            }
            else { // point to the first of an internal char of a word
                // make "start" point to the first char of the word 
                while (start > 0 && str[(start-1) % len] != ' ') -- start;
            }
        }

        // "start" now points to the char for the beginning of the next row
        // range [0, start-1] of the infinite sentence can be printed, i.e.,
        // length start-1+1 can be printed
        return (start-1+1) / len;
    }
};

// Optimized version; refer to @iaming https://leetcode.com/problems/sentence-screen-fitting/discuss/90845
// Time Complexity: O(n + k), where n is the number of rows, and k is the length of the sentence
// Space Complexity: O(k)
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string str;

        // trick: add a space at the end of the sentence, and imagine an infinite sentence that repeats the given sentence
        // e.g., "hello world hello world ..." for ["hello", "world"]
        for (auto s: sentence) str += (s + " ");

        int len = str.length();

        vector<int> move(len, 0);
        
        // refer to @iaming's solution and @zzg_zzm's explanation in https://leetcode.com/problems/sentence-screen-fitting/discuss/90845
        for (int i=1; i<len; ++i) {
            if (str[i] == ' ') move[i] = +1; // moving right will point to the first char of a word
            else move[i] = move[i-1] + (-1); // moving left will point to the first char of a word
        }
        
        // index of the first char of a word in the infinite sentence, in which the word is the beginning of a row
        int start = 0;

        for (int i=0; i<rows; ++i) {
            start += cols; // make "start" point to the char of a word for the next row
            start += move[start % len];          
        }

        // "start" now points to the char for the beginning of the next row
        // range [0, start-1] of the infinite sentence can be printed, i.e.,
        // length start-1+1 can be printed
        return (start-1+1) / len;
    }
};
