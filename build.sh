#!/bin/sh

gcc src/main.c \
    src/singleton.c \
    src/run-detached.c \
    src/log-message.c \
    src/make-directory.c \
    src/main-loop.c \
    src/remove-old-log.c \
    -o daemon

if [ $? -ne 0 ]; then
    echo "Build failed. Please check the error messages above."
    exit 1
else
    echo "Build successful!"
    exit 0
fi