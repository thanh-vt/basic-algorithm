#include <gtest/gtest.h>

extern "C" {
#include <common-matrix.h>
#include <counting.h>
}

namespace CountingModuleTest {
    std::string getFullPath(const std::string &fileName) {
        return "resources/counting_test_data/" + fileName;
    }
}