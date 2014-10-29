/* This is an automatically generated bindings file. Don't modify it! */
#if !defined(BOOST_SPINLOCK_MAP_NAMESPACE_BEGIN) || !defined(BOOST_SPINLOCK_MAP_NAMESPACE_END)
#error You need to define BOOST_SPINLOCK_MAP_NAMESPACE_BEGIN and BOOST_SPINLOCK_MAP_NAMESPACE_END to use this header file
#endif
#include "spinlock.hpp"
BOOST_SPINLOCK_MAP_NAMESPACE_BEGIN
extern const char *boost_local_bind_in;
template<class Key, class T, class Hash, class Pred, class Alloc> using concurrent_unordered_map = boost::spinlock::v1_std::concurrent_unordered_map<Key, T, Hash, Pred, Alloc>;
using boost::spinlock::v1_std::is_lockable_locked;
using spins_to_sleep = boost::spinlock::v1_std::spins_to_sleep;
template<size_t _0> using spins_to_yield = boost::spinlock::v1_std::spins_to_yield<_0>;
template<size_t _0, bool _1=true> using spins_to_loop = boost::spinlock::v1_std::spins_to_loop<_0, _1>;
using null_spin_policy = boost::spinlock::v1_std::null_spin_policy;
template<class T> using spinlockbase = boost::spinlock::v1_std::spinlockbase<T>;
template<class T> using lockable_ptr = boost::spinlock::v1_std::lockable_ptr<T>;
template<typename T, template<class> class spinpolicy2=spins_to_loop<125>::policy, template<class> class spinpolicy3=spins_to_yield<250>::policy, template<class> class spinpolicy4=spins_to_sleep::policy> using spinlock = boost::spinlock::v1_std::spinlock<T, spinpolicy2, spinpolicy3, spinpolicy4>;
BOOST_SPINLOCK_MAP_NAMESPACE_END
#undef BOOST_SPINLOCK_MAP_NAMESPACE_BEGIN
#undef BOOST_SPINLOCK_MAP_NAMESPACE_END
