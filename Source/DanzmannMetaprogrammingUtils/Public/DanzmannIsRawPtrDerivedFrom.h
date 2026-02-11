// Copyright (C) 2025 Vicente Danzmann. All Rights Reserved.

#pragma once

namespace Danzmann
{
	/**
	 * Verify if T is a raw pointer and if what it holds is derived from TBaseClass during compile-time.
	 * @tparam T The type to test, a raw pointer.
	 * @tparam TBaseClass The base class to check against.
	 * @return Whether T is a raw pointer derived from TBaseClass.
	 * @note Short-circuit behavior: verify if it's derived from TBaseClass only if it is a raw pointer first.
	 */
	template<typename T, typename TBaseClass>
	constexpr bool IsRawPtrDerivedFrom()
	{
		return TIsPointerOrObjectPtrToBaseOf<T, TBaseClass>::Value;
	}
}
