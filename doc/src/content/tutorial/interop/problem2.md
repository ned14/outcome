+++
title = "Arbitrary failure handling"
weight = 10
+++

Thanks to the age of C, there are a great deal of common design patterns for returning failure
which C++ not only must cope with, but often copies and is inspired by. Here are some
APIs copied and pasted from various well-known libraries and systems:

```c++
// Returns -1 if failed, can check errno for cause.
ssize_t read(int fd, void *buf, size_t count);

// Returns FALSE if failed, can check GetLastError() for cause.
BOOL WINAPI ReadFile(
  _In_        HANDLE       hFile,
  _Out_       LPVOID       lpBuffer,
  _In_        DWORD        nNumberOfBytesToRead,
  _Out_opt_   LPDWORD      lpNumberOfBytesRead,
  _Inout_opt_ LPOVERLAPPED lpOverlapped
);

// Returns 0 if it *may* have failed. ferror() can be used to check.
size_t fread(void *ptr, size_t size, size_t count, FILE *stream);

// You must call alGetError(void) after every API call to check if it failed!
void alSourceQueueBuffers (ALuint sourceName, ALsizei numBuffers, ALuint *bufferNames);

// Returns 0 for success, anything else is the cause of failure.
int sqlite3_blob_read(sqlite3_blob *, void *Z, int N, int iOffset);
```

... in progress ...
