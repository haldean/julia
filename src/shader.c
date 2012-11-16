#include "shader.h"

#include <stdlib.h>
#include <stdio.h>

#include "glinclude.h"

void set_uniform1f(unsigned int prog, const char *name, float val) {
  int loc = glGetUniformLocation(prog, name);
  if(loc != -1) {
    glUniform1f(loc, val);
  }
}

void set_uniform2f(unsigned int prog, const char *name, float v1, float v2) {
  int loc = glGetUniformLocation(prog, name);
  if(loc != -1) {
    glUniform2f(loc, v1, v2);
  }
}

void set_uniform1i(unsigned int prog, const char *name, int val) {
  int loc = glGetUniformLocation(prog, name);
  if(loc != -1) {
    glUniform1i(loc, val);
  }
}

unsigned int setup_shader(const char *fname) {
  FILE *fp;
  unsigned int prog, sdr, len;
  char *src_buf;
  int success, linked;

  if(!(fp = fopen(fname, "r"))) {
    fprintf(stderr, "failed to open shader: %s\n", fname);
    return 0;
  }
  fseek(fp, 0, SEEK_END);
  len = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  src_buf = malloc(len + 1);

  fread(src_buf, 1, len, fp);
  src_buf[len] = 0;

  sdr = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(sdr, 1, (const char**)&src_buf, NULL);
  free(src_buf);

  glCompileShader(sdr);
  glGetShaderiv(sdr, GL_COMPILE_STATUS, &success);
  if(!success) {
    int info_len;
    char *info_log;

    glGetShaderiv(sdr, GL_INFO_LOG_LENGTH, &info_len);
    if(info_len > 0) {
      if(!(info_log = malloc(info_len + 1))) {
        perror("malloc failed");
        return 0;
      }
      glGetShaderInfoLog(sdr, info_len, 0, info_log);
      fprintf(stderr, "shader compilation failed: %s\n", info_log);
      free(info_log);
    } else {
      fprintf(stderr, "shader compilation failed\n");
    }
    return 0;
  }

  prog = glCreateProgram();
  glAttachShader(prog, sdr);
  glLinkProgram(prog);
  glGetShaderiv(prog, GL_LINK_STATUS, &linked);

  glUseProgram(prog);
  return prog;
}
