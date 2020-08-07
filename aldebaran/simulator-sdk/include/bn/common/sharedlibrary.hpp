/* -*- Mode: C++;  -*- */
/**
* @author aldebaran-robotics
* Aldebaran Robotics (c) 2007 All Rights Reserved - This file is confidential.\n
*
* Version : $Id$
*/
#ifndef SHARED_LIBRARY
#define SHARED_LIBRARY

# include <string>
# include <bn/common.hpp>

# ifdef WIN32
#  include <windows.h>
# else
#  include <dlfcn.h>
# endif

namespace bn
{

/**
 * SharedLibrary manage dynamic load of library
 *
 */
  class SharedLibrary
  {
  public:

    static Ptr<SharedLibrary> create() { return Ptr<SharedLibrary>(new SharedLibrary()); }

    /**
     * load the library
     */
    sInt32 loadLibrary(std::string libraryName);

    /**
     * destructor
     */
    ~SharedLibrary(void);

    /**
     * getFunction
     * @param function name in library
     * @return pointer on function
     */
    void *getFunction(const char *pFunctionName);

  protected:
    /**
     * convert libraryname into filename
     */
    static void libNameToFileName(std::string &refLibraryName);

  private:
    void *handle;
  };
};

#endif
