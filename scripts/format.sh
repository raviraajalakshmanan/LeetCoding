#!/bin/sh
clang-format -i $(git ls-files '*.cpp' '*.h')
