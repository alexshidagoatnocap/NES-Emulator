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

  lut[0x10] = {&c::IN_BPL, &c::MO_REL, 2}; // ** +1 if branch
  lut[0x11] = {&c::IN_ORA, &c::MO_IDY, 5}; // *  +1 if page bound crossed
  lut[0x12] = {&c::IN_WTF, &c::MO_IMP, 2};
  lut[0x13] = {&c::IN_WTF, &c::MO_IMP, 2};
  lut[0x14] = {&c::IN_WTF, &c::MO_IMP, 2};
  lut[0x15] = {&c::IN_ORA, &c::MO_ZPX, 4};
  lut[0x16] = {&c::IN_ASL, &c::MO_ZPX, 6};
  lut[0x17] = {&c::IN_WTF, &c::MO_IMP, 2};
  lut[0x18] = {&c::IN_CLC, &c::MO_IMP, 2};
  lut[0x19] = {&c::IN_ORA, &c::MO_ABY, 4}; // *
  lut[0x1A] = {&c::IN_WTF, &c::MO_IMP, 2};
  lut[0x1B] = {&c::IN_WTF, &c::MO_IMP, 2};
  lut[0x1C] = {&c::IN_WTF, &c::MO_IMP, 2};
  lut[0x1D] = {&c::IN_ORA, &c::MO_ABX, 4}; // *
  lut[0x1E] = {&c::IN_ASL, &c::MO_ABX, 7};
  lut[0x1F] = {&c::IN_WTF, &c::MO_IMP, 2};
}
