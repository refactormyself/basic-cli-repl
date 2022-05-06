#!/usr/bin/env bash

docker build -t basic-repl-gcc-cmake-x86 -f x86.Dockerfile .
docker run -it --rm --name running-repl-x86 basic-repl-gcc-cmake-x86