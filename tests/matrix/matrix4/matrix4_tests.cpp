#include "gtest/gtest.h"
#include "matrix.h"

using namespace hm;

class Matrix4Fixture : public ::testing::Test {
protected:
    Mat4f m1;
    Mat4f m2;

    void SetUp() override
    {
        m1 = Mat4f{1, 2, 3, 4,
                   5, 6, 7, 8,
                   9, 10, 11, 12,
                   13, 14, 15, 16};

        m2 = Mat4f{16, 15, 14, 13,
                   12, 11, 10, 9,
                   8, 7, 6, 5,
                   4, 3, 2, 1};
    }

    void expect_matrixf_eq(const Mat4f &act, const Mat4f &exp)
    {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                EXPECT_FLOAT_EQ(act[i][j], exp[i][j]) << "Expectation indices:\n" << "row: " << i
                                                      << "\ncolumn: " << j << std::endl;
            }
        }
    }
};

TEST_F(Matrix4Fixture, test_translate_with_coordinate_param)
{
    m1.translate(1.0f, 1.0f, 1.0f);

    Mat4f exp = Mat4f{1.0f, 2.0f, 3.0f, 10.0f,
                      5.0f, 6.0f, 7.0f, 26.0f,
                      9.0f, 10.0f, 11.0f, 42.0f,
                      13.0f, 14.0f, 15.0f, 58.0f};

    expect_matrixf_eq(m1, exp);
}

TEST_F(Matrix4Fixture, test_translate_with_vector_param)
{
    m1.translate(Vec3f{1.0f, 1.0f, 1.0f});

    Mat4f exp = Mat4f{1.0f, 2.0f, 3.0f, 10.0f,
                      5.0f, 6.0f, 7.0f, 26.0f,
                      9.0f, 10.0f, 11.0f, 42.0f,
                      13.0f, 14.0f, 15.0f, 58.0f};

    expect_matrixf_eq(m1, exp);
}

TEST_F(Matrix4Fixture, test_translate_with_array_param)
{
    float arr[]{1.0f, 1.0f, 1.0};
    m1.translate(arr);

    Mat4f exp = Mat4f{1.0f, 2.0f, 3.0f, 10.0f,
                      5.0f, 6.0f, 7.0f, 26.0f,
                      9.0f, 10.0f, 11.0f, 42.0f,
                      13.0f, 14.0f, 15.0f, 58.0f};

    expect_matrixf_eq(m1, exp);
}

TEST_F(Matrix4Fixture, test_translated_with_coordinate_param)
{
    Mat4f res = m1.translated(1.0f, 1.0f, 1.0f);

    Mat4f exp = Mat4f{1.0f, 2.0f, 3.0f, 10.0f,
                      5.0f, 6.0f, 7.0f, 26.0f,
                      9.0f, 10.0f, 11.0f, 42.0f,
                      13.0f, 14.0f, 15.0f, 58.0f};

    expect_matrixf_eq(res, exp);
}

TEST_F(Matrix4Fixture, test_tranlated_with_vector_param)
{
    Mat4f res = m1.translated(Vec3f{1.0f, 1.0f, 1.0f});

    Mat4f exp = Mat4f{1.0f, 2.0f, 3.0f, 10.0f,
                      5.0f, 6.0f, 7.0f, 26.0f,
                      9.0f, 10.0f, 11.0f, 42.0f,
                      13.0f, 14.0f, 15.0f, 58.0f};

    expect_matrixf_eq(res, exp);
}

TEST_F(Matrix4Fixture, test_translated_with_array_param)
{
    float arr[]{1.0f, 1.0f, 1.0f};
    Mat4f res = m1.translated(arr);

    Mat4f exp = Mat4f{1.0f, 2.0f, 3.0f, 10.0f,
                      5.0f, 6.0f, 7.0f, 26.0f,
                      9.0f, 10.0f, 11.0f, 42.0f,
                      13.0f, 14.0f, 15.0f, 58.0f};

    expect_matrixf_eq(res, exp);
}

TEST_F(Matrix4Fixture, test_set_translation_with_coordinate_param)
{
    m1.set_translation(1.0f, 1.0f, 1.0f);

    Mat4f exp = Mat4f{1, 2, 3, 1,
                      5, 6, 7, 1,
                      9, 10, 11, 1,
                      13, 14, 15, 1};

    expect_matrixf_eq(m1, exp);
}

TEST_F(Matrix4Fixture, test_set_translation_with_vector_param)
{
    m1.set_translation(Vec3f{1.0f, 1.0f, 1.0f});

    Mat4f exp = Mat4f{1, 2, 3, 1,
                      5, 6, 7, 1,
                      9, 10, 11, 1,
                      13, 14, 15, 1};

    expect_matrixf_eq(m1, exp);
}

TEST_F(Matrix4Fixture, test_set_translation_with_array_param)
{
    float arr[]{1.0f, 1.0f, 1.0f};
    m1.set_translation(arr);

    Mat4f exp = Mat4f{1, 2, 3, 1,
                      5, 6, 7, 1,
                      9, 10, 11, 1,
                      13, 14, 15, 1};

    expect_matrixf_eq(m1, exp);
}

TEST_F(Matrix4Fixture, test_scale_with_coordinate_param)
{
    m1.scale(2.0f, 2.0f, 2.0f, 2.0f);

    Mat4f exp = Mat4f{2.0f, 4.0f, 6.0f, 8.0f,
                      10.0f, 12.0f, 14.0f, 16.0f,
                      18.0f, 20.0f, 22.0f, 24.0f,
                      26.0f, 28.0f, 30.0f, 32.0f};

    expect_matrixf_eq(m1, exp);
}

TEST_F(Matrix4Fixture, test_scale_with_vector_param)
{
    m1.scale(Vec4f{2.0f, 2.0f, 2.0f, 2.0f});

    Mat4f exp = Mat4f{2.0f, 4.0f, 6.0f, 8.0f,
                      10.0f, 12.0f, 14.0f, 16.0f,
                      18.0f, 20.0f, 22.0f, 24.0f,
                      26.0f, 28.0f, 30.0f, 32.0f};

    expect_matrixf_eq(m1, exp);
}

TEST_F(Matrix4Fixture, test_scale_with_array_param)
{
    float arr[]{2.0f, 2.0f, 2.0f, 2.0f};
    m1.scale(arr);

    Mat4f exp = Mat4f{2.0f, 4.0f, 6.0f, 8.0f,
                      10.0f, 12.0f, 14.0f, 16.0f,
                      18.0f, 20.0f, 22.0f, 24.0f,
                      26.0f, 28.0f, 30.0f, 32.0f};

    expect_matrixf_eq(m1, exp);
}

TEST_F(Matrix4Fixture, test_scaled_with_coordinate_param)
{
    Mat4f res = m1.scaled(2.0f, 2.0f, 2.0f, 2.0f);

    Mat4f exp = Mat4f{2.0f, 4.0f, 6.0f, 8.0f,
                      10.0f, 12.0f, 14.0f, 16.0f,
                      18.0f, 20.0f, 22.0f, 24.0f,
                      26.0f, 28.0f, 30.0f, 32.0f};

    expect_matrixf_eq(res, exp);
}

TEST_F(Matrix4Fixture, test_scaled_with_vector_param)
{
    Mat4f res = m1.scaled(Vec4f{2.0f, 2.0f, 2.0f, 2.0f});

    Mat4f exp = Mat4f{2.0f, 4.0f, 6.0f, 8.0f,
                      10.0f, 12.0f, 14.0f, 16.0f,
                      18.0f, 20.0f, 22.0f, 24.0f,
                      26.0f, 28.0f, 30.0f, 32.0f};

    expect_matrixf_eq(res, exp);
}

TEST_F(Matrix4Fixture, test_scaled_with_array_param)
{
    float arr[]{2.0f, 2.0f, 2.0f, 2.0f};
    Mat4f res = m1.scaled(arr);

    Mat4f exp = Mat4f{2.0f, 4.0f, 6.0f, 8.0f,
                      10.0f, 12.0f, 14.0f, 16.0f,
                      18.0f, 20.0f, 22.0f, 24.0f,
                      26.0f, 28.0f, 30.0f, 32.0f};

    expect_matrixf_eq(res, exp);
}

TEST_F(Matrix4Fixture, test_set_scaling_with_coordinate_params)
{
    m1.set_scaling(2.0f, 2.0f, 2.0f, 2.0f);

    Mat4f exp = Mat4f{2.0f, 2.0f, 3.0f, 4.0f,
                      5.0f, 2.0f, 7.0f, 8.0f,
                      9.0f, 10.0f, 2.0f, 12.0f,
                      13.0f, 14.0f, 15.0f, 2.0f};

    expect_matrixf_eq(m1, exp);
}

TEST_F(Matrix4Fixture, test_set_scaling_with_vector_param)
{
    m1.set_scaling(Vec4f{2.0f, 2.0f, 2.0f, 2.0f});

    Mat4f exp = Mat4f{2.0f, 2.0f, 3.0f, 4.0f,
                      5.0f, 2.0f, 7.0f, 8.0f,
                      9.0f, 10.0f, 2.0f, 12.0f,
                      13.0f, 14.0f, 15.0f, 2.0f};

    expect_matrixf_eq(m1, exp);
}

TEST_F(Matrix4Fixture, test_set_scaling_with_array_param)
{
    float arr[]{2.0f, 2.0f, 2.0f, 2.0f};
    m1.set_scaling(arr);

    Mat4f exp = Mat4f{2.0f, 2.0f, 3.0f, 4.0f,
                      5.0f, 2.0f, 7.0f, 8.0f,
                      9.0f, 10.0f, 2.0f, 12.0f,
                      13.0f, 14.0f, 15.0f, 2.0f};

    expect_matrixf_eq(m1, exp);
}

TEST_F(Matrix4Fixture, test_transpose)
{
    m1.transpose();

    Mat4f exp{1, 5, 9, 13,
              2, 6, 10, 14,
              3, 7, 11, 15,
              4, 8, 12, 16};

    expect_matrixf_eq(m1, exp);
}

TEST_F(Matrix4Fixture, test_transposed)
{
    Mat4f res{m1.transposed()};

    Mat4f exp{1, 5, 9, 13,
              2, 6, 10, 14,
              3, 7, 11, 15,
              4, 8, 12, 16};

    expect_matrixf_eq(res, exp);
}

TEST_F(Matrix4Fixture, test_operator_matrix_assignment_matrix4)
{
    Mat4f res;
    res = m1;

    expect_matrixf_eq(res, m1);
}

TEST_F(Matrix4Fixture, test_operator_matrix_assignment_matrix3)
{
    Mat3f m;

    m1 = m;

    Mat4f exp{1, 0, 0, 4,
              0, 1, 0, 8,
              0, 0, 1, 12,
              13, 14, 15, 16};

    expect_matrixf_eq(m1, exp);
}

TEST_F(Matrix4Fixture, test_operator_matrix_mult_matrix)
{
    Mat4f res{m1 * m2};

    Mat4f exp{80.0f, 70.0f, 60.0f, 50.0f,
              240.0f, 214.0f, 188.0f, 162.0f,
              400.0f, 358.0f, 316.0f, 274.0f,
              560.0f, 502.0f, 444.0f, 386.0f};

    expect_matrixf_eq(res, exp);
}

TEST_F(Matrix4Fixture, test_operator_matrix_equals_matrix)
{
    Mat4f mat;
    Mat4f exp;

    EXPECT_TRUE(mat == exp);
}

TEST_F(Matrix4Fixture, test_operator_matrix_not_equals_matrix)
{
    Mat4f mat;
    Mat4f exp;
    exp.set_row_vector({1, 2, 3, 4}, 0);

    EXPECT_TRUE(mat != exp);
}
