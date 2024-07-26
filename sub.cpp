// #include "add.cpp"
#include "intToBin.cpp"

binaryNumber complement(binaryNumber& r) {
    // this generates 1's complement of the number 
    binaryNumber comp;
    for (int i = 31;i>=0;i--) {
        comp.v[i] = r.v[i] ? 0 : 1;
    }
    return comp;
}

binaryNumber complement2(binaryNumber& r) {
    binaryNumber comp = complement(r);
    binaryNumber one = intToBin(1);
    // cout << "this is 1" << endl;
        // printIt(one);
    return add(one,comp);
}

binaryNumber sub(binaryNumber& a,binaryNumber& b) {
    binaryNumber c = complement2(b);
    return add(a,c);
}