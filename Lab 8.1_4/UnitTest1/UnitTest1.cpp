#include "pch.h"
#include "CppUnitTest.h"
#include <string>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int CountStr(const string s) {
    int k = 0;
    size_t pos = 0;
    while ((pos = s.find("while", pos)) != string::npos) {
        k++;
        pos += 5;
    }
    return k;
}

string ChangeStr(string& s) {
    size_t pos = 0;
    while ((pos = s.find("while", pos)) != string::npos) {
        s.replace(pos, 5, "***");
        pos += 3;
    }
    return s;
}

namespace UnitTestString {
    TEST_CLASS(StringStyleTests) {
public:
    TEST_METHOD(TestCount) {
        string s = "while test while";
        Assert::AreEqual(2, CountStr(s));
    }
    TEST_METHOD(TestChange) {
        string s = "one while two";
        string res = ChangeStr(s);
        Assert::AreEqual(string("one *** two"), res);
    }
    };
}