/* FOR INSTRUCTIONAL PURPOSES ONLY, DO NOT USE IN PRODUCTION */

.global main
main:
  mov   r0, #5            /* decimal */
  mov   r1, #0x0A         /* hexadecimal */
  mov   r2, #0b00000011   /* binary */
  add   r0, r1
  add   r0, r2
  bx    lr
