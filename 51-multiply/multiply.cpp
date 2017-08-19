// B[i] = A[0]*A[1]* ... *A[i-1]*A[i+1]* ... *A[n-1]
//不许使用除法

vector<int> multiply(const vector<int>& A) {
    vector<int> B(A.size(), 1);
    for (int i=1; i<A.size(); i++) {
        B[i] = B[i-1] * A[i-1];
    }
    int temp = 1;
    for (int i=A.size()-1; i>=0; i--) {
        B[i] *= temp;
        temp *= A[i];
    }

    return B;
}