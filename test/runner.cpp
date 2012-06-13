/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>
#include <cxxtest/Win32Gui.h>

int main( int argc, char *argv[] ) {
 return CxxTest::GuiTuiRunner<CxxTest::Win32Gui, CxxTest::ErrorPrinter>( argc, argv ).run();
}
#include "c:/build/work/packages/serialization/main/test/test_primitive.cpp"

static SerializationTestSuite suite_SerializationTestSuite;

static CxxTest::List Tests_SerializationTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_SerializationTestSuite( "c:/build/work/packages/serialization/main/test/test_primitive.cpp", 12, "SerializationTestSuite", suite_SerializationTestSuite, Tests_SerializationTestSuite );

static class TestDescription_SerializationTestSuite_test_OutputPrimitives : public CxxTest::RealTestDescription {
public:
 TestDescription_SerializationTestSuite_test_OutputPrimitives() : CxxTest::RealTestDescription( Tests_SerializationTestSuite, suiteDescription_SerializationTestSuite, 17, "test_OutputPrimitives" ) {}
 void runTest() { suite_SerializationTestSuite.test_OutputPrimitives(); }
} testDescription_SerializationTestSuite_test_OutputPrimitives;

static class TestDescription_SerializationTestSuite_test_DerivedClass : public CxxTest::RealTestDescription {
public:
 TestDescription_SerializationTestSuite_test_DerivedClass() : CxxTest::RealTestDescription( Tests_SerializationTestSuite, suiteDescription_SerializationTestSuite, 64, "test_DerivedClass" ) {}
 void runTest() { suite_SerializationTestSuite.test_DerivedClass(); }
} testDescription_SerializationTestSuite_test_DerivedClass;

#include <cxxtest/Root.cpp>
