/*
** shmtypes.hpp
** Login : <ctaf42@speed-core>
** Started on  Sun Mar 29 19:45:35 2009 Cedric GESTES
** $Id$
**
** Author(s):
**  - Cedric GESTES <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2009 Aldebaran Robotics
*/

#ifndef   	SHMTYPES_HPP_
# define   	SHMTYPES_HPP_

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/map.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
// #include <boost/unordered_map.hpp>
#include <boost/functional/hash.hpp>
#include <functional>
#include <utility>

namespace bn {
  namespace ipc {

    namespace bip = boost::interprocess;

/*
 * Shared Memory Allocator
 */
    template <typename T>
    class ShmAllocator: public bip::allocator<T, bip::managed_shared_memory::segment_manager>  {
    public:
      ShmAllocator(bip::managed_shared_memory::segment_manager* _seg)
        : bip::allocator<T, bip::managed_shared_memory::segment_manager>(_seg)
      {;}
    };


/*
 * Shared Memory Vector
 */
    template <typename T>
    class ShmVector : public bip::vector<T, ShmAllocator<T> > {
    public:
      ShmVector(const ShmAllocator<T>& _all): bip::vector<T, ShmAllocator<T> >(_all) {;}
    };

/*
 * Shared Memory Map
 */
    template <typename K, typename T>
    class ShmMap: public bip::map<K, T, std::less<K>,  ShmAllocator<std::pair<const K, T> > >
    {
    protected:
      //typedef bip::allocator< std::pair<K, T> , bip::managed_shared_memory::segment_manager> MapAllocator;

    public:
      //ShmAllocator< std::pair<K, T> >
      ShmMap(const ShmAllocator< std::pair<const K, T> >& _all)
        : bip::map<K, T, std::less<K>, ShmAllocator< std::pair<const K, T> > >(std::less<K>(),_all)
      {
        ;
      }
    };

   /*
    * Shared Memory Map
    */
//     template <int size, typename K, typename T>
//     class ShmHashMap: public boost::unordered_map<K, T, boost::hash<K>, std::equal_to<K>,  ShmAllocator<std::pair<const K, T> > >
//     {
//     public:
//       ShmHashMap(ShmAllocator< std::pair<const K, T> >& _all)
//         : boost::unordered_map<K,
//                                T,
//                                boost::hash<K>,
//                                std::equal_to<K>,
//                                ShmAllocator< std::pair<const K, T> >
//                                > (size, boost::hash<K>(), std::equal_to<K>(), _all)
//       {
//         ;
//       }
//     };



/*
 * Shared Memory String
 */
//     template <typename T>
//     class ShmBasicString : public bip::basic_string<T, std::char_traits<T>, ShmAllocator<T> > {
//     public:
//       ShmBasicString(ShmAllocator<T>& _all)
//         : bip::basic_string<T, std::char_traits<T>, ShmAllocator<T> >(_all)
//       {
//         ;
//       }
//     };
//     typedef ShmBasicString<char> ShmString;
    typedef bip::basic_string<char, std::char_traits<char>, ShmAllocator<char> >  ShmString;

  }
}


#endif	    /* !SHMTYPES_PP_ */
