// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_BASIC_OARCHIVE_HPP
#define BITC_SERIALIZATION_BASIC_OARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// BasicOutArchive.hpp: basic output archive

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

#include <boost/mpl/bool.hpp>    // for isSaving

namespace s11n {

// Basic output archive interface.
template <typename Archive>
class BasicOutArchive
{
public:
    // e.g. to split Serialize() into Load() and Save() (see s11n/Split.hpp)
    typedef boost::mpl::bool_<true> isSaving;

    // return a pointer to the most derived class
    Archive* This()
    {
        return static_cast<Archive*>(this);
    }

    // the << operator, defined in terms of Archive implementation 
    template <typename T>
    Archive& operator<< (T const& t)
    {
        this->This()->SaveOverride(t);
        return *this->This();
    }
    
    // the & operator, defined in terms of << operator
    template <typename T>
    Archive& operator& (T const& t)
    {
        return *this->This() << t;
    }

    // for function-call style of invoking the serialization
    template <typename T>
    Archive& Process(T const& t)
    {
        return *this->This() << t;
    }

protected:
    BasicOutArchive() {}
    ~BasicOutArchive() {}

    void SaveStart(char const*) {}
    void SaveEnd(char const*) {}

};

} // namespace s11n

#endif // BITC_SERIALIZATION_BASIC_OARCHIVE_HPP
