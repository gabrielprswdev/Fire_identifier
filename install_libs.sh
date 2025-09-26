#!/bin/bash

libs=(
  "ESP Mail Client@3.4.24"
)

for lib in "${libs[@]}"; do
    arduino-cli lib install "$lib"
done