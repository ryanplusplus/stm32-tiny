MEMORY {
  rom (rx) : ORIGIN = 0x08000000, LENGTH = 128K
  ram (rwx) : ORIGIN = 0x20000000, LENGTH = 36K
}

INCLUDE ld/common.ld
