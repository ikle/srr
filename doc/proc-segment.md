# Process Segments

A process segment represents a contiguous region of process memory with
specific access rights and shadow storage. Segments are merged into one if
they represent one contiguous memory region with the same permissions and
also represent one contiguous region in the shadow storage (if they have
such mapping). The segments cannot overlap.

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
the target for methods that change the process memory map is valid only for
processes with CAP\_PROC\_SEGMENT capability, even if the calling process ID
is specified. Interface functions always return -EINVAL if a negative target
process ID is specified.

## Segment Management Methods

### Create a new Segment

The proc\_segment\_alloc function allocates a memory segment of the specified
size and associates it with an area of the specified file. In the case where
a new segment intersects an existing one, the behavior of the function is
undefined (UB): a concrete implementation can either delete part of the
existing mapping or simply return an error (EBUSY).

On success, returns the address of the requested segment. In case the new
segment was merged with an existing one, the returned address may point to
the middle of the merged segment. (In the case of using a segmented memory
model, segments are not merged.)

### Remove a Memory Segment

The proc\_segment\_free function removes the specified memory segment from
the process's memory map. Succeeds if the segment to be removed does not
exist. Might return an out-of-memory error (ENOMEM) if a region is removed in
the middle of an existing segment, as such removal may require splitting the
segment into two separate segments.

In the case of using a segmented memory model, it is impossible to remove
part of the segment region at the beginning of the segment (this would
require changing the address of the beginning of the segment), as well as to
remove part of the region in the middle. In this case, a busy error (EBUSY)
is returned. (Removing an area at the end of a segment simply changes the
size of the segment.)

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
