// #include "intToBin.cpp"

#include <chrono>
// #include "mul.cpp"
#include "div.cpp"

int main() {
   

    cout << "enter first number:" << " ";
    int x;
    cin >> x;
    cout << endl;
    int y;
    cout << "enter second number" << " ";
    cin >> y;
    cout << endl;

    binaryNumber xx = intToBin(x);
    binaryNumber yy = intToBin(y);

    cout << "first number in binary is " << endl;
    printIt(xx);
    cout << "second number in binary is " << endl;
    printIt(yy);

    // addition 
    // cout << "here" << endl;
    binaryNumber ad = add(xx,yy);
    cout << "the result of addition operation is :" << endl;
    printIt(ad);
    // cout << "here2" << endl;
    cout << "equivalent result in base 10 is " << endl;
    cout << BinToInt(ad) << endl;


    binaryNumber sb = sub(xx,yy);

    cout << "the result of subtraction operation is :" << endl;
    printIt(sb);
    cout << "equivalent result in base 10 is " << endl;
    cout << BinToInt(sb) << endl;



    auto start = chrono::high_resolution_clock::now();
    binaryNumber mu = mul(xx,yy);
    auto end = chrono::high_resolution_clock::now();
    cout << "result of regular multiplication is:" << endl;
    printIt(mu);
    cout << "equivalent result in base 10 :" << " " << BinToInt(mu) << endl;
    
    
    chrono::duration<double> duration = end - start;
    cout << "time taken to multipy the two numbers with brute force is " << duration.count() << ".seconds" << endl;

    start = chrono::high_resolution_clock::now();
    binaryNumber bmu = mul(xx,yy);
    end = chrono::high_resolution_clock::now();
    cout << "multiplication by booth's algorithm:" << endl;
    printIt(bmu);
    cout << "equivalent result in base 10: " << BinToInt(bmu) << endl; 
    duration = end - start;
    cout << "time taken to multipy the two numbers with Booth's algorithm is " << duration.count() << ".seconds" << endl;


    pair<binaryNumber,binaryNumber> d = nonResDiv(xx,yy);
    cout << "the division of the two numbers their quoient and remainder are as follows" <<endl;
    cout << "quotient:";
    printIt(d.second);
    cout << "equivalent in base 10 is " << BinToInt(d.second) << endl;

    // cout << "the division of the two numbers their quoient and remainder are as follows" <<endl;
    cout << "remainder:";
    printIt(d.first);
    cout << "equivalent in base 10 is " << BinToInt(d.first) << endl;
    


    


    return 0;
}
