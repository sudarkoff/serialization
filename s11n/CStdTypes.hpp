// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_CSTDTYPES_HPP
#define BITC_SERIALIZATION_CSTDTYPES_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// cstdtypes.hpp: primitive type definitions

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

namespace s11n {

//@todo add more platforms
#if defined(_MSC_VER)
    typedef __int64 int64_t;
    typedef unsigned __int64 uint64_t;
    typedef __int64 intmax_t;
    typedef unsigned __int64 uintmax_t;
#elif defined(__GNUC__)
    typedef long long int64_t;
    typedef unsigned long long uint64_t;
    typedef long long intmax_t;
    typedef unsigned long long uintmax_t;
#endif

} // namespace s11n


#endif // BITC_SERIALIZATION_CSTDTYPES_HPP
