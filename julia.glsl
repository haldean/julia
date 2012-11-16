/* vim: set filetype=c : */

uniform vec2 c;
uniform int iter;

void main() {
  vec2 z;
  z.x = 3.0 * (gl_TexCoord[0].x - .5);
  z.y = 3.0 * (gl_TexCoord[0].y - .5);

  int i;
  for (i=0; i<iter; i++) {
		float x = (z.x * z.x - z.y * z.y) + c.x;
    float y = (z.x * z.y + z.x * z.y) + c.y;

    if ((x * x + y * y) > 10.0) break;
    z.x = x;
    z.y = y;
  }

  float val = float(i) / float(iter);
  gl_FragColor = vec4(1. - val, 1. - val, 1. - val, 1);
}
