// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_BASIC_BINARY_OARCHIVE_HPP
#define BITC_SERIALIZATION_BASIC_BINARY_OARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// BasicBinaryOutArchive.hpp: 

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

#include <s11n/BasicOutArchive.hpp>
#include <s11n/OutSerializer.hpp>
#include <s11n/Nvp.hpp>

namespace s11n {

// Archive-specific handling of types. Allows to:
// * Insert archive-specific handling of serialization (xml tags, etc.)
// * Provide special treatment of types (char* - C-string, NOT an array)
// * Re-route comlex types to s11n::OutSerializer or user-defined serializer
template<typename Archive>
class BasicBinaryOutArchive :
    public BasicOutArchive<Archive>
{
protected:
    friend class BasicOutArchive<Archive>;

    // Call serializer/user-defined function for types not handled below.
    template <typename T>
    void SaveOverride(T const& t)
    {
        s11n::Save(*this->This(), t);
    }

    // Drop the name part of NVP and serialize only a value.
    template<typename T>
    void SaveOverride(Nvp<T> const& t)
    {
        *this->This() << t.Value();
    }

    // Override to avoid passing c-string through the serializer
    // as it is going to be treated as an array by default,
    // which is not what we want here.
    void SaveOverride(char const* str)
    {
        this->This()->Save(str);
    }

    BasicBinaryOutArchive() :
        BasicOutArchive<Archive>()
    {}
};

} // namespace s11n

#endif // BITC_SERIALIZATION_BASIC_BINARY_OARCHIVE_HPP
