class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string url) {
        reverse(url.begin(), url.end());
        return url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string url) {
        reverse(url.begin(), url.end());
        return url;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));