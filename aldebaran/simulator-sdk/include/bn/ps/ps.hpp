//
// ps.hpp for libbn
//
// Made by Laurent Lec
// Login   <laurent@lse.epita.fr>
//
// Started on  Wed Dec 10 15:34:39 2008 Laurent Lec
// Last update Wed Dec 10 15:46:00 2008 Laurent Lec
//
#ifndef PSM_HPP_
# define PSM_HPP_

# include <fstream>
# include <iostream>
# include <pthread.h>
# include <boost/filesystem/operations.hpp>
# include <boost/filesystem/path.hpp>

# include "spawn.hpp"

# define PID_DIR "./pid"

class PSM
{
private:
  PSM();
  ~PSM();
  static PSM*	_instance;
  pthread_t	_pool;
public:
  pid_t		exec(char* const* args);
  void		kill(pid_t pid);
  void		purge();
  static PSM*	get();
};

#endif /* !PSM_HPP_ */
