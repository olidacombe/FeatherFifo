#include <cstdint>

template <class T = uint8_t, uint8_t N = 16>
class FeatherFifo
{
private:
  T buffer[N];
  uint8_t size;
  uint8_t read_idx;
  uint8_t write_idx;
  void inc_idx(uint8_t &idx);

public:
  enum class Exceptions
  {
    POP_FROM_EMPTY
  };
  FeatherFifo() : size(0), read_idx(0), write_idx(0){};
  const bool empty();
  void push(const T);
  const T pop();
};