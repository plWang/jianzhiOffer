void backtrack(vector<string>& solutions, string& temp, string candidates, vector<int>& used, int size, int& n) {
    if (n == size) {
        solutions.push_back(temp);
        return;
    }

    for (int i=0; i<size; i++) {
        if (i>0 && candidates[i-1] == candidates[i] && used[i-1] == 0)
            continue;
        if (used[i] == 0) {
            temp.push_back(candidates[i]);
            n++;
            used[i] = 1;
            backtrack(solutions, temp, candidates, used, size, n);
            temp.pop_back();
            n--;
            used[i] = 0;
        }
    }

}

vector<string> Permutation(string str) {
    vector<string> solutions;
    if (str.size() == 0) return solutions;
    string temp = "";
    vector<int> used(str.size(), 0);
    sort(str.begin(), str.end());
    int size = str.size();
    int n=0;
    backtrack(solutions, temp, str, used, size, n);

    return solutions;
}