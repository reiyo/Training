class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        # refer to https://leetcode.com/problems/most-common-word/discuss/123854
        
        # \w matches any alphanumeric character, i.e., [a-zA-Z0-9_], so below \w also works
        wordlst = re.findall('[a-z]+', paragraph.lower())
        bannedset = set(banned)
        nonbannedWordlst = [w for w in wordlst if w not in bannedset]
        return collections.Counter(nonbannedWordlst).most_common(1)[0][0]
