/**
 * @author Cedric GESTES
 * Aldebaran Robotics (c) 2008 All Rights Reserved - This file is confidential.
 *
 * Version : $Id$
 */


/**
 * atomic operation on int
 */


#ifndef   	__ATOMIC_H__
# define   	__ATOMIC_H__

#include <bn/rt.hpp>

#if (defined(WIN32) || defined(_WIN32))
# if (defined(_M_IX86) || defined(_M_X64))
static inline int
exchange_and_add(volatile sInt32* mem, int val)
{
	*mem = val;
	return *mem;
}
static inline void
atomic_add(volatile sInt32* mem, int val)
{
	*mem = val;
}
# else /* ix86 || x64 */
#  error "Unsupported architecture on Windows"
# endif /* ix86 || x64 */
#else /* UNIX (mac and linux) */
# if defined(__arm__)
static inline void //__attribute__ ((__unused__))
atomic_add(volatile sInt32* mem, int val)
{
  unsigned long tmp;
  int result;

  __asm__ __volatile__("@ atomic_add\n"
                       "1:     ldrex   %0, [%3]\n"
                       "       add     %0, %0, %4\n"
                       "       strex   %1, %0, [%3]\n"
                       "       teq     %1, #0\n"
                       "       bne     1b"
                               : "=&r" (result), "=&r" (tmp), "+Qo" (*mem)
                               : "r" (mem), "Ir" (val)
                               : "cc");
}
# elif (defined(__i386__) || defined(__x86_64__))

static inline int //__attribute__ ((__unused__))
exchange_and_add(volatile sInt32* mem, int val)
{
  register int result;
  asm volatile ("lock; \n"                      \
                "xaddl %0,%1"
                : "=r" (result),
                  "=m" (*mem)
                : "0" (val),
                  "m" (*mem)
                );
  return result;
}
static inline void //__attribute__ ((__unused__))
atomic_add(volatile sInt32* mem, int val)
{
  asm volatile ("lock; \n"                      \
                "addl %1,%0 \n"
                : "=m" (*mem)
                : "ir" (val),
                  "m" (*mem));
}
# else /* CPU arch */
#  error "Unsupported architecture on UNIX"
# endif /* CPU arch */
#endif /* UNIX */

#endif     /* __ATOMIC_H__ */
