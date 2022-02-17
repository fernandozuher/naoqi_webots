/*
** shmfactory.hpp
** Login : <ctaf42@speed-core>
** Started on  Sun Mar 29 19:37:06 2009 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2009 Aldebaran Robotics
*/

#ifndef   	SHMFACTORY_HPP_
# define   	SHMFACTORY_HPP_

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/smart_ptr/shared_ptr.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/smart_ptr/deleter.hpp>

namespace bn {
  namespace ipc {

    namespace bip = boost::interprocess;


    class ShmFactory
    {


    protected:
      /*
       * inner class to handle destruction properly
       */
      class DestructorSignature
      {
      public:
        virtual ~DestructorSignature() {;}
      };

      template <class T>
      class Destructor : public DestructorSignature
      {
      public:
        Destructor(ShmFactory& f, const std::string& name);
        ~Destructor();

      private:
        ShmFactory&     fFactory;
        std::string     fName;
      };

    protected:
      typedef std::map<std::string, DestructorSignature*>       DestructorMap;

    public:
      ShmFactory(const std::string& shName);
      ShmFactory(const std::string& shName, const std::size_t& size);
      ~ShmFactory();

      bip::managed_shared_memory& getSegment();

      /**
       * create an object of a POD type
       */
      template <typename T>
      void create(const std::string& name);

      /**
       * create an object of a POD type
       */
      template <typename T>
      void createAny(const std::string& name);

      /**
       * create a container object
       */
      template <typename C>
      void createContainer(const std::string &name);
      // = (const char *)bip::anonymous_instance);

      /**
       * create a new shm buffer
       */
      void *alloc(const std::size_t &size);

      /**
       * return an instance of an object
       */
      template <typename T>
      T& get(const std::string& id);

      // template <typename T>
      // bip::managed_shared_ptr<T, bip::managed_shared_memory> ShmFactory::get(const std::string& id);

    protected:
      /**
       * get an allocator for a container
       */
      template <typename T>
      ShmAllocator<T> getAllocator();


      bool isMySegment();
      void createSegment();
      void destroySegment();

    protected:
      std::string                       fName;
      std::size_t                       fSize;
      bool                              fIsMySegment;
      bip::managed_shared_memory*       fSegment;
      DestructorMap                     fDestructors;
    };

  }
}

#ifndef INCLUDE_HXX_TEMPLATE
# define INCLUDE_HXX_TEMPLATE
#endif
#include "shmfactory.hxx"
#undef INCLUDE_HXX_TEMPLATE

#endif	    /* !SHMFACTORY_HPP_ */
