/* =========================================================================
 * This file is part of NITRO
 * =========================================================================
 *
 * (C) Copyright 2004 - 2008, General Dynamics - Advanced Information Systems
 *
 * NITRO is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, If not,
 * see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __NITF_DEFINES_H__
#define __NITF_DEFINES_H__

/* The version of the NITF library */
#define NITF_LIB_VERSION    "2.5"

#include "nrt/Defines.h"

#define NITF_C              NRT_C
#define NITF_GUARD          NRT_GUARD
#define NITF_ENDGUARD       NRT_ENDGUARD
#define NITF_BOOL           NRT_BOOL
#define NITFAPI             NRTAPI
#define NITFPROT            NRTPROT
#define NITF_ATO32          NRT_ATO32
#define NITF_ATOU32         NRT_ATOU32
#define NITF_ATOU32_BASE    NRT_ATOU32_BASE
#define NITF_ATO64          NRT_ATO64
#define NITF_SNPRINTF       NRT_SNPRINTF
#define NITF_VSNPRINTF      NRT_VSNPRINTF
#define NITF_CXX_GUARD      NRT_CXX_GUARD
#define NITF_CXX_ENDGUARD   NRT_CXX_ENDGUARD
#define NITFPRIV            NRTPRIV
#define NITF_FILE           NRT_FILE
#define NITF_LINE           NRT_LINE
#define NITF_FUNC           NRT_FUNC


/**
 * Macro which declares a TRE Plugin
 *
 * This assumes that the variable 'descriptions' is an accessible
 * nitf_TRE_DescriptionSet
 *
 * _Tre the name of the input TRE
 */
#define NITF_DECLARE_PLUGIN(_Tre) \
    static char *ident[] = { \
        NITF_PLUGIN_TRE_KEY, \
        #_Tre, \
        NULL \
    }; \
    static nitf_TREHandler _Tre##Handler; \
    NITFAPI(char**) _Tre##_init(nitf_Error* error){ \
       if (!nitf_TREUtils_createBasicHandler(&descriptionSet,\
                                        &_Tre##Handler,error)) \
       return NULL; return ident; \
    } \
    NITFAPI(nitf_TREHandler*) _Tre##_handler(nitf_Error* error) { \
        return &_Tre##Handler; \
    }

/**
 * Declare a TRE Plugin with a single TREDescription
 *
 * _Tre the name of the input TRE
 * _Description the description to use
 */
#define NITF_DECLARE_SINGLE_PLUGIN(_Tre, _Description) \
    static nitf_TREDescriptionInfo descriptions[] = { \
        { #_Tre, _Description, NITF_TRE_DESC_NO_LENGTH }, \
        { NULL, NULL, NITF_TRE_DESC_NO_LENGTH } \
    }; \
    static nitf_TREDescriptionSet descriptionSet = { 0, descriptions }; \
    NITF_DECLARE_PLUGIN(_Tre)

/**
 * Reference a TRE that has been statically compiled inside of a library
 *
 */

#ifdef __cplusplus
#define NITF_TRE_STATIC_HANDLER_REF(_Tre) \
        extern "C" char** _Tre##_init(nitf_Error*); \
        extern "C" nitf_TREHandler* _Tre##_handler(nitf_Error*);
#else
#define NITF_TRE_STATIC_HANDLER_REF(_Tre) \
        extern char** _Tre##_init(nitf_Error*); \
        extern nitf_TREHandler* _Tre##_handler(nitf_Error*);
#endif


#endif
