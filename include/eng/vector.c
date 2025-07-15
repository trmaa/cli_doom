#include "vector.h"

eng_vec2 eng_new_vec2(float x, float y) {
    eng_vec2 v;
    v.x = x;
    v.y = y;
    return v;
}


eng_ivec2 eng_new_ivec2(int x, int y) {
    eng_ivec2 v;
    v.x = x;
    v.y = y;
    return v;
}


eng_vec3 eng_new_vec3(float x, float y, float z) {
    eng_vec3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}


eng_ivec3 eng_new_ivec3(int x, int y, int z) {
    eng_ivec3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}
