// BeginLicense:
// Part of: cpde_syslibs - Cross Platform Development Environment, system libraries
// Copyright (C) 2017 Carsten Arnholm
// All rights reserved
//
// This file may be used under the terms of either the GNU General
// Public License version 2 or 3 (at your option) as published by the
// Free Software Foundation and appearing in the files LICENSE.GPL2
// and LICENSE.GPL3 included in the packaging of this file.
//
// This file is provided "AS IS" with NO WARRANTY OF ANY KIND,
// INCLUDING THE WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE.
// EndLicense:

#ifndef CE_ANGELSCRIPT_EX_CONFIG_H_INCLUDED
#define CE_ANGELSCRIPT_EX_CONFIG_H_INCLUDED

#ifdef _MSC_VER

   /// MSVC compiler

   #ifdef CE_ANGELSCRIPT_EX_IMPLEMENTATION
      #define CE_ANGELSCRIPT_EX_PUBLIC
      #define CE_ANGELSCRIPT_EX_EXTERN
   #else
      #define CE_ANGELSCRIPT_EX_PUBLIC
      #define CE_ANGELSCRIPT_EX_EXTERN
   #endif
   #define CE_ANGELSCRIPT_EX_PRIVATE

#elif __GNUC__

   /// gnu gcc

   #define CE_ANGELSCRIPT_EX_PUBLIC
   #define CE_ANGELSCRIPT_EX_PRIVATE
   #define CE_ANGELSCRIPT_EX_EXTERN

#else

  #error "Unknown compiler"

#endif


#endif // CE_ANGELSCRIPT_EX_CONFIG_H_INCLUDED

