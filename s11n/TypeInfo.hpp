// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_TYPEINFO_HPP
#define BITC_SERIALIZATION_TYPEINFO_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// TypeInfo.hpp: type information to be saved along with an object

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

#include <boost/type_traits/is_polymorphic.hpp>
#include <boost/type_traits/is_const.hpp>

namespace s11n {

class TypeInfo
{
public:
    void Register();

    bool operator< (TypeInfo const& rhs) const;

    bool operator== (TypeInfo const& rhs) const
    {
        return (this == &rhs);
    }

    bool operator!= (TypeInfo const& rhs) const
    {
        return (this != &rhs);
    }

    static TypeInfo const* Find(TypeInfo const*);

protected:
    //static 

private:
    bool m_registered;

}

} // namespace s11n


#endif // BITC_SERIALIZATION_TYPEINFO_HPP
