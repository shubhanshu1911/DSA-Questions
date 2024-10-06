class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Split the sentences into words
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        
        // Make sure words1 is the shorter or equal length sentence
        if (words1.size() > words2.size()) {
            swap(words1, words2);
        }
        
        int i = 0, j = 0;
        int m = words1.size(), n = words2.size();
        
        // Compare from the start (prefix comparison)
        while (i < m && words1[i] == words2[i]) {
            i++;
        }
        
        // Compare from the end (suffix comparison)
        while (j < m && words1[m - j - 1] == words2[n - j - 1]) {
            j++;
        }
        
        // Check if all words of the shorter sentence are covered
        return i + j >= m;
    }
    
private:
    // Helper function to split a sentence into words
    vector<string> split(const string& sentence) {
        vector<string> words;
        istringstream stream(sentence);
        string word;
        while (stream >> word) {
            words.push_back(word);
        }
        return words;
    }
};
