// Copyright (C) 2025 Vicente Danzmann. All Rights Reserved.

#pragma once

#include "DanzmannIsTSoftClassPtr.h"

namespace Danzmann
{
	/**
	 * Verify if T is a TSoftClassPtr and if what it holds is derived from TBaseClass during compile-time.
	 * @tparam T The type to test, a TSoftClassPtr<...>.
	 * @tparam TBaseClass The base class to check against.
	 * @return Whether T is a TSoftClassPtr derived from TBaseClass.
	 * @note Short-circuit behavior: verify if it's derived from TBaseClass only if it is a TSoftClassPtr first.
	 */
	template<typename T, typename TBaseClass>
	constexpr bool IsTSoftClassPtrDerivedFrom()
	{
		if constexpr (TDanzmannIsTSoftClassPtr<T>::Value)
		{
			return TIsDerivedFrom<typename T::ElementType, TBaseClass>::Value;
		}
		
		return false;
	}
}
