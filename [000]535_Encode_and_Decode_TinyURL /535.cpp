#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
// https://leetcode.com/problems/design-tinyurl
// http://tinyurl.com/4e9iAk
string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string Input = "leetcode.com/problems/design-tinyurl";
string Output = "http://tinyurl.com/4e9iAk";
int id = 0;
unordered_map<string, string> m; //key is longURL, value is shortURL
unordered_map<int, string> idm;  //key is id in DB, value is longURL
// Encodes a URL to a shortened URL.
string encode(string longUrl) {
    if (m.find(longUrl) != m.end())return m[longUrl];
    string res = "";
    id++;
    cout << "[0]id:" << id << endl;
    int count = id;
    cout << "[1]count:" << count << endl;

    while (count > 0) {
        res = dict[count % 62] + res;
        cout << "res:" << res << endl;
        cout << "[2]count:" << count << endl;
        count /= 62;
        cout << "[3]count:" << count << endl;
    }
    while (res.size() < 6) {
        res = "0" + res;
    }
    m[longUrl] = res;
    idm[id] = longUrl;
    return res;
}

// Decodes a shortened URL to its original URL.
string decode(string shortUrl) {
    int id = 0;
    for (int i = 0; i < shortUrl.size(); i++) {
        id = 62 * id + (int)(dict.find(shortUrl[i]));
    }
    if (idm.find(id) != idm.end())return idm[id];
    return "";
}
int main(int argc, char const *argv[]) {
    cout << encode(Input) << endl;
    cout << encode(Output) << endl;

    return 0;
}