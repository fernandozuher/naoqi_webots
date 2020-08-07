/**
 * @author Cedric GESTES
 * Aldebaran Robotics (c) 2008 All Rights Reserved - This file is confidential.
 *
 * Version : $Id$
 */


/**
 * This file implement a real-time thread safe printf
 *
 * TODO:
 *  - display when overflow occur
 */
#ifndef __PRINTF_HPP__
#define __PRINTF_HPP__

# include <bn/rt.hpp>

namespace bn {
namespace rt {

void rtprintf(const char *fmt, ...);

}
}

#endif /* __RTPRINTF_H__ */
