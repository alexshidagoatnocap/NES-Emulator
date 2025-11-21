#include <cstdint>

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

private:
};
