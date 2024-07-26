#include "add.cpp"

binaryNumber intToBin(int x) {
    binaryNumber res;
    int i = 0;
    while (x != 0) {
            res.v[i++] = x%2;
            x /= 2;
    }
    return res;
    
}

void printIt(binaryNumber& r) {
    for (int i = BITS - 1;i >= 0;i--) {
        cout << r.v[i] << " ";
    }
    cout << endl;
}

int BinToInt(binaryNumber& r) {
    int ans = 0;
    int pow = 1;
    for (int i = 0;i < BITS;i++) {
        ans = ans + pow*r.v[i];
        pow = pow*2;
    }
    return ans;
}





