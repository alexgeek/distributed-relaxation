Distributed Relaxation
==========

Relaxation algorithm in a distributed environment.
Written in C with MPI, built with CMake, [Check](http://check.sourceforge.net/) for unit testing.

Building and Testing
--------------------
From the root directory:

```bash
cd build
cmake ..
make
```

Then to run unit tests:


```bash
make test
```

Example output:

```
Running tests...
Test project /home/apollo/Projects/distributed-relaxation/build
    Start 1: check_matrix
1/2 Test #1: check_matrix .....................   Passed    0.00 sec
    Start 2: check_image
2/2 Test #2: check_image ......................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.01 sec
```
