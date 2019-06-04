#include "testoes.h"
#include "testoes_save.h"
#include "m.h"
#include "rh.h"
#include "shownum.h"
#include "plb.h"


#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
