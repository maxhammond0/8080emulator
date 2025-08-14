#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ConditionCodes {
  uint8_t z : 1;
  uint8_t s : 1;
  uint8_t p : 1;
  uint8_t cy : 1;
  uint8_t ac : 1;
  uint8_t pad : 3;
} ConditionCodes;

typedef struct State8080 {
  uint8_t a;
  uint8_t b;
  uint8_t c;
  uint8_t d;
  uint8_t e;
  uint8_t h;
  uint8_t l;
  uint16_t sp;
  uint16_t pc;
  uint8_t *memory;
  struct ConditionCodes cc;
  uint8_t int_enable;
} State8080;

void UnimplementedInstruction(State8080 *state) {
  // pc will have to advance once, so undo that
  printf("error: Unimplemented instruction\n");
  exit(1);
}

int parity(int x, int size) {
  int i;
  int p = 0;
  x = (x & (1 << size) - 1);
  for (i = 0; i < size; i++) {
    if (x & 0x1)
      p++;
    x = x >> 1;
  }

  return (0 == (p & 0x01));
}

void Emulate8080Op(State8080 *state) {
  uint8_t x;
  uint8_t ret;
  uint8_t *opcode = &state->memory[state->pc];

  switch (*opcode) {
  case 0x00: // NOP
    break;
  case 0x01: // LXI
    state->c = opcode[1];
    state->b = opcode[2];
    state->pc += 2; // advance two more bytes
    break;
  case 0x02: // STAX
    UnimplementedInstruction(state);
    break;
  case 0x03:
    UnimplementedInstruction(state);
    break;
  case 0x04:
    UnimplementedInstruction(state);
    break;
  case 0x05:
    UnimplementedInstruction(state);
    break;
  case 0x06:
    UnimplementedInstruction(state);
    break;
  case 0x07:
    UnimplementedInstruction(state);
    break;
  case 0x08:
    UnimplementedInstruction(state);
    break;
  case 0x0A:
    UnimplementedInstruction(state);
    break;
  case 0x0B:
    UnimplementedInstruction(state);
    break;
  case 0x0C:
    UnimplementedInstruction(state);
    break;
  case 0x0D:
    UnimplementedInstruction(state);
    break;
  case 0x0E:
    UnimplementedInstruction(state);
    break;
  case 0x0F:
    uint8_t x = state->a;
    state->a = ((x & 1) << 7) | (x >> 1);
    state->cc.cy = (1 == (x & 1));
    break;
  case 0x10:
    UnimplementedInstruction(state);
    break;
  case 0x11:
    UnimplementedInstruction(state);
    break;
  case 0x12:
    UnimplementedInstruction(state);
    break;
  case 0x13:
    UnimplementedInstruction(state);
    break;
  case 0x14:
    UnimplementedInstruction(state);
    break;
  case 0x15:
    UnimplementedInstruction(state);
    break;
  case 0x16:
    UnimplementedInstruction(state);
    break;
  case 0x17:
    UnimplementedInstruction(state);
    break;
  case 0x18:
    UnimplementedInstruction(state);
    break;
  case 0x19:
    UnimplementedInstruction(state);
    break;
  case 0x1A:
    UnimplementedInstruction(state);
    break;
  case 0x1B:
    UnimplementedInstruction(state);
    break;
  case 0x1C:
    UnimplementedInstruction(state);
    break;
  case 0x1D:
    UnimplementedInstruction(state);
    break;
  case 0x1E:
    UnimplementedInstruction(state);
    break;
  case 0x1F:
    UnimplementedInstruction(state);
    break;
  case 0x20:
    UnimplementedInstruction(state);
    break;
  case 0x21:
    UnimplementedInstruction(state);
    break;
  case 0x22:
    UnimplementedInstruction(state);
    break;
  case 0x23:
    UnimplementedInstruction(state);
    break;
  case 0x24:
    UnimplementedInstruction(state);
    break;
  case 0x25:
    UnimplementedInstruction(state);
    break;
  case 0x26:
    UnimplementedInstruction(state);
    break;
  case 0x27:
    UnimplementedInstruction(state);
    break;
  case 0x28:
    UnimplementedInstruction(state);
    break;
  case 0x29:
    UnimplementedInstruction(state);
    break;
  case 0x2A:
    UnimplementedInstruction(state);
    break;
  case 0x2B:
    UnimplementedInstruction(state);
    break;
  case 0x2C:
    UnimplementedInstruction(state);
    break;
  case 0x2D:
    UnimplementedInstruction(state);
    break;
  case 0x2E:
    UnimplementedInstruction(state);
    break;
  case 0x2F:
    state->a = ~state->a;
    break;
  case 0x30:
    UnimplementedInstruction(state);
    break;
  case 0x31:
    UnimplementedInstruction(state);
    break;
  case 0x32:
    UnimplementedInstruction(state);
    break;
  case 0x33:
    UnimplementedInstruction(state);
    break;
  case 0x34:
    UnimplementedInstruction(state);
    break;
  case 0x35:
    UnimplementedInstruction(state);
    break;
  case 0x36:
    UnimplementedInstruction(state);
    break;
  case 0x37:
    UnimplementedInstruction(state);
    break;
  case 0x38:
    UnimplementedInstruction(state);
    break;
  case 0x39:
    UnimplementedInstruction(state);
    break;
  case 0x3A:
    UnimplementedInstruction(state);
    break;
  case 0x3B:
    UnimplementedInstruction(state);
    break;
  case 0x3C:
    UnimplementedInstruction(state);
    break;
  case 0x3D:
    UnimplementedInstruction(state);
    break;
  case 0x3E:
    UnimplementedInstruction(state);
    break;
  case 0x3F:
    UnimplementedInstruction(state);
    break;
  case 0x40:
    UnimplementedInstruction(state);
    break;
  case 0x41:
    UnimplementedInstruction(state);
    break;
  case 0x42:
    UnimplementedInstruction(state);
    break;
  case 0x43:
    UnimplementedInstruction(state);
    break;
  case 0x44:
    UnimplementedInstruction(state);
    break;
  case 0x45:
    UnimplementedInstruction(state);
    break;
  case 0x46:
    UnimplementedInstruction(state);
    break;
  case 0x47:
    UnimplementedInstruction(state);
    break;
  case 0x48:
    UnimplementedInstruction(state);
    break;
  case 0x49:
    UnimplementedInstruction(state);
    break;
  case 0x4A:
    UnimplementedInstruction(state);
    break;
  case 0x4B:
    UnimplementedInstruction(state);
    break;
  case 0x4C:
    UnimplementedInstruction(state);
    break;
  case 0x4D:
    UnimplementedInstruction(state);
    break;
  case 0x4E:
    UnimplementedInstruction(state);
    break;
  case 0x4F:
    UnimplementedInstruction(state);
    break;
  case 0x50:
    UnimplementedInstruction(state);
    break;
  case 0x51:
    UnimplementedInstruction(state);
    break;
  case 0x52:
    UnimplementedInstruction(state);
    break;
  case 0x53:
    UnimplementedInstruction(state);
    break;
  case 0x54:
    UnimplementedInstruction(state);
    break;
  case 0x55:
    UnimplementedInstruction(state);
    break;
  case 0x56:
    UnimplementedInstruction(state);
    break;
  case 0x57:
    UnimplementedInstruction(state);
    break;
  case 0x58:
    UnimplementedInstruction(state);
    break;
  case 0x59:
    UnimplementedInstruction(state);
    break;
  case 0x5A:
    UnimplementedInstruction(state);
    break;
  case 0x5B:
    UnimplementedInstruction(state);
    break;
  case 0x5C:
    UnimplementedInstruction(state);
    break;
  case 0x5D:
    UnimplementedInstruction(state);
    break;
  case 0x5E:
    UnimplementedInstruction(state);
    break;
  case 0x5F:
    UnimplementedInstruction(state);
    break;
  case 0x60:
    UnimplementedInstruction(state);
    break;
  case 0x61:
    UnimplementedInstruction(state);
    break;
  case 0x62:
    UnimplementedInstruction(state);
    break;
  case 0x63:
    UnimplementedInstruction(state);
    break;
  case 0x64:
    UnimplementedInstruction(state);
    break;
  case 0x65:
    UnimplementedInstruction(state);
    break;
  case 0x66:
    UnimplementedInstruction(state);
    break;
  case 0x67:
    UnimplementedInstruction(state);
    break;
  case 0x68:
    UnimplementedInstruction(state);
    break;
  case 0x69:
    UnimplementedInstruction(state);
    break;
  case 0x6A:
    UnimplementedInstruction(state);
    break;
  case 0x6B:
    UnimplementedInstruction(state);
    break;
  case 0x6C:
    UnimplementedInstruction(state);
    break;
  case 0x6D:
    UnimplementedInstruction(state);
    break;
  case 0x6E:
    UnimplementedInstruction(state);
    break;
  case 0x6F:
    UnimplementedInstruction(state);
    break;
  case 0x70:
    UnimplementedInstruction(state);
    break;
  case 0x71:
    UnimplementedInstruction(state);
    break;
  case 0x72:
    UnimplementedInstruction(state);
    break;
  case 0x73:
    UnimplementedInstruction(state);
    break;
  case 0x74:
    UnimplementedInstruction(state);
    break;
  case 0x75:
    UnimplementedInstruction(state);
    break;
  case 0x76:
    UnimplementedInstruction(state);
    break;
  case 0x77:
    UnimplementedInstruction(state);
    break;
  case 0x78:
    UnimplementedInstruction(state);
    break;
  case 0x79:
    UnimplementedInstruction(state);
    break;
  case 0x7A:
    UnimplementedInstruction(state);
    break;
  case 0x7B:
    UnimplementedInstruction(state);
    break;
  case 0x7C:
    UnimplementedInstruction(state);
    break;
  case 0x7D:
    UnimplementedInstruction(state);
    break;
  case 0x7E:
    UnimplementedInstruction(state);
    break;
  case 0x7F:
    UnimplementedInstruction(state);
    break;
  case 0x80:
    UnimplementedInstruction(state);
    break;
  case 0x81:
    UnimplementedInstruction(state);
    break;
  case 0x82:
    UnimplementedInstruction(state);
    break;
  case 0x83:
    UnimplementedInstruction(state);
    break;
  case 0x84:
    UnimplementedInstruction(state);
    break;
  case 0x85:
    UnimplementedInstruction(state);
    break;
  case 0x86:
    UnimplementedInstruction(state);
    break;
  case 0x87:
    UnimplementedInstruction(state);
    break;
  case 0x88:
    UnimplementedInstruction(state);
    break;
  case 0x89:
    UnimplementedInstruction(state);
    break;
  case 0x8A:
    UnimplementedInstruction(state);
    break;
  case 0x8B:
    UnimplementedInstruction(state);
    break;
  case 0x8C:
    UnimplementedInstruction(state);
    break;
  case 0x8D:
    UnimplementedInstruction(state);
    break;
  case 0x8E:
    UnimplementedInstruction(state);
    break;
  case 0x8F:
    UnimplementedInstruction(state);
    break;
  case 0x90:
    UnimplementedInstruction(state);
    break;
  case 0x91:
    UnimplementedInstruction(state);
    break;
  case 0x92:
    UnimplementedInstruction(state);
    break;
  case 0x93:
    UnimplementedInstruction(state);
    break;
  case 0x94:
    UnimplementedInstruction(state);
    break;
  case 0x95:
    UnimplementedInstruction(state);
    break;
  case 0x96:
    UnimplementedInstruction(state);
    break;
  case 0x97:
    UnimplementedInstruction(state);
    break;
  case 0x98:
    UnimplementedInstruction(state);
    break;
  case 0x99:
    UnimplementedInstruction(state);
    break;
  case 0x9A:
    UnimplementedInstruction(state);
    break;
  case 0x9B:
    UnimplementedInstruction(state);
    break;
  case 0x9C:
    UnimplementedInstruction(state);
    break;
  case 0x9D:
    UnimplementedInstruction(state);
    break;
  case 0x9E:
    UnimplementedInstruction(state);
    break;
  case 0x9F:
    UnimplementedInstruction(state);
    break;
  case 0xA0:
    UnimplementedInstruction(state);
    break;
  case 0xA1:
    UnimplementedInstruction(state);
    break;
  case 0xA2:
    UnimplementedInstruction(state);
    break;
  case 0xA3:
    UnimplementedInstruction(state);
    break;
  case 0xA4:
    UnimplementedInstruction(state);
    break;
  case 0xA5:
    UnimplementedInstruction(state);
    break;
  case 0xA6:
    UnimplementedInstruction(state);
    break;
  case 0xA7:
    UnimplementedInstruction(state);
    break;
  case 0xA8:
    UnimplementedInstruction(state);
    break;
  case 0xA9:
    UnimplementedInstruction(state);
    break;
  case 0xAA:
    UnimplementedInstruction(state);
    break;
  case 0xAB:
    UnimplementedInstruction(state);
    break;
  case 0xAC:
    UnimplementedInstruction(state);
    break;
  case 0xAD:
    UnimplementedInstruction(state);
    break;
  case 0xAE:
    UnimplementedInstruction(state);
    break;
  case 0xAF:
    UnimplementedInstruction(state);
    break;
  case 0xB0:
    UnimplementedInstruction(state);
    break;
  case 0xB1:
    UnimplementedInstruction(state);
    break;
  case 0xB2:
    UnimplementedInstruction(state);
    break;
  case 0xB3:
    UnimplementedInstruction(state);
    break;
  case 0xB4:
    UnimplementedInstruction(state);
    break;
  case 0xB5:
    UnimplementedInstruction(state);
    break;
  case 0xB6:
    UnimplementedInstruction(state);
    break;
  case 0xB7:
    UnimplementedInstruction(state);
    break;
  case 0xB8:
    UnimplementedInstruction(state);
    break;
  case 0xB9:
    UnimplementedInstruction(state);
    break;
  case 0xBA:
    UnimplementedInstruction(state);
    break;
  case 0xBB:
    UnimplementedInstruction(state);
    break;
  case 0xBC:
    UnimplementedInstruction(state);
    break;
  case 0xBD:
    UnimplementedInstruction(state);
    break;
  case 0xBE:
    UnimplementedInstruction(state);
    break;
  case 0xBF:
    UnimplementedInstruction(state);
    break;
  case 0xC0:
    UnimplementedInstruction(state);
    break;
  case 0xC1:
    state->c = state->memory[state->sp];
    state->b = state->memory[state->sp + 1];
    state->pc += 2;
    break;
  case 0xC2:
    if (0 == state->cc.z) {
      state->pc = (opcode[2] << 8) | opcode[1];
    } else {
      // branch not taken
      state->pc += 2;
    }
    break;
  case 0xC3:
    state->pc = (opcode[2] << 8) | opcode[1];
    break;
  case 0xC4:
    UnimplementedInstruction(state);
    break;
  case 0xC5:
    state->memory[state->sp - 1] = state->b;
    state->memory[state->sp - 2] = state->c;
    state->sp = state->sp - 2;
    break;
  case 0xC6:
    UnimplementedInstruction(state);
    break;
  case 0xC7:
    UnimplementedInstruction(state);
    break;
  case 0xC8:
    UnimplementedInstruction(state);
    break;
  case 0xC9:
    state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
    state->pc += 2;
    break;
  case 0xCA:
    UnimplementedInstruction(state);
    break;
  case 0xCB:
    UnimplementedInstruction(state);
    break;
  case 0xCC:
    UnimplementedInstruction(state);
    break;
  case 0xCD:
    uint16_t ret = state->pc + 2;
    state->memory[state->sp + 1] = (ret >> 8) & 0xff;
    state->memory[state->sp + 1] = (ret & 0xff);
    state->sp = state->sp - 2;
    state->pc = (opcode[2] << 8) | opcode[1];
    break;
  case 0xCE:
    UnimplementedInstruction(state);
    break;
  case 0xCF:
    UnimplementedInstruction(state);
    break;
  case 0xD0:
    UnimplementedInstruction(state);
    break;
  case 0xD1:
    UnimplementedInstruction(state);
    break;
  case 0xD2:
    UnimplementedInstruction(state);
    break;
  case 0xD3:
    UnimplementedInstruction(state);
    break;
  case 0xD4:
    UnimplementedInstruction(state);
    break;
  case 0xD5:
    UnimplementedInstruction(state);
    break;
  case 0xD6:
    UnimplementedInstruction(state);
    break;
  case 0xD7:
    UnimplementedInstruction(state);
    break;
  case 0xD8:
    UnimplementedInstruction(state);
    break;
  case 0xD9:
    UnimplementedInstruction(state);
    break;
  case 0xDA:
    UnimplementedInstruction(state);
    break;
  case 0xDB:
    UnimplementedInstruction(state);
    break;
  case 0xDC:
    UnimplementedInstruction(state);
    break;
  case 0xDD:
    UnimplementedInstruction(state);
    break;
  case 0xDE:
    UnimplementedInstruction(state);
    break;
  case 0xDF:
    UnimplementedInstruction(state);
    break;
  case 0xE0:
    UnimplementedInstruction(state);
    break;
  case 0xE1:
    UnimplementedInstruction(state);
    break;
  case 0xE2:
    UnimplementedInstruction(state);
    break;
  case 0xE3:
    UnimplementedInstruction(state);
    break;
  case 0xE4:
    UnimplementedInstruction(state);
    break;
  case 0xE5:
    UnimplementedInstruction(state);
    break;
  case 0xE6:
    uint8_t x = state->a & opcode[1];
    state->cc.z = (x == 0);
    state->cc.s = (0x80 == (x & 0x80));
    state->cc.p = parity(x, 8);
    state->cc.cy = 0;
    state->pc++;
    break;
  case 0xE7:
    UnimplementedInstruction(state);
    break;
  case 0xE8:
    UnimplementedInstruction(state);
    break;
  case 0xE9:
    UnimplementedInstruction(state);
    break;
  case 0xEA:
    UnimplementedInstruction(state);
    break;
  case 0xEB:
    UnimplementedInstruction(state);
    break;
  case 0xEC:
    UnimplementedInstruction(state);
    break;
  case 0xED:
    UnimplementedInstruction(state);
    break;
  case 0xEE:
    UnimplementedInstruction(state);
    break;
  case 0xEF:
    UnimplementedInstruction(state);
    break;
  case 0xF0:
    break;
  case 0xF1:
    state->a = state->memory[state->sp + 1];
    uint8_t psw = state->memory[state->sp];
    state->cc.z = (0x01 == (psw & 0x01));
    state->cc.s = (0x02 == (psw & 0x02));
    state->cc.p = (0x04 == (psw & 0x04));
    state->cc.cy = (0x05 == (psw & 0x05));
    state->cc.ac = (0x10 == (psw & 0x10));
    break;
  case 0xF2:
    UnimplementedInstruction(state);
    break;
  case 0xF3:
    UnimplementedInstruction(state);
    break;
  case 0xF4:
    UnimplementedInstruction(state);
    break;
  case 0xF5:
    state->memory[state->sp - 1] = state->a;
    uint8_t psw = (state->cc.z | state->cc.s << 1 | state->cc.p << 2 |
                   state->cc.cy << 3 | state->cc.ac << 4);
    state->memory[state->sp - 2] = psw;
    state->sp = state->sp - 2;
    break;
  case 0xF6:
    UnimplementedInstruction(state);
    break;
  case 0xF7:
    UnimplementedInstruction(state);
    break;
  case 0xF8:
    UnimplementedInstruction(state);
    break;
  case 0xF9:
    UnimplementedInstruction(state);
    break;
  case 0xFA:
    UnimplementedInstruction(state);
    break;
  case 0xFB:
    UnimplementedInstruction(state);
    break;
  case 0xFC:
    UnimplementedInstruction(state);
    break;
  case 0xFD:
    UnimplementedInstruction(state);
    break;
  case 0xFE:
    uint8_t x = state->a - opcode[1];
    state->cc.z = (x == 0);
    state->cc.s = (0x80 == (x & 0x80));
    state->cc.p = parity(x, 8);
    break;
  case 0xFF:
    break;
  }

  state->pc += 1;
}

int Disassemble8080p(uint8_t *codebuffer, int pc) {
  uint8_t *code = &codebuffer[pc];
  int opbytes = 1;
  printf("%04x ", pc);

  switch (*code) {
  case 0x00:
    printf("NOP");
    break;
  case 0x01:
    printf("LXI   B,D16,#$%02x%02x", code[2], code[1]);
    opbytes = 3;
    break;
  case 0x02:
    printf("STAX  B");
    break;
  case 0x03:
    printf("INX   B");
    break;
  case 0x04:
    printf("INR   B");
    break;
  case 0x05:
    printf("DCR   B");
    break;
  case 0x06:
    printf("MVI   B,#$%02x", code[1]);
    opbytes = 2;
    break;
  case 0x07:
    printf("RLC");
    break;
  case 0x08:
    printf("NOP");
    break;
  case 0x09:
    break;
  case 0x0a:
    break;
  case 0x0b:
    break;
  case 0x0c:
    break;
  case 0x0d:
    break;
  case 0x0e:
    break;
  case 0x0f:
    break;
  case 0x10:
    break;
  }

  printf("\n");
  return opbytes;
}

int main(int argc, char **argv) {
  FILE *f = fopen(argv[1], "rb");
  if (f == NULL) {
    printf("error: Couldn't open %s\n", argv[1]);
    exit(-1);
  }

  // Get the file size and read it into a memory buffer
  fseek(f, 0L, SEEK_END);
  int fsize = ftell(f);
  fseek(f, 0L, SEEK_SET);

  uint8_t *buffer = malloc(fsize);

  fread(buffer, fsize, 1, f);
  fclose(f);

  int pc = 0;

  while (pc < fsize) {
    pc += Disassemble8080p(buffer, pc);
  }

  return 0;
}
