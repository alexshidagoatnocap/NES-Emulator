#include "../inc/bus.h"
#include <cstdint>

Bus::Bus() {
  // TODO: Write initialization process in constructor
  clear_memory();
}

Bus::~Bus() {}

void Bus::write_memory(uint16_t addr, uint8_t data) { memory[addr] = data; }

uint8_t Bus::read_memory(uint16_t addr) { return memory[addr]; }

void Bus::clear_memory() { memory.fill(0x00); }
