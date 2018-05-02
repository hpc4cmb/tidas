
.. _dev:

Developer Documentation
=============================

The goal of this section is to provide more background information for developers reading through the source code and making changes.


Backends
--------------------------

.. todo::

    Talk here about implementing backend classes for group, intervals, and dict objects.


.. doxygenenum:: tidas::data_type

.. doxygenenum:: tidas::backend_type

.. doxygenenum:: tidas::compression_type

.. doxygenenum:: tidas::access_mode



Location Information
-----------------------

Each object has a "location" which represents its on-disk position relative to other objects in the hierarchy.

.. todo::

    Add more details...

.. doxygenclass:: tidas::backend_path
        :members:


Indexing (Metadata Database)
----------------------------------

.. todo::

    Describe the 2 different metadata indices, how transactions are retrieved / replayed, etc.


