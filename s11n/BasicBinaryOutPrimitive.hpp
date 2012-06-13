// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_BASIC_BINARY_OPRIMITIVE_HPP
#define BITC_SERIALIZATION_BASIC_BINARY_OPRIMITIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// BasicBinaryOPrimitive.hpp: output primitives to a stream in a binary format

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

#include <cassert>            // for assert
#include <limits>             // for std::numeric_limits

namespace s11n {

// Archive specific default handling of primitive types.
// Working with the stream.
    
// Specialize it to use with CFile, for example.

template <typename OStream>
class BasicBinaryOutPrimitive
{
protected:
    BasicBinaryOutPrimitive(OStream& os) : m_os(os) {}
    ~BasicBinaryOutPrimitive() { m_os.flush(); }

    // default saving of primitives
    template <typename T>
    void Save(T const& t)
    {
        SaveBinary(&t, sizeof(T));
    }

    void SaveBinary(void const*, std::size_t);

    OStream& m_os;

};

template<typename OStream>
inline void BasicBinaryOutPrimitive<OStream>::SaveBinary(
    void const* address, std::size_t count
)
{
    // make sure we're not trying to save the whole world in one scoop
    assert(count <= static_cast<std::size_t>(
        (std::numeric_limits<std::streamsize>::max)()
    ));
    count = (count + sizeof(typename OStream::char_type) - 1) / 
        sizeof(typename OStream::char_type);
    m_os.write(static_cast<typename OStream::char_type const*>(address), 
        static_cast<std::streamsize>(count));
    assert(m_os.good());
}

} // namespace s11n

#endif // BITC_SERIALIZATION_BASIC_BINARY_OPRIMITIVE_HPP
