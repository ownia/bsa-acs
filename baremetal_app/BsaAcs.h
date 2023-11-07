/** @file
 * Copyright (c) 2023, Arm Limited or its affiliates. All rights reserved.
 * SPDX-License-Identifier : Apache-2.0

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
**/

#ifndef __BSA_AVS_LEVEL_H__
#define __BSA_AVS_LEVEL_H__


#define SIZE_4K 0x100

#define BSA_ACS_MAJOR_VER      1
#define BSA_ACS_MINOR_VER      0
#define BSA_ACS_SUBMINOR_VER   6

#define INVALID_MPIDR     0xffffffff

#define STACK_SIZE          0x1000

#define VAL_TG0_4K  0x0
#define VAL_TG0_64K 0x1
#define VAL_TG0_16K 0x2
#define PAGE_SIZE_4K        0x1000
#define PAGE_SIZE_16K       (4 * 0x1000)
#define PAGE_SIZE_64K       (16 * 0x1000)
#define PAGE_BITS_4K        12
#define PAGE_BITS_16K       14
#define PAGE_BITS_64K       16

#define PLATFORM_CPU_COUNT PLATFORM_OVERRIDE_PE_CNT

#if (PLATFORM_PAGE_SIZE == PAGE_SIZE_4K)
 #define PAGE_ALIGNMENT      PAGE_SIZE_4K
 #define PAGE_SIZE           PAGE_SIZE_4K
 #define TCR_TG0             VAL_TG0_4K
#elif (PLATFORM_PAGE_SIZE == PAGE_SIZE_16K)
 #define PAGE_ALIGNMENT      PAGE_SIZE_16K
 #define PAGE_SIZE           PAGE_SIZE_16K
 #define TCR_TG0             VAL_TG0_16K
#elif (PLATFORM_PAGE_SIZE == PAGE_SIZE_64K)
 #define PAGE_ALIGNMENT      PAGE_SIZE_64K
 #define PAGE_SIZE           PAGE_SIZE_64K
 #define TCR_TG0             VAL_TG0_64K
#else
 #error "Undefined value for PLATFORM_PAGE_SIZE"
#endif

/*******************************************************************************
 * Used to align variables on the biggest cache line size in the platform.
 * This is known only to the platform as it might have a combination of
 * integrated and external caches.
 ******************************************************************************/
#define CACHE_WRITEBACK_SHIFT     6
#define CACHE_WRITEBACK_GRANULE   (1 << CACHE_WRITEBACK_SHIFT)

#ifdef _AARCH64_BUILD_
  unsigned long __stack_chk_guard = 0xBAAAAAAD;
  unsigned long __stack_chk_fail =  0xBAAFAAAD;
#endif

#define SCTLR_I_BIT         (1 << 12)
#define SCTLR_M_BIT         (1 << 0)
#define DISABLE_MMU_BIT     (0xFFFFFFFFFFFFFFFE)

#endif /* __BSA_AVS_LEVEL_H__ */
