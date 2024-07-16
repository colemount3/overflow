# Buffer Overflow Exploit

This is a basic buffer overflow exploit designed to execute 'malicious' shell code.

## Overview

This exploit leverages the vulnerability in the `gets()` function by passing an excessive number of characters to it. This overflow of characters surpasses the allocated buffer's storage capacity, allowing the overflow to overwrite the function's memory. Specifically, this exploit overwrites the return pointer with the address of the start of the buffer, causing the program to execute whatever is stored in the buffer. The buffer is filled with NOPs (for accuracy) leading to shellcode that grants the user root access, indicating a successful exploit.

## Payload Structure

The payload sent to the `gets()` function to overwrite the memory is structured as follows:

```plaintext
payload = NOP + shell + ebp_addr + packed_address
```
NOP: A series of no-operation instructions to handle any inaccuracies in memory addressing.
shell: The shellcode that will be executed.

ebp_addr: The base pointer address to be overwritten.

packed_address: The address of the start of the buffer, causing the NOPs and shellcode to be executed.

Details

Buffer Overflow: By exceeding the buffer's capacity, the overflow overwrites memory, including the return address.
Return Pointer Overwrite: The exploit sets the return pointer to the start of the buffer.

Shell Execution: The buffer, now filled with NOPs leading to shellcode, executes the shellcode, providing root access.

## Disclaimer
This exploit is not intended as a "plug and play" practice exploit. Processor types and memory settings vary between different machines, and this code should not be reused without proper understanding and modification.