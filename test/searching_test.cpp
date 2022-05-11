#include <gtest/gtest.h>

extern "C" {
#include <common-matrix.h>
#include <searching.h>
}

namespace SearchingModuleTest {
    std::string getFullPath(const std::string &fileName) {
        return "resources/searching_test_data/" + fileName;
    }
}

