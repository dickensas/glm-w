#ifndef __GLM_W_H__
#define __GLM_W_H__

#ifdef _WIN32
#define GLM_W_EXPORT_FUNC __declspec(dllexport)
#else
#define GLM_W_EXPORT_FUNC
#endif

GLM_W_EXPORT_FUNC typedef struct glmw {
    float* (*perspective)(float a, float b, float c, float d);
    float* (*translate)(float* a, float* b);
    float* (*rotate)(float* a, float b, float*c);
    float* (*scale)(float a, float b);
    float* (*mat4x4_mul)(float* a, float* b);
    void (*free)(void *);
} glmw;

GLM_W_EXPORT_FUNC glmw Glmw();

#endif
