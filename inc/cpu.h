#pragma once

#include <cstdint>

class Bus;

class Cpu6502 {
public:
  Cpu6502();
  ~Cpu6502();

public:
  // CPU registers
  uint16_t PC = 0x0000; // Program Counter
  uint8_t SP = 0x00;    // Stack Pointer
  uint8_t ACC = 0x00;   // Accumulator
  uint8_t IRX = 0x00;   // Index Register X
  uint8_t IRY = 0x00;   // Index Register Y
  uint8_t STAT = 0x00;  // Status Register

  // Status flags
  enum StatusFlags {
    CARRY = (1 << 0),
    ZERO = (1 << 1),
    INTERRUPT_DISABLE = (1 << 2),
    DECIMAL_MODE = (1 << 3),
    BREAK_CMD = (1 << 4),
    OVERFLOW = (1 << 5),
    NEGATIVE = (1 << 6)
  };

public: 
  inline void connect_to_bus(Bus *bus) { busptr = bus; };
  void reset();

private:
  Bus *busptr = nullptr;

  void write_to_bus(uint16_t addr, uint8_t data);
  uint8_t read_from_bus(uint16_t addr);

  void clock_cycle();

private:
  // Official Instruction Handlers
  uint8_t IN_ADC(); uint8_t IN_AND(); uint8_t IN_ASL(); uint8_t IN_BCC();
  uint8_t IN_BCS(); uint8_t IN_BEQ(); uint8_t IN_BIT(); uint8_t IN_BMI(); 
  uint8_t IN_BNE(); uint8_t IN_BPL(); uint8_t IN_BRK(); uint8_t IN_BVC(); 
  uint8_t IN_BVS(); uint8_t IN_CLC(); uint8_t IN_CLD(); uint8_t IN_CLI(); 
  uint8_t IN_CLV(); uint8_t IN_CMP(); uint8_t IN_CPX(); uint8_t IN_CPY();
  uint8_t IN_DEC(); uint8_t IN_DEX(); uint8_t IN_DEY(); uint8_t IN_EOR(); 
  uint8_t IN_INC(); uint8_t IN_INX(); uint8_t IN_INY(); uint8_t IN_JMP(); 
  uint8_t IN_JSR(); uint8_t IN_LDA(); uint8_t IN_LDX(); uint8_t IN_LDY(); 
  uint8_t IN_LSR(); uint8_t IN_NOP(); uint8_t IN_ORA(); uint8_t IN_PHA(); 
  uint8_t IN_PHP(); uint8_t IN_PLA(); uint8_t IN_PLP(); uint8_t IN_ROL();
  uint8_t IN_ROR(); uint8_t IN_RTI(); uint8_t IN_RTS(); uint8_t IN_SBC(); 
  uint8_t IN_SEC(); uint8_t IN_SED(); uint8_t IN_SEI(); uint8_t IN_STA(); 
  uint8_t IN_STX(); uint8_t IN_STY(); uint8_t IN_TAX(); uint8_t IN_TAY(); 
  uint8_t IN_TSX(); uint8_t IN_TXA(); uint8_t IN_TXS(); uint8_t IN_TYA();

private:
  // Addressing Modes
	uint8_t MO_ABS(); uint8_t MO_IDX();
	uint8_t MO_ABX(); uint8_t MO_IDY();
	uint8_t MO_ABY(); uint8_t MO_REL();
	uint8_t MO_IMM(); uint8_t MO_ZPG();
	uint8_t MO_IMP(); uint8_t MO_ZPX();
	uint8_t MO_IND(); uint8_t MO_ZPY();
};
