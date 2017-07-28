
.. _volume:

Volumes
=================

A volume is the top-level TIDAS object.  It defines the "backend" data format and holds a metadata database for fast(er) data selection and query operations.  It also contains the root of a hierarchy (a tree) of "blocks".





Blocks
----------------

A "block" is simply a logical collection of data which has a "name" (a string) associated with it.  A block can contain data itself, other blocks, or both.  A volume contains a special "root" block, which is the top of the tree / hierarchy of blocks in the volume.

C++
~~~~~~~~~
.. doxygenclass:: tidas::block
        :members:

Python
~~~~~~~~~
.. autoclass:: tidas.Block
    :members:


Planning the Layout of a Volume
--------------------------------------

An important feature of TIDAS volumes is the ability to open / copy / link only a subset of the data.  This selection operation is performed with a regular expression match on the tree of block names.  This means that it is critical to plan out the organization of blocks to make it possible to do any desired data selections.

Most data collected from monitoring systems, experimental apparatuses, etc, have natural ways that the data might be split up into pieces.  For example, if the data collection is started fresh each day, you might have a block for each day.  If there are different sorts of data within one day which you might want to frequently split up, then you could have sub-blocks in each day for the different data types.  Going the other direction up the hierarchy, you might organize the days into blocks for each month, each quarter, each year, etc. 


Example
----------------------


