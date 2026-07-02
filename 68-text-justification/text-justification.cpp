class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {

            int j = i;
            int letters = 0;

            // Pick maximum words for current line
            while (j < n &&
                   letters + words[j].size() + (j - i) <= maxWidth) {
                letters += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            // Last line OR only one word
            if (j == n || gaps == 0) {

                line += words[i];

                for (int k = i + 1; k < j; k++)
                    line += " " + words[k];

                line += string(maxWidth - line.size(), ' ');
            }
            else {

                int totalSpaces = maxWidth - letters;

                int even = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                for (int k = i; k < j; k++) {

                    line += words[k];

                    if (k == j - 1)
                        continue;

                    int spaces = even;

                    if (extra > 0) {
                        spaces++;
                        extra--;
                    }

                    line += string(spaces, ' ');
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};