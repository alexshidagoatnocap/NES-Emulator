#include "../inc/bus.h"
#include <cstdint>

Bus::Bus() {
  // TODO: Write initialization process in constructor
}

Bus::~Bus() {}

void Bus::write_memory(uint16_t addr, uint8_t data) {
  if (addr >= 0 && addr <= MAX_ADDR_MEMORY) {
    memory[addr] = data;
  }
}

uint8_t Bus::read_memory(uint16_t addr) {
  if (addr >= 0 && addr <= MAX_ADDR_MEMORY) {
    return memory[addr];
  }

  // TODO: Make new type for better error handling
  return 0x00;
}
