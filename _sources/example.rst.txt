
.. _example:

Examples
==============

It is always debatable whether the examples should come before or after the detailed documentation.  You should read through the following sections for more details about the different TIDAS objects, terminology, and use. 


Simple "Weather" Data
-------------------------

In this toy example, we create a volume with the serial Python interface and
write some fake data.  Then we show how to copy a subset of that volume as well
as how to set up a linked volume that can have additional data objects added 
to it.

.. literalinclude:: ../../examples/demo_weather.py


Fake Telescope
-------------------------

In this example, we create several groups per day with data at very different
sampling rates.

.. literalinclude:: ../../examples/demo_telescope.py

