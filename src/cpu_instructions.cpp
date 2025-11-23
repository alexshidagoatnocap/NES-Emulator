#include "../inc/cpu.h"

void Cpu6502::initInstructionLUT() {
  auto &lut = instructionLUT;

  lut[0x00] = {&Cpu6502::IN_BRK, &Cpu6502::MO_IMP, 7};
  lut[0x01] = {&Cpu6502::IN_ORA, &Cpu6502::MO_IDX, 6};
}
