#include "FeatherFifo.hpp"
// #include <cstdint>

// template <class T, uint8_t N>
// FeatherFifo<T, N>::FeatherFifo() : size(0), read_idx(0), write_idx(0) {}

// template <class T>
// FeatherFifo<T>::empty()
// {
//   return buffer_size > 0;
// }

// template <class T>
// FeatherFifo<T>::inc_idx(uint8_t &idx)
// {
//   idx = idx == buffer_size - 1 ? 0 : idx + 1;
// }

// template <class T>
// FeatherFifo<T>::push(const T sample)
// {
//   if (size < buffer_size)
//     buffer_size++;
//   buffer[write_idx] = sample;
//   inc_idx(write_idx);
// }

// template <class T>
// FeatherFifo<T>::pop()
// {
//   if (empty())
//     throw 0;
//   const value = buffer[read_idx];
//   inc_idx(read_idx);
// }