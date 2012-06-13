// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
#ifndef BITC_SERIALIZATION_OSERIALIZER_HPP
#define BITC_SERIALIZATION_OSERIALIZER_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// oserializer.hpp: This is the brains of the serialization library.

// Copyright (c) 2006 by Bitcomber.com
// All Rights Reserved.

#include <boost/config.hpp>
#include <boost/type_traits/is_fundamental.hpp>
#include <boost/type_traits/is_enum.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

#include <s11n/Serialization.hpp>

namespace s11n {
namespace detail {

// both VC6 and VC7.1 do not support friend templates correctly
class SaveAccess {
public:
    template <typename Archive, typename T>
    static void Save(Archive& ar, T const& t)
    {
        ar.Save(t);
    }
};

template <typename Archive, typename T>
struct SaveNonPointerType
{
    struct SavePrimitive {
        static void Invoke(Archive& ar, T const& t)
        {
            SaveAccess::Save(ar, t);
        }
    };

    struct SaveNonPrimitive {
        static void Invoke(Archive& ar, T const& t)
        {
            s11n::SerializeAdl(ar, const_cast<T&>(t));
        }
    };

    typedef 
        // if (is_fundamental(T))
        BOOST_DEDUCED_TYPENAME boost::mpl::eval_if<
            boost::is_fundamental<T>,
            // then
                boost::mpl::identity<SavePrimitive>,
            // else
                boost::mpl::identity<SaveNonPrimitive>
        >::type typex;

    static void Invoke(Archive& ar, T const& t)
    {
        typex::Invoke(ar, t);
    }
};

template <typename Archive, typename TPtr>
struct SavePointerType
{
    template <typename T>
    struct NonPolymorphic
    {
    };

    // and now let's dance...
    template <typename T>
    struct Polymorphic
    {
    };

    //template <typename T>
    //static void Save(Archive& ar, T const& t, 
    //    PtrOutSerializer const* ps)
    //{
    //    typedef 
    //    // if (isPolymonphic(T))
    //        BOOST_DEDUCED_TYPENAME mpl::eval_if<
    //            BOOST_DEDUCED_TYPENAME s11n::TypeInfo<T>::type::isPolymorphic,
    //        // then Polymorphic::Save()
    //            mpl::identity<Polymorphic<T> >,
    //        // else NonPolymorphic::Save()
    //            mpl::identity<NonPolymorphic<T> >
    //        >::type typex;
    //    typex::Save(ar, const_cast<T&>(t), ps);
    //}

    static void Invoke(Archive& ar, TPtr const t)
    {
        //PtrOutSerializer const* ps = RegisterType(ar, *t);
        //if(t == NULL)
        //{
        //    // @todo Save null pointer
        //    throw std::runtime_error("saving null pointer is not implemented");
        //}
        //Save(ar, *t, ps);
        throw std::runtime_error("saving pointer type is not implementid");
    }
};

template <typename Archive, typename T>
struct SaveEnumType
{
    static void Invoke(Archive& ar, T const& t)
    {
        // convert enum to integers
        const int i = static_cast<int>(t);
        ar << s11n::MakeNvp(0, i);
    }
};

template <typename Archive, typename T>
struct SaveArrayType
{
    static void Invoke(Archive& ar, T const& t)
    {
        std::size_t count = sizeof(t) / (
            static_cast<const char*>(static_cast<const void*>(&t[1])) 
            - static_cast<const char*>(static_cast<const void*>(&t[0]))
        );
        //@todo What's the appropriate encoding for the array?
        ar << s11n::MakeNvp("count", count);
        for(std::size_t i = 0; i < count; ++i)
            ar << s11n::MakeNvp("item", t[i]);
    }
};

} // namespace detail

template <typename Archive, typename T>
inline void Save(Archive& ar, T const& t)
{
    // A huge compile-time switch that decides how to handle the type
    typedef 
    // if (is_pointer(T))
        BOOST_DEDUCED_TYPENAME boost::mpl::eval_if<boost::is_pointer<T>,
        // then typex = SavePointerType
            boost::mpl::identity<detail::SavePointerType<Archive, T> >,
        // else if (is_enum(T))
            BOOST_DEDUCED_TYPENAME boost::mpl::eval_if<boost::is_enum<T>,
            // then typex = SaveEnumType
                boost::mpl::identity<detail::SaveEnumType<Archive, T> >,
            // else if (is_array(T))
                BOOST_DEDUCED_TYPENAME boost::mpl::eval_if<boost::is_array<T>,
                // then typex = SaveArrayType
                    boost::mpl::identity<detail::SaveArrayType<Archive, T> >,
                // else typex = SaveNonPoiterType
                    boost::mpl::identity<detail::SaveNonPointerType<Archive, T> >
                >
            >
        >::type typex;

    typex::Invoke(ar, t);

    // @todo skip the remainder of the frame
}

} // namespace s11n

#endif // BITC_SERIALIZATION_OSERIALIZER_HPP
