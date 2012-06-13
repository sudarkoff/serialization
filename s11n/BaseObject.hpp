// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_BASE_OBJ_HPP
#define BITC_SERIALIZATION_BASE_OBJ_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// base_object.hpp: Serialize base object

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

#include <boost/config.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/type_traits/is_const.hpp>

namespace s11n {

template<class Base, class Derived>
struct BaseCast
{
    typedef 
    // if (is_const(Derived))
        BOOST_DEDUCED_TYPENAME boost::mpl::if_<boost::is_const<Derived>, 
        // then
            const Base, 
        // else
            Base
        >::type type;
};

template<class Base, class Derived>
typename BaseCast<Base, Derived>::type& BaseObject(Derived &d)
{
    typedef BOOST_DEDUCED_TYPENAME BaseCast<Base, Derived>::type type;
    return static_cast<type&>(d);
}

} // namespace s11n


#endif // BITC_SERIALIZATION_BASE_OBJ_HPP
