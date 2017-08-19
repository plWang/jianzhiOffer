// hash table 

bool duplicate(int numbers[], int length, int* duplication) {
    vector<int> hashTable(length, 0);
    for (int i=0; i<length; i++) {
        int index = numbers[i];
        if (hashTable[index] != 0) {
            *duplication = index;
            return true;
        }
        else
            hashTable[index] = 1;
    }

    return false;
}