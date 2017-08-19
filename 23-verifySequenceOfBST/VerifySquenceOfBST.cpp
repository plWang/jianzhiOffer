bool Verify(vector<int> sequence, int begin, int end) {
    if (begin >= end) return true;
    int root = sequence[end];
    int i=begin;
    while (i<=end-1 && sequence[i++] < root);
    int mid = i;
    while (i<=end-1) {
        if (sequence[i++] < root) return false;
    }

    return (Verify(sequence, begin, mid-1) && Verify(sequence, mid, end-1));
}

bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.size() == 0) return false; 
    if (sequence.size() == 1) return true;
    return Verify(sequence, 0, sequence.size()-1);
}