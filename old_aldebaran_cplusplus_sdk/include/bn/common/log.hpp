/* -*- Mode: C++;  -*- */
/*
** Login : <ctaf@localhost.localdomain>
** Started on  Tue Sep 30 11:26:47 2008 Cedric GESTES
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2008 Aldebaran Robotics
*/

#ifndef   	LOG_H_
# define   	LOG_H_

//# include <bn/common.hpp>
# include <bn/common/types.hpp>
# include <map>
# include <string>
# include <cstdarg>
# include <bn/common/singleton.hpp>

namespace bn
{

  /**
   * logger class
   *
   * environment var:
   * DEBUG_INFO     : display information on file/function/line
   * DEBUG_VERBOSE  : choose the log level (0 = no log, 5 = full verbosity)
   * DEBUG_DETAIL   : choose verbosity for each category
   * DEBUG_COLOR    : set to 0 or 1 this enable color in the log output
   *
   * ex:
   * export DEBUG_INFO="1"
   * export DEBUG_VERBOSE="5"
   * export DEBUG_DETAIL="paths=5;main=3;"
   *
   * TODO:
   *  - asynchronous write (sync would be possible with DEBUG_SYNC)
   *  - signal when writing, with a default handler
   *
   *
   * TODO:
   *  - support syslog as a backend
   *
   *             LOG_EMERG      system is unusable
   *             LOG_ALERT      action must be taken immediately
   *  FATAL    : LOG_CRIT       critical conditions
   *  ERROR    : LOG_ERR        error conditions
   *  WARNING  : LOG_WARNING    warning conditions
   *  MESSAGE  : LOG_NOTICE     normal, but significant, condition
   *           : LOG_INFO       informational message
   *  DEBUG    : LOG_DEBUG      debug-level message
   */
  class Log
  {
  public:
    enum {
      BufferMaxSize = 512
    };
    typedef int (*printFunction)(const char *);
    Log();

    inline void setAsyncLog(bool async)
    {
      fAsync = async;
    }

    inline void setCallback(printFunction p)
    {
      fPrint = p;
    }

    inline void setGlobalVerbosity(uInt32 verb)
    {
      fGlobalVerbosity = verb;
    }

    inline void setLocalVerbosity(const std::string file, uInt32 verb)
    {
      fLogs[file] = verb;
    }

    inline sInt32 globalVerbosity()const { return fGlobalVerbosity; }

    void doLog(const Int8      *file,
               const Int8      *fct,
               const sInt32     line,
               const Int8      *cat,
               const sInt8      verb,
               const Int8      *fmt, ...)const;

    void vDoLog(const Int8      *file,
                const Int8      *fct,
                const sInt32     line,
                const Int8      *cat,
                const sInt8      verb,
                const Int8      *fmt, va_list ap)const;

  protected:
    void header(Int8          *&buffer,
                sInt32         &size,
                const Int8     *file,
                const Int8     *fct,
                const sInt32    line,
                const Int8     *cat,
                const sInt8     verb)const;
    void snprintf(Int8 *&buffer, sInt32 &size, const Int8 *fmt, ...)const;

    /**
     * convert verbose level to char*
     */
    const char * verboseToChar(char verbose)const;

    /**
     * parse DEBUG_DETAIL
     */
    void parseDetail(const std::string &detail);

  public:
    enum e_verbose {
      none              = 0,
      fatal,
      error,
      warning,
      message,
      debug
    };

    enum e_attr {
      reset             = 0,
      bright,
      dim,
      underline,
      blink,
      reverse		= 7,
      hidden
    };

    enum e_color {
      black             = 0,
      red,
      green,
      yellow,
      blue,
      magenta,
      cyan,
      white
    };

  protected:
    void textColor(Int8 *&buffer, sInt32 &size, Int8 fg, Int8 bg = -1, Int8 attr = -1)const;
    void textColorBG(Int8 *&buffer, sInt32 &size, Int8 bg)const;
    void textColorAttr(Int8 *&buffer, sInt32 &size, Int8 attr)const;

  protected:
    std::map<std::string, sInt32>       fLogs;
    sInt8                               fGlobalVerbosity;
    sInt8                               fGlobalInfo;
    printFunction                       fPrint;
    bool                                fAsync;
    bool                                fColor;
  };
};


#ifdef NO_DDEBUG
# define ddebug(cat, ...)
#else
# define ddebug(cat, ...)                                                                \
  bn::Singleton<bn::Log>()->doLog(__FILE__, __FUNCTION__, __LINE__, cat, bn::Log::debug, __VA_ARGS__)
#endif

#ifdef NO_DMESSAGE
# define dmessage(cat, ...)
#else
# define dmessage(cat, ...)                                                              \
  bn::Singleton<bn::Log>()->doLog(__FILE__, __FUNCTION__, __LINE__, cat, bn::Log::message, __VA_ARGS__)
#endif

#ifdef NO_DWARNING
# define dwarning(cat, ...)
#else
# define dwarning(cat, ...)                                                                \
  bn::Singleton<bn::Log>()->doLog(__FILE__, __FUNCTION__, __LINE__, cat, bn::Log::warning, __VA_ARGS__)
#endif

#ifdef NO_DERROR
# define derror(cat, ...)
#else
# define derror(cat, ...)                                                               \
  bn::Singleton<bn::Log>()->doLog(__FILE__, __FUNCTION__, __LINE__, cat, bn::Log::error, __VA_ARGS__)
#endif

#ifdef NO_FATAL
# define dfatal(cat, ...)
#else
# define dfatal(cat, ...)                                                                \
  bn::Singleton<bn::Log>()->doLog(__FILE__, __FUNCTION__, __LINE__, cat, bn::Log::fatal, __VA_ARGS__)
#endif

#endif 	    /* !LOG_H_ */
