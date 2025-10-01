// Copyright (C) 2025 Dancing Man Games. All Rights Reserved.

#pragma once

template<typename T> constexpr bool TDanzmannIsTSoftObjectPtr_V                                  = false;
template<typename T> constexpr bool TDanzmannIsTSoftObjectPtr_V<               TSoftObjectPtr<T>> = true;
template<typename T> constexpr bool TDanzmannIsTSoftObjectPtr_V<const          TSoftObjectPtr<T>> = true;
template<typename T> constexpr bool TDanzmannIsTSoftObjectPtr_V<      volatile TSoftObjectPtr<T>> = true;
template<typename T> constexpr bool TDanzmannIsTSoftObjectPtr_V<const volatile TSoftObjectPtr<T>> = true;

/**
 * Type trait to determine if T is of type TSoftObjectPtr during compile-time.
 * @tparam T Type to check if it is a TSoftObjectPtr.
 */
template<typename T>
struct TDanzmannIsTSoftObjectPtr
{
	static constexpr bool Value = TDanzmannIsTSoftObjectPtr_V<T>;
};
