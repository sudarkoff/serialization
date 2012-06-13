// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_BASIC_TEXT_OPRIMITIVE_HPP
#define BITC_SERIALIZATION_BASIC_TEXT_OPRIMITIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// BasicTextOPrimitive.hpp: 

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

namespace s11n {

template <typename OStream>
class BasicTextOutPrimitive
{
protected:
    BasicTextOutPrimitive(OStream& os) : m_os(os) {}
    ~BasicTextOutPrimitive() { m_os.flush(); }

    // default saving of primitives
    template<typename T>
    void Save(T const& t)
    {
        m_os << t;
    }

    void Save(float const t)
    {
        m_os << std::setprecision(std::numeric_limits<float>::digits10 + 2);
        m_os << t;
    }

    void Save(double const t)
    {
        m_os << std::setprecision(std::numeric_limits<double>::digits10 + 2);
        m_os << t;
    }

    void SaveBinary(void const*, std::size_t) {}

    OStream& m_os;

};

} // namespace s11n


#endif // BITC_SERIALIZATION_BASIC_TEXT_OPRIMITIVE_HPP
