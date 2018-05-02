
.. _intervals:

Intervals
=================

When dealing with time domain data, it is very common to specify ranges of time that have some meaning.  These might be spans of good or bad data, or time ranges that enclose some important event or feature.  This use case is so common that TIDAS has a built in object for this.  An "intervals" object represents a list of time ranges.  Each span can also optionally have a range of sample indices, which is useful if the intervals are associated with a particular group.


Python
~~~~~~~~~

.. autoclass:: tidas.Intrvl
    :members:

.. autoclass:: tidas.Intervals
    :members:


C++
~~~~~~~~~

.. doxygenclass:: tidas::intrvl
        :members:

.. doxygenclass:: tidas::intervals
        :members:


