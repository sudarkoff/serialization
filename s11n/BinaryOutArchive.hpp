// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_BINARY_OARCHIVE_HPP
#define BITC_SERIALIZATION_BINARY_OARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// BinaryOutArchive.hpp: Bitcomber's binary output archive

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

#include <ostream>

#include <s11n/CStdTypes.hpp>
#include <s11n/BasicBinaryOutArchive.hpp>
#include <s11n/BasicBinaryOutPrimitive.hpp>

namespace s11n {

// Bitcomber's binary output archive implementation.

class BinaryOutArchive :
    private BasicBinaryOutPrimitive<std::ostream>,
    public BasicBinaryOutArchive<BinaryOutArchive>
{
public:
    BinaryOutArchive(std::ostream&);
    ~BinaryOutArchive() { }

protected:
    friend class BasicBinaryOutArchive;
    friend class BasicBinaryOutPrimitive;
    friend class detail::SaveAccess;

    void Init();

    // Use default saving of primitive types for everything
    // that is not defined below
    template<typename T>
    void Save(T const& t)
    {
        BasicBinaryOutPrimitive<std::ostream>::Save(t);
    }

    // Note that all overloads take their parameters 
    // by reference to const specialized type
    void Save(bool const&);
    void Save(int const&);
    void Save(unsigned int const&);
    void Save(int64_t const&);
    void Save(uint64_t const&);
    void Save(char const* const&);

};

} // namespace s11n

#endif // BITC_SERIALIZATION_BINARY_OARCHIVE_HPP
