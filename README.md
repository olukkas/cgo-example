# CGO - Example

A simple Go project that uses cgo for integrating with C code.
this repo contains just a small script with an example of cgo
for personal learning process

## Prerequisites
if you want to try with this example in your machine
u must have gcc and go installed (this project uses 1.21.4 of go)

## How to Run
on linux

1. Clone the repository to your local machine:

```bash
   make lib
   make run
```

make lib will invoque gcc to compile the c code in the lib directory
make is just an alias to ``go run main.co``
