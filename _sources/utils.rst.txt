
.. _utils:

Utilities
==============

TIDAS has several small helper functions / classes.  They are documented here for lack of a better place.

Dictionaries
------------------

The TIDAS dictionary class exists mainly to provide a strongly typed implementation that can be read / written by a backend implementation.  In the Python API, all classes / functions just use normal python dictionaries and these are converted under the hood to a C++ TIDAS dictionary.

.. doxygenclass:: tidas::dict
    :members:


Filesystem Utilities
--------------------------

In Python, there are already extensive tools for easy manipulation of the filesystem.  These C++ tools are used internally but might also be useful for application developers, which is why they are documented here.


.. doxygenfunction:: tidas::fs_stat

.. doxygenfunction:: tidas::fs_rm

.. doxygenfunction:: tidas::fs_mkdir


