.. _install:

Installation
====================

TIDAS requires a C++11 compiler for building.  The only currently implemented "backend" storage format is HDF5, so installation also requires the serial HDF5 library.  Optional dependencies are an MPI C++ compiler compatible with the serial compiler and a modern python version.


Compiled Dependencies
--------------------------

The serial HDF5 library can be built from source (see `the downloads here <https://support.hdfgroup.org/HDF5/>`_).  However, most Linux distributions and OS X package managers (MACports, Homebrew, etc) have packages for HDF5 and that is probably the easiest way to install it.


Python Dependencies
------------------------

To use the python bindings you should have a reasonably new version of python (>= 2.7 or >= 3.4).  We also require
several common python packages:

    * numpy
    * mpi4py (>= 2.0.0, only if using the MPI interface)

For mpi4py, ensure that this package is compatible with the MPI C++ compiler
used during TIDAS installation.  There are obviously several ways to meet these python requirements.  Your OS package manager may already provide these, or you might use an external Python distribution (e.g. Anaconda).


CMake Build System
-----------------------

TIDAS uses cmake to build and install both the compiled code and the python bindings.  You should use an out-of-source build.  For example, make a top-level "build" directory and run cmake from there::

    %> mkdir build
    %> cd build
    %> cmake ..
    %> make -j 4

In practice, there are likely other options you want to pass to cmake.  The "platforms" directory contains several examples of running cmake.  For example, to use the ubuntu gcc example and install to $HOME/software, one could do::

    %> mkdir build
    %> cd build
    %> ../platforms/ubuntu-gcc.sh -DCMAKE_INSTALL_PREFIX=$HOME/software
    %> make -j 4
    %> make install


Testing the Installation
-----------------------------

After installation, you can test the serial compiled software with::

    %> tidas_test

and can test the MPI compiled library with (your command for launching MPI programs may be different)::

    %> mpirun -np 4 tidas_test_mpi

You can test the Python bindings in a similar way::

    %> python -c "import tidas.test; tidas.test.run()"

and::

    %> mpirun -np 4 python -c "import tidas.test; tidas.test.run_mpi()"

Some of the above commands will create temporary output directories in your current working directory.
