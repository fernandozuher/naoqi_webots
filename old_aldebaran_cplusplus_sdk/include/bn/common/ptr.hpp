/* -*- Mode: C++; -*- */
/**
* @author aldebaran-robotics
* Aldebaran Robotics (c) 2008 All Rights Reserved - This file is confidential.\n
*
*/

#ifndef PTR_HPP
#define PTR_HPP

#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

namespace bn
{
  // Ptr definition
  template <class T> class Ptr: public boost::shared_ptr<T>
  {
  public:
    template<class Y> explicit Ptr(Y* p): boost::shared_ptr<T>(p) {}

    template <class Y> Ptr(const boost::shared_ptr<Y>& p):
      boost::shared_ptr<T>(p) {}

    Ptr() : boost::shared_ptr<T>(){}
  };

  // WeakPtr definition
  template <class T> class WeakPtr: public boost::weak_ptr<T>
  {
  public:
    template<class Y> WeakPtr(Ptr<Y> const & p):
      boost::weak_ptr<T>(p) {}

    template<class Y> WeakPtr(boost::shared_ptr<Y> const & p):
      boost::weak_ptr<T>(p) {}

    template<class Y> WeakPtr(boost::weak_ptr<Y> const & p):
      boost::weak_ptr<T>(p) {}

    WeakPtr() : boost::weak_ptr<T>(){}

    Ptr<T> lock() const {return boost::weak_ptr<T>::lock();}
  };

  // add the typedef in your class for easier use
  template <class T> class AnyPtr : public boost::enable_shared_from_this<T>
  {
  public:
    bn::Ptr<T> getThis() {return boost::enable_shared_from_this<T>::shared_from_this();}
    bn::Ptr<const T> getThis() const {return boost::enable_shared_from_this<T>::shared_from_this();}

    //factory
    static Ptr<T> create() { return Ptr<T>(new T()); }
  };

  //basic factory constructor
  template <class T> class PtrFactory : public boost::enable_shared_from_this<T>
  {
  public:
    //factory
    static Ptr<T> create() { return Ptr<T>(new T()); }
  };

  /**
   *  generic ptr stream operator
   *  allow thing like:
   *    Ptr< std::cout > pcout;
   *    Ptr< std::string > pstring;
   *    pcout << pstring;
   */
  template <class S, class T>
  inline Ptr<S> operator<< (Ptr<S> stream, Ptr<T> p) { return stream << *p; }

  template <class S, class T>
  inline Ptr<S> operator>> (Ptr<S> stream, Ptr<T> p) { return stream << *p; }


  template<class T, class U> Ptr<T> static_ptr_cast(Ptr<U> const & r)
  {
    return boost::static_pointer_cast<T>(r);
  }

  template<class T, class U> Ptr<T> const_ptr_cast(Ptr<U> const & r)
  {
    return boost::const_pointer_cast<T>(r);
  }

  template<class T, class U> Ptr<T> dynamic_ptr_cast(Ptr<U> const & r)
  {
    return boost::dynamic_pointer_cast<T>(r);
  }
}
#endif
