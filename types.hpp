#ifndef TYPES_H
#define TYPES_H

#include <complex>


namespace input_braces{

  using Real = double;
  using Cplx = std::complex<double>;
  using Complex = std::complex<double>;

  const Cplx Complex_1 = Cplx(1,0);
  const Cplx Complex_i = Cplx(0,1);
  const Cplx Cplx_1 = Cplx(1,0);
  const Cplx Cplx_i = Cplx(0,1);
  
} //* namespace input_braces

#endif //* TYPES_H
