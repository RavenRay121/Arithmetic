#include<iostream>
#include<vector>
using namespace std;

#define BITS 32

class binaryNumber{
    public:
    vector<bool> v;
    binaryNumber() {
        v = vector<bool>(BITS,0);
    }
};

binaryNumber add(binaryNumber& a,binaryNumber& b) {
    bool carry = 0;
    binaryNumber ans;
// cout << "i am here" << endl;
int i;
    for (i = 0;i < BITS;i++) {
        ans.v[i] = ((carry)^(a.v[i]))^(b.v[i]);
        carry = (carry&a.v[i])|(carry&b.v[i])|(a.v[i]&b.v[i]);
        // cout << i << endl;
    }
    return ans;
}
// int main() {
//     cout << "helloWOrld this is a arithmetic file holder" << endl;
//     binaryNumber a;
//     binaryNumber b;
//     a.v[6] = 1;
//     b.v[7] = 1;
//     add(a,b);
//     cout << "done" <<endl;
//     return 0;
// }