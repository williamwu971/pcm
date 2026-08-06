/*
 * inf_writer.c -- malloc 1GiB, then loop forever writing 1 byte to
 * every 64-byte cacheline.
 *
 * Build: gcc -O2 -o inf_writer inf_writer.c
 * Run:   ./inf_writer          (Ctrl-C to stop)
 *        numactl -m 2 ./inf_writer
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SZ (1UL << 30) /* 1 GiB */
#define CACHELINE 64

int main(void) {
  volatile unsigned char *p = malloc(SZ);
  if (!p) {
    perror("malloc");
    return 1;
  }

  printf("writing 1 byte per %d B line over %lu GiB, forever (Ctrl-C)\n",
         CACHELINE, SZ >> 30);

  unsigned char v = 0;
  for (;;) {
    for (size_t i = 0; i < SZ; i += CACHELINE)
      p[i] = v;
    v++;
  }
  return 0;
}