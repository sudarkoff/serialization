// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_AUTOPTR_HPP
#define BITC_SERIALIZATION_AUTOPTR_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// AutoPtr.hpp: serialize std::auto_ptr

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

#include <memory>
#include <s11n/Split.hpp>

namespace s11n {

template <typename Archive, typename T>
inline void Save(Archive& ar, std::auto_ptr<T> const& t)
{
    T const* const ptr = t.get();
    ar << ptr;
}

template <typename Archive, typename T>
inline void Load(Archive& ar, std::auto_ptr<T>& t)
{
    T* ptr;
    ar >> ptr;
    t.reset(ptr);
}

template <typename Archive, typename T>
inline void Serialize(Archive& ar, std::auto_ptr<T>& t)
{
    s11n::Split(ar, t);
}

} // namespace s11n


#endif // BITC_SERIALIZATION_AUTOPTR_HPP
