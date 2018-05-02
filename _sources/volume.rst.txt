
.. _volume:

Volumes
=================

A volume is the top-level TIDAS object.  It defines the "backend" data format and holds a metadata database for fast(er) data selection and query operations.  It also contains the root of a hierarchy (a tree) of "blocks".


Planning the Layout of a Volume
--------------------------------------

An important feature of TIDAS volumes is the ability to open / copy / link only a subset of the data.  This selection operation is performed with a regular expression match on the tree of block names.  This means that it is critical to plan out the organization of blocks to make it possible to do any desired data selections.

Most data collected from monitoring systems, experimental apparatuses, etc, have natural ways that the data might be split up into pieces.  For example, if the data collection is started fresh each day, you might have a block for each day.  If there are different sorts of data within one day which you might want to frequently split up, then you could have sub-blocks in each day for the different data types.  Going the other direction up the hierarchy, you might organize the days into blocks for each month, each quarter, each year, etc.


Interface
---------------

Here is a basic reference for the volume interface.


Python
~~~~~~~~~

.. autoclass:: tidas.Volume
    :members:


C++
~~~~~~~~~

.. doxygenclass:: tidas::volume
    :members:
    :no-link:


Blocks
----------------

A "block" is simply a logical collection of data which has a "name" (a string) associated with it.  A block can contain data itself, other blocks, or both.  A volume contains a special "root" block, which is the top of the tree / hierarchy of blocks in the volume.


Python
~~~~~~~~~

.. autoclass:: tidas.Block
    :members:


C++
~~~~~~~~~

.. doxygenclass:: tidas::block
    :members:


MPI Volumes
----------------------

On supported systems, an MPI interface to TIDAS volumes will be installed.
These are very similar to serial volumes.  When a volume is opened through
the MPI interface, all processes get a copy of the metadata index.  If any
objects are added or resized on one process, the other processes will not
see those changes until the synchronization method is called.

.. warning::

	Multiple processes writing to the same group or intervals object is not supported, and may corrupt the data files for those objects!


Python
~~~~~~~~~

.. autoclass:: tidas.mpi.MPIVolume
    :members:


C++
~~~~~~~~~

.. doxygenclass:: tidas::mpi_volume
    :members:
    :no-link:
