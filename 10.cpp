// FAILS TEST CASE 6.
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */
int binary_search(vector<int>a, int score) {
	int mid {};
	int l {};
	int h = a.size() - 1;

	while (l <= h) {
		mid = l + (h - l) / 2;
		if (a[mid] == score)
			return mid;
		else if (a[mid] < score && a[mid - 1] > score)
			return mid;
		else if (a[mid] > score && a[mid + 1] <= score)
			return mid + 1;
		else if (a[mid] < score)
			h = mid - 1;
		else if (a[mid] > score)
			l = mid + 1;
	}
	return -1;
}

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    int n = ranked.size();
	int m = player.size();
	int cur_score {};

	vector<int> res {};
	vector<int> rank {};

	rank.push_back(1);

	for (int i = 1; i < n; i++) { 
		if (ranked[i] == ranked[i - 1])
			rank.push_back(rank[i - 1]);
		else
			rank.push_back(rank[i - 1] + 1);
	}

	for (int i = 0; i < m; i++) {
		cur_score = player[i];

		if (cur_score > ranked[0])
			res.push_back(1);
		else if (cur_score < ranked[n - 1])
			res.push_back(rank[n - 1] + 1);
		else {
			int pos = binary_search(ranked, cur_score);
			res.push_back(rank[pos]);
		}
	}

	return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ranked_count_temp;
    getline(cin, ranked_count_temp);

    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(cin, ranked_temp_temp);

    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++) {
        int ranked_item = stoi(ranked_temp[i]);

        ranked[i] = ranked_item;
    }

    string player_count_temp;
    getline(cin, player_count_temp);

    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(cin, player_temp_temp);

    vector<string> player_temp = split(rtrim(player_temp_temp));

    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++) {
        int player_item = stoi(player_temp[i]);

        player[i] = player_item;
    }

    vector<int> result = climbingLeaderboard(ranked, player);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
