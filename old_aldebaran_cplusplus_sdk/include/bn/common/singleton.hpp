/* -*- Mode: C++; -*- */
/**
* @author aldebaran-robotics
* Aldebaran Robotics (c) 2007 All Rights Reserved - This file is confidential.\n
*
*/
#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <bn/common/ptr.hpp>

namespace bn
{

  /*
   * singleton class
   * to use:
   *   Singleton<Myclass> o;
   *   o->myfunction();
   *   o()->myfunction();
   * or
   *   Singleton<Myclass>()->myfunction();
   *
   */
  template <typename T>
  class Singleton
  {
  public:
    Singleton ()  {}
    ~Singleton () {}

  public:
    Ptr<T> get()
    {
      if (!_singleton)
        _singleton = Ptr<T>(new T);
      return _singleton;
    }

    void reset()
    {
      _singleton = Ptr<T>();
    }

    void set(Ptr<T> object)
    {
      _singleton = object;
    };

    Ptr<T> operator()()
    {
      if (!_singleton)
        _singleton = Ptr<T>(new T);
      return _singleton;
    };

    Ptr<T> operator->()
    {
      if (!_singleton)
        _singleton = Ptr<T>(new T);
      return _singleton;
    };

  private:
    static Ptr<T> _singleton;
  };


//   template <typename T>
//   class EnableSingletonFromThis
//   {
//   public:
//     friend class Singleton<T>;
//   };

//   template <typename T>
//   class RestrictToSingleton : public EnableSingletonFromThis<T>
//   {
//   protected:
//     RestrictToSingleton() {;}
//   };

}  //namespace bn

#ifndef INCLUDE_HXX_TEMPLATE
# define INCLUDE_HXX_TEMPLATE
#endif
#include "singleton.hxx"
#undef INCLUDE_HXX_TEMPLATE

#endif
