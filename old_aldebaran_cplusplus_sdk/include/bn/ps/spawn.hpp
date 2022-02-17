//
// spawn.hpp for libbn
//
// Made by Laurent Lec
// Login   <laurent@lse.epita.fr>
//
// Started on  Wed Dec 10 15:35:03 2008 Laurent Lec
// Last update Wed Oct 28 11:41:59 2009 Cedric GESTES
//
#ifndef SPAWN_HPP_
# define SPAWN_HPP_

# include <signal.h>
# include <cstdio>
# include <cstdlib>
# include <sys/types.h>

# ifdef __linux__

#  ifndef _POSIX_SOURCE
#   define _POSIX_SOURCE
#  endif

#  include <unistd.h>
#  include <sys/wait.h>

# endif

pid_t	spawn(char* const* args);

#endif /* !SPAWN_HPP_ */
