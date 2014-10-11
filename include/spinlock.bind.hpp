/* This is an automatically generated bindings file. Don't modify it! */
#if !defined(BOOST_SPINLOCK_MAP_NAMESPACE_BEGIN) || !defined(BOOST_SPINLOCK_MAP_NAMESPACE_END)
#error You need to define BOOST_SPINLOCK_MAP_NAMESPACE_BEGIN and BOOST_SPINLOCK_MAP_NAMESPACE_END to use this header file
#endif
#include <spinlock.hpp>
BOOST_SPINLOCK_MAP_NAMESPACE_BEGIN
extern const char *boost_local_bind_in;
template<class Key, class T, class Hash, class Pred, class Alloc> using concurrent_unordered_map = boost::spinlock::v1::concurrent_unordered_map<Key, T, Hash, Pred, Alloc>;
using boost::spinlock::v1::is_lockable_locked;
template<class T, class , class , class > using spinlock = boost::spinlock::v1::spinlock<T, , , >;
using spins_to_sleep = boost::spinlock::v1::spins_to_sleep;
template<size_t _0> using spins_to_yield = boost::spinlock::v1::spins_to_yield<_0>;
template<size_t _0, bool _1> using spins_to_loop = boost::spinlock::v1::spins_to_loop<_0, _1>;
using null_spin_policy = boost::spinlock::v1::null_spin_policy;
template<class T> using spinlockbase = boost::spinlock::v1::spinlockbase<T>;
template<class T> using lockable_ptr = boost::spinlock::v1::lockable_ptr<T>;
BOOST_SPINLOCK_MAP_NAMESPACE_END
#undef BOOST_SPINLOCK_MAP_NAMESPACE_BEGIN
#undef BOOST_SPINLOCK_MAP_NAMESPACE_END
