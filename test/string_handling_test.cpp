#include <gtest/gtest.h>

extern "C" {
#include <common-matrix.h>
#include <string_handling.h>
}

namespace StringHandlingModuleTest {
    std::string getFullPath(const std::string &fileName) {
        return "resources/string_handling_test_data/" + fileName;
    }
}

