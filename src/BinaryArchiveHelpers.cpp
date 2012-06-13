// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// binary_archive_helpers.cpp

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

#include <StdAfx.h>
#include <cassert>                                // for assert
#include <boost/detail/endian.hpp>              // for endianness

#include "s11n/BinaryArchiveHelpers.hpp"

namespace s11n {
namespace ba_helpers {

// Encode the number:
//  [-16 : 15]       => 000XXXXXb
//  [-2^07 : 2^07-1] => 00100000b XXh
//  [-2^15 : 2^15-1] => 00100001b XXh XXh
//  [-2^31 : 2^31-1] => 00100010b XXh XXh XXh XXh
//  [-2^63 : 2^63-1] => 00100011b XXh XXh XXh XXh XXh XXh XXh XXh
//  [ 2^63 : 2^64-1] => 00100100b XXh XXh XXh XXh XXh XXh XXh XXh
std::size_t EncodeNumber(s11n::intmax_t const i, unsigned char* output)
{
    //@todo extract this into a separate function and
    // pass the command byte as a parameter to be able to
    // handle lenghts specifiers of certain containers

    //@todo Check the endianness of the platform and
    // perform the conversion if needed

    std::size_t bytes = 1; // command byte is always there
    //if ((i >= -16) && (i <= 15)) {
    //    output[0] = static_cast<unsigned char>(i);
    //}
    //else if ((i >= -128) && (i <= 127)) {
    //    output[0] = 0;
    //    output[1] = static_cast<unsigned char>(i);
    //    bytes = 2;
    //}
    //else if ((i >= -32768) && (i <= 32767)) {
    // 
    //}

    return bytes;
}

} // namespace ba_helpers
} // namespace s11n

// EOF
