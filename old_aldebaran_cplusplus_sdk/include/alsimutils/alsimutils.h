/**
* Copyright (c) 2012 Aldebaran Robotics  All Rights Reserved
*/

#ifndef ALSIMUTILS_H
#define ALSIMUTILS_H

#include <qi/macro.hpp>

#ifdef alsimutils_EXPORTS
# define ALSIMUTILS_API QI_EXPORT_API
#elif defined(alsimutils_IMPORTS)
# define ALSIMUTILS_API QI_IMPORT_API
#else
# define ALSIMUTILS_API
#endif


#endif // ALSIMUTILS_H
