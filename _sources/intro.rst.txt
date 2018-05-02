.. _intro:

Introduction
=================================

Storing, retrieving, and searching large datasets is a task that is common across many scientific endeavors and in private enterprises.  People from wide-ranging disciplines have been developing and using tools for these tasks for decades.  The software ecosystem for dealing with large datasets has many existing components.  Tools exist for everything from low-level optimized I/O that works closely with the filesystem to high-level workflow managers that have their own data formats and querying languages.

The TImestream DAta Storage (TIDAS) package aims to provide a specific piece of "middleware" to allow applications to organize, select, replicate, and do I/O on datasets which consist of values recorded at particular times.  Many data tools try to be general enough to work with all types of data, however timestream data has several unique features:

    * The metadata (descriptive properties, statistics, etc) for a data stream is usually **much** smaller than the data itself.

    * The smallest piece of data we typically work with might be thousands or millions of values.  Rarely are we studying one single datum.

    * For data recorded by some real-world apparatus, we often have multiple data streams that are recorded in lock-step.

    * Since the "data" is just a bunch of timestreams, there are only two dimensions over which we typically do selections (intervals of time, and the timestreams).

In TIDAS we focus on common operations that are needed in working with timestream data.  TIDAS can support multiple "backend" storage formats on disk and these are transparent to the application interface.


Data Organization
---------------------------------------

The highest-level object in TIDAS is a "volume".  A volume contains a hierarchy of "blocks".  Each block is a logical collection of data based on some common property.  A block can contain data itself, and/or other blocks.  The data inside a block is organized into one or more "groups".  The timestreams in a group are sampled consistently.  A block can optionally contain an "intervals" object which is a collection of smaller time ranges within the block.  These intervals might describe sections of good (or bad) data, or specify time ranges that have some special property.  The two objects which actually contain data (groups and intervals) also have an optional dictionary of arbitrary scalar properties.  Putting this all together, here is a crude schematic of a simple TIDAS volume:

.. todo::

    A figure here showing nested blocks and groups of timestreams would be nice.


Code Organization and Requirements
---------------------------------------

TIDAS consists mainly of a serial C++(11) library with no external dependencies.  There is an optional high-level MPI interface for working with TIDAS volumes.  There are also C and Python bindings for many operations.  Data and metadata are written to disk through the use of compile-time plugins ("backends").  Currently there is only one backend (HDF5), so the serial HDF5 library is also currently a requirement for doing any meaningful work with this package.

