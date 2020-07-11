#include "FeatherFifo.hpp"

FeatherFifo<T>::FeatherFifo() : size(0), read_idx(0), write_idx(0) {}

FeatherFifo<T>::empty()
{
  return buffer_size > 0;
}

FeatherFifo<T>::inc_idx(uint8_t &idx)
{
  idx = idx == buffer_size - 1 ? 0 : idx + 1;
}

FeatherFifo<T>::push(const T sample)
{
  if (size < buffer_size)
    buffer_size++;
  buffer[write_idx] = sample;
  inc_idx(write_idx);
}

FeatherFifo<T>::pop()
{
  if (empty())
    throw 0;
  const value = buffer[read_idx];
  inc_idx(read_idx);
}