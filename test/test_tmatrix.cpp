#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> v(5);
    EXPECT_TRUE(m == v);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    TDynamicMatrix<int> m(5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            m[i][j] = i;
        }
    }
    TDynamicMatrix<int> v(5);
    v = m;
    m = m * 2;
    EXPECT_FALSE(m == v);
}

TEST(TDynamicMatrix, can_get_size)
{
    TDynamicMatrix<int> v(5);
    ASSERT_NO_THROW(v.getSize());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    TDynamicMatrix<int> v(5);
    ASSERT_NO_THROW(v[0][0] = 1);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    TDynamicMatrix<int> v(5);
    ASSERT_ANY_THROW(v[0][-1] = 1);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> v(5);
    ASSERT_ANY_THROW(v[0][6] = 1);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> v(5);
    ASSERT_NO_THROW(v = v);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> v(5);
    TDynamicMatrix<int> v1(5);
    ASSERT_NO_THROW(v1 = v);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicMatrix<int> v(5);
    TDynamicMatrix<int> v1(4);
    v1 = v;
    EXPECT_EQ(5, v1.getSize());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int> v(5);
    TDynamicMatrix<int> v1(4);
    ASSERT_NO_THROW(v1 = v);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> v(5);
    TDynamicMatrix<int> v1(5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            v[i][j] = j;
        }
    }
    v1 = v;
    EXPECT_TRUE(v1 == v);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> v(5);
    EXPECT_TRUE(v == v);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> v(5);
    TDynamicMatrix<int> v1(4);
    ASSERT_ANY_THROW(v1 == v);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int> v(5);
    TDynamicMatrix<int> v1(5);
    ASSERT_NO_THROW(v1 + v);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> v(5);
    TDynamicMatrix<int> v1(4);
    ASSERT_ANY_THROW(v1 + v);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> v(5);
    TDynamicMatrix<int> v1(5);
    ASSERT_NO_THROW(v1 - v);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> v(5);
    TDynamicMatrix<int> v1(4);
    ASSERT_ANY_THROW(v1 - v);
}

