
.. _selection:

Data Selection
=================

Selecting subsections of a volume is a fundamental feature of TIDAS.  This is useful for a wide variety of situations:

    * You are only working with a subset of the volume and want to reduce the metadata in memory.
    * You want to copy a subset of the volume to some other workspace or local disk.
    * You want to symlink a portion of a large volume to a smaller one for testing analysis tools.
    * You want to selectively delete portions of the volume.

Data selection in TIDAS is performed with a regular expression syntax applied to the names of the hierarchy of blocks and their child groups and intervals.


Syntax
-----------

The full selection string uses several special characters to split up the regular expressions applied to the objects.  Blocks are separated by a normal slash.  If we had 3 levels of blocks (not counting the root) in our volume, we might select a subset with:

.. parsed-literal::

    /\ **block-re-1**\ /\ **block-re-2**\ /\ **block-re-3**

So there is a regular expression matching the block names for each level of the hierarchy.  Although any block might also contain data (groups and intervals), let us assume for this example that only the lowest level blocks have some groups and intervals.  We can apply a list of selections to the groups and intervals based on their names.  This list is enclosed in square brackets and separated by commas:

.. parsed-literal::

    /\ **block-re-1**\ /\ **block-re-2**\ /\ **block-re-3**\ [grp=\ **group-re-1**\ ,grp=\ **group-re-2**\ ,intr=\ **interval-re-1**\ ]

When using a selection string for opening or linking a volume, the above granularity (selecting whole blocks, groups, and intervals) is the only thing possible.  However, when *copying* a volume, TIDAS supports selecting only a subset of the fields in a group, and also supports selection of a subset of the values in the dictionaries of groups and intervals.  Here is an example that slices out only some fields from the first group regex, and also only gets some dictionary values:

.. parsed-literal::

    /\ **block-re-1**\ /\ **block-re-2**\ /\ **block-re-3**\ [grp=\ **group-re-1**\ [schm=\ **field-re**\ ,dict=\ **key-re**\ ],grp=\ **group-re-2**\ ,intr=\ **interval-re-1**\ ]

Each of the regular expressions in the above examples simply uses a std::regex object with extended syntax.  You should follow that standard when crafting strings to match against the different object names.


Example
------------------

For a more detailed example, imagine we are copying a subset of a volume.  Our volume has top-level blocks named after years (2008, 2009, 2010, 2011, etc), and then blocks named after the months, followed by blocks named after the day of the month.  The lowest level blocks have several data groups, named daq1, daq2, daq3, etc.  We would like to export just the data from the first day of every month in the year 2010, and we only want the data from daq3.  We could duplicate the volume with the following selection string:

.. parsed-literal::

    /2010/.*/01[grp=daq3]

