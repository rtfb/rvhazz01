#!/bin/bash

# This script is being called from .github/workflows/maketest.yml to install
# necessary software to build/run tests in CI.

sudo apt-get install -y gcc-riscv64-linux-gnu
sudo apt-get install -y qemu-system-riscv64
