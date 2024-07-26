#include "mul.cpp"

pair<binaryNumber,binaryNumber> nonResDiv(binaryNumber& a,binaryNumber& b) {  // a/b
    binaryNumber accu;
    binaryNumber q = a;
    for (int i = 0;i < BITS;i++) {
        if (accu.v[31]) {
            // negative
          accu =  shiftLeft(accu);
            accu.v[0] =  q.v[BITS-1];
           q =  shiftLeft(q);
            accu = add(accu,b);
        }
        else {
          accu =  shiftLeft(accu);
            accu.v[0] = q.v[BITS - 1];
           q =  shiftLeft(q);
            accu = sub(accu,b);
        }
        if (accu.v[31] == 0) q.v[0] = 1; 
    }
        if (accu.v[31]) accu = add(accu,b);
        return {accu,q};

}