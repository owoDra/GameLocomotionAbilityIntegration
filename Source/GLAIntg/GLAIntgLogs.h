// Copyright (C) 2023 owoDra

#pragma once

#include "Logging/LogMacros.h"

GLAINTG_API DECLARE_LOG_CATEGORY_EXTERN(LogGLAI, Log, All);

#if !UE_BUILD_SHIPPING

#define GLAILOG(FormattedText, ...) UE_LOG(LogGLAI, Log, FormattedText, __VA_ARGS__)

#define GLAIENSURE(InExpression) ensure(InExpression)
#define GLAIENSURE_MSG(InExpression, InFormat, ...) ensureMsgf(InExpression, InFormat, __VA_ARGS__)
#define GLAIENSURE_ALWAYS_MSG(InExpression, InFormat, ...) ensureAlwaysMsgf(InExpression, InFormat, __VA_ARGS__)

#define GLAICHECK(InExpression) check(InExpression)
#define GLAICHECK_MSG(InExpression, InFormat, ...) checkf(InExpression, InFormat, __VA_ARGS__)

#else

#define GLAILOG(FormattedText, ...)

#define GLAIENSURE(InExpression) InExpression
#define GLAIENSURE_MSG(InExpression, InFormat, ...) InExpression
#define GLAIENSURE_ALWAYS_MSG(InExpression, InFormat, ...) InExpression

#define GLAICHECK(InExpression) InExpression
#define GLAICHECK_MSG(InExpression, InFormat, ...) InExpression

#endif