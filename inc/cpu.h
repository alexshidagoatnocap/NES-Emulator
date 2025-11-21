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

  // Status flags
  typedef enum {
    CARRY = (1 << 0),
    ZERO = (1 << 1),
    INTERRUPT_DISABLE = (1 << 2),
    DECIMAL_MODE = (1 << 3),
    BREAK_CMD = (1 << 4),
    OVERFLOW = (1 << 5),
    NEGATIVE = (1 << 6)
  } StatusFlags;

private:
};
