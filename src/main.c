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

void Emulate8080Op(State8080 *state) {
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
    break;
  case 0x03:
    break;
  case 0x04:
    break;
  case 0x05:
    break;
  case 0x06:
    break;
  case 0x07:
    break;
  case 0x08:
    break;
  case 0x0A:
    break;
  case 0x0B:
    break;
  case 0x0C:
    break;
  case 0x0D:
    break;
  case 0x0E:
    break;
  case 0x0F:
    break;
  case 0x10:
    break;
  case 0x11:
    break;
  case 0x12:
    break;
  case 0x13:
    break;
  case 0x14:
    break;
  case 0x15:
    break;
  case 0x16:
    break;
  case 0x17:
    break;
  case 0x18:
    break;
  case 0x19:
    break;
  case 0x1A:
    break;
  case 0x1B:
    break;
  case 0x1C:
    break;
  case 0x1D:
    break;
  case 0x1E:
    break;
  case 0x1F:
    break;
  case 0x20:
    break;
  case 0x21:
    break;
  case 0x22:
    break;
  case 0x23:
    break;
  case 0x24:
    break;
  case 0x25:
    break;
  case 0x26:
    break;
  case 0x27:
    break;
  case 0x28:
    break;
  case 0x29:
    break;
  case 0x2A:
    break;
  case 0x2B:
    break;
  case 0x2C:
    break;
  case 0x2D:
    break;
  case 0x2E:
    break;
  case 0x2F:
    break;
  case 0x30:
    break;
  case 0x31:
    break;
  case 0x32:
    break;
  case 0x33:
    break;
  case 0x34:
    break;
  case 0x35:
    break;
  case 0x36:
    break;
  case 0x37:
    break;
  case 0x38:
    break;
  case 0x39:
    break;
  case 0x3A:
    break;
  case 0x3B:
    break;
  case 0x3C:
    break;
  case 0x3D:
    break;
  case 0x3E:
    break;
  case 0x3F:
    break;
  case 0x40:
    break;
  case 0x41:
    break;
  case 0x42:
    break;
  case 0x43:
    break;
  case 0x44:
    break;
  case 0x45:
    break;
  case 0x46:
    break;
  case 0x47:
    break;
  case 0x48:
    break;
  case 0x49:
    break;
  case 0x4A:
    break;
  case 0x4B:
    break;
  case 0x4C:
    break;
  case 0x4D:
    break;
  case 0x4E:
    break;
  case 0x4F:
    break;
  case 0x50:
    break;
  case 0x51:
    break;
  case 0x52:
    break;
  case 0x53:
    break;
  case 0x54:
    break;
  case 0x55:
    break;
  case 0x56:
    break;
  case 0x57:
    break;
  case 0x58:
    break;
  case 0x59:
    break;
  case 0x5A:
    break;
  case 0x5B:
    break;
  case 0x5C:
    break;
  case 0x5D:
    break;
  case 0x5E:
    break;
  case 0x5F:
    break;
  case 0x60:
    break;
  case 0x61:
    break;
  case 0x62:
    break;
  case 0x63:
    break;
  case 0x64:
    break;
  case 0x65:
    break;
  case 0x66:
    break;
  case 0x67:
    break;
  case 0x68:
    break;
  case 0x69:
    break;
  case 0x6A:
    break;
  case 0x6B:
    break;
  case 0x6C:
    break;
  case 0x6D:
    break;
  case 0x6E:
    break;
  case 0x6F:
    break;
  case 0x70:
    break;
  case 0x71:
    break;
  case 0x72:
    break;
  case 0x73:
    break;
  case 0x74:
    break;
  case 0x75:
    break;
  case 0x76:
    break;
  case 0x77:
    break;
  case 0x78:
    break;
  case 0x79:
    break;
  case 0x7A:
    break;
  case 0x7B:
    break;
  case 0x7C:
    break;
  case 0x7D:
    break;
  case 0x7E:
    break;
  case 0x7F:
    break;
  case 0x80:
    break;
  case 0x81:
    break;
  case 0x82:
    break;
  case 0x83:
    break;
  case 0x84:
    break;
  case 0x85:
    break;
  case 0x86:
    break;
  case 0x87:
    break;
  case 0x88:
    break;
  case 0x89:
    break;
  case 0x8A:
    break;
  case 0x8B:
    break;
  case 0x8C:
    break;
  case 0x8D:
    break;
  case 0x8E:
    break;
  case 0x8F:
    break;
  case 0x90:
    break;
  case 0x91:
    break;
  case 0x92:
    break;
  case 0x93:
    break;
  case 0x94:
    break;
  case 0x95:
    break;
  case 0x96:
    break;
  case 0x97:
    break;
  case 0x98:
    break;
  case 0x99:
    break;
  case 0x9A:
    break;
  case 0x9B:
    break;
  case 0x9C:
    break;
  case 0x9D:
    break;
  case 0x9E:
    break;
  case 0x9F:
    break;
  case 0xA0:
    break;
  case 0xA1:
    break;
  case 0xA2:
    break;
  case 0xA3:
    break;
  case 0xA4:
    break;
  case 0xA5:
    break;
  case 0xA6:
    break;
  case 0xA7:
    break;
  case 0xA8:
    break;
  case 0xA9:
    break;
  case 0xAA:
    break;
  case 0xAB:
    break;
  case 0xAC:
    break;
  case 0xAD:
    break;
  case 0xAE:
    break;
  case 0xAF:
    break;
  case 0xB0:
    break;
  case 0xB1:
    break;
  case 0xB2:
    break;
  case 0xB3:
    break;
  case 0xB4:
    break;
  case 0xB5:
    break;
  case 0xB6:
    break;
  case 0xB7:
    break;
  case 0xB8:
    break;
  case 0xB9:
    break;
  case 0xBA:
    break;
  case 0xBB:
    break;
  case 0xBC:
    break;
  case 0xBD:
    break;
  case 0xBE:
    break;
  case 0xBF:
    break;
  case 0xC0:
    break;
  case 0xC1:
    break;
  case 0xC2:
    break;
  case 0xC3:
    break;
  case 0xC4:
    break;
  case 0xC5:
    break;
  case 0xC6:
    break;
  case 0xC7:
    break;
  case 0xC8:
    break;
  case 0xC9:
    break;
  case 0xCA:
    break;
  case 0xCB:
    break;
  case 0xCC:
    break;
  case 0xCD:
    break;
  case 0xCE:
    break;
  case 0xCF:
    break;
  case 0xD0:
    break;
  case 0xD1:
    break;
  case 0xD2:
    break;
  case 0xD3:
    break;
  case 0xD4:
    break;
  case 0xD5:
    break;
  case 0xD6:
    break;
  case 0xD7:
    break;
  case 0xD8:
    break;
  case 0xD9:
    break;
  case 0xDA:
    break;
  case 0xDB:
    break;
  case 0xDC:
    break;
  case 0xDD:
    break;
  case 0xDE:
    break;
  case 0xDF:
    break;
  case 0xE0:
    break;
  case 0xE1:
    break;
  case 0xE2:
    break;
  case 0xE3:
    break;
  case 0xE4:
    break;
  case 0xE5:
    break;
  case 0xE6:
    break;
  case 0xE7:
    break;
  case 0xE8:
    break;
  case 0xE9:
    break;
  case 0xEA:
    break;
  case 0xEB:
    break;
  case 0xEC:
    break;
  case 0xED:
    break;
  case 0xEE:
    break;
  case 0xEF:
    break;
  case 0xF0:
    break;
  case 0xF1:
    break;
  case 0xF2:
    break;
  case 0xF3:
    break;
  case 0xF4:
    break;
  case 0xF5:
    break;
  case 0xF6:
    break;
  case 0xF7:
    break;
  case 0xF8:
    break;
  case 0xF9:
    break;
  case 0xFA:
    break;
  case 0xFB:
    break;
  case 0xFC:
    break;
  case 0xFD:
    break;
  case 0xFE:
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
