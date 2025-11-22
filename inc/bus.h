#pragma once

#include "cpu.h"
#include <array>
#include <cstdint>

#define MAX_ADDR_MEMORY 0xFFFF

class Bus {
public:
  Bus();
  ~Bus();

  Cpu6502 cpu;

  std::array<uint8_t, MAX_ADDR_MEMORY + 1> memory; // 64kb of memory

public:
  void write_memory(uint16_t addr, uint8_t data);
  uint8_t read_memory(uint16_t addr);

private:
  void clear_memory();
};
