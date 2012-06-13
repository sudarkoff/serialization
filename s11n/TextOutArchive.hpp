// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_TEXT_OARCHIVE_HPP
#define BITC_SERIALIZATION_TEXT_OARCHIVE_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// TextOutArchive.hpp: Simple text output archive

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

#include <ostream>

#include <s11n/BasicTextOutArchive.hpp>
#include <s11n/BasicTextOutPrimitive.hpp>

namespace s11n {

class TextOutArchive :
    private BasicTextOutPrimitive<std::ostream>,
    public BasicTextOutArchive<TextOutArchive>
{
public:
    TextOutArchive(std::ostream& os) 
        : BasicTextOutPrimitive<std::ostream>(os)
    {}
    ~TextOutArchive() {}

protected:
    friend class BasicTextOutArchive;
    friend class BasicTextOutPrimitive;
    friend class detail::SaveAccess;

    void Init();

    template <typename T>
    void Save(T const& t)
    {
        BasicTextOutPrimitive<std::ostream>::Save(t);
    }

};

} // namespace s11n

#endif // BITC_SERIALIZATION_TEXT_OARCHIVE_HPP
