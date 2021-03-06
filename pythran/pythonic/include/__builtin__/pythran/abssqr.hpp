#ifndef PYTHONIC_INCLUDE_BUILTIN_PYTHRAN_ABSSQR_HPP
#define PYTHONIC_INCLUDE_BUILTIN_PYTHRAN_ABSSQR_HPP

#include "pythonic/include/utils/functor.hpp"
#include "pythonic/include/utils/meta.hpp"
#include "pythonic/include/utils/numpy_traits.hpp"
#include "pythonic/include/types/numpy_op_helper.hpp"

PYTHONIC_NS_BEGIN

namespace __builtin__
{

  namespace pythran
  {
    namespace details
    {

      template <class T>
      T abssqr(T const &v);

      template <class T>
      T abssqr(std::complex<T> const &v);

#ifdef USE_XSIMD
      template <class T, std::size_t N>
      auto abssqr(xsimd::batch<std::complex<T>, N> const &val)
          -> decltype(xsimd::abs(val *val))
      {
        return xsimd::abs(val * val);
      }
#endif
    }

#define NUMPY_NARY_FUNC_NAME abssqr
#define NUMPY_NARY_FUNC_SYM details::abssqr
#include "pythonic/include/types/numpy_nary_expr.hpp"
  }
}
PYTHONIC_NS_END

#endif
