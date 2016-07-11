#include "gtest/gtest.h"
#include "helmath.h"

TEST(Vec3_double_tests, test_length)
{
    hm::Vec3d v{10.677350318091823091823,
                20.277350318812388123222,
                30.977350318999999999999};

    double length = v.length();

    EXPECT_DOUBLE_EQ(length, 38.532752024130666);
}

TEST(Vec3_double_tests, test_normalize)
{
    hm::Vec3d v{30.0, 50.0, 100.0};

    v.normalize();

    double length = v.length();

    ASSERT_DOUBLE_EQ(length, 1.0);
}

TEST(Vec3_double_tests, test_operator_overload_vec_mult_scalar)
{
    hm::Vec3d v{2.0, 2.0, 2.0};

    hm::Vec3d res = v * 2.0;

    ASSERT_DOUBLE_EQ(res.x, 4.0);
    ASSERT_DOUBLE_EQ(res.y, 4.0);
    ASSERT_DOUBLE_EQ(res.z, 4.0);
}

TEST(Vec3_double_tests, test_operator_overload_scalar_mult_vec)
{
    hm::Vec3d v{2.0, 2.0, 2.0};

    hm::Vec3d res = 2.0 * v;

    ASSERT_DOUBLE_EQ(res.x, 4.0);
    ASSERT_DOUBLE_EQ(res.y, 4.0);
    ASSERT_DOUBLE_EQ(res.z, 4.0);
}