/* ----------------------------------------------------------------------
 * Project:      CMSIS DSP Library
 * Title:        arm_offset_f32.c
 * Description:  Floating-point vector offset
 *
 * $Date:        18. March 2019
 * $Revision:    V1.6.0
 *
 * Target Processor: Cortex-M cores
 * -------------------------------------------------------------------- */
/*
 * Copyright (C) 2010-2019 ARM Limited or its affiliates. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "arm_math.h"

/**
  @ingroup groupMath
 */

/**
  @defgroup BasicOffset Vector Offset

  Adds a constant offset to each element of a vector.

  <pre>
      pDst[n] = pSrc[n] + offset,   0 <= n < blockSize.
  </pre>

  The functions support in-place computation allowing the source and
  destination pointers to reference the same memory buffer.
  There are separate functions for floating-point, Q7, Q15, and Q31 data types.
 */

/**
  @addtogroup BasicOffset
  @{
 */

/**
  @brief         Adds a constant offset to a floating-point vector.
  @param[in]     pSrc       points to the input vector
  @param[in]     offset     is the offset to be added
  @param[out]    pDst       points to the output vector
  @param[in]     blockSize  number of samples in each vector
  @return        none
 */

void arm_offset_f32(const float32_t* pSrc, float32_t offset, float32_t* pDst, uint32_t blockSize)
{
    uint32_t blkCnt; /* Loop counter */

#if defined(ARM_MATH_NEON_EXPERIMENTAL)
    float32x4_t vec1;
    float32x4_t res;

    /* Compute 4 outputs at a time */
    blkCnt = blockSize >> 2U;

    while (blkCnt > 0U)
    {
        /* C = A + offset */

        /* Add offset and then store the results in the destination buffer. */
        vec1 = vld1q_f32(pSrc);
        res  = vaddq_f32(vec1, vdupq_n_f32(offset));
        vst1q_f32(pDst, res);

        /* Increment pointers */
        pSrc += 4;
        pDst += 4;

        /* Decrement the loop counter */
        blkCnt--;
    }

    /* Tail */
    blkCnt = blockSize & 0x3;

#else
#if defined(ARM_MATH_LOOPUNROLL)

    /* Loop unrolling: Compute 4 outputs at a time */
    blkCnt = blockSize >> 2U;

    while (blkCnt > 0U)
    {
        /* C = A + offset */

        /* Add offset and store result in destination buffer. */
        *pDst++ = (*pSrc++) + offset;

        *pDst++ = (*pSrc++) + offset;

        *pDst++ = (*pSrc++) + offset;

        *pDst++ = (*pSrc++) + offset;

        /* Decrement loop counter */
        blkCnt--;
    }

    /* Loop unrolling: Compute remaining outputs */
    blkCnt = blockSize % 0x4U;

#else

    /* Initialize blkCnt with number of samples */
    blkCnt = blockSize;

#endif /* #if defined (ARM_MATH_LOOPUNROLL) */
#endif /* #if defined(ARM_MATH_NEON_EXPERIMENTAL) */

    while (blkCnt > 0U)
    {
        /* C = A + offset */

        /* Add offset and store result in destination buffer. */
        *pDst++ = (*pSrc++) + offset;

        /* Decrement loop counter */
        blkCnt--;
    }
}

/**
  @} end of BasicOffset group
 */
