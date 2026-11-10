#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TESTING
#include "../Lab_08_1_char/Lab_08_1_char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81char
{
    TEST_CLASS(UnitTest81char)
    {
    public:

        TEST_METHOD(TestInclude)
        {
            char str1[] = "w_h_i_l_e";
            Assert::IsTrue(Include(str1));

            char str2[] = "world_hello";
            Assert::IsFalse(Include(str2)); // відсутня буква 'i'
        }

        TEST_METHOD(TestChange)
        {
            char str[101] = "abcwhilexyzwhile123";
            char* dest = Change(str);
            Assert::AreEqual("abc**xyz**123", str);
            Assert::AreEqual("abc**xyz**123", dest);
        }
    };
}