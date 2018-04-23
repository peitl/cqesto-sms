/*
 * File:  VariableManager.h
 * Author:  mikolas
 * Created on:  Fri, May 15, 2015 4:52:29 PM
 * Copyright (C) 2015, Mikolas Janota
 */
#ifndef VARIABLEMANAGER_H_3087
#define VARIABLEMANAGER_H_3087
namespace qesto {
class VariableManager {
public:
  VariableManager(const VariableManager& o) : last(o.last) { }
  VariableManager() : last(0) { }
  VariableManager& operator=(const VariableManager& o) {
    last=o.last;
    return *this;
  }
public:
  inline Var new_var() { return ++last; }
  inline void dealoc(Var v) { assert(v<=last); if (v==last) --last; }
  inline Var max() const { return last; }
private:
  Var last;
};
}
#endif /* VARIABLEMANAGER_H_3087 */
