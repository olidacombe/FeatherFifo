#pragma once

#include <cstdint>

template <class T = uint8_t, uint8_t N = 16>
class FeatherFifo
{
private:
  T buffer[N];
  uint8_t size;
  uint8_t read_idx;
  uint8_t write_idx;
  void inc_idx(uint8_t &idx)
  {
    idx = idx == N - 1 ? 0 : idx + 1;
  };

public:
  enum class Exceptions
  {
    POP_FROM_EMPTY
  };
  FeatherFifo() : size(0), read_idx(0), write_idx(0){};
  const bool empty()
  {
    return size == 0;
  };
  void push(const T sample)
  {
    if (size < N)
      size++;
    else
      inc_idx(read_idx);
    buffer[write_idx] = sample;
    inc_idx(write_idx);
  };
  const T pop()
  {
    if (empty())
      throw 0;
    const T value = buffer[read_idx];
    inc_idx(read_idx);
    size--;
    return value;
  };
};