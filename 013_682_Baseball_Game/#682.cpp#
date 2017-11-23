/*
You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

Integer (one round's score): Directly represents the number of points you get in this round.

"+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.

"D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.

"C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.

Each round's operation is permanent and could have an impact on the round before and the round after.

You need to return the sum of the points you could get in all the rounds.

*/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0, score = 0;
        vector<int> rounds;
        for (string op : ops) {
            if (op == "C") {
                sum -= rounds.back();
                rounds.pop_back();
                continue;
            }
            if (op == "D") {
                sum += score = rounds.back() * 2;
            }
            else if (op == "+") {
                sum += score = rounds[rounds.size() - 1] + rounds[rounds.size() - 2];
            }
            else {
                sum += score = stoi(op);
            }
            rounds.push_back(score);
        }
        return sum;
    }
};
