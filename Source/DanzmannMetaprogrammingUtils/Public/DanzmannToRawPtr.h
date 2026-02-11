// Copyright (C) 2025 Vicente Danzmann. All Rights Reserved.

#pragma once

#include "DanzmannIsRawPtrDerivedFrom.h"
#include "DanzmannIsTSoftClassPtrDerivedFrom.h"
#include "DanzmannIsTSoftObjectPtrDerivedFrom.h"

namespace Danzmann
{
	/**
	 * Try to extract and return a raw pointer from T during compile-time. T is expected to already
	 * be a raw pointer (which would just return itself) or a TSoftObjectPtr/TSoftClassPtr
	 * @tparam T Parameter to extract raw pointer.
	 */
	template<typename T>
	constexpr UObject* ToRawPointer(const T Asset)
	{
		if constexpr (Danzmann::IsRawPtrDerivedFrom<T, UObject>())
		{
			return Asset;
		}
		else if constexpr (Danzmann::IsTSoftObjectPtrDerivedFrom<T, UObject>() || Danzmann::IsTSoftClassPtrDerivedFrom<T, UObject>())
		{
			return Asset.Get();
		}
		else
		{
			return nullptr;
		}
	}
};
