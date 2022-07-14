#include <gtest/gtest.h>

extern "C" {
#include <common_matrix.h>
#include <graph.h>
}

namespace GraphModuleTest {
    std::string getFullPath(const std::string &fileName) {
        return "resources/graph_test_data/" + fileName;
    }
}

TEST(GraphModuleTest, IsTournamentTest1) {
    using namespace std;
    string fileName = GraphModuleTest::getFullPath("is_tournament_test_1.txt");
    matrix_int *data = importIntMatrix(fileName.c_str());
    ASSERT_TRUE(isTournament(5, data->arr[0], data->arr[1]));
    freeIntMatrix(data);
}

TEST(GraphModuleTest, IsTournamentTest2) {
    using namespace std;
    string fileName = GraphModuleTest::getFullPath("is_tournament_test_2.txt");
    matrix_int *data = importIntMatrix(fileName.c_str());
    ASSERT_FALSE(isTournament(5, data->arr[0], data->arr[1]));
    freeIntMatrix(data);
}

TEST(GraphModuleTest, IsTournamentTest3) {
    using namespace std;
    string fileName = GraphModuleTest::getFullPath("is_tournament_test_3.txt");
    matrix_int *data = importIntMatrix(fileName.c_str());
    ASSERT_FALSE(isTournament(5, data->arr[0], data->arr[1]));
    freeIntMatrix(data);
}

TEST(GraphModuleTest, IsTournamentTest4) {
    using namespace std;
    string fileName = GraphModuleTest::getFullPath("is_tournament_test_4.txt");
    matrix_int *data = importIntMatrix(fileName.c_str());
    ASSERT_FALSE(isTournament(5, data->arr[0], data->arr[1]));
    freeIntMatrix(data);
}

TEST(GraphModuleTest, IsTournamentTest5) {
    using namespace std;
    string fileName = GraphModuleTest::getFullPath("is_tournament_test_5.txt");
    matrix_int *data = importIntMatrix(fileName.c_str());
    ASSERT_FALSE(isTournament(5, data->arr[0], data->arr[1]));
    freeIntMatrix(data);
}
