#include <cxxtest/TestSuite.h>

#include <fstream>
#include <strstream>
#include <s11n/TextOutArchive.hpp>
#include <s11n/BinaryOutArchive.hpp>
#include <s11n/BaseObject.hpp>
#include <s11n/Nvp.hpp>

#include "test_derived.hpp"

class SerializationTestSuite : public CxxTest::TestSuite
{
public:
    static const long long integers[];

    void test_OutputPrimitives()
    {
        std::ofstream ofs("archive.bin");
        TS_ASSERT(ofs.is_open());
        // @todo Simulate single Serialize routine 
        // that performs both loading and saving
        // serializePrimitive(ofs)

        s11n::BinaryOutArchive ar(ofs);

        bool some_flag = false;
        TS_ASSERT_THROWS_NOTHING(ar & TAG(some_flag));
        bool some_other_flag = true;
        TS_ASSERT_THROWS_NOTHING(ar & TAG(some_other_flag));

        // serialize integers of different sizes
        TS_ASSERT_EQUALS(sizeof(long long), 8);
        
        for (std::size_t i = 0; integers[i] > 0; ++i) {
            TS_ASSERT_THROWS_NOTHING(ar & TAG( integers[i]));
            TS_ASSERT_THROWS_NOTHING(ar & TAG(-integers[i]));
        }

        unsigned long long longlong1 = 18446744073709551615;
        TS_ASSERT_THROWS_NOTHING(ar & TAG(longlong1));

        double float1 = 101.1;
        TS_ASSERT_THROWS_NOTHING(ar & TAG(float1));
        // single character, NOT a string
        char char1 = 'j';
        TS_ASSERT_THROWS_NOTHING(ar & TAG(char1));
        // this is a string, NOT an array
        char const* cstr1 = "test string";
        TS_ASSERT_THROWS_NOTHING(ar & TAG(cstr1));
        // this IS an array
        int some_nums[] = {2, 4, 8};
        TS_ASSERT_THROWS_NOTHING(ar & TAG(some_nums));
    }

    //void test_InputPrimitives()
    //{
    //    std::ifstream ifs("archive.bin");
    //    TS_ASSERT(ifs.is_open());
    //    s11n::binary_iarchive ar(ifs);
    //    @todo now read the archive and compare the results
    //}

    void test_DerivedClass()
    {
        std::ofstream ofs("archive.txt");
        TS_ASSERT(ofs.is_open());
        s11n::TextOutArchive ar(ofs);
        DerivedClass d;
        TS_ASSERT_THROWS_NOTHING(ar & TAG(d));
    }

};

const long long SerializationTestSuite::integers[] = 
    {15, 127, 32767, 2147483647, 9223372036854775807, -1};
