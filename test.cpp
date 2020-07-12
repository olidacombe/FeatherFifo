#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "FeatherFifo.hpp"

SCENARIO("FeatherFifo acts as a small fifo ring-buffer", "[fifo][ring buffer]")
{
  enum TSample
  {
    A,
    B,
    C
  };
  GIVEN("An empty FeatherFifo")
  {
    FeatherFifo<> ff;

    REQUIRE(ff.empty());
  }
}