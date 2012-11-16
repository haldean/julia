#ifndef __SHADER_H__
#define __SHADER_H__

unsigned int setup_shader(const char *fname);
void set_uniform1f(unsigned int prog, const char *name, float val);
void set_uniform2f(unsigned int prog, const char *name, float v1, float v2);
void set_uniform1i(unsigned int prog, const char *name, int val);

#endif
