//
// globals.cpp
//
// Copyright (c) 2003-2010 Michael F. Henry
//
// mfh 10/2010
//

#include "stdafx.h"
#include "globals.h"

#include "orbitTools/SysDefine.h"


namespace Zeptomoby 
{
namespace OrbitTools
{
//////////////////////////////////////////////////////////////////////////////
double sqr(const double x) 
{
#if ENABLE_QD_INTEGRATION
   return ::sqr(x);
#else
   return (x * x);
#endif
}

//////////////////////////////////////////////////////////////////////////////
double Fmod2p(const double arg)
{
   double modu = std::fmod(arg, TWOPI);

   if (modu < 0.0)
   {
      modu += TWOPI;
   }

   return modu;
}

//////////////////////////////////////////////////////////////////////////////
// AcTan()
// ArcTangent of sin(x) / cos(x). The advantage of this function over arctan()
// is that it returns the correct quadrant of the angle.
double AcTan(const double sinx, const double cosx)
{
   if (cosx == 0.0)
   {
      return (sinx > 0.0) ? (PI / 2.0) : (3.0 * PI / 2.0);
   }
   else
   {
      return (cosx > 0.0) ? (std::atan(sinx / cosx)) : (PI + std::atan(sinx / cosx));
   }
}

//////////////////////////////////////////////////////////////////////////////
double rad2deg(const double r)
{
   const double DEG_PER_RAD = 180.0 / PI;
   return r * DEG_PER_RAD;
}

//////////////////////////////////////////////////////////////////////////////
double deg2rad(const double d)
{
   const double RAD_PER_DEG = PI / 180.0;
   return d * RAD_PER_DEG;
}
}
}
