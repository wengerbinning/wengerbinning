#ifndef _COMPLEX_H_
#define _COMPLEX_H_

class Complex {
    int re;
    int im;
  public:
    Complex() = default;
    Complex(int re,int im):re(re), im(im){};
    Complex(const &Complex complex);
    ~Complex();
}

inline
Complex::Complex(const &Complex complex):
re(complex.re), im(complex.im)
{
    // todo:     
}

#endif