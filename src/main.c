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
