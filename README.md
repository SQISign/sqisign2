# SQISign: compact post-quantum signatures from quaternions and isogenies

This code implements a variant of the isogeny-based signature scheme SQISign.

(C) 2020, The SQISign team. MIT license.
(C) 2022, The SQISign2 team. MIT license.

## Dependencies

The code depends on the latest stable version of the [PARI/GP
library](http://pari.math.u-bordeaux.fr/), 2.11.4.

The code has an optional dependency on [GMP](https://gmplib.org/),
which is also an optional dependency of PARI/GP and is typically
installed along with it.

## Supported platforms

The code compiles and runs on Linux and MacOS.

It contains two implementations of the low-level arithmetic functions:

- One based on handwritten assembly for the x86-64 platform,
  starting from Broadwell architectures.

- One based on GMP.

By default, both versions are compiled and tested.

## Compile

To compile, test and benchmark the GMP version, run

```
make
make check
make benchmark
```

For the assembly version:

```
make ASM=1
make check ASM=1
make benchmark ASM=1
```

or alternatively, to save typing:

```
export ASM=1
make
make check
make benchmark
```

It is advised not mixing object files compiled with and without
`ASM=1`. If you move from GMP to assembly, retrigger a full
compilation with `make -B`.


## Tuning

The algorithms have already been tuned on a modern processors, and the
default values should be fine. However, should you wish to fine-tune
for your machine, run:

```
make tune
make
```

Add `ASM=1` if you want to tune for assembly. Be patient, tuning takes
several minutes.


## Changing base field

The base field (a quadratic extension of GF(p)) is defined by several
global constants and hand optimized ad-hoc functions. These are
defined in a subfolder named `pXXXX...` for each different prime.

The default prime is `p3923`. Other possibilities are `p6983`,
`p3433`, `p175e48c7879e3` and `p14ffe5311380b`. To switch prime do

```
make PRIME=p3433
make check PRIME=p3433
make benchmark PRIME=p3433
```

or

```
export PRIME=p3433
make
make check
make benchmark
```

Object files are created in separate folder, there is no need to
recompile from scratch with `make -B` when you change prime.


## Running individual tests and benchmarks

All tests are found in the folder `test/`, all benchmarks in the
folder `bench/`. To run test `mytest.c` type

```
make test_mytest
```

to run benchmark `mybench.c` type

```
make bench_mybench
```

optionally adding `ASM=1` and `PRIME=...` as needed.
