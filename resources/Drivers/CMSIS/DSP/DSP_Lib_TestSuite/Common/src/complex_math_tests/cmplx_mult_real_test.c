#include "arm_math.h" /* FUTs */
#include "arr_desc.h"
#include "complex_math_templates.h"
#include "complex_math_test_data.h"
#include "jtest.h"
#include "ref.h" /* Reference Functions */
#include "test_templates.h"
#include "type_abbrev.h"

#define JTEST_ARM_CMPLX_MULT_REAL_TEST(suffix, comparison_interface)                              \
    COMPLEX_MATH_DEFINE_TEST_TEMPLATE_BUF2_BLK(cmplx_mult_real, suffix, TYPE_FROM_ABBREV(suffix), \
                                               TYPE_FROM_ABBREV(suffix), comparison_interface)

JTEST_ARM_CMPLX_MULT_REAL_TEST(f32, COMPLEX_MATH_COMPARE_CMPLX_INTERFACE);
JTEST_ARM_CMPLX_MULT_REAL_TEST(q31, COMPLEX_MATH_SNR_COMPARE_CMPLX_INTERFACE);
JTEST_ARM_CMPLX_MULT_REAL_TEST(q15, COMPLEX_MATH_COMPARE_CMPLX_INTERFACE);

/*--------------------------------------------------------------------------------*/
/* Collect all tests in a group. */
/*--------------------------------------------------------------------------------*/

JTEST_DEFINE_GROUP(cmplx_mult_real_tests)
{
    JTEST_TEST_CALL(arm_cmplx_mult_real_f32_test);
    JTEST_TEST_CALL(arm_cmplx_mult_real_q31_test);
    JTEST_TEST_CALL(arm_cmplx_mult_real_q15_test);
}
