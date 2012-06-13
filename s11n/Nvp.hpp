// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_NVP_HPP
#define BITC_SERIALIZATION_NVP_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// nvp.hpp: name-value pair

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

namespace s11n {

template <typename T>
struct Nvp : public std::pair<char const*, T*>
{
    explicit Nvp(char const* name, T const& t) : 
        std::pair<char const*, T*>(name, (T*)(&t))
    { }

    Nvp(Nvp const& rhs) : 
        std::pair<char const*, T*>(rhs.first, rhs.second)
    { }

    char const* Name() const
    {
        return this->first;
    }

    T& Value() const
    {
        return *(this->second);
    }

    // no return value based overloading
    T const& ConstValue() const
    {
        return *(this->second);
    }

};

template<typename T>
inline const Nvp<T> MakeNvp(char const* name, T const& t)
{
    return Nvp<T>(name, t);
}

#define TAG(name) s11n::MakeNvp(#name, name)

} // namespace s11n

#endif // BITC_SERIALIZATION_NVP_HPP
