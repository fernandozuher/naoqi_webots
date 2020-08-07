/*
** shmfactory.hxx
** Login : <ctaf@localhost.localdomain>
** Started on  Mon Mar 30 13:31:25 2009 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2009 Aldebaran Robotics
*/

//protect against bad #include
//this file should only be include by shmfactory.hpp
#ifdef INCLUDE_HXX_TEMPLATE

# ifndef   	SHMFACTORY_HXX_
#  define   	SHMFACTORY_HXX_


namespace bn {
  namespace ipc {

    template <typename T>
    void ShmFactory::create(const std::string& name)
    {
      DestructorMap::iterator i = fDestructors.find(name);

      if (i != fDestructors.end())
        throw MsgException("Trying to re-create an existing shared object '" + name + "'");
      fDestructors.insert(std::make_pair(name, new Destructor<T>(*this, name)));
      //T* p =
      //TODO: use find_or_construct?
      getSegment().template construct<T>(name.c_str())();
    }

    template <typename T>
    void ShmFactory::createAny(const std::string& name)
    {
      DestructorMap::iterator i = fDestructors.find(name);

      if (i != fDestructors.end())
        throw MsgException("Trying to re-create an existing shared object '" + name + "'");
      fDestructors.insert(make_pair(name, new Destructor<T>(*this, name)));
      // ShmAllocator<typename C::value_type> a = getAllocator<typename C::value_type>();
      // getSegment().template construct<C>(name.c_str())(a);
      //T* p =
      getSegment().template construct<T>(name.c_str())(getSegment().get_segment_manager());
    }

    template <typename C>
    void ShmFactory::createContainer(const std::string &name)
    {
      DestructorMap::iterator i = fDestructors.find(name);

      if (i != fDestructors.end())
        throw MsgException("Trying to re-create an existing shared object '" + name + "'");
      ShmAllocator<typename C::value_type> a = getAllocator<typename C::value_type>();
      //const void *ano = name;
      getSegment().template construct<C>(name.c_str())(a);
      DestructorSignature* d = new Destructor<C>(*this, name);
      fDestructors.insert(make_pair(name, d));
      //return c;
    }

    //!gets a reference to the shared object
    template <typename T>
    T& ShmFactory::get(const std::string& id)
    {
      std::pair<T*, std::size_t> res;
      res = this->getSegment().template find< T >(id.c_str());
      //std::cout << "res.second = " << res.second << std::endl;
      assert(res.second == 1);

      return *(res.first);
    }

//     template <typename T>
//     bip::managed_shared_ptr<T, bip::managed_shared_memory>::type ShmFactory::get(const std::string& id)
//     {
//       std::pair<T*, std::size_t> res;
//       res = this->getSegment().template find< T >(id.c_str());
//       //std::cout << "res.second = " << res.second << std::endl;
//       assert(res.second == 1);
//       bip::managed_shared_ptr<T, bip::managed_shared_memory>::type sh_ptr = res.first;
//       return sh_ptr;
//     }
// //    boost::interprocess::shared_ptr

    template <typename T>
    ShmAllocator<T> ShmFactory::getAllocator()
    {
      return ShmAllocator<T>(getSegment().get_segment_manager());
    }


    template <class T>
    ShmFactory::Destructor<T>::Destructor(ShmFactory& f, const std::string& name)
      : fFactory(f),
        fName(name)
    {
      ;
    }

    template <class T>
    ShmFactory::Destructor<T>::~Destructor()
    {
      fFactory.getSegment().template destroy<T>(fName.c_str());
    }

  }
}


# endif	    /* !SHMFACTORY_HXX_ */
#endif
