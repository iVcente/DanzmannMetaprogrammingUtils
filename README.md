# DanzmannMetaprogrammingUtils
A collection of useful type traits and `constexpr` functions for writing templates. They help on creating asserts that are validated at compile-time.

## Usage Example
Given the following function below with `T` as a templated parameter. Suppose that `T` should either be a raw pointer, `TSoftObjectPtr` or a `TSoftClassPtr` -- and a class derived from `UObject`. You can guarantee that the function is being called correctly by creating an assert and calling the respective `constexpr` functions. These functions use internally type traits in their implementations.

```cpp
template<typename T>
void MyFunction(const TArray<T>& MyArray)
{
    static_assert(
        Danzmann::IsRawPtrDerivedFrom<T, UObject>() ||
        Danzmann::IsTSoftObjectPtrDerivedFrom<T, UObject>() ||
        Danzmann::IsTSoftClassPtrDerivedFrom<T, UObject>(),
        "MyArray must be an array of raw pointer, TSoftObjectPtr or TSoftClassPtr derived from UObject."
    );

    // ...
}
```
