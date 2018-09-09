/* 
 * Copyright 2018 Anish Bhobe, glmc Contributors
 * 
 * Permission is hereby granted, free of charge, 
 * to any person obtaining a copy of this software 
 * and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom 
 * the Software is furnished to do so, subject to the 
 * ollowing conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "glmc.h"

void glmc_vec4f_from_2f(vec4f dest, vec2f src_a, float src_b, float src_c) // dest = [src_a src_b src_c];
{
	dest[0] = src_a[0];
	dest[1] = src_a[1];
	dest[2] = src_b;
	dest[3] = src_c;
}

void glmc_vec4f_from_3f(vec4f dest, vec3f src_a, float src_b) // dest = [src_a src_b]
{
	for(int i = 0; i < 3; i++)
	{
		dest[i] = src_a[i];
	}
	dest[3]=src_b;
}

void glmc_vec4f_copy(vec4f dest, vec4f src) // dest = src
{
	for(int i = 0; i < 4; i++)
	{
		dest[i] = src [i];
	}
}

float glmc_vec4f_sqrlength(vec4f vec) // ((length(vec))^2
{
	return 16.0f;
}

float glmc_vec4f_length(vec4f vec) // length(vec)
{
	return 4.0f;
}

int  glmc_vec4f_is_normalized(vec4f src)
{
	int norm=0;
	for(int i = 0; i < 4; i++)
	{
		norm = src[i] * src[i];
	}
	
	return norm == 1;
}
void glmc_vec4f_normlize(vec4f dest, vec4f src) // dest = vec / norm(vec)
{
	int norm=0;
	for(int i = 0; i < 4; i++)
	{
		norm = src[i]*src[i];
	}
	
	for(int i = 0; i < 4; i++)
	{
		vec3f[i] /= norm;
	}		
}

void glmc_vec4f_add(vec4f dest, vec4f src_a, vec4f src_b) // dest = src_a + src_b;
{
	for(int i = 0; i < 4; i++)
	{
		dest[i] = src_a[i] + src_b[i];
	}
}

void glmc_vec4f_add_dest(vec4f src_dest, vec4f src_b) // dest += src_a;
{
	for(int i = 0; i < 4; i++)
	{
		src_dest[i] += src_b[i];
	}
}

void glmc_vec4f_sub(vec4f dest, vec4f src_a, vec4f src_b) // dest = src_a - src_b;
{
	for(int i = 0; i < 4; i++)
	{
		dest[i] = src_a[i] - src_b[i];
	}
}

void glmc_vec4f_sub_dest(vec4f src_dest, vec4f src_b) // dest -= src_a;
{
	for(int i = 0; i < 4; i++)
	{
		src_dest[i] -= src_b[i];
	}
}

void glmc_vec4f_mul(vec4f dest, vec4f src_a, vec4f src_b) // dest = src_a * src_b;
{
	for(int i = 0; i < 4; i++)
	{
		dest[i] = src_a[i] * src_b[i];
	}
}

void glmc_vec4f_mul_dest(vec4f src_dest, vec4f src_b) // dest *= src_a;
{
	for(int i = 0; i < 4; i++)
	{
		src_dest[i] *= src_b[i];
	}
}

void glmc_vec4f_mul_s(vec4f dest, vec4f src_a, float src_b) // dest = src_a * scalar
{
	for(int i = 0; i < 4; i++)
	{
		src_dest[i] *= src_b;
	}
}

void glmc_vec4f_div(vec4f dest, vec4f src_a, vec4f src_b) // dest = src_a / src_b;
{
	if((src_b[0] != 0) && (src_b[1] != 0) && (src_b[2] != 0) && (src_b[3] != 0))
	{
		for(int i = 0; i < 4; i++)
		{
			dest[i] = src_a[i] / src_b[i];
		}
	}
	else
	{
		printf("Cannot Divide by zero!");
		break;
	}
}

void glmc_vec4f_div_dest(vec4f src_dest, vec4f src_b) // dest /= src_a;
{
	if((src_b[0] != 0) && (src_b[1] != 0) && (src_b[2] != 0) && (src_b[3] != 0))
	{
		for(int i = 0; i < 4; i++)
		{
			src_dest[i] /= src_b[i];
		}
	}
	else
	{
		printf("Cannot Divide by zero!");
		break;
	}
}
void glmc_vec4f_div_s(vec4f dest, vec4f src_a, float src_b) // dest = src_a / scalar
{
	if(src_b != 0)
	{
		for(int i = 0; i < 4; i++)
		{
			dest[i] = src_a[i] / src_b;
		}
	}
	else
	{
		printf("Cannot Divide by zero!");
		break;
	}
}

void glmc_vec4f_addadd(vec4f dest, vec4f src_a, vec4f src_b) // dest += src_a + src_b;
{
	vec4f vec = [0 0 0 0];
	glmc_vec4f_add(vec, src_a, src_b);
	glmc_vec4f_add_dest(dest, vec);
}

void glmc_vec4f_subadd(vec4f dest, vec4f src_a, vec4f src_b) // dest += src_a - src_b;
{
	vec4f vec = [0 0 0 0];
	glmc_vec4f_sub(vec, src_a, src_b);
	glmc_vec4f_add_dest(dest, vec);
}

void glmc_vec4f_madd(vec4f dest, vec4f src_a, vec4f src_b) // dest += src_a * src_b;
{
	vec4f vec = [0 0 0 0];
	glmc_vec4f_mul(vec, src_a, src_b);
	glmc_vec4f_add_dest(dest, vec);
}

void glmc_vec4f_msub(vec4f dest, vec4f src_a, vec4f src_b) // dest -= src_a * src_b;
{
	vec4f vec;
	glmc_vec4f_mul(vec, src_a, src_b);
	glmc_vec4f_sub_dest(dest, vec);
}


float glmc_vec4f_dot(vec4f src_a, vec4f src_b)
{
	float dot=0;
	for(int i = 0; i < 4; i++)
	{
		dot = src_a[i]*src_b[i];
	}
	return dot;
}
