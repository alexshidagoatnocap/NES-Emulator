#include "../inc/cpu.h"
#include "../inc/bus.h"
#include <cstdint>

Cpu6502::Cpu6502() { reset(); }

Cpu6502::~Cpu6502() {}

void Cpu6502::reset() {
  ACC = 0;
  IRX = 0;
  IRY = 0;
  PC = 0xFFFC;
  SP = 0xFD;
  STAT |= INTERRUPT_DISABLE;
}

uint8_t Cpu6502::read_from_bus(uint16_t addr) {
  return busptr->read_memory(addr);
}

void Cpu6502::write_to_bus(uint16_t addr, uint8_t data) {
  busptr->write_memory(addr, data);
}
