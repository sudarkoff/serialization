// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_SPLIT_HPP
#define BITC_SERIALIZATION_SPLIT_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// Split.hpp: Split Serialize() into Load() and Save()

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

#include <boost/config.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

#include <s11n/serialization.hpp>

namespace s11n {

template <typename Archive, typename T>
struct Saver
{
    static void Invoke(Archive& ar, T const& t)
    {
        Save(ar, t, v);
    }
};

template <typename Archive, typename T>
struct Loader
{
    static void Invoke(Archive& ar, T& t)
    {
        Load(ar, t, v);
    }
};

template <typename Archive, typename T>
inline void Split(Archive& ar, T& t)
{
    typedef 
    // if (Archive::isSaving)
        BOOST_DEDUCED_TYPENAME mpl::eval_if<
            BOOST_DEDUCED_TYPENAME Archive::isSaving,
            // then typex = Saver
                mpl::identity<Saver<Archive, T> >, 
            // else typex = Loader
                mpl::identity<Loader<Archive, T> >
        >::type typex;

    typex::Invoke(ar, t);
}

} // namespace s11n


#endif // BITC_SERIALIZATION_SPLIT_HPP
