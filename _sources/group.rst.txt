
.. _group:

Groups
=================

A "group" contains a collection of timestreams with consistent sampling.  In other words, each timestream in the group has the same number of samples.  Each timestream has a name, a data type, and a string describing the units.  This metadata for one timestream is called a "field".  The collection of fields used in a group is called the "schema" of the group.  A group's schema is fixed at creation time, but the number of samples may be changed as needed.  A group is associated with a parent block.  Read and write operations on the data in a group is passed off to the "backend" class in use.  A group may also have a dictionary of scalar properties associated with it.


Python
~~~~~~~~~

.. autoclass:: tidas.Group
    :members:


C++
~~~~~~~~~

.. doxygenclass:: tidas::group
        :members:
