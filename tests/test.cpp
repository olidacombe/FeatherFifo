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
    FeatherFifo<TSample, 4> ff;

    REQUIRE(ff.empty());

    WHEN("pop() is attempted")
    {
      THEN("exception is thrown")
      {
        REQUIRE_THROWS(ff.pop());
      }
    }

    WHEN("a value is pushed")
    {
      ff.push(TSample::A);
      THEN("empty() returns false")
      {
        REQUIRE(!ff.empty());
      }
    }

    WHEN("values are pushed")
    {
      ff.push(TSample::A);
      ff.push(TSample::B);
      ff.push(TSample::C);
      THEN("values are popped in fifo order until empty")
      {
        REQUIRE(ff.pop() == TSample::A);
        REQUIRE(ff.pop() == TSample::B);
        REQUIRE(ff.pop() == TSample::C);
        REQUIRE(ff.empty());
      }
    }

    WHEN("the buffer is full")
    {
      ff.push(TSample::A);
      ff.push(TSample::B);
      ff.push(TSample::C);
      ff.push(TSample::A);
      WHEN("a further value is pushed")
      {
        ff.push(TSample::B);
        THEN("the first value is evicted")
        {
          REQUIRE(ff.pop() == TSample::B);
          REQUIRE(ff.pop() == TSample::C);
          REQUIRE(ff.pop() == TSample::A);
          REQUIRE(ff.pop() == TSample::B);
          REQUIRE(ff.empty());
        }
      }
    }
  }
}