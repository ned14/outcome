/* This is an automatically generated bindings file. Don't modify it! */
#if !defined(BOOST_SPINLOCK_MAP_NAMESPACE_BEGIN) || !defined(BOOST_SPINLOCK_MAP_NAMESPACE_END)
#error You need to define BOOST_SPINLOCK_MAP_NAMESPACE_BEGIN and BOOST_SPINLOCK_MAP_NAMESPACE_END to use this header file
#endif
#include "spinlock.hpp"
BOOST_SPINLOCK_MAP_NAMESPACE_BEGIN
extern const char *boost_local_bind_in;
template<class Key, class T, class Hash, class Pred, class Alloc> using concurrent_unordered_map = BOOST_SPINLOCK_V1_NAMESPACE::concurrent_unordered_map<Key, T, Hash, Pred, Alloc>;
using BOOST_SPINLOCK_V1_NAMESPACE::is_lockable_locked;
using spins_to_sleep = BOOST_SPINLOCK_V1_NAMESPACE::spins_to_sleep;
template<size_t _0> using spins_to_yield = BOOST_SPINLOCK_V1_NAMESPACE::spins_to_yield<_0>;
template<size_t _0, bool _1=true> using spins_to_loop = BOOST_SPINLOCK_V1_NAMESPACE::spins_to_loop<_0, _1>;
using null_spin_policy = BOOST_SPINLOCK_V1_NAMESPACE::null_spin_policy;
template<class T> using spinlockbase = BOOST_SPINLOCK_V1_NAMESPACE::spinlockbase<T>;
template<class T> using lockable_ptr = BOOST_SPINLOCK_V1_NAMESPACE::lockable_ptr<T>;
template<typename T, template<class> class spinpolicy2=spins_to_loop<125>::policy, template<class> class spinpolicy3=spins_to_yield<250>::policy, template<class> class spinpolicy4=spins_to_sleep::policy> using spinlock = BOOST_SPINLOCK_V1_NAMESPACE::spinlock<T, spinpolicy2, spinpolicy3, spinpolicy4>;
BOOST_SPINLOCK_MAP_NAMESPACE_END
#undef BOOST_SPINLOCK_MAP_NAMESPACE_BEGIN
#undef BOOST_SPINLOCK_MAP_NAMESPACE_END
