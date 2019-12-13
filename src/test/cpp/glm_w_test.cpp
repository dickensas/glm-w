#include <glm_w.h>
#include <cassert>
#include <stdio.h>

int main() {
	struct glmw mCGlw = Glmw();
	float a[16] = { 3.0f, 4.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 4.0f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
	float b[16] = { 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f};
	float *c = mCGlw.mat4x4_mul(a,b);
	mCGlw.free(c);

	for(int i=0;i<16;i++){
		printf("%2.2f ", c[i]);
		if((i+1)%4==0)printf("\n");
	}

	assert(c[12]==12);
    return 0;
}
