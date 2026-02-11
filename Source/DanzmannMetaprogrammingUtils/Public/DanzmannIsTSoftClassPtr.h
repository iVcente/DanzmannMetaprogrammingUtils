// Copyright (C) 2025 Vicente Danzmann. All Rights Reserved.

#pragma once

template<typename T> constexpr bool TDanzmannIsTSoftClassPtr_V                                  = false;
template<typename T> constexpr bool TDanzmannIsTSoftClassPtr_V<               TSoftClassPtr<T>> = true;
template<typename T> constexpr bool TDanzmannIsTSoftClassPtr_V<const          TSoftClassPtr<T>> = true;
template<typename T> constexpr bool TDanzmannIsTSoftClassPtr_V<      volatile TSoftClassPtr<T>> = true;
template<typename T> constexpr bool TDanzmannIsTSoftClassPtr_V<const volatile TSoftClassPtr<T>> = true;

/**
 * Type trait to determine if T is of type TSoftClassPtr during compile-time.
 * @tparam T Parameter to check if it is of type TSoftClassPtr.
 */
template<typename T>
struct TDanzmannIsTSoftClassPtr
{
	static constexpr bool Value = TDanzmannIsTSoftClassPtr_V<T>;
};
