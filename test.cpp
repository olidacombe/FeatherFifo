#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
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

    WHEN("pop() is attempted")
    {
      THEN("exception is thrown")
      {
        REQUIRE_THROWS(ff.pop());
      }
    }
  }
}