#ifndef PYTHONIC_INCLUDE_CMATH_E_HPP
#define PYTHONIC_INCLUDE_CMATH_E_HPP

#include "pythonic/utils/proxy.hpp"

#include <cmath>

namespace pythonic
{

  namespace cmath
  {
    double PYTHONIC_CONSTEXPR e = std::exp(1);
  }
}

#endif