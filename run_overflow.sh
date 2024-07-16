#!/bin/bash
sleep 1
# Run the Python script and pipe its output to the overflow program
(python3 exploit3.py) | ./overflow
