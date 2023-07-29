#pragma once

#define CHUNK_LIMIT 1048576

#include <cstdio>
#include <sstream>
#include <string>
#include <zlib.h>
class StreamBuffer {
  protected:
    gzFile in;
    char *buf;
    int pos;
    int size;

    void assureLookahead() {
        if (pos >= size) {
            pos = 0;
            size = gzread(in, buf, sizeof(buf));
        }
    }

  public:
    explicit StreamBuffer(gzFile i) : in(i), pos(0), size(0) {
        buf = new char[CHUNK_LIMIT];
        assureLookahead();
    }

    virtual ~StreamBuffer() { delete[] buf; }

    int operator*() { return (pos >= size) ? EOF : buf[pos]; }
    void operator++() {
        pos++;
        assureLookahead();
    }
};