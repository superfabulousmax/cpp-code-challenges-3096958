#include "complex_num.h"

complex_num::complex_num(double r, double i){
    // Write your code here
    complex_num::a = r;
    complex_num::b = i;
}

    // z+w = (a+ib)+(c+id) = (a+c) + i(b+d)
complex_num complex_num::operator +(complex_num w){
    complex_num z;
    z.a = complex_num::a + w.a;
    z.b = complex_num::b + w.b;
    return z;
}
    // z-w = (a+ib)-(c+id) = (a-c) + i(b-d)
complex_num complex_num::operator -(complex_num w){
    complex_num z;
    z.a = complex_num::a - w.a;
    z.b = complex_num::b - w.b;
    return z;
}
    // z*w = (a+ib)*(c+id) = (ac-bd) + i(ad+bc)
complex_num complex_num::operator *(complex_num w){
    complex_num z;
    z.a = complex_num::a * w.a - complex_num::b * w.b;
    z.b = complex_num::a * w.b + complex_num::b * w.a;
    return z;
}

    // z/w = (a+ib)/(c+id) = ((ac+bd)/(c^2+d^2)) + i((bc-ad)/(c^2+d^2))
complex_num complex_num::operator /(complex_num w){
    complex_num z;
    auto denominator = (w.a * w.a) + (w.b * w.b);
    z.a = (complex_num::a * w.a + complex_num::b * w.b) / denominator;
    z.b = (complex_num::b * w.a - complex_num::a * w.b) / denominator;
    return z;
}

void complex_num::print(std::ostream &os){
    if (b >= 0)
    {
        os << complex_num::a << " + " << complex_num::b << "i";
    }
    else
    {
        os << complex_num::a << " - " << complex_num::b * -1 << "i";
    }

    os << std::flush;
}