// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_BASIC_IARCHIVE_HPP
#define BITC_SERIALIZATION_BASIC_IARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// BasicInArchive.hpp: basic input archive

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

namespace s11n {

// Basic input archive.

template <typename Archive>
class BasicInArchive
{
public:
    // return a pointer to the most derived class
    Archive* This() {
        return static_cast<Archive*>(this);
    }

    // the >> operator, calling the function from derived class
    template<typename T>
    Archive& operator>> (T& t) {
        this->This()->LoadOverride(t);
        return *this->This();
    }
    
    // the & operator, defined in terms of >> operator
    template<typename T>
    Archive& operator& (T& t) {
        return *this->This() >> t;
    }

    // for function-call style of invoking the serialization
    template <typename T>
    Archive& Process(T const& t)
    {
        return *this->This() >> t;
    }

protected:
    BasicInArchive() {}
    ~BasicInArchive() {}

};

} // namespace s11n

#endif // BITC_SERIALIZATION_BASIC_IARCHIVE_HPP
