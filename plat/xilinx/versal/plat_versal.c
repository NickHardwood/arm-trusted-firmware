/*
 * Copyright (c) 2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <platform.h>
#include "versal_private.h"

int plat_core_pos_by_mpidr(u_register_t mpidr)
{
	if (mpidr & MPIDR_CLUSTER_MASK)
		return -1;

	if ((mpidr & MPIDR_CPU_MASK) >= PLATFORM_CORE_COUNT)
		return -1;

	return versal_calc_core_pos(mpidr);
}