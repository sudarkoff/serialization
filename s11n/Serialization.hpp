// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_HPP
#define BITC_SERIALIZATION_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// serialization.hpp: 

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

#include <s11n/Nvp.hpp>

namespace s11n {

// Default: call T::Serialize() routine
template <typename Archive, typename T>
inline void Serialize(Archive& ar, T& t)
{
    t.Serialize(ar);
}

// Choose the highest interface that might be specialized by the user.
// Argument-dependent lookup allows Serialize() overrides to be found 
// in one of the following places:
//   - same namespace as Archive
//   - same namespace as T
//   - s11n namespace
template<class Archive, class T>
inline void SerializeAdl(Archive& ar, T& t)
{
    Serialize(ar, t);
}

} // namespace s11n

#endif // BITC_SERIALIZATION_HPP
