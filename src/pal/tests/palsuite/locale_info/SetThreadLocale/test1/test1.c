//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information. 
//

/*============================================================================
**
** Source: test1.c
**
** Purpose: Tests SetThreadLocale with every valid locale to see that it passes
**          and that it actually sets the locale.
**
**
**==========================================================================*/

#include <palsuite.h>

int __cdecl main(int argc, char *argv[])
{
    int i;

 
    if (PAL_Initialize(argc, argv))
    {
        return FAIL;
    }

    /* Try all possible locale's */
    for (i=0; i<0x000fffff; i++)
    {
        if (!IsValidLocale(i, LCID_INSTALLED))
        {
            continue;
        }

        if (!SetThreadLocale(i))
        {
            Fail("SetThreadLocale failed for an installed locale!\n");
        }
        
        if (GetThreadLocale() != i)
        {
            Fail("SetThreadLocale didn't actually change to LCID %#x!\n", i);
        }
    }

    PAL_Terminate();

    return PASS;
}

