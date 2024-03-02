/*
 * File:  options.h
 * Author:  mikolas
 * Created on:  Thu Jul 27 14:43:08 CEST 2023
 * Copyright (C) 2023, Mikolas Janota
 */
#pragma once
#include <string>

class SMSOptions {
  public:
    int vertices;
};

class Options {
  public:
    Options() {}

  public:
    std::string file_name;
    bool aig;
    bool simplify;
    bool flatten;
    bool unit;
    bool polarities;
    bool full;
    bool luby_restart;
    bool enumerate;
    bool simple_cut;
    int verbose;
    SMSOptions sms_args;

    bool has_free = false;
};
