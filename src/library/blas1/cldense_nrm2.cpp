#include "include/clSPARSE-private.hpp"
#include "internal/kernel_cache.hpp"
#include "internal/kernel_wrap.hpp"

#include "atomic_reduce.hpp"

#include "reduce.hpp"

#include <algorithm>

clsparseStatus
cldenseSnrm2(clsparseScalar* s,
             const clsparseVector* x,
             const clsparseControl control)
{
    clsparseScalarPrivate* pS = static_cast<clsparseScalarPrivate*> ( s );
    const clsparseVectorPrivate* pX = static_cast<const clsparseVectorPrivate*> ( x );

    return reduce<cl_float, FLOAT, SQR, SQRT>(pS, pX, control);

}

clsparseStatus
cldenseDnrm2(clsparseScalar* s,
             const clsparseVector* x,
             const clsparseControl control)
{
    clsparseScalarPrivate* pS = static_cast<clsparseScalarPrivate*> ( s );
    const clsparseVectorPrivate* pX = static_cast<const clsparseVectorPrivate*> ( x );

    return reduce<cl_double, DOUBLE, SQR, SQRT>(pS, pX, control);
}