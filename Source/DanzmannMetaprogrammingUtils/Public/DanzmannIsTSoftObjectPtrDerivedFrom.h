// Copyright (C) 2025 Dancing Man Games. All Rights Reserved.

#pragma once

#include "DanzmannIsTSoftObjectPtr.h"

namespace Danzmann
{
	/**
	 * Verify if T is a TSoftObjectPtr and if what it holds is derived from TBaseClass during compile-time.
	 * @tparam T The type to test, a TSoftObjectPtr<...>.
	 * @tparam TBaseClass The base class to check against.
	 * @return Whether T is a TSoftObjectPtr derived from TBaseClass.
	 * @note Short-circuit behavior: verify if it's derived from TBaseClass only if it is a TSoftObjectPtr first.
	 */
	template<typename T, typename TBaseClass>
	constexpr bool IsTSoftObjectPtrDerivedFrom()
	{
		if constexpr (TDanzmannIsTSoftObjectPtr<T>::Value)
		{
			return TIsDerivedFrom<typename T::ElementType, TBaseClass>::Value;
		}
		
		return false;
	}
}
