// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_ARCHIVE_EXCEPTION_HPP
#define BITC_SERIALIZATION_ARCHIVE_EXCEPTION_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// ArchiveException.hpp: exceptions thrown by archives

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

namespace s11n {

class ArchiveException : 
    public virtual std::exception
{
public:
    typedef enum {
        kNoException           // uninitialized exception
       ,kUnknownFormat         // archive format is unknown
       ,kStreamError           // i/o error on stream
    } ExceptionCode;

    ExceptionCode m_code;

    ArchiveException(ExceptionCode c) : 
        m_code(c)
    {}

    virtual const char* what( ) const throw( )
    {
        const char *msg = "programming error";
        switch(m_code){
        case kNoException:
            msg = "uninitialized exception";
            break;

        case kUnknownFormat:
            msg = "unknown archive format";
            break;

        case kStreamError:
            msg = "stream error";
            break;

        default:
            assert(false);
            break;
        }
        return msg;
    }
    
protected:
    ArchiveException() : 
         m_code(kNoException)
    {}
};
    
} // namespace s11n


#endif // BITC_SERIALIZATION_ARCHIVE_EXCEPTION_HPP
