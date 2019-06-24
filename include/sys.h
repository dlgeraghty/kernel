#ifndef  SYS_H
#define SYS_H

int inport(unsigned short port){
  int rv;
  __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (port));
  return rv;
}

void outport(unsigned short port, unsigned short data){
  __asm__ __volatile__ ("out %1, %0" : : "dN" (port), "a" (data));
}

#endif /* end of include guard: SYS_H */
