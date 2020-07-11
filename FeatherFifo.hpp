#define buffer_size 16

class FeatherFifo<T>
{
private:
  T buffer[buffer_size];
  uint8_t size;
  uint8_t read_idx;
  uint8_t write_idx;
  uint8_t inc_idx(uint8_t &idx);

public:
  FeatherFifo();
  const bool empty();
  void push(const T);
  const T pop();
};