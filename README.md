# Daemon Application

This repository contains the source code for a simple daemon application in C. The daemon runs in the background and writes a log message to a file every 20 seconds. The log messages are stored in the folder /var/log/daemon/.

## Requirements

    A C compiler, such as GCC
    The standard C library and development headers
    The POSIX functions for working with signals, processes, and file systems.

## Building the Application

To build the application, simply run the following command in the root of the repository:

```bash
./build.sh
```

This will compile the source files and create an executable file named daemon.

## Running the Application

To run the application in the foreground, simply execute the following command:

```bash
./daemon
```

To run the application as a daemon in the background, execute the following command:

```bash
./daemon -d
```

## Log Files

The daemon will write log messages to files in the folder /var/log/daemon/. The log files have a prefix of daemon- and a date stamp in the format YYYY-MM-DD with an extension of .log. The daemon will also remove log files that are older than 7 days.