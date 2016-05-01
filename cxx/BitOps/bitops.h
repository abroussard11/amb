/**
 * BitOps/bitops.h
 */

#ifndef BITOPS_BITOPS_H_
#define BITOPS_BITOPS_H_

#include <type_traits>

namespace BitOps {

// Helper templates

// if_integral
template <class T>
class if_integral
    : public std::enable_if<std::is_integral<T>::value, int> {};

template <class T>
using if_integral_t = typename if_integral<T>::type;

// if_not_integral
template <class T>
class if_not_integral
    : public std::enable_if<!std::is_integral<T>::value, int> {};

template <class T>
using if_not_integral_t = typename if_not_integral<T>::type;


} // End namespace BitOps

#endif // BITOPS_BITOPS_H_
