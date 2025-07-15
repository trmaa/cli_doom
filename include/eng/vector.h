#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
	float x, y;
} eng_vec2;

typedef struct {
	int x, y;
} eng_ivec2;

typedef struct {
	float x, y, z;
} eng_vec3;

typedef struct {
	int x, y, z;
} eng_ivec3;


eng_vec2 eng_new_vec2(float x, float y);


eng_ivec2 eng_new_ivec2(int x, int y);


eng_vec3 eng_new_vec3(float x, float y, float z);


eng_ivec3 eng_new_ivec3(int x, int y, int z);

#define eng_vec2_op(a, op, b) ((eng_vec2) { (a).x op (b).x, (a).y op (b).y })

#define eng_ivec2_op(a, op, b) ((eng_ivec2) { (a).x op (b).x, (a).y op (b).y })

#define eng_vec3_op(a, op, b) ((eng_vec3) { (a).x op (b).x, (a).y op (b).y, (a).z op (b).z })

#define eng_ivec3_op(a, op, b) ((eng_ivec3) { (a).x op (b).x, (a).y op (b).y, (a).z op (b).z })

#define eng_vec2_length(v) sqrtf(v.x * v.x + v.y * v.y)

#define eng_vec3_length(v) sqrtf(v.x * v.x + v.y * v.y + v.z * v.z)

#define eng_vec2_dotp(a, b) (a.x * b.x + a.y * b.y)

#define eng_vec3_dotp(a, b) (a.x * b.x + a.y * b.y + a.z * b.z)

#define eng_vec2_normalize(v) eng_vec2_op(v, /, eng_vec2_length(v)) 

#define eng_vec3_normalize(v) eng_vec3_op(v, /, eng_vec3_length(v))

#define eng_crossp(a, b) eng_new_vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x)

#endif
