/**
 * @author Julien SERRE
 * Aldebaran Robotics (c) 2007 All Rights Reserved - This file is confidential.
 *
 * Version : $Id$
 */

#ifndef __TYPES_H__
#define  __TYPES_H__

// standard type definitions
typedef unsigned long long      uInt64;
typedef signed long long        sInt64;
typedef signed long long        Int64;

#ifndef ALTYPES_DEFINED
#  define ALTYPES_DEFINED
typedef unsigned int            uInt32;
typedef signed int              sInt32;

typedef unsigned short          uInt16;
typedef signed short            sInt16;

typedef unsigned char           uInt8;
typedef signed char             sInt8;
#endif // ALTYPES_DEFINED

typedef signed int              Int32;
typedef signed short            Int16;
//char can be nor signed nor unsigned !!
//(compiler handle signed char and char differently)
//cause c string are char
typedef char                    Int8;



#endif

