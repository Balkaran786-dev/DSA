// easy one, only understand the question clearly..
class Solution {
public:
    static bool cmp(vector<string> &v1, vector<string> &v2) {
        if (v1[1] == v2[1]) {
            return v1[0]=="OFFLINE" &&  v2[0]=="MESSAGE";
        }

        return stoi(v1[1]) < stoi(v2[1]);
    }

    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int> mention(n, 0);
        vector<int> offline(n, 0);

        sort(events.begin(), events.end(), cmp);

        for (auto event : events) {
            int time_stamp = stoi(event[1]);

            if (event[0] == "MESSAGE") {
                if (event[2] == "ALL") {
                    // If the message is for ALL users, increment mention for all users
                    for (int i = 0; i < n; i++) {
                        mention[i]++;
                    }
                }
                else if (event[2] == "HERE") {
                    // If the message is for users who are currently online, increment mention for online users
                    for (int i = 0; i < n; i++) {
                        if (offline[i] == 0 || offline[i] + 60 <= time_stamp) {
                            mention[i]++;
                        }
                    }
                }
                else {
                    // If the message is for specific users, handle the user IDs correctly
                    string num = "";
                    int sz=event[2].size();
                    for (int i = 0; i < sz; i++) {
                        if (event[2][i] == 'i' || event[2][i] == 'd') {
                            continue;
                        } else if (event[2][i] == ' ') {
                            int id = stoi(num);
                            mention[id]++;
                            num = "";
                        } else {
                            num.push_back(event[2][i]);
                        }
                    }
                    int lastId = stoi(num);  // for the last idx.
                    mention[lastId]++;
                }
            }
            else if (event[0] == "OFFLINE") {
                // Mark the user as offline at the given timestamp
                int id = stoi(event[2]);
                offline[id] = time_stamp;
            }
        }

        return mention;
    }
};
