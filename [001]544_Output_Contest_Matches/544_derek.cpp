class Solution {
  public:
    vector<string> Merge(vector<string> games) {
        // cout << "Get into merge" << endl;
        if (games.size() < 2) {
            return games;
        } else {
            vector<string> NextRound;
            for (int i = 0; i < games.size() / 2; i++) {
                NextRound.push_back( "(" + games[i] + "," + games[games.size() - 1 - i] + ")");
            }
            return Merge(NextRound);
        }
    }
    string findContestMatch(int n) {
        int num = n / 2;
        string output;
        vector<string> games;
        for (int i = 1; i < num + 1; i++) {
            games.push_back("(" + to_string(i) + "," + to_string(n + 1 - i) + ")");
        }

        vector<string> FinalGame = Merge(games);
        return FinalGame[0];
    }
};
////////////////////////
/// Version 2
////////////////////////
class Solution {
public:
    string findContestMatch(int n) {
        // Initilize vector
        vector<string> v(n);
        for(int i = 0; i < n; i++){
            v[i] = to_string(i+1);
        }
        // Key point: n > 1; v[n-1-i]
        while(n > 1){
            for(int i = 0; i < n/2; i++){
                v[i] = "(" + v[i] + "," + v[n-1-i] + ")";
            }
            n /=2;
        }
        return v[0];
    }
};