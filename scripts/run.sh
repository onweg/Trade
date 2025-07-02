#!/bin/bash
set -e

EXECUTABLE="./build/TradeBot"

./scripts/clean.sh
./scripts/build.sh
./$EXECUTABLE