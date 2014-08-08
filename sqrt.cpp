#include <iostream>
#include <math.h>

int main() {
    double x;
    double min;
    double max;
    double med;
    double med2;

    x = 821103;
    //x = 8211033008671125504.797537487928582144;
    //x = 0.211033008671125504797537487928582144;

    max = x;
    int n;
    double a = frexp(x,&n);
    med = pow(2, n/2); 

    std::cout << a << " " << n << std::endl;
        
    std::bitset<64> d(x);
    std::cout << d << std::endl;

    long l;
    l = (long) x >>1;

    std::bitset<64> b(l);
    std::cout << b << std::endl;

    l = l <<53;
    l = l >>53;

    std::bitset<64> e(l);
    std::cout << e << std::endl;
    std::cout << l - 1023 << std::endl;

    // std::cout << d.parts.expoent - 1022 << std::endl;

    med2 = med * med;
/*
    int c = 0;
        std::cout << med << " " << med2 << " " << x << std::endl;
    while (c < 20 and fabs(x - med2) > 0.1) {
        c++;
        med = (med + x / med)/2;
        med2 = med * med;

        std::cout << med << " " << med2 << " " << x << std::endl;
    }
        std::cout << med << " " << med2 << " " << x << std::endl;
*/
    return 0;
}
