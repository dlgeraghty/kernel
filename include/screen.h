#ifndef  SCREEN_H
#define SCREEN_H

void printc(char l, char c, int *x, int *y, unsigned char *v){
  int cursorX = *x;
  int cursorY = *y;
  switch(l){
    case ('\n'):
        *x = 0;
        *y+=2;
        break;
    default:
        v[(cursorY*w + cursorX)] = l;
        v[(cursorY*w + cursorX)+1] = c;
        *x+=2;
        break;
  }

  printcursor(*x,*y);

}

void cls(unsigned char *v){
  for (int i = 0; i < w*h*2; i++) {
    v[i] = 0x0;
  }
}

void prints(char *p, int *x, int *y, unsigned char *v){
  for(int i = 0; p[i] != '\0'; ++i){
    printc(p[i], 0x09, x, y, v);
  }
  printc((*y)+48, 0x07, x, y, v);
}

void nextLine(){
  string vidmem = (string)0xb8000;
  for(int i = 0; i < w*(h-1)*2; i++){
    vidmem[i] = vidmem[i + w*2];
  }
}

void printcursor(int x,int y){
  outport(0x3D4, 14);
  outport(0x3D5, (y*w + x) >> 8);
  outport(0x3D4, 15);
  outport(0x3D5, (y*w + x));
}

#endif /* end of include guard: SCREEN_H */
