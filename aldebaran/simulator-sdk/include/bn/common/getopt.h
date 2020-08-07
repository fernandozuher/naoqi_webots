/*
** getopt.h
** Login : <ctaf@localhost.localdomain>
** Started on  Wed Dec 10 10:12:03 2008 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2008, 2011 Aldebaran Robotics
*/

#ifndef   	GETOPT_H_
# define   	GETOPT_H_


# ifdef WIN32
extern int      optind, opterr;
extern TCHAR    *optarg;

int getopt(int argc, TCHAR *argv[], TCHAR *optstring);

# else

# include <getopt.h>

# endif

#endif 	    /* !GETOPT_H_ */
