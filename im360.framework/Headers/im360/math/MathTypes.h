#ifndef _MathTypes_h_
#define _MathTypes_h_

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include "cml/cml.h"
#include "cml/mathlib/matrix_projection.h"
#include "cml/mathlib/matrix_translation.h"

#define I3d_Pi 3.1415926f
#define I3d_min(v1,v2)(v1<v2?v1:v2)
#define I3d_max(v1,v2)(v1>v2?v1:v2)
#define I3d_abs(v)(v<0?-v:v)
#define I3d_isNaN(v)(v!=v)

namespace im360 {
namespace math {

    typedef ::cml::matrix44f_c      matrix;
    typedef ::cml::vector2f         vec2;
    typedef ::cml::vector3f         vec3;
    typedef ::cml::quaternionf_p    quaternion;

}}
#endif
#endif
