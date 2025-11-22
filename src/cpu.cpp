#include "../inc/cpu.h"

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
