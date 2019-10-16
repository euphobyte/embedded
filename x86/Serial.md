# Serial Initialization

```
Bits
| 7 6 5 | 4 3 | 2 | 1 0 |
    │      │    │    │
    │      │    │    └ Bits per character: 11 = 8, 10 = 7
    │      │    └───── Stop bits: 0 = 1, 1 = 2
    │      └────────── Parity: 00 = none, 01 = odd, 11 = even
    └───────────────── Baudrate: 111 = 9600, 110 = 4800, 100 = 1200, 010 = 300, 001 = 150, 000 = 110   
```
