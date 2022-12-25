# Process Segments

A process segment represents a contiguous region of process memory with
specific access rights and shadow storage. Segments are merged into one if
they represent one contiguous memory region with the same permissions and
also represent one contiguous region in the shadow storage (if they have
such mapping).

Another process may be granted the right to map a segment of another process
(or part of it) to its own. At the same time, access rights during such
transfer can be limited by both the transmitting side and the receiving side.

A process may declare its segment (created or received from another process)
as private. In such a case, the segment may be declared writable even if no
write permission has been granted by the sender. When process tries to write
to such segment, a new memory mapping of its memory will be created, into
which the original contents will be copied. For real-time tasks, such copying
can be done at the time of creating or importing a segment.

## General Provisions of the Interface

Users of the interface to manage their own process memory segments should
specify zero as the target process ID. Specifying a positive process ID as
the target is only valid for processes with CAP\_PROC\_SEGMENT capability,
even if the calling process ID is specified. Interface functions always
return -EINVAL when specifying a negative target process ID.

## Segment Management Methods

### Request Information about a Segment

The proc\_segment\_query function queries information about the process
memory segment. Succeeds if a memory segment is found whose start address is
greater than or equal to the specified one. Note that the specified address
may not belong to the segment whose information can be returned. If the
caller needs to check for the occurrence of a specified address in a memory
segment, then it must compare its value with the address of the end of the
segment. This behavior of this method allows you to get information about all
segments of the process memory without knowing in advance the addresses of
the beginning of the segments.
