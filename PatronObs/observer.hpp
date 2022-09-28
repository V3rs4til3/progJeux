#pragma once
/// @brief Observer class
/// @details Intervenants
template <typename T>
class Observer{
public:
    virtual void notification(T data) = 0;
};
