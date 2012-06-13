// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// binary_archive.cpp

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

#include <StdAfx.h>
#include <s11n/BinaryOutArchive.hpp>
#include <s11n/BinaryArchiveHelpers.hpp>

namespace s11n {

BinaryOutArchive::BinaryOutArchive(std::ostream& os) :
    BasicBinaryOutPrimitive<std::ostream>(os)
{
    Init();
}

void BinaryOutArchive::Init() throw( )
{
    unsigned char achive_sig[] = {0xf1, 0x22, 0xe1, 0x9d, 0x14, 0xb5, 0x24, 0xf5};
    SaveBinary(achive_sig, 8);
}

void BinaryOutArchive::Save(bool const& b)
{
    m_os << static_cast<unsigned char>(b);
}

void BinaryOutArchive::Save(int const& i)
{
    unsigned char output[sizeof(i) + 1];
    std::size_t bytes = ba_helpers::EncodeNumber(i, output);
    SaveBinary(output, bytes);
}

void BinaryOutArchive::Save(unsigned int const& i)
{
    unsigned char output[sizeof(i) + 1];
    std::size_t bytes = ba_helpers::EncodeNumber(i, output);
    SaveBinary(output, bytes);
}

void BinaryOutArchive::Save(int64_t const& i)
{
    unsigned char output[sizeof(i) + 1];
    std::size_t bytes = ba_helpers::EncodeNumber(i, output);
    SaveBinary(output, bytes);
}

void BinaryOutArchive::Save(uint64_t const& i)
{
    unsigned char output[sizeof(i) + 1];
    std::size_t bytes = ba_helpers::EncodeNumber(i, output);
    SaveBinary(output, bytes);
}

void BinaryOutArchive::Save(char const* const& s)
{
    // @todo encode the value
    const std::size_t len = std::ostream::traits_type::length(s);
    *this->This() << (int)len;
    SaveBinary(s, len);
}

} // namespace s11n

// EOF
