// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_BASIC_TEXT_OARCHIVE_HPP
#define BITC_SERIALIZATION_BASIC_TEXT_OARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// BasicTextOutArchive.hpp: 

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

#include <s11n/BasicOutArchive.hpp>
#include <s11n/OutSerializer.hpp>
#include <s11n/Nvp.hpp>

namespace s11n {

template<typename Archive>
class BasicTextOutArchive :
    public BasicOutArchive<Archive>
{
protected:
    friend class BasicOutArchive<Archive>;

    unsigned int m_depth;

    // Call serializer/user-defined function for types not handled below.
    template <typename T>
    void SaveOverride(T const& t)
    {
        throw std::logic_error("Tag is missing!");
    }

    template<typename T>
    void SaveOverride(Nvp<T> const& t)
    {
        this->This()->SaveStart(t.Name());
        s11n::Save(*this->This(), t.ConstValue());
        this->This()->SaveEnd(t.Name());
    }

    void SaveStart(char const* name)
    {
        if (name == 0) return;
        if(m_depth > 0){
            this->This()->Save("\n");
            Indent();
        }
        ++m_depth;
        this->This()->Save("[");
        this->This()->Save(name);
        this->This()->Save("]:");
    }

    void SaveEnd(char const* name)
    {
        --m_depth;
    }

    void Indent()
    {
        for(std::size_t i = m_depth; i-- > 0;) {
            this->This()->Save("\t");
        }
    }

    BasicTextOutArchive() :
        BasicOutArchive<Archive>(),
        m_depth(0)
    {}
};

} // namespace s11n

#endif // BITC_SERIALIZATION_BASIC_TEXT_OARCHIVE_HPP
