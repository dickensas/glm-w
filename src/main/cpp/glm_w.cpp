#include <stdlib.h>
#include <stdio.h>
#include "glm_w.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/ext/matrix_relational.hpp>
#include <glm/gtc/type_ptr.hpp>

int foo() {
    return 0;
}

float* perspective(float a, float b, float c, float d) {
	float *arr = (float *)malloc(16);
	memcpy( arr, ( glm::value_ptr(glm::perspective(a,b,c,d)) ), sizeof( float ) * 16 );
	return arr;
}

float* translate(float *a, float *b) {
	float *arr = (float *)malloc(16);
	memcpy( arr, ( glm::value_ptr( glm::translate(glm::make_mat4x4(a),glm::make_vec3(b)) ) ), sizeof( float ) * 16 );
	return arr;
}

float* rotate(float* a, float b, float* c) {
	float *arr = (float *)malloc(16);
	memcpy( arr, ( glm::value_ptr( glm::rotate(glm::make_mat4x4(a),b,glm::make_vec3(c)) ) ), sizeof( float ) * 16 );
	return arr;
}

float* scale(float a, float b) {
	float *arr = (float *)malloc(16);
	memcpy( arr, ( glm::value_ptr(glm::scale(glm::mat4(a), glm::vec3(b))) ), sizeof( float ) * 16 );
	return arr;
}

float* mat4x4_mul(float* a, float* b) {
	float *arr = (float *)malloc(16);
	memcpy( arr, glm::value_ptr(glm::make_mat4x4(a) * glm::make_mat4x4(b)), sizeof( float ) * 16 );
	return arr;
}

glmw Glmw() {
    struct glmw mGlmw;
    mGlmw.perspective = &perspective;
    mGlmw.rotate = &rotate;
    mGlmw.scale = &scale;
    mGlmw.mat4x4_mul = &mat4x4_mul;
    mGlmw.free = &free;
    return mGlmw;
}
