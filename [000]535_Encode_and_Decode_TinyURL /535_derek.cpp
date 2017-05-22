// unordered_map
class Solution {
  public:
    int counter = 0;
    unordered_map<string, string> m;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (m.find(longUrl) != m.end()) {
            // The url is already in the map
            return m[longUrl];
        } else {
            string new_tinyURL = to_string(counter);
            // Append 0 before the tiny URL
            while (new_tinyURL.size() < 6) {
                new_tinyURL = "0" + new_tinyURL;
            }
            m[longUrl] = new_tinyURL;
            counter++;
            return new_tinyURL;
        }
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        for ( const auto& n : m ) {
            if (n.second == shortUrl)
                return n.first;
        }
    }
};