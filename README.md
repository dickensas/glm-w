# glm-w
GLM C Wrapper

## Sample code

```cpp
#include <glm_w.h>
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
```

Output

```bash
13.00 8.00 7.00 5.00 
9.00 7.00 5.00 4.00 
9.00 7.00 5.00 4.00 
12.00 11.00 6.00 5.00 
```
