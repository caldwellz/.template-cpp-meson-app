/***************************************************
* version.h: Product version / revision            *
* Copyright (C)                                    *
****************************************************
* This Source Code Form is subject to the terms of *
* the Mozilla Public License, v. 2.0. If a copy of *
* the MPL was not distributed with this file, You  *
* can obtain one at http://mozilla.org/MPL/2.0/.   *
***************************************************/

#ifndef _VERSION_H_
#define _VERSION_H_

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

extern const char* PUBLISHER_NAME;
extern const char* PRODUCT_NAME;
extern const char* PRODUCT_DESCRIPTION;
extern const char* PRODUCT_VERSION_STR;
extern const short PRODUCT_VERSION_MAJOR;
extern const short PRODUCT_VERSION_MINOR;
extern const short PRODUCT_VERSION_PATCH;
extern const short PRODUCT_VERSION_BUILD;
extern const char* PRODUCT_REVISION;
extern const char* PRODUCT_BUILD_TYPE;
extern const char* PRODUCT_COMPILER;
extern const char* PRODUCT_COMPILER_VERSION;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //_VERSION_H_
