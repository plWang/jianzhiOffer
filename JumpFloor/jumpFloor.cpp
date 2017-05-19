int jumpFloor(int number) {
    if (number == 1) return 1;
    if (number == 2) return 2;
    int a = 1, b=2;
    int res;
    for (int i=3; i<number; i++) {
        res = a+b;
        a = b;
        b = res;
    }

    return res;
}