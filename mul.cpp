#include "sub.cpp"

binaryNumber shiftLeft(binaryNumber& a) {// equivalent to multiplication of 2
    binaryNumber l;
    for (int i = BITS - 1;i > 0;i--) {
        l.v[i] = a.v[i - 1];
    }
    return l;
}

binaryNumber shiftRight(binaryNumber& a) {// equivalent to division of 2
    binaryNumber l;
    for (int i = 0;i < BITS - 1;i++) {
        l.v[i] = a.v[i +  1];
    }
    return l;
}

// code for regular multiplication
binaryNumber mul(binaryNumber& a,binaryNumber& b) {
    binaryNumber temp = a;
    binaryNumber ans;
    for (int i = 0;i < 32;i++) {
        if (b.v[i]) {
            ans = add(ans,temp);
        }
        // printIt(temp);
      temp =  shiftLeft(temp);
    }
    return ans;
}

// int main(){
//         cout << "enter first number:" << " ";
//     int x;
//     cin >> x;
//     cout << endl;
//     int y;
//     // cout << "enter second number" << " ";
//     // cin >> y;
//     // cout << endl;

//     binaryNumber xx = intToBin(x);
//     // binaryNumber yy = intToBin(y);

//     cout << "first number in binary is " << endl;
//     printIt(xx);
//     binaryNumber yy = shiftLeft(xx);
//     printIt(yy);


//     return 0;
// }


/*
following code is for booth algorithm 
*/

binaryNumber boothMul(binaryNumber& a,binaryNumber& b) {
    bool over_lsb = false;
    binaryNumber accumulator;
    binaryNumber bb = b;
    int i = 0;
    for (i = 0;i < 32;i++) {
        if (over_lsb ==  false && bb.v[0] == true) accumulator = add(accumulator,a);
        else if (over_lsb == true && bb.v[0] == false) accumulator = sub(accumulator,a);
        // code for right shift
        over_lsb = bb.v[0];
        shiftRight(bb);
        bb.v[31] = accumulator.v[0];
        shiftRight(accumulator);
        accumulator.v[31] = accumulator.v[30];
        
    }
    // return s only 32 bits 
    return bb;

}