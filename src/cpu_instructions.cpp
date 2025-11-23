#include "../inc/cpu.h"

void Cpu6502::initInstructionLUT() {
  auto &lut = instructionLUT;
  using c = Cpu6502;

  lut[0x00] = {&c::IN_BRK, &c::MO_IMP, 7};
  lut[0x01] = {&c::IN_ORA, &c::MO_IDX, 6};
  lut[0x02] = {&c::IN_WTF, &c::MO_IMP, 2};
  lut[0x03] = {&c::IN_WTF, &c::MO_IMP, 2};
  lut[0x04] = {&c::IN_WTF, &c::MO_IMP, 2};
  lut[0x05] = {&c::IN_ORA, &c::MO_ZPG, 3};
  lut[0x06] = {&c::IN_ASL, &c::MO_ZPG, 5};
  lut[0x07] = {&c::IN_WTF, &c::MO_IMP, 2};
  lut[0x08] = {&c::IN_PHP, &c::MO_IMP, 3};
  lut[0x09] = {&c::IN_ORA, &c::MO_IMM, 2};
  lut[0x0A] = {&c::IN_ASL, &c::MO_ACC, 2};
  lut[0x0B] = {&c::IN_WTF, &c::MO_IMP, 2};
  lut[0x0C] = {&c::IN_WTF, &c::MO_IMP, 2};
  lut[0x0D] = {&c::IN_ORA, &c::MO_ABS, 4};
  lut[0x0E] = {&c::IN_ASL, &c::MO_ABS, 6};
  lut[0x0F] = {&c::IN_WTF, &c::MO_IMP, 2};

  lut[0x10] = {&c::IN_BPL, &c::MO_REL, 2};
}
