// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_BINARY_ARCHIVE_HELPERS_HPP
#define BITC_SERIALIZATION_BINARY_ARCHIVE_HELPERS_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// binary_archive_helpers.hpp: 

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

#include <cstddef>            // for std::size_t

#include <s11n/CStdTypes.hpp>

namespace s11n {
namespace ba_helpers {

    static const std::size_t max_bytes_per_num = sizeof(s11n::intmax_t);

    // bit-masks for extracting/applying command and subcommand bits
    static const unsigned char kCmdMask = 0xe0;
    static const unsigned char kSubMask = 0x1f;

    typedef enum {
        kCmdSmallNumber = 0x00
       ,kCmdNumber = 0x20
       ,kCmdSmallString = 0x40
       ,kCmdString = 0x60
    } CommandSignature;

    typedef enum {
        kSubcmdInt7 = 0x00
       ,kSubcmdInt15 = 0x01
       ,kSubcmdInt31 = 0x02
       ,kSubcmdInt63 = 0x03
       ,kSubcmdInt64 = 0x04
       ,kSubcmdFloat64 = 0x08
    } SubcommandSignature;

    // pre: caller allocates output buffer
    // return the number of bytes in the butput buffer
    std::size_t EncodeNumber(s11n::intmax_t const i, unsigned char* output);

} // namespace ba_helpers
} // namespace s11n

#endif // BITC_SERIALIZATION_BINARY_ARCHIVE_HELPERS_HPP
