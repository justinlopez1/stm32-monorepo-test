#include "ref.h"

void ref_negate_f32(float32_t* pSrc, float32_t* pDst, uint32_t blockSize)
{
    uint32_t i;

    for (i = 0; i < blockSize; i++)
    {
        pDst[i] = -pSrc[i];
    }
}

void ref_negate_q31(q31_t* pSrc, q31_t* pDst, uint32_t blockSize)
{
    uint32_t i;

    for (i = 0; i < blockSize; i++)
    {
        pDst[i] = -pSrc[i];
    }
}

void ref_negate_q15(q15_t* pSrc, q15_t* pDst, uint32_t blockSize)
{
    uint32_t i;

    for (i = 0; i < blockSize; i++)
    {
        pDst[i] = -pSrc[i];
    }
}

void ref_negate_q7(q7_t* pSrc, q7_t* pDst, uint32_t blockSize)
{
    uint32_t i;

    for (i = 0; i < blockSize; i++)
    {
        pDst[i] = -pSrc[i];
    }
}
