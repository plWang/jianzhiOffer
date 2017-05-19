int FirstNotRepeatingChar(string str) {
    if (str.size() <= 0) return -1;
    vector<int> hashmap(256, 0);
    for (int i=0; i<str.size(); i++) {
        hashmap[str[i]]++;
    }

    for (int i=0; i<str.size(); i++) {
        if (hashmap[str[i]] == 1)
            return i;
    }

    return -1;
}